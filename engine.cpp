// Residual - Virtual machine to run LucasArts' 3D adventure games
// Copyright (C) 2003-2004 The ScummVM-Residual Team (www.scummvm.org)
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA

#include "stdafx.h"
#include "engine.h"
#include "scene.h"
#include "lua.h"
#include "colormap.h"
#include "actor.h"
#include "textobject.h"
#include <SDL.h>
#include <SDL_timer.h>
#include <assert.h>
#include "screen.h"
#include "smush.h"

#include "driver_gl.h"

Engine *Engine::instance_ = NULL;

Engine::Engine() :
		currScene_(NULL), selectedActor_(NULL) {
	for (int i = 0; i < SDLK_EXTRA_LAST; i++)
		controlsEnabled_[i] = false;
	_speechMode = 2;
}

void Engine::mainLoop() {
	movieTime_ = 0;
	frameTime_ = 0;
	frameStart_ = SDL_GetTicks();
	unsigned int frameCounter = 0;
	unsigned int timeAccum = 0;
	char fps[8] = "";

	for (;;) {
		// Process events
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN && controlsEnabled_[event.key.keysym.sym]) {
				lua_beginblock();
				lua_Object handler = getEventHandler("buttonHandler");
				if (handler != LUA_NOOBJECT) {
					lua_pushnumber(event.key.keysym.sym);
					lua_pushnumber(1);
					lua_pushnil();
					lua_callfunction(handler);
				}
				lua_endblock();
			}
			if (event.type == SDL_KEYUP && controlsEnabled_[event.key.keysym.sym]) {
				lua_beginblock();
				lua_Object handler = getEventHandler("buttonHandler");
				if (handler != LUA_NOOBJECT) {
					lua_pushnumber(event.key.keysym.sym);
					lua_pushnil();
					lua_pushnil();
					lua_callfunction(handler);
				}
				lua_endblock();
			}
			if (event.type == SDL_QUIT) {
				lua_beginblock();
				lua_Object handler = getEventHandler("exitHandler");
				if (handler != LUA_NOOBJECT)
					lua_callfunction(handler);
				lua_endblock();
			}
			if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_q)
					return;
			}
		}

		// Run asynchronous tasks
		lua_runtasks();

		if (_mode == ENGINE_MODE_SMUSH) {
			if (g_smush->isPlaying()) {
				movieTime_ = g_smush->getMovieTime();
				if (g_smush->isUpdateNeeded()) {
					g_driver->prepareSmushFrame(g_smush->getWidth(), g_smush->getHeight(), g_smush->getDstPtr());
					g_smush->clearUpdateNeeded();
				}
				if (g_smush->getFrame() > 0) {
					g_driver->drawSmushFrame(g_smush->getX(), g_smush->getY());
					if (SHOWFPS_GLOBAL)
						g_driver->drawEmergString(550, 25, fps, Color(255, 255, 255));
				}
			}
		} else if (_mode == ENGINE_MODE_NORMAL) {
			if (SCREENBLOCKS_GLOBAL)
				screenBlocksReset();

			// Update actor costumes
			for (actor_list_type::iterator i = actors_.begin(); i != actors_.end(); i++) {
				Actor *a = *i;
				assert(currScene_);
				if (a->inSet(currScene_->name()) && a->visible())
					a->update();
			} 

			g_driver->clearScreen();

			if (SCREENBLOCKS_GLOBAL)
				screenBlocksBlitDirtyBlocks();

			if (currScene_ != NULL) {
				currScene_->drawBackground();
			}

			if (g_smush->isPlaying()) {
				movieTime_ = g_smush->getMovieTime();
				if (g_smush->isUpdateNeeded()) {
					g_driver->prepareSmushFrame(g_smush->getWidth(), g_smush->getHeight(), g_smush->getDstPtr());
					g_smush->clearUpdateNeeded();
				}
				if (g_smush->getFrame() > 0)
					g_driver->drawSmushFrame(g_smush->getX(), g_smush->getY());
			}

			if (currScene_ != NULL) {
				currScene_->drawBitmaps(ObjectState::OBJSTATE_UNDERLAY);
				currScene_->drawBitmaps(ObjectState::OBJSTATE_STATE);
			}

			g_driver->set3DMode();

			if (currScene_ != NULL)
				currScene_->setupCamera();

			// Draw actors
			for (actor_list_type::iterator i = actors_.begin(); i != actors_.end(); i++) {
				Actor *a = *i;
				if (a->inSet(currScene_->name()) && a->visible())
					a->draw();
			}
			//screenBlocksDrawDebug();

			// Draw text
			for (text_list_type::iterator i = textObjects_.begin(); i != textObjects_.end(); i++) {
				(*i)->draw();
			}

			if (SHOWFPS_GLOBAL)
				g_driver->drawEmergString(550, 25, fps, Color(255, 255, 255));

			currScene_->drawBitmaps(ObjectState::OBJSTATE_OVERLAY);
		}

		g_driver->flipBuffer();

		// don't kill CPU
		SDL_Delay(1);

		// Update timing information
		unsigned newStart = SDL_GetTicks();
		frameTime_ = newStart - frameStart_;
		frameStart_ = newStart;

		lua_beginblock();
		set_frameTime(frameTime_);
		lua_endblock();

		lua_beginblock();
		set_movieTime(movieTime_);
		lua_endblock();

		if (SHOWFPS_GLOBAL) {
			frameCounter++;
			timeAccum += frameTime_;
			if (timeAccum > 1000) {
				sprintf(fps, "%7.2f", (double)(frameCounter * 1000) / (double)timeAccum );
				frameCounter = 0;
				timeAccum = 0;
			}
		}
	}
}

void Engine::setScene(const char *name) {
	Block *b = ResourceLoader::instance()->getFileBlock(name);
	if (b == NULL)
		warning("Could not find scene file %s\n", name);
	delete currScene_;
	currScene_ = new Scene(name, b->data(), b->len());
	delete b;
}

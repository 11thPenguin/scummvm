// Residual - Virtual machine to run LucasArts' 3D adventure games
// Copyright (C) 2003-2005 The ScummVM-Residual Team (www.scummvm.org)
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
#include "smush.h"
#include "driver.h"

#include "imuse/imuse.h"

#include <SDL.h>
#include <SDL_timer.h>
#include <assert.h>

Engine *g_engine = NULL;

extern Imuse *g_imuse;
int g_imuseState = -1;

// hack for access current upated actor to allow access position of actor to sound costume component
Actor *g_currentUpdatedActor = NULL;

Engine::Engine() :
		_currScene(NULL), _selectedActor(NULL) {
	for (int i = 0; i < SDLK_EXTRA_LAST; i++)
		_controlsEnabled[i] = false;
	_speechMode = 3; // VOICE + TEXT

	textObjectDefaults.x = 0;
	textObjectDefaults.y = 200;
	textObjectDefaults.width = 10;
	textObjectDefaults.height = 0;
	textObjectDefaults.fgColor._vals[0] = 255;
	textObjectDefaults.fgColor._vals[1] = 255;
	textObjectDefaults.fgColor._vals[2] = 255;
	textObjectDefaults.font = NULL;
	textObjectDefaults.justify = 2;

	sayLineDefaults.x = 0;
	sayLineDefaults.y = 100;
	sayLineDefaults.width = 0;
	sayLineDefaults.height = 0;
	sayLineDefaults.fgColor._vals[0] = 255;
	sayLineDefaults.fgColor._vals[1] = 255;
	sayLineDefaults.fgColor._vals[2] = 255;
	sayLineDefaults.font = NULL;
	sayLineDefaults.justify = 1;

	printLineDefaults.x = 0;
	printLineDefaults.y = 100;
	printLineDefaults.width = 0;
	printLineDefaults.height = 0;
	printLineDefaults.fgColor._vals[0] = 255;
	printLineDefaults.fgColor._vals[1] = 255;
	printLineDefaults.fgColor._vals[2] = 255;
	printLineDefaults.font = NULL;
	printLineDefaults.justify = 1;
}

void Engine::mainLoop() {
	_movieTime = 0;
	_frameTime = 0;
	_frameStart = SDL_GetTicks();
	unsigned int frameCounter = 0;
	unsigned int timeAccum = 0;
	unsigned int frameTimeCollection = 0;
	char fps[8] = "";
	_savegameLoadRequest = false;
	_savegameSaveRequest = false;
	_savegameFileName = NULL;

	for (;;) {
		// Process events
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN && _controlsEnabled[event.key.keysym.sym]) {
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
			if (event.type == SDL_KEYUP && _controlsEnabled[event.key.keysym.sym]) {
				// temporary hack for save/load request until game menu will work
				if (event.key.keysym.sym == SDLK_F7) {
					_savegameLoadRequest = true;
					continue;
				} else if (event.key.keysym.sym == SDLK_F8) {
					_savegameSaveRequest = true;
					continue;
				}

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

		if (_savegameLoadRequest) {
			savegameRestore();
		}
		if (_savegameSaveRequest) {
			savegameSave();
		}

		if (_mode == ENGINE_MODE_SMUSH) {
			if (g_smush->isPlaying()) {
				_movieTime = g_smush->getMovieTime();
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
			g_driver->clearScreen();

			// Update actor costumes
			for (ActorListType::iterator i = _actors.begin(); i != _actors.end(); i++) {
				Actor *a = *i;
				g_currentUpdatedActor = *i;
				if (_currScene != NULL && a->inSet(_currScene->name()) && a->visible())
					a->update();
			}
			g_currentUpdatedActor = NULL;

			if (_currScene != NULL) {
				_currScene->drawBackground();
			}

			if (g_smush->isPlaying()) {
				_movieTime = g_smush->getMovieTime();
				if (g_smush->isUpdateNeeded()) {
					g_driver->prepareSmushFrame(g_smush->getWidth(), g_smush->getHeight(), g_smush->getDstPtr());
					g_smush->clearUpdateNeeded();
				}
				if (g_smush->getFrame() > 0)
					g_driver->drawSmushFrame(g_smush->getX(), g_smush->getY());
			}

			if (_currScene != NULL) {
				_currScene->drawBitmaps(ObjectState::OBJSTATE_UNDERLAY);
				_currScene->drawBitmaps(ObjectState::OBJSTATE_STATE);
				_currScene->drawBitmaps(ObjectState::OBJSTATE_OVERLAY);
			}

			if (SHOWFPS_GLOBAL)
				g_driver->drawEmergString(550, 25, fps, Color(255, 255, 255));

			if (_currScene != NULL) {
				_currScene->setupCamera();
			}

			g_driver->set3DMode();

			if (_currScene != NULL) {
				_currScene->setupLights();
			}

			// Draw actors
			for (ActorListType::iterator i = _actors.begin(); i != _actors.end(); i++) {
				Actor *a = *i;
				if (_currScene != NULL && a->inSet(_currScene->name()) && a->visible())
					a->draw();
			}
		}

		// Draw text
		for (TextListType::iterator i = _textObjects.begin(); i != _textObjects.end(); i++) {
			(*i)->draw();
		}

		g_imuse->flushTracks();
		g_imuse->refreshScripts();

		g_driver->flipBuffer();

		// don't kill CPU
		SDL_Delay(1);

		// Update timing information
		unsigned newStart = SDL_GetTicks();
		_frameTime = newStart - _frameStart;
		_frameStart = newStart;

		frameTimeCollection += _frameTime;
		if (frameTimeCollection > 10000) {
			frameTimeCollection = 0;
			lua_collectgarbage(0);
		}

		lua_beginblock();
		setFrameTime(_frameTime);
		lua_endblock();

		lua_beginblock();
		setMovieTime(_movieTime);
		lua_endblock();

		if (SHOWFPS_GLOBAL) {
			frameCounter++;
			timeAccum += _frameTime;
			if (timeAccum > 1000) {
				sprintf(fps, "%7.2f", (double)(frameCounter * 1000) / (double)timeAccum );
				frameCounter = 0;
				timeAccum = 0;
			}
		}

		// Run asynchronous tasks
		lua_runtasks();

		if (g_imuseState != -1) {
			g_imuse->setMusicState(g_imuseState);
			g_imuseState = -1;
		}
	}
}

void Engine::savegameGzread(void *data, int size) {
	gzread(g_engine->_savegameFileHandle, data, size);
}

void Engine::savegameGzwrite(void *data, int size) {
	gzwrite(g_engine->_savegameFileHandle, data, size);
}

void Engine::savegameRestore() {
	printf("Engine::savegameRestore() started.\n");
	_savegameLoadRequest = false;
	char filename[200];
	if (_savegameFileName == NULL) {
		strcpy(filename, "grim.sav");
	} else {
		strcpy(filename, _savegameFileName);
	}
	_savegameFileHandle = gzopen(filename, "rb");
	if (_savegameFileHandle == NULL) {
		warning("savegameRestore() Error opening savegame file");
		return;
	}

	g_imuse->stopAllSounds();
	g_imuse->resetState();
	g_smush->stop();
	g_imuse->pause(true);
	g_smush->pause(true);

	//  free all resource
	//  lock resources

	uint32 tag;
	uint32 version;
	savegameGzread(&tag, 4);
	assert(tag == 'RSAV');
	savegameGzread(&version, 4);
	assert(version == 1);

	//Chore_Restore(savegameGzread);
	//Resource_Restore(savegameGzread);
	//Text_Restore(savegameGzread);
	//Room_Restore(savegameGzread);
	//Actor_Restore(savegameGzread);
	//Render_Restore(savegameGzread);
	//Primitive_Restore(savegameGzread);
	//Smush_Restore(savegameGzread);
	g_imuse->restoreState(savegameGzread);
	lua_Restore(savegameGzread);
	//  unlock resources
	gzclose(_savegameFileHandle);

	//bundle_dofile("patch05.bin");

	g_imuse->pause(false);
	g_smush->pause(false);
	printf("Engine::savegameRestore() finished.\n");
}

void Engine::savegameSave() {
	printf("Engine::savegameSave() started.\n");
	_savegameSaveRequest = false;
	char filename[200];
	if (_savegameFileName == NULL) {
		strcpy(filename, "grim.sav");
	} else {
		strcpy(filename, _savegameFileName);
	}
	_savegameFileHandle = gzopen(filename, "wb");
	if (_savegameFileHandle == NULL) {
		warning("savegameSave() Error creating savegame file");
		return;
	}

	g_imuse->pause(true);
	g_smush->pause(true);

	uint32 tag = 'RSAV';
	uint32 version = 1;
	savegameGzwrite(&tag, 4);
	savegameGzwrite(&version, 4);

	savegameCallback();

	//Chore_Save(savegameGzwrite);
	//Resource_Save(savegameGzwrite);
	//Text_Save(savegameGzwrite);
	//Room_Save(savegameGzwrite);
	//Actor_Save(savegameGzwrite);
	//Render_Save(savegameGzwrite);
	//Primitive_Save(savegameGzwrite);
	//Smush_Save(savegameGzwrite);
	g_imuse->saveState(savegameGzread);
	lua_Save(savegameGzwrite);

	gzclose(_savegameFileHandle);

	g_imuse->pause(false);
	g_smush->pause(false);
	printf("Engine::savegameSave() finished.\n");
}

void Engine::savegameCallback() {
	lua_Object funcParam1;
	lua_Object funcParam2;
	bool unk1 = false;
	bool unk2 = false;

	lua_beginblock();
	lua_pushobject(lua_getglobal("system"));
	lua_pushstring("saveGameCallback");
	funcParam2 = lua_gettable();

	if (lua_istable(funcParam2)) {
		lua_pushobject(funcParam2);
		lua_pushstring("saveGameCallback");
		funcParam1 = lua_gettable();
		if (lua_isfunction(funcParam1)) {
			unk1 = true;
			unk2 = true;
		} else {
			assert(false);
		}
	} else if (lua_isfunction(funcParam2)) {
		funcParam1 = funcParam2;
		unk1 = false;
		unk2 = true;
	} else if (!lua_isnil(funcParam2)) {
		assert(false);
	}
	if (unk2) {
		if (unk1) {
			lua_pushobject(funcParam2);
		}
		lua_callfunction(funcParam1);
	}
	lua_endblock();
}

void Engine::setScene(const char *name) {
	Block *b = g_resourceloader->getFileBlock(name);
	if (b == NULL)
		warning("Could not find scene file %s\n", name);
	delete _currScene;
	_currScene = new Scene(name, b->data(), b->len());
	_currScene->setSoundParameters(20, 127);
	delete b;
}

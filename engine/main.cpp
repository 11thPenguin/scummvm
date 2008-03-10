/* Residual - Virtual machine to run LucasArts' 3D adventure games
 * Copyright (C) 2003-2006 The ScummVM-Residual Team (www.scummvm.org)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 *
 * $URL$
 * $Id$
 *
 */

#include "common/sys.h"
#include "common/debug.h"

#include "engine/bitmap.h"
#include "engine/resource.h"
#include "engine/lua.h"
#include "engine/registry.h"
#include "engine/localize.h"
#include "engine/engine.h"
#include "common/timer.h"
#include "engine/smush/smush.h"

#include "engine/backend/sdl/driver_gl.h"
#include "engine/backend/sdl/driver_tinygl.h"

#include "mixer/mixer.h"

#include "engine/imuse/imuse.h"

#include <SDL.h>
#include <SDL_video.h>

#if defined (WIN32) && !defined (_MSC_VER)
int WinMain(HINSTANCE /*hInst*/, HINSTANCE /*hPrevInst*/,  LPSTR /*lpCmdLine*/, int /*iShowCmd*/) {
    return main(__argc, __argv);
}
#endif

#ifdef _MSC_VER
	#undef main
#endif

// Hacky global toggles for experimental/debug code
bool ZBUFFER_GLOBAL, SHOWFPS_GLOBAL, TINYGL_GLOBAL;
enDebugLevels debugLevel = DEBUG_NONE;

static bool g_lua_initialized = false;
Driver *g_driver = NULL;
DefaultTimerManager *g_timer = NULL;
Audio::Mixer *g_mixer = NULL;

static bool parseBoolStr(const char *val) {
	if (val == NULL || val[0] == 0)
		return false;

	switch (val[0]) {
	case 'y': case 'Y':	// yes
	case 't': case 'T':	// true
	case '1':
		return true;
	case 'n': case 'N':	// no
	case 'f': case 'F':	// false
	case '0':
		return false;
	case 'o':
		switch (val[1]) {
		case 'n': case 'N': // on
			return true;
		case 'f': case 'F': // off
			return false;
		}
	}

	error("Unrecognized boolean value %s\n", val);
	return false;
}

void quit();

int main(int argc, char *argv[]) {
	int i;

	g_registry = new Registry();

	// Parse command line
	ZBUFFER_GLOBAL = parseBoolStr(g_registry->get("zbuffer", "TRUE"));
	SHOWFPS_GLOBAL = parseBoolStr(g_registry->get("fps", "FALSE"));
	TINYGL_GLOBAL = parseBoolStr(g_registry->get("soft", "FALSE"));
	bool fullscreen = parseBoolStr(g_registry->get("fullscreen", "FALSE"));
	for (i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-zbuffer") == 0)
			ZBUFFER_GLOBAL = true;
		else if (strcmp(argv[i], "-nozbuffer") == 0)
			ZBUFFER_GLOBAL = false;
		else if (strcmp(argv[i], "-fps") == 0)
			SHOWFPS_GLOBAL = true;
		else if (strcmp(argv[i], "-nofps") == 0)
			SHOWFPS_GLOBAL = false;
		else if (strcmp(argv[i], "-fullscreen") == 0)
			fullscreen = true;
		else if (strcmp(argv[i], "-nofullscreen") == 0)
			fullscreen = false;
		else if (strcmp(argv[i], "-soft") == 0)
			TINYGL_GLOBAL = true;
		else if (strcmp(argv[i], "-nosoft") == 0)
			TINYGL_GLOBAL = false;
		else if (strncmp(argv[i], "-debug=", 7) == 0) {
			bool numeric = true;
			char debugtxt[20];
			unsigned int j;
			int level;
			
			sscanf(argv[i], "%*[^=]%*1s%s", debugtxt);
			for (j = 0;j < strlen(debugtxt); j++) {
				if (!isdigit(debugtxt[j]))
					numeric = false;
			}
			if (numeric) {
				sscanf(debugtxt, "%d", &level);
				if (level < 0 || level > DEBUG_ALL)
					goto needshelp;
			} else {
				level = -1;
				for (j = 0; j <= DEBUG_ALL; j++) {
					if (!strcasecmp(debugtxt, debug_levels[j])) {
						level = j;
						break;
					}
				}
				if (level == -1)
					goto needshelp;
			}
			debugLevel = (enDebugLevels) level;
			printf("Debug level set to: %s\n", debug_levels[debugLevel]);
		} else {
			int j;
needshelp:
			printf("Residual SVN Version\n");
			printf("--------------------\n");
			printf("Recognised options:\n");
			printf("\t-[no]zbuffer\t\tEnable/disable ZBuffers (Very slow on older cards)\n");
			printf("\t-[no]fps\t\tEnable/disable fps display in upper right corner\n");
			printf("\t-[no]fullscreen\t\tEnable/disable fullscreen mode at startup\n");
			printf("\t-[no]soft\t\tEnable/disable software renderer\n");
			printf("\t-debug=[level]\t\tSet debug to [level], valid levels:\n");
			for (j = 0;j <= DEBUG_ALL; j++)
				printf("\t\t%-8s (%d): %s.\n", debug_levels[j], j, debug_descriptions[j]);
			exit(-1);
		}
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return 1;

	atexit(quit);

	if (TINYGL_GLOBAL)
		g_driver = new DriverTinyGL(640, 480, 16, fullscreen);
	else
		g_driver = new DriverGL(640, 480, 24, fullscreen);
	g_timer = new DefaultTimerManager();
	g_driver->setTimerCallback();
	g_mixer = new Audio::Mixer();
	g_driver->setSoundCallback(Audio::Mixer::mixCallback, g_mixer);
	g_mixer->setReady(true);
	g_mixer->setVolumeForSoundType(Audio::Mixer::kPlainSoundType, 127);
	g_mixer->setVolumeForSoundType(Audio::Mixer::kSFXSoundType, Audio::Mixer::kMaxMixerVolume);
	g_mixer->setVolumeForSoundType(Audio::Mixer::kSpeechSoundType, Audio::Mixer::kMaxMixerVolume);
	g_mixer->setVolumeForSoundType(Audio::Mixer::kMusicSoundType, Audio::Mixer::kMaxMixerVolume);
	g_engine = new Engine();
	g_resourceloader = new ResourceLoader();
	g_localizer = new Localizer();
	g_smush = new Smush();
	g_imuse = new Imuse(20);

	Bitmap *splash_bm = NULL;
	if (!(g_flags & GF_DEMO))
		splash_bm = g_resourceloader->loadBitmap("splash.bm");
	if (splash_bm != NULL)
		splash_bm->ref();

	g_driver->clearScreen();

	if (!(g_flags & GF_DEMO))
		splash_bm->draw();

	g_driver->flipBuffer();

	if (splash_bm != NULL)
		splash_bm->deref();

	lua_iolibopen();
	lua_strlibopen();
	lua_mathlibopen();

	register_lua();
	g_lua_initialized = true;

	bundle_dofile("_system.lua");

	lua_pushnil();		// resumeSave
	lua_pushnil();		// bootParam
//	lua_pushnumber(0);		// bootParam
	lua_call("BOOT");

	g_engine->setMode(ENGINE_MODE_NORMAL);
	g_engine->mainLoop();

	quit();

	return 0;
}

void quit() {
	if (g_lua_initialized) {
		lua_removelibslists();
		lua_close();
		g_lua_initialized = false;
	}
	if (g_registry) {
		g_registry->save();
		delete g_registry;
		g_registry = NULL;
	}
	if (g_driver)
		g_driver->clearTimerCallback();
	delete g_smush;
	g_smush = NULL;
	delete g_imuse;
	g_imuse = NULL;
	delete g_localizer;
	g_localizer = NULL;
	delete g_engine;
	g_engine = NULL;
	delete g_resourceloader;
	g_resourceloader = NULL;
	delete g_timer;
	g_timer = NULL;
	delete g_mixer;
	g_mixer = NULL;
	delete g_driver;
	g_driver = NULL;

	SDL_Quit();
}

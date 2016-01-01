/* ResidualVM - A 3D game interpreter
 *
 * ResidualVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the AUTHORS
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef STARK_SERVICES_SERVICES_H
#define STARK_SERVICES_SERVICES_H

#include "common/singleton.h"
#include "common/scummsys.h"

namespace Common {
class RandomSource;
}

namespace Stark {

namespace Gfx {
class Driver;
}

class ArchiveLoader;
class DialogPlayer;
class Global;
class ResourceProvider;
class StaticProvider;
class Scene;
class GameInterface;
class UI;

/**
 * Public services available as a singleton
 */
class StarkServices : public Common::Singleton<StarkServices> {
public:
	StarkServices() {
		archiveLoader = nullptr;
		dialogPlayer = nullptr;
		gfx = nullptr;
		global = nullptr;
		resourceProvider = nullptr;
		randomSource = nullptr;
		scene = nullptr;
		staticProvider = nullptr;
		gameInterface = nullptr;
		ui = nullptr;
	}

	ArchiveLoader *archiveLoader;
	DialogPlayer *dialogPlayer;
	Gfx::Driver *gfx;
	Global *global;
	ResourceProvider *resourceProvider;
	Common::RandomSource *randomSource;
	Scene *scene;
	StaticProvider *staticProvider;
	GameInterface *gameInterface;
	UI *ui;
};

} // End of namespace Stark

#endif // STARK_SERVICES_SERVICES_H

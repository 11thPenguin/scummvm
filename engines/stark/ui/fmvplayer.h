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

#ifndef STARK_UI_FMV_PLAYER_H
#define STARK_UI_FMV_PLAYER_H

#include "engines/stark/ui/window.h"

#include "video/bink_decoder.h"

namespace Video {
class BinkDecoder;
}

namespace Stark {

namespace Gfx {
class Texture;
}

/**
 * FMV Player
 *
 * Handles the state of the currently running FMV.
 */
class FMVPlayer : public Window {
public:
	FMVPlayer(Gfx::Driver *gfx, Cursor *cursor);
	virtual ~FMVPlayer();
	void play(const Common::String &name);
	bool isPlaying();
	void stop();

protected:
	void onRender() override;
	void onMouseMove(const Common::Point &pos) override {};
	void onClick(const Common::Point &pos) override {};

private:
	Video::BinkDecoder *_decoder;
	Gfx::Texture *_texture;
};

} // End of namespace Stark

#endif // STARK_UI_FMV_PLAYER_H

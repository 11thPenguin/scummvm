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

#ifndef STARK_TOPMENU_H
#define STARK_TOPMENU_H

#include "common/scummsys.h"
#include "common/rect.h"

#include "engines/stark/ui/window.h"

namespace Stark {

class VisualImageXMG;
class Button;

class TopMenu : public Window {
public:
	TopMenu(Gfx::Driver *gfx, Cursor *cursor);
	~TopMenu();

	// Window API
	void onRender() override;
	void onMouseMove(const Common::Point &pos) override;
	void onClick(const Common::Point &pos) override;

private:
	Common::String getMouseHintAtPosition(Common::Point point);

	bool _widgetsVisible;

	Button *_inventoryButton;
	Button *_exitButton;
	Button *_diaryButton;
};

} // End of namespace Stark

#endif // STARK_TOPMENU_H

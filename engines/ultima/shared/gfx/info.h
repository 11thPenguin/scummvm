/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
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

#ifndef ULTIMA_SHARED_GFX_INFO_H
#define ULTIMA_SHARED_GFX_INFO_H

#include "ultima/shared/gfx/visual_item.h"
#include "common/str-array.h"

namespace Ultima {
namespace Shared {

/**
 * Textual info area, showing what commands area done, and any responses to them
 */
class Info : public Gfx::VisualItem {
	DECLARE_MESSAGE_MAP;
	bool InfoMsg(CInfoMsg &msg);
private:
	Common::StringArray _lines;
protected:
	/**
	 * Draws a prompt character
	 */
	virtual void drawPrompt(Gfx::VisualSurface &surf, const Point &pt) = 0;
public:
	CLASSDEF;
	Info(TreeItem *parent, const Rect &bounds) : Gfx::VisualItem("Info", bounds, parent) {}
	virtual ~Info() {}

	/**
	 * Draw the contents
	 */
	virtual void draw();
};

} // End of namespace Shared
} // End of namespace Ultima

#endif
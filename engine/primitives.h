/* Residual - Virtual machine to run LucasArts' 3D adventure games
 *
 * Residual is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the AUTHORS
 * file distributed with this source distribution.
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

#ifndef PRIMITIVESOBJECT_H
#define PRIMITIVESOBJECT_H

#include "common/sys.h"
#include "common/debug.h"

#include "engine/font.h"
#include "engine/color.h"
#include "engine/gfx_base.h"

#include <string>

class PrimitiveObject {
public:
	PrimitiveObject();
	~PrimitiveObject();

	void createRectangle(int x1, int x2, int y1, int y2, Color color, bool filled);
	void createBitmap(Bitmap *bitmap, int x, int y, bool transparent);
	void createLine(int x1, int x2, int y1, int y2, Color color);
	void createPolygon(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, Color color);
	int getX1() { return _x1; }
	int getY1() { return _y1; }
	int getX2() { return _x2; }
	int getY2() { return _y2; }
	int getX3() { return _x3; }
	int getY3() { return _y3; }
	int getX4() { return _x4; }
	int getY4() { return _y4; }
	void setY1(int coord) { _y1 = coord; }
	void setY2(int coord) { _y2 = coord; }
	void setY3(int coord) { _y3 = coord; }
	void setY4(int coord) { _y4 = coord; }
	int getType() { return _type; }
	void setColor(Color color) { _color = color; }
	Color getColor() { return _color; }
	bool isFilled() { return _filled; }
	void draw();
	bool isBitmap() { return _type == 2; }
	Bitmap *getBitmapHandle() { assert(_bitmap); return _bitmap; }

private:
	int _x1, _y1, _x2, _y2, _x3, _y3, _x4, _y4;
	Color _color;
	bool _filled;
	int _type;
	Bitmap *_bitmap;
};

#endif

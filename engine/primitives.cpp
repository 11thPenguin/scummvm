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

#include "engine/gfx_base.h"
#include "engine/primitives.h"

PrimitiveObject::PrimitiveObject() {
	_x1 = 0;
	_y1 = 0;
	_x2 = 0;
	_y2 = 0;
	_color._vals[0] = 0;
	_color._vals[1] = 0;
	_color._vals[2] = 0;
	_filled = false;
	_type = 0;
	_bitmap = NULL;
}

PrimitiveObject::~PrimitiveObject() {
	if (_type == 2)
		g_driver->destroyBitmap(_bitmap);
}

void PrimitiveObject::createRectangle(int x1, int x2, int y1, int y2, Color color, bool filled) {
	_x1 = x1;
	_y1 = y1;
	_x2 = x2;
	_y2 = y2;
	_color = color;
	_filled = filled;
	_type = 1;
}

void PrimitiveObject::createBitmap(Bitmap *bitmap, int x, int y, bool /*transparent*/) {
	_type = 2;
	_bitmap = bitmap;
	_bitmap->setX(x);
	_bitmap->setY(y);
	// transparent: what to do ?
	g_driver->createBitmap(_bitmap);
}

void PrimitiveObject::createLine(int x1, int x2, int y1, int y2, Color color) {
	_x1 = x1;
	_y1 = y1;
	_x2 = x2;
	_y2 = y2;
	_color = color;
	_type = 3;
}

void PrimitiveObject::createPolygon(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, Color color) {
	_x1 = x1;
	_y1 = y1;
	_x2 = x2;
	_y2 = y2;
	_x3 = x3;
	_y3 = y3;
	_x4 = x4;
	_y4 = y4;
	_color = color;
	_type = 4;
}

void PrimitiveObject::draw() {
	assert(_type);

	if (_type == 1)
		g_driver->drawRectangle(this);
	else if (_type == 2)
		g_driver->drawBitmap(_bitmap);
	else if (_type == 3)
		g_driver->drawLine(this);
	else if (_type == 4)
		g_driver->drawPolygon(this);
}

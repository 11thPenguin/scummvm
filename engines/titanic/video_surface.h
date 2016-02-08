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

#ifndef TITANIC_VIDEO_SURFACE_H
#define TITANIC_VIDEO_SURFACE_H

#include "common/scummsys.h"
#include "common/array.h"
#include "graphics/surface.h"
#include "titanic/font.h"

namespace Titanic {

class CScreenManager;

class CVideoSurface {
private:
	CScreenManager *_screenManager;
	Graphics::Surface *_surface;
public:
	CVideoSurface(CScreenManager *screenManager, Graphics::Surface *surface);

	void setSurface(CScreenManager *screenManager, Graphics::Surface *surface);
};

class OSVideoSurface : public CVideoSurface {
public:
	OSVideoSurface(CScreenManager *screenManager, Graphics::Surface *surface);
};

} // End of namespace Titanic

#endif /* TITANIC_VIDEO_SURFACE_H */

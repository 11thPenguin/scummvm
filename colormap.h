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

#ifndef COLORMAP_H
#define COLORMAP_H

#include "debug.h"
#include "resource.h"
#include <cstring>

class CMap : public Resource {
public:
	// Load a colormap from the given data.
	CMap(const char *filename, const char *data, int len) :
		Resource(filename) {
	if (len < 4 || std::memcmp(data, "CMP ", 4) != 0)
		error("Invalid magic loading colormap\n");
		std::memcpy(_colors, data + 64, sizeof(_colors));
	}

	// The color data, in RGB format
	char _colors[256 * 3];
};

#endif

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

#ifndef LIPSYNCH_H
#define LIPSYNCH_H

#include "common/sys.h"

#include "engine/resource.h"

#include <list>

class LipSynch : public Resource {
public:
	LipSynch(const char *filename, const char *data, int len);
	~LipSynch();

	struct LipEntry {
		uint16 frame;
		uint16 anim;
	};

	int getAnim(int pos);

private:
	LipEntry *_entries;
	int _numEntries;

	struct PhonemeAnim {
		uint16 phoneme;
		uint16 anim;
	};

	static const PhonemeAnim _animTable[];
	static const int _animTableSize;
};

#endif


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

#ifndef SAVEGAME_H
#define SAVEGAME_H

#ifdef __SYMBIAN32__
#include <zlib\zlib.h>
#else
#include <zlib.h>
#endif

#include "common/debug.h"

#include "engine/lua.h"

namespace Common {
	class SaveFileManager;
}

extern Common::SaveFileManager *g_saveFileMan;

class SaveGame {
public:
	SaveGame(const char *filename, bool saving);
	~SaveGame();

	uint32 beginSection(uint32 sectionTag);
	void endSection();
	void read(void *data, int size);
	void write(const void *data, int size);

protected:
	bool _saving;
	gzFile _fileHandle;
	uint32 _currentSection;
	uint32 _sectionSize;
	uint32 _sectionPtr;
	char *_sectionBuffer;
};

#endif

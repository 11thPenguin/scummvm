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

#include "common/debug.h"
#include "common/savefile.h"

#include "engine/savegame.h"

Common::SaveFileManager *g_saveFileMan;

#define SAVEGAME_HEADERTAG	'RSAV'
#define SAVEGAME_FOOTERTAG	'ESAV'
#define SAVEGAME_VERSION		1

// Constructor. Should create/open a saved game
SaveGame::SaveGame(const char *filename, bool saving) :
		_saving(saving), _currentSection(0) {
	if (_saving) {
		_outSaveFile = g_saveFileMan->openForSaving(filename);
		if (!_outSaveFile) {
			warning("SaveGame::SaveGame() Error creating savegame file");
			return;
		}
		_outSaveFile->writeUint32BE(SAVEGAME_HEADERTAG);
		_outSaveFile->writeUint32BE(SAVEGAME_VERSION);
	} else {
		uint32 tag, version;

		_inSaveFile = g_saveFileMan->openForLoading(filename);
		if (!_inSaveFile) {
			warning("SaveGame::SaveGame() Error opening savegame file");
			return;
		}
		tag = _inSaveFile->readUint32BE();
		assert(tag == SAVEGAME_HEADERTAG);
		version = _inSaveFile->readUint32BE();
		assert(version == SAVEGAME_VERSION);
	}
}

SaveGame::~SaveGame() {
	uint32 tag = SAVEGAME_FOOTERTAG;
	
	if (_saving) {
		_outSaveFile->writeUint32BE(SAVEGAME_FOOTERTAG);
		_outSaveFile->finalize();
		if (_outSaveFile->ioFailed())
			warning("SaveGame::~SaveGame()Can't write file. (Disk full?)");
		delete _outSaveFile;
	} else
		delete _inSaveFile;
}

uint32 SaveGame::beginSection(uint32 sectionTag) {
	if (_currentSection != 0)
		error("Tried to begin a new save game section with ending old section!");
	_currentSection = sectionTag;
	_sectionSize = 0;
	_sectionBuffer = (byte *)malloc(_sectionSize);
	if (!_saving) {
		uint32 tag = 0;
		
		while (tag != sectionTag) {
			free(_sectionBuffer);
			tag = _inSaveFile->readUint32BE();
			if (tag == SAVEGAME_FOOTERTAG)
				error("Unable to find requested section of savegame!");
			_sectionSize = _inSaveFile->readUint32BE();
			_sectionBuffer = (byte *)malloc(_sectionSize);
			_inSaveFile->read(_sectionBuffer, _sectionSize);
		}
	}
	_sectionPtr = 0;
	return _sectionSize;
}

void SaveGame::endSection() {
	if (_currentSection == 0)
		error("Tried to end a save game section without starting a section!");
	if (_saving) {
		_outSaveFile->writeUint32BE(_currentSection);
		_outSaveFile->writeUint32BE(_sectionSize);
		_outSaveFile->write(_sectionBuffer, _sectionSize);
	}
	free(_sectionBuffer);
	_sectionBuffer = NULL;
	_currentSection = 0;
}

void SaveGame::read(void *data, int size) {
	if (_saving)
		error("SaveGame::readBlock called when storing a savegame!");
	if (_currentSection == 0)
		error("Tried to read a block without starting a section!");
	memcpy(data, &_sectionBuffer[_sectionPtr], size);
	_sectionPtr += size;
}

void SaveGame::write(const void *data, int size) {
	if (!_saving)
		error("SaveGame::writeBlock called when restoring a savegame!");
	if (_currentSection == 0)
		error("Tried to write a block without starting a section!");
	_sectionBuffer = (byte *)realloc(_sectionBuffer, _sectionSize + size);
	if (!_sectionBuffer)
		error("Failed to allocate space for buffer!");
	memcpy(&_sectionBuffer[_sectionSize], data, size);
	_sectionSize += size;
}

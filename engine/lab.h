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

#ifndef LAB_H
#define LAB_H

#include <string>
#include <map>

#include "common/file.h"

class LuaFile;

class Block {
public:
	Block(const char *data, int len) : _data(data), _len(len) {}
	const char *data() const { return _data; }
	int len() const { return _len; }

	~Block() { delete[] _data; }

private:
	Block();
	const char *_data;
	int _len;
	bool _owner;
};

class Lab {
public:
	Lab() : _f(NULL) { }
	explicit Lab(const char *filename) : _f(NULL) { open(filename); }
	bool open(const char *filename);
	bool isOpen() const { return _f->isOpen(); }
	void close();
	bool fileExists(const char *filename) const;
	Block *getFileBlock(const char *filename) const;
	Common::File *openNewStreamFile(const char *filename) const;
	LuaFile *openNewStreamLua(const char *filename) const;
	int fileLength(const char *filename) const;

	~Lab() { close(); }

private:
	struct LabEntry {
		LabEntry(int the_offset, int the_len) :
		offset(the_offset), len(the_len) {}
		int offset, len;
	};

	Common::File *_f;
	typedef std::map<std::string, LabEntry> FileMapType;
	FileMapType _fileMap;
	std::string _labFileName;

	FileMapType::const_iterator findFilename(const char *filename) const;
};

#endif

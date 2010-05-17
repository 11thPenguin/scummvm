/* Residual - A 3D game interpreter
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

#include "engines/grim/resource.h"
#include "engines/grim/colormap.h"
#include "engines/grim/costume.h"
#include "engines/grim/keyframe.h"
#include "engines/grim/material.h"
#include "engines/grim/grim.h"
#include "engines/grim/lipsync.h"

namespace Grim {

ResourceLoader *g_resourceloader = NULL;

ResourceLoader::ResourceLoader() {
	int lab_counter = 0;
	_cacheDirty = false;
	_cacheMemorySize = 0;

	Lab *l;
	Common::ArchiveMemberList files;

	SearchMan.listMatchingMembers(files, "*.lab");

	if (files.empty())
		error("Cannot find game data - check configuration file");

	for (Common::ArchiveMemberList::const_iterator x = files.begin(); x != files.end(); ++x) {
		const Common::String filename = (*x)->getName();
		l = new Lab(filename.c_str());
		if (l->isOpen()) {
			if (filename.equalsIgnoreCase("data005.lab"))
				_labs.push_front(l);
			else
				_labs.push_back(l);
			lab_counter++;
		} else {
			delete l;
		}
	}

	files.clear();

	if (g_grim->getGameFlags() & GF_DEMO) {
		SearchMan.listMatchingMembers(files, "*.mus");

		for (Common::ArchiveMemberList::const_iterator x = files.begin(); x != files.end(); ++x) {
			const Common::String filename = (*x)->getName();
			l = new Lab(filename.c_str());
			if (l->isOpen()) {
				_labs.push_back(l);
				lab_counter++;
			} else {
				delete l;
			}
		}
	}
}

ResourceLoader::~ResourceLoader() {
	for (LabList::const_iterator i = _labs.begin(); i != _labs.end(); ++i)
		delete *i;
}

const Lab *ResourceLoader::getLab(const char *filename) const {
	for (LabList::const_iterator i = _labs.begin(); i != _labs.end(); ++i)
		if ((*i)->fileExists(filename))
			return *i;

	return NULL;
}

static int sortCallback(const void *entry1, const void *entry2) {
	return strcasecmp(((ResourceLoader::ResourceCache *)entry1)->fname, ((ResourceLoader::ResourceCache *)entry2)->fname);
}

Block *ResourceLoader::getFileFromCache(const char *filename) {
	ResourceLoader::ResourceCache *entry = getEntryFromCache(filename);
	if (entry)
		return entry->resPtr;
	else
		return NULL;
}

ResourceLoader::ResourceCache *ResourceLoader::getEntryFromCache(const char *filename) {
	if (_cache.empty())
		return NULL;
	
	if (_cacheDirty) {
		qsort(_cache.begin(), _cache.size(), sizeof(ResourceCache), sortCallback);
		_cacheDirty = false;
	}

	ResourceCache key;
	key.fname = (char *)filename;

	return (ResourceLoader::ResourceCache *)bsearch(&key, _cache.begin(), _cache.size(), sizeof(ResourceCache), sortCallback);
}

bool ResourceLoader::fileExists(const char *filename) const {
	return getLab(filename) != NULL;
}

Block *ResourceLoader::getFileBlock(const char *filename) const {
	const Lab *l = getLab(filename);
	if (!l)
		return NULL;
	else
		return l->getFileBlock(filename);
}

LuaFile *ResourceLoader::openNewStreamLuaFile(const char *filename) const {
	const Lab *l = getLab(filename);

	if (!l)
		return NULL;
	else
		return l->openNewStreamLua(filename);
}

Common::File *ResourceLoader::openNewStreamFile(const char *filename) const {
	const Lab *l = getLab(filename);

	if (!l)
		return NULL;
	else
		return l->openNewStreamFile(filename);
}

int ResourceLoader::fileLength(const char *filename) const {
	const Lab *l = getLab(filename);
	if (l)
		return l->fileLength(filename);
	else
		return 0;
}

void ResourceLoader::putIntoCache(Common::String fname, Block *res) {
	ResourceCache entry;
	entry.resPtr = res;
	entry.fname = new char[fname.size() + 1];
	strcpy(entry.fname, fname.c_str());
	_cacheMemorySize += res->len();
	_cache.push_back(entry);
	_cacheDirty = true;
}

Bitmap *ResourceLoader::loadBitmap(const char *filename) {
	Common::String fname = filename;
	fname.toLowercase();
	Block *b = getFileFromCache(fname.c_str());
	if (!b) {
		b = getFileBlock(fname.c_str());
		if (!b) {	// Grim sometimes asks for non-existant bitmaps (eg, ha_overhead)
			warning("Could not find bitmap %s", filename);
			return NULL;
		}
		putIntoCache(fname, b);
	}

	Bitmap *result = g_grim->registerBitmap(filename, b->data(), b->len());

	return result;
}

CMap *ResourceLoader::loadColormap(const char *filename) {
	Common::String fname = filename;
	fname.toLowercase();
	Block *b = getFileFromCache(fname.c_str());
	if (!b) {
		b = getFileBlock(fname.c_str());
		if (!b)
			error("Could not find colormap %s", filename);
		putIntoCache(fname, b);
	}

	CMap *result = new CMap(filename, b->data(), b->len());

	return result;
}

Costume *ResourceLoader::loadCostume(const char *filename, Costume *prevCost) {
	Common::String fname = filename;
	fname.toLowercase();
	Block *b = getFileFromCache(fname.c_str());
	if (!b) {
		b = getFileBlock(fname.c_str());
		if (!b)
			error("Could not find costume %s", filename);
		putIntoCache(fname, b);
	}
	Costume *result = new Costume(filename, b->data(), b->len(), prevCost);

	return result;
}

Font *ResourceLoader::loadFont(const char *filename) {
	Common::String fname = filename;
	fname.toLowercase();
	Block *b = getFileFromCache(fname.c_str());
	if (!b) {
		b = getFileBlock(fname.c_str());
		if (!b)
			error("Could not find font file %s", filename);
		putIntoCache(fname, b);
	}

	Font *result = new Font(filename, b->data(), b->len());

	return result;
}

KeyframeAnim *ResourceLoader::loadKeyframe(const char *filename) {
	Common::String fname = filename;
	fname.toLowercase();
	Block *b = getFileFromCache(fname.c_str());
	if (!b) {
		b = getFileBlock(fname.c_str());
		if (!b)
			error("Could not find keyframe file %s", filename);
		putIntoCache(fname, b);
	}

	KeyframeAnim *result = new KeyframeAnim(filename, b->data(), b->len());

	return result;
}

LipSync *ResourceLoader::loadLipSync(const char *filename) {
	Common::String fname = filename;
	fname.toLowercase();
	LipSync *result;
	Block *b = getFileFromCache(fname.c_str());
	if (!b) {
		b = getFileBlock(fname.c_str());
		if (!b)
			return NULL;
	}

	result = new LipSync(filename, b->data(), b->len());

	// Some lipsync files have no data
	if (result->isValid()) {
		putIntoCache(fname, b);
	} else {
		delete result;
		delete b;
		result = NULL;
	}

	return result;
}

Material *ResourceLoader::loadMaterial(const char *filename, const CMap *c) {
	Common::String fname = Common::String(filename);
	fname.toLowercase();
	Block *b = getFileFromCache(fname.c_str());
	if (!b) {
		b = getFileBlock(fname.c_str());
		if (!b)
			error("Could not find material %s", filename);
		putIntoCache(fname, b);
	}

	Material *result = new Material(fname.c_str(), b->data(), b->len(), c);

	return result;
}

Model *ResourceLoader::loadModel(const char *filename, const CMap *c) {
	Common::String fname = filename;
	fname.toLowercase();
	Block *b = getFileFromCache(fname.c_str());
	if (!b) {
		b = getFileBlock(fname.c_str());
		if (!b)
			error("Could not find model %s", filename);
		putIntoCache(fname, b);
	}

	Model *result = new Model(filename, b->data(), b->len(), c);

	return result;
}

void ResourceLoader::uncache(const char *filename) {
	Common::String fname = filename;
	fname.toLowercase();

	if (_cacheDirty) {
		qsort(_cache.begin(), _cache.size(), sizeof(ResourceCache), sortCallback);
		_cacheDirty = false;
	}

	for (unsigned int i = 0; i < _cache.size(); i++) {
		if (fname.compareTo(_cache[i].fname) == 0) {
			delete[] _cache[i].fname;
			_cacheMemorySize -= _cache[i].resPtr->len();
			delete _cache[i].resPtr;
			_cache.remove_at(i);
			_cacheDirty = true;
		}
	}
}

} // end of namespace Grim

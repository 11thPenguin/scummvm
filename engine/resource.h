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

#ifndef RESOURCE_H
#define RESOURCE_H

#include "common/archive.h"

#include "engine/lab.h"

#include <list>
#include <string>
#include <map>

class Bitmap;
class CMap;
class Costume;
class Font;
class KeyframeAnim;
class Material;
class Model;
class LipSync;

class Resource {
public:
	Resource(const char *filename) :
		_fname(filename), _ref(0), _luaRef(false) { }
	Resource(const Resource &r) : _fname(r._fname), _ref(0), _luaRef(false) {}
	virtual ~Resource() { }
	void ref() { _ref++; }
	void deref();
	const char *filename() const { return _fname.c_str(); }

	void luaRef() { if (!_luaRef) { ref(); _luaRef = true; } }
	void luaGc() { if (_luaRef) { _luaRef = false; deref(); } }

private:
	std::string _fname;
	int _ref;
	bool _luaRef;
};

template <class T>
class ResPtr {
public:
	ResPtr() { _ptr = NULL; }
	ResPtr(const ResPtr &p) { _ptr = p._ptr; if (_ptr) _ptr->ref(); }
	ResPtr(T* ptr) { _ptr = ptr; if (_ptr) _ptr->ref(); }
	operator T*() { return _ptr; }
	operator const T*() const { return _ptr; }
	T& operator *() { return *_ptr; }
	const T& operator *() const { return *_ptr; }
	T* operator ->() { return _ptr; }
	const T* operator ->() const { return _ptr; }
	ResPtr& operator =(T* ptr) {
		if (_ptr == ptr) return *this;
		if (_ptr) _ptr->deref();
		_ptr = ptr;
		if (_ptr) _ptr->ref();
		return *this;
	}
	ResPtr& operator =(const ResPtr& p) {
	if (this == &p || _ptr == p._ptr) return *this;
		if (_ptr) _ptr->deref();
		_ptr = p._ptr;
		if (_ptr) _ptr->ref();
		return *this;
	}
	~ResPtr() { if (_ptr) _ptr->deref(); }

private:
	T* _ptr;
};

class ResourceLoader {
public:
	bool fileExists(const char *filename) const;
	Block *getFileBlock(const char *filename) const;
	Common::File *openNewStreamFile(const char *filename) const;
	LuaFile *openNewStreamLua(const char *filename) const;
	int fileLength(const char *filename) const;

	bool exportResource(const char *filename);
	Bitmap *loadBitmap(const char *fname);
	CMap *loadColormap(const char *fname);
	Costume *loadCostume(const char *fname, Costume *prevCost);
	Font *loadFont(const char *fname);
	KeyframeAnim *loadKeyframe(const char *fname);
	Material *loadMaterial(const char *fname, const CMap &c);
	Model *loadModel(const char *fname, const CMap &c);
	LipSync *loadLipSync(const char *fname);
	void uncache(const char *fname);

	ResourceLoader();
	ResourceLoader(const ResourceLoader &);
	~ResourceLoader();
	const Lab *findFile(const char *filename) const;
private:

	typedef std::list<Lab *> LabList;
	LabList _labs;

	typedef std::map<std::string, Resource *> CacheType;
	CacheType _cache;

	Common::SearchSet _files;

	// Shut up pointless g++ warning
	friend class dummy;
};

extern ResourceLoader *g_resourceloader;

inline void Resource::deref() {
	if (--_ref == 0) {
		g_resourceloader->uncache(_fname.c_str());
		delete this;
	}
}

#endif

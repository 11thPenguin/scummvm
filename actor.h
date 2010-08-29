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

#ifndef STARK_ACTOR_H
#define STARK_ACTOR_H

#include "engines/stark/sceneelement.h"

#include "graphics/vector3d.h"
#include "common/str.h"

namespace Common {
	class ReadStream;
	class Archive;
}

namespace Stark {

class VertNode {
public:
	Graphics::Vector3d _pos1, _pos2;
	Graphics::Vector3d _normal;
	float _texS, _texT;
	uint32 _bone1, _bone2;
	float _boneWeight;
};

class TriNode {
public:
	uint32 _vert1, _vert2, _vert3;
};

class FaceNode {
public:
	FaceNode() { }

	~FaceNode() { 
		for (Common::Array<VertNode *>::iterator it = _verts.begin(); it != _verts.end(); ++it)
			delete *it;

		for (Common::Array<TriNode *>::iterator it = _tris.begin(); it != _tris.end(); ++it)
			delete *it;
	}
	
	uint32 _idx;
	Common::Array<VertNode *> _verts;
	Common::Array<TriNode *> _tris;
};


class MeshNode {
public:
	MeshNode() { }
	~MeshNode() { 
		Common::Array<FaceNode *>::iterator it = _faces.begin();
		while (it != _faces.end()) {
			delete *it;
			++it;
		}
	
	}
	Common::String _name;
	Common::Array<FaceNode *> _faces;
};


class MaterialNode {
public:
	Common::String _name;
	uint32 _unknown1;
	Common::String _texName;
	float _r, _g, _b;
};

class UnknownNode {
public:
	float _u1, _u2, _u3, _u4;
};

class BoneNode {
public:
	BoneNode() { }
	~BoneNode() { }
	Common::String _name;
	float _u1;
	Common::Array<uint32> _children;
};






class Actor {
public:
	Actor();
	~Actor();

	bool readFromStream(Common::ReadStream *stream);

private:
	uint32 _id;

	Common::Array<MaterialNode *> _materials;
	Common::Array<MeshNode *> _meshes;
	Common::Array<BoneNode *> _bones;
	

};

class AnimKey {
public:
	uint32 _time;
	Graphics::Vector3d _rot;
	float _rotW;
	Graphics::Vector3d _pos;
};

class AnimNode {
public:
	~AnimNode() {
		for (Common::Array<AnimKey *>::iterator it = _keys.begin(); it != _keys.end(); ++it)
			delete *it;
	}

	uint32 _bone;
	Common::Array<AnimKey *> _keys;
};

class Animation {
public:
	~Animation() {
		for (Common::Array<AnimNode *>::iterator it = _anims.begin(); it != _anims.end(); ++it)
			delete *it;
	}
	bool readFromStream(Common::ReadStream *stream);

private:
	uint32 _id, _ver, _u1, _u2, _time;

	Common::Array<AnimNode *> _anims;
};

class SceneElementActor : public SceneElement {
private:
	SceneElementActor();

public:
	~SceneElementActor();

	static SceneElementActor *load(const Common::Archive *archive, const Common::String &name);
	bool setAnim(const Common::Archive *archive, const Common::String &name);

	void render(GfxDriver *gfx);

private:
	Actor *_actor;
	Animation *_anim;
};

} // end of namespace Stark

#endif

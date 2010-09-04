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

#include "engines/stark/skeleton.h"
#include "engines/stark/skeleton_anim.h"
#include "engines/stark/gfx/coordinate.h"
#include "engines/stark/stark.h"

#include "common/stream.h"

namespace Stark {

Skeleton::Skeleton() : _anim(NULL){
	
}

Skeleton::~Skeleton() {
	for (Common::Array<BoneNode *>::iterator it = _bones.begin(); it != _bones.end(); ++it)
		delete *it;
}

bool Skeleton::readFromStream(Common::ReadStream *stream) {
	uint32 numBones = stream->readUint32LE();
	for (uint32 i = 0; i < numBones; ++i) {
		BoneNode *node = new BoneNode();

		uint32 len = stream->readUint32LE();
		char *ptr = new char[len + 4];
		stream->read(ptr, len + 4);
		node->_name = Common::String(ptr, len);
		node->_u1 = get_float(ptr + len);
		delete[] ptr;

		len = stream->readUint32LE();
		for (uint32 j = 0; j < len; ++j)
			node->_children.push_back(stream->readUint32LE());

		node->_idx = _bones.size();
		_bones.push_back(node);
	}

	for (uint32 i = 0; i < numBones; ++i) {
		BoneNode *node = _bones[i];
		for (int j = 0; j < node->_children.size(); ++j) {
			_bones[node->_children[j]]->_parent = i;
		}
	}

	return true;
}

bool Skeleton::setAnim(Common::ReadStream *stream) {
	SkeletonAnim *_oldAnim = _anim;
	_anim = new SkeletonAnim();
	if (_anim->createFromStream(stream)) {
		animate();
		delete _oldAnim;
	} else {
		_anim = _oldAnim;
		return false;
	}
	return true;
}

void Skeleton::setNode(uint32 time, BoneNode *bone, const Coordinate &parentCoord) {
	Coordinate animCoord = _anim->getCoordForBone(time, bone->_idx);
	animCoord.rotate(parentCoord);
	bone->_animPos = parentCoord + animCoord;

	for (int i = 0; i < bone->_children.size(); ++i)
	{
		setNode(time, _bones[bone->_children[i]], bone->_animPos);
	}
}

bool Skeleton::animate(uint32 time) {
	// Start at root bone
	// For each child
	//  - Set childs animation coordinate
	//  - Process that childs children
	
	setNode(time, _bones[0], Coordinate());
	/*
	Graphics::Vector3d b1 = (*face)->_verts[vertIdx]->_pos1;
	idx = (*face)->_verts[vertIdx]->_bone1;
	BoneNode *bone;
	do {
		bone = bones[idx];
		key1 = anims[idx]->_keys[0];
		Graphics::Vector3d tmp = key1->_pos;
		float tmpRot[] = _Q_MAT(-key1->_rotW, key1->_rot.x(), key1->_rot.y(), key1->_rot.z()); // - is LH to RH
		_VECT_ROTATE(b1, tmpRot);
		b1 += tmp;
		idx = bone->_parent;

	} while (idx != -1);
*/
					
	return true;
}

} // end of namespace Stark

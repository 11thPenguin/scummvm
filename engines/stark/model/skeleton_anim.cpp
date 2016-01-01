/* ResidualVM - A 3D game interpreter
 *
 * ResidualVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the AUTHORS
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

#include "engines/stark/model/skeleton_anim.h"

#include "engines/stark/services/archiveloader.h"
#include "engines/stark/model/skeleton.h"

namespace Stark {


SkeletonAnim::SkeletonAnim() {
}

SkeletonAnim::~SkeletonAnim() {
	for (Common::Array<AnimNode *>::iterator it = _anims.begin(); it != _anims.end(); ++it)
		delete *it;
}

void SkeletonAnim::createFromStream(ArchiveReadStream *stream) {
	_id = stream->readUint32LE();
	_ver = stream->readUint32LE();
	if (_ver == 3) {
		_u1 = 0;
		_time = stream->readUint32LE();
		_u2 = stream->readUint32LE();
	} else {
		_u1 = stream->readUint32LE();
		_u2 = stream->readUint32LE();
		_time = stream->readUint32LE();
	}
	if (_u2 != 0xdeadbabe) {
		error("Wrong magic while reading animation");
	}

	uint32 num = stream->readUint32LE();
	_anims.resize(num);
	for (uint32 i = 0; i < num; ++i) {
		AnimNode *node = new AnimNode();
		node->_bone = stream->readUint32LE();
		uint32 numKeys = stream->readUint32LE();

		for (uint32 j = 0; j < numKeys; ++j) {
			AnimKey *key = new AnimKey();
			key->_time = stream->readUint32LE();
			key->_rot = stream->readQuaternion();
			key->_pos = stream->readVector3();
			node->_keys.push_back(key);
		}

		_anims[node->_bone] = node;
	}
}

void SkeletonAnim::getCoordForBone(uint32 time, int boneIdx, Math::Vector3d &pos, Math::Quaternion &rot) {
	for (Common::Array<AnimKey *>::iterator it = _anims[boneIdx]->_keys.begin(); it < _anims[boneIdx]->_keys.end(); ++it) {
		if ((*it)->_time == time) {
			AnimKey *key = *it;
			pos = key->_pos;
			rot = key->_rot;
			break;

		} else if ((*it)->_time > time) {
			// Between two key frames, interpolate
			AnimKey *a = *it;
			--it;
			AnimKey *b = *it;

			float t = (float)(time - b->_time) / (float)(a->_time - b->_time);

			pos = b->_pos + (a->_pos - b->_pos) * t;
			rot = b->_rot.slerpQuat(a->_rot, t);

			break;
		}
	}
}

} // End of namespace Stark

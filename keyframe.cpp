// Residual - Virtual machine to run LucasArts' 3D adventure games
// Copyright (C) 2003-2005 The ScummVM-Residual Team (www.scummvm.org)
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

#include "stdafx.h"
#include "keyframe.h"
#include "debug.h"
#include "bits.h"
#include "textsplit.h"
#include <cstring>

KeyframeAnim::KeyframeAnim(const char *filename, const char *data, int len) :
		Resource(filename) {
	if (len >= 4 && std::memcmp(data, "FYEK", 4) == 0)
		loadBinary(data, len);
	else {
		TextSplitter ts(data, len);
		loadText(ts);
	}
}

void KeyframeAnim::loadBinary(const char *data, int len) {
	_flags = READ_LE_UINT32(data + 40);
	_type = READ_LE_UINT32(data + 48);
	_fps = get_float(data + 52);
	_numFrames = READ_LE_UINT32(data + 56);
	_numJoints = READ_LE_UINT32(data + 60);
	_numMarkers = READ_LE_UINT32(data + 68);
	_markers = new Marker[_numMarkers];
	for (int i = 0; i < _numMarkers; i++) {
		_markers[i].frame = get_float(data + 72 + 4 * i);
		_markers[i].val = READ_LE_UINT32(data + 104 + 4 * i);
	}

	_nodes = new KeyframeNode *[_numJoints];
	for (int i = 0; i < _numJoints; i++)
		_nodes[i] = NULL;
	const char *dataEnd = data + len;
	data += 180;
	while (data < dataEnd) {
		int nodeNum = READ_LE_UINT32(data + 32);
		_nodes[nodeNum] = new KeyframeNode;
		_nodes[nodeNum]->loadBinary(data);
	}
}

void KeyframeAnim::loadText(TextSplitter &ts) {
	ts.expectString("section: header");
	ts.scanString("flags %i", 1, &_flags);
	ts.scanString("type %i", 1, &_type);
	ts.scanString("frames %d", 1, &_numFrames);
	ts.scanString("fps %f", 1, &_fps);
	ts.scanString("joints %d", 1, &_numJoints);

	if (std::strcmp(ts.currentLine(), "section: markers") == 0) {
		ts.nextLine();
		ts.scanString("markers %d", 1, &_numMarkers);
		_markers = new Marker[_numMarkers];
		for (int i = 0; i < _numMarkers; i++)
			ts.scanString("%f %d", 2, &_markers[i].frame, &_markers[i].val);
	} else {
		_numMarkers = 0;
		_markers = NULL;
	}

	ts.expectString("section: keyframe nodes");
	int numNodes;
	ts.scanString("nodes %d", 1, &numNodes);
	_nodes = new KeyframeNode *[_numJoints];
	for (int i = 0; i < _numJoints; i++)
		_nodes[i] = NULL;
	for (int i = 0; i < numNodes; i++) {
		int which;
		ts.scanString("node %d", 1, &which);
		_nodes[which] = new KeyframeNode;
		_nodes[which]->loadText(ts);
	}
}

KeyframeAnim::~KeyframeAnim() {
	for (int i = 0; i < _numJoints; i++)
		delete _nodes[i];
	delete[] _markers;
}

void KeyframeAnim::animate(Model::HierNode *nodes, float time, int priority1, int priority2) const {
	float frame = time * _fps;

	if (frame > _numFrames)
		frame = _numFrames;

	for (int i = 0; i < _numJoints; i++)
		if (_nodes[i] != NULL)

	_nodes[i]->animate(nodes[i], frame, ((_type & nodes[i]._type) != 0 ? priority2 : priority1));
}

void KeyframeAnim::KeyframeEntry::loadBinary(const char *&data) {
	_frame = get_float(data);
	_flags = READ_LE_UINT32(data + 4);
	_pos = get_vector3d(data + 8);
	_pitch = get_float(data + 20);
	_yaw = get_float(data + 24);
	_roll = get_float(data + 28);
	_dpos = get_vector3d(data + 32);
	_dpitch = get_float(data + 44);
	_dyaw = get_float(data + 48);
	_droll = get_float(data + 52);
	data += 56;
}

void KeyframeAnim::KeyframeNode::loadBinary(const char *&data) {
	std::memcpy(_meshName, data, 32);
	_numEntries = READ_LE_UINT32(data + 36);
	data += 44;
	_entries = new KeyframeEntry[_numEntries];
	for (int i = 0; i < _numEntries; i++)
		_entries[i].loadBinary(data);
	}

void KeyframeAnim::KeyframeNode::loadText(TextSplitter &ts) {
	ts.scanString("mesh name %s", 1, _meshName);
	ts.scanString("entries %d", 1, &_numEntries);
	_entries = new KeyframeEntry[_numEntries];
	for (int i = 0; i < _numEntries; i++) {
		int which, flags;
		float frame, x, y, z, p, yaw, r, dx, dy, dz, dp, dyaw, dr;
		ts.scanString(" %d: %f %i %f %f %f %f %f %f", 9, &which, &frame, &flags, &x, &y, &z, &p, &yaw, &r);
		ts.scanString(" %f %f %f %f %f %f", 6, &dx, &dy, &dz, &dp, &dyaw, &dr);
		_entries[which]._frame = frame;
		_entries[which]._flags = flags;
		_entries[which]._pos = Vector3d(x, y, z);
		_entries[which]._dpos = Vector3d(dx, dy, dz);
		_entries[which]._pitch = p;
		_entries[which]._yaw = yaw;
		_entries[which]._roll = r;
		_entries[which]._dpitch = dp;
		_entries[which]._dyaw = dyaw;
		_entries[which]._droll = dr;
	}
}

KeyframeAnim::KeyframeNode::~KeyframeNode() {
	delete[] _entries;
}

void KeyframeAnim::KeyframeNode::animate(Model::HierNode &node,
	float frame, int priority) const {
	if (_numEntries == 0)
		return;
	if (priority < node._priority)
		return;

	// Do a binary search for the nearest previous frame
	// Loop invariant: entries_[low].frame_ <= frame < entries_[high].frame_
	int low = 0, high = _numEntries;
	while (high > low + 1) {
		int mid = (low + high) / 2;
		if (_entries[mid]._frame <= frame)
			low = mid;
		else
			high = mid;
	}

	float dt = frame - _entries[low]._frame;
	Vector3d pos = _entries[low]._pos + dt * _entries[low]._dpos;
	float pitch = _entries[low]._pitch + dt * _entries[low]._dpitch;
	float yaw = _entries[low]._yaw + dt * _entries[low]._dyaw;
	float roll = _entries[low]._roll + dt * _entries[low]._droll;
	if (pitch > 180)
		pitch -= 360;
	if (yaw > 180)
		yaw -= 360;
	if (roll > 180)
		roll -= 360;

	if (priority > node._priority) {
		node._priority = priority;
		node._totalWeight = 1;
		node._animPos = pos;
		node._animPitch = pitch;
		node._animYaw = yaw;
		node._animRoll = roll;
	} else { // priority == node._priority
		node._totalWeight++;
		node._animPos += pos;
		node._animPitch += pitch;
		node._animYaw += yaw;
		node._animRoll += roll;
	}

	//  node
}

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

#include "common/debug.h"

#include "engines/stark/formats/xrc.h"
#include "engines/stark/gfx/driver.h"
#include "engines/stark/resources/anim.h"
#include "engines/stark/resources/bonesmesh.h"
#include "engines/stark/resources/direction.h"
#include "engines/stark/resources/image.h"
#include "engines/stark/resources/item.h"
#include "engines/stark/resources/textureset.h"
#include "engines/stark/services/archiveloader.h"
#include "engines/stark/services/global.h"
#include "engines/stark/services/services.h"
#include "engines/stark/model/skeleton_anim.h"
#include "engines/stark/visual/actor.h"
#include "engines/stark/visual/smacker.h"

namespace Stark {
namespace Resources {

Object *Anim::construct(Object *parent, byte subType, uint16 index, const Common::String &name) {
	switch (subType) {
	case kAnimImages:
		return new AnimImages(parent, subType, index, name);
	case kAnimSub2:
		return new AnimSub2(parent, subType, index, name);
	case kAnimVideo:
		return new AnimVideo(parent, subType, index, name);
	case kAnimSkeleton:
		return new AnimSkeleton(parent, subType, index, name);
	default:
		error("Unknown anim subtype %d", subType);
	}
}

Anim::~Anim() {
}

Anim::Anim(Object *parent, byte subType, uint16 index, const Common::String &name) :
				Object(parent, subType, index, name),
				_usage(0),
				_currentFrame(0),
				_numFrames(0),
				_refCount(0) {
	_type = TYPE;
}

void Anim::readData(Formats::XRCReadStream *stream) {
	_usage = stream->readUint32LE();
	_numFrames = stream->readUint32LE();
}

void Anim::selectFrame(uint32 frameIndex) {
}

Visual *Anim::getVisual() {
	return nullptr;
}

uint32 Anim::getUsage() const {
	return _usage;
}

void Anim::applyToItem(Item *item) {
	_refCount++;
}
void Anim::removeFromItem(Item *item) {
	_refCount--;
}

bool Anim::isInUse() {
	return _refCount > 0;
}

int Anim::getPointHotspotIndex(const Common::Point &point) const {
	// Most anim types only have one hotspot
	return 0;
}

void Anim::printData() {
	debug("usage: %d", _usage);
	debug("numFrames: %d", _numFrames);
}

AnimImages::~AnimImages() {
}

AnimImages::AnimImages(Object *parent, byte subType, uint16 index, const Common::String &name) :
				Anim(parent, subType, index, name),
				_field_3C(0),
				_currentDirection(0),
				_currentFrameImage(nullptr) {
}

void AnimImages::readData(Formats::XRCReadStream *stream) {
	Anim::readData(stream);

	_field_3C = stream->readFloat();
}

void AnimImages::onAllLoaded() {
	Anim::onAllLoaded();

	_directions = listChildren<Direction>();
}

void AnimImages::selectFrame(uint32 frameIndex) {
	if (frameIndex > _numFrames) {
		error("Error setting frame %d for anim '%s'", frameIndex, getName().c_str());
	}

	_currentFrame = frameIndex;
}

Visual *AnimImages::getVisual() {
	Direction *direction = _directions[_currentDirection];
	_currentFrameImage = direction->findChildWithIndex<Image>(_currentFrame);
	return _currentFrameImage->getVisual();
}

void AnimImages::printData() {
	Anim::printData();

	debug("field_3C: %f", _field_3C);
}

int AnimImages::getPointHotspotIndex(const Common::Point &point) const {
	if (_currentFrameImage) {
		return _currentFrameImage->indexForPoint(point);
	}
	return -1;
}

AnimSub2::~AnimSub2() {
}

AnimSub2::AnimSub2(Object *parent, byte subType, uint16 index, const Common::String &name) :
				Anim(parent, subType, index, name) {
}

AnimVideo::~AnimVideo() {
	delete _smacker;
}

AnimVideo::AnimVideo(Object *parent, byte subType, uint16 index, const Common::String &name) :
				Anim(parent, subType, index, name),
				_width(0),
				_height(0),
				_smacker(nullptr),
				_field_4C(-1),
				_field_50(0),
				_field_7C(0) {
}

void AnimVideo::readData(Formats::XRCReadStream *stream) {
	Anim::readData(stream);
	_smackerFile = stream->readString();
	_width = stream->readUint32LE();
	_height = stream->readUint32LE();

	_positions.clear();
	_sizes.clear();

	uint32 size = stream->readUint32LE();
	for (uint i = 0; i < size; i++) {
		_positions.push_back(stream->readPoint());
		_sizes.push_back(stream->readRect());
	}

	_field_7C = stream->readUint32LE();
	_field_4C = stream->readSint32LE();

	if (stream->isDataLeft()) {
		_field_50 = stream->readUint32LE();
	}

	_archiveName = stream->getArchiveName();
}

void AnimVideo::onAllLoaded() {
	if (!_smacker) {
		Common::SeekableReadStream *stream = StarkArchiveLoader->getExternalFile(_smackerFile, _archiveName);

		_smacker = new VisualSmacker(StarkGfx);
		_smacker->load(stream);
		updateSmackerPosition();
	}
}

void AnimVideo::onGameLoop() {
	if (!isInUse()) {
		return; // Animation not in use, no need to update the movie
	}

	if (!_smacker) {
		return;
	}

	_smacker->update();
	updateSmackerPosition();
}

Visual *AnimVideo::getVisual() {
	return _smacker;
}

void AnimVideo::updateSmackerPosition() {
	int frame = _smacker->getFrameNumber();
	if (frame != -1 && frame < (int) _positions.size()) {
		_smacker->setPosition(_positions[frame]);
	}
}

void AnimVideo::printData() {
	Anim::printData();

	debug("smackerFile: %s", _smackerFile.c_str());
	debug("size: x %d, y %d", _width, _height);

	Common::String description;
	for (uint32 i = 0; i < _positions.size(); i++) {
		description += Common::String::format("(x %d, y %d) ", _positions[i].x, _positions[i].y);
	}
	debug("positions: %s", description.c_str());

	description.clear();
	for (uint32 i = 0; i < _sizes.size(); i++) {
		description += Common::String::format("(l %d, t %d, r %d, b %d) ",
				_sizes[i].left, _sizes[i].top, _sizes[i].right, _sizes[i].bottom);
	}
	debug("sizes: %s", description.c_str());

	debug("field_4C: %d", _field_4C);
	debug("field_50: %d", _field_50);
	debug("field_7C: %d", _field_7C);
}

AnimSkeleton::~AnimSkeleton() {
	delete _visual;
	delete _seletonAnim;
}

AnimSkeleton::AnimSkeleton(Object *parent, byte subType, uint16 index, const Common::String &name) :
				Anim(parent, subType, index, name),
				_castsShadow(true),
				_field_48(0),
				_movementSpeed(100),
				_field_6C(1),
				_seletonAnim(nullptr),
				_currentTime(0),
				_totalTime(0) {
	_visual = StarkGfx->createActorRenderer();
}

void AnimSkeleton::applyToItem(Item *item) {
	Anim::applyToItem(item);

	ModelItem *modelItem = Object::cast<ModelItem>(item);

	BonesMesh *mesh = modelItem->findBonesMesh();
	TextureSet *texture = modelItem->findTextureSet(TextureSet::kTextureNormal);

	_visual->setModel(mesh->getModel());
	_visual->setTexture(texture->getTexture());
	_visual->setAnim(_seletonAnim);
}

void AnimSkeleton::removeFromItem(Item *item) {
	Anim::removeFromItem(item);
}

Visual *AnimSkeleton::getVisual() {
	return _visual;
}

void AnimSkeleton::readData(Formats::XRCReadStream *stream) {
	Anim::readData(stream);

	_animFilename = stream->readString();
	stream->readString(); // Skipped in the original
	stream->readString(); // Skipped in the original
	stream->readString(); // Skipped in the original

	_field_48 = stream->readUint32LE();
	_movementSpeed = stream->readUint32LE();

	  if (_movementSpeed < 1) {
		_movementSpeed = 100;
	}

	if (stream->isDataLeft()) {
		_castsShadow = stream->readBool();
	} else {
		_castsShadow = true;
	}

	if (stream->isDataLeft()) {
		_field_6C = stream->readUint32LE();
	} else {
		_field_6C = 1;
	}

	_archiveName = stream->getArchiveName();
}

void AnimSkeleton::onPostRead() {
	ArchiveReadStream *stream = StarkArchiveLoader->getFile(_animFilename, _archiveName);

	_seletonAnim = new SkeletonAnim();
	_seletonAnim->createFromStream(stream);

	delete stream;
}

void AnimSkeleton::onAllLoaded() {
	Anim::onAllLoaded();

	_totalTime = _seletonAnim->getLength();
	_currentTime = 0;
}

void AnimSkeleton::onGameLoop() {
	Anim::onGameLoop();

	if (isInUse() && _totalTime) {
		_currentTime = (_currentTime + StarkGlobal->getMillisecondsPerGameloop()) % _totalTime;
		_visual->setTime(_currentTime);
	}
}

uint32 AnimSkeleton::getMovementSpeed() const {
	return _movementSpeed;
}

void AnimSkeleton::printData() {
	Anim::printData();

	debug("filename: %s", _animFilename.c_str());
	debug("castsShadow: %d", _castsShadow);
	debug("field_48: %d", _field_48);
	debug("movementSpeed: %d", _movementSpeed);
	debug("field_6C: %d", _field_6C);
}

} // End of namespace Resources
} // End of namespace Stark

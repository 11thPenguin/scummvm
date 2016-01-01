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

#include "engines/stark/resources/image.h"

#include "common/debug.h"

#include "engines/stark/formats/xrc.h"
#include "engines/stark/services/archiveloader.h"
#include "engines/stark/services/services.h"
#include "engines/stark/visual/image.h"

#include "math/line2d.h"
#include "math/vector2d.h"

namespace Stark {
namespace Resources {

Object *Image::construct(Object *parent, byte subType, uint16 index, const Common::String &name) {
	switch (subType) {
	case kImageSub2:
	case kImageSub3:
		return new ImageSub23(parent, subType, index, name);
	case kImageSub4:
		return new UnimplementedResource(parent, TYPE, subType, index, name);
	default:
		error("Unknown anim subtype %d", subType);
	}
}

Image::~Image() {
	delete _visual;
}

Image::Image(Object *parent, byte subType, uint16 index, const Common::String &name) :
				Object(parent, subType, index, name),
				_transparent(false),
				_transparency(0),
				_field_44_ADF(0),
				_field_48_ADF(30),
				_visual(nullptr) {
	_type = TYPE;
}

void Image::readData(Formats::XRCReadStream *stream) {
	_filename = stream->readString();
	_hotspot = stream->readPoint();
	_transparent = stream->readBool();
	_transparency = stream->readUint32LE();

	uint32 polygonCount = stream->readUint32LE();
	for (uint32 i = 0; i < polygonCount; i++) {
		Polygon polygon;

		uint32 pointCount = stream->readUint32LE();
		for (uint32 j = 0; j < pointCount; j++) {
			polygon.push_back(stream->readPoint());
		}

		_polygons.push_back(polygon);
	}

	_archiveName = stream->getArchiveName();
}

Visual *Image::getVisual() {
	return nullptr;
}

void Image::printData() {
	debug("filename: %s", _filename.c_str());
	debug("hotspot: x %d, y %d", _hotspot.x, _hotspot.y);
	debug("transparent: %d", _transparent);
	debug("transparency: %d", _transparency);
	debug("field_44: %d", _field_44_ADF);
	debug("field_48: %d", _field_48_ADF);

	for (uint32 i = 0; i < _polygons.size(); i++) {
		Common::String description;
		for (uint32 j = 0; j < _polygons[i].size(); j++) {
			description += Common::String::format("(x %d, y %d) ", _polygons[i][j].x, _polygons[i][j].y);
		}
		debug("polygon %d: %s", i, description.c_str());
	}
}

int Image::indexForPoint(const Common::Point &point) const {
	Math::Vector2d prevPoint;
	Math::Segment2d testLine(Math::Vector2d(point.x, point.y), Math::Vector2d(-1, -1));
	int intersectCount = 0;
	// TODO: This doesn't necessarily get the innermost polygon
	int index = -1;
	for (uint32 i = 0; i < _polygons.size(); i++) {
		intersectCount = 0;
		for (uint32 j = 0; j < _polygons[i].size(); j++) {
			Math::Vector2d curPoint = Math::Vector2d(_polygons[i][j].x, _polygons[i][j].y);
			if (j == 0) {
				// Special case the line created between the last point and the first
				if (_polygons[i].size() > 1) {
					prevPoint = Math::Vector2d(_polygons[i][_polygons[i].size() - 1].x, _polygons[i][_polygons[i].size() - 1].y);
				} else {
					break;
				}
			}
			Math::Segment2d l(prevPoint, curPoint);
			if (l.intersectsSegment(testLine, nullptr)) {
				intersectCount++;
			}
			prevPoint = curPoint;
		}
		if (intersectCount % 2 != 0) {
			index = i;
		}
	}

	return index;
}

ImageSub23::~ImageSub23() {
}

ImageSub23::ImageSub23(Object *parent, byte subType, uint16 index, const Common::String &name) :
				Image(parent, subType, index, name),
				_noName(false) {
}

void ImageSub23::readData(Formats::XRCReadStream *stream) {
	Image::readData(stream);

	if (stream->isDataLeft()) {
		_field_44_ADF = stream->readUint32LE();
		_field_44_ADF /= 33;
	}

	if (stream->isDataLeft()) {
		_field_48_ADF = stream->readUint32LE();
	}

	_noName = _filename == "noname" || _filename == "noname.xmg";
}

void ImageSub23::onPostRead() {
	initVisual();
}

Visual *ImageSub23::getVisual() {
	initVisual();
	return _visual;
}

void ImageSub23::initVisual() {
	if (_visual) {
		return; // The visual is already there
	}

	if (_noName) {
		return; // No file to load
	}

	Common::ReadStream *stream = StarkArchiveLoader->getFile(_filename, _archiveName);

	VisualImageXMG *xmg = new VisualImageXMG(StarkGfx);
	xmg->load(stream);
	xmg->setHotSpot(_hotspot);

	_visual = xmg;

	delete stream;
}

void ImageSub23::printData() {
	Image::printData();
}

} // End of namespace Resources
} // End of namespace Stark

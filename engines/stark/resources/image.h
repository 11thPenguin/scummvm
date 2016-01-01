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

#ifndef STARK_RESOURCES_IMAGE_H
#define STARK_RESOURCES_IMAGE_H

#include "common/rect.h"
#include "common/str.h"

#include "engines/stark/resources/object.h"

namespace Stark {

class Visual;
namespace Formats {
class XRCReadStream;
}

namespace Resources {

/**
 * A still image resource
 */
class Image : public Object {
public:
	static const Type::ResourceType TYPE = Type::kImage;

	enum SubType {
		kImageSub2 = 2,
		kImageSub3 = 3,
		kImageSub4 = 4
	};

	/** Image factory */
	static Object *construct(Object *parent, byte subType, uint16 index, const Common::String &name);

	typedef Common::Array<Common::Point> Polygon;

	Image(Object *parent, byte subType, uint16 index, const Common::String &name);
	virtual ~Image();

	// Resource API
	void readData(Formats::XRCReadStream *stream) override;

	/** Initialize the renderable for the image */
	virtual Visual *getVisual();

	bool polygonContainsPoint(Common::Point point);

	/** Get the pat-table index for a given point */
	int indexForPoint(Common::Point);
protected:
	void printData() override;

	Common::String _filename;
	Common::String _archiveName;

	Visual *_visual;

	bool _transparent;
	uint32 _transparency;
	uint32 _field_44_ADF;
	uint32 _field_48_ADF;

	Common::Point _hotspot;
	Common::Array<Polygon> _polygons;
};

/**
 * A still image resource loading its data from an XMG file
 */
class ImageSub23 : public Image {
public:
	ImageSub23(Object *parent, byte subType, uint16 index, const Common::String &name);
	virtual ~ImageSub23();

	// Resource API
	void readData(Formats::XRCReadStream *stream) override;
	void onPostRead() override;

	// Image API
	Visual *getVisual() override;

protected:
	void printData() override;

	void initVisual();

	bool _noName;
};

} // End of namespace Resources
} // End of namespace Stark

#endif // STARK_RESOURCES_IMAGE_H

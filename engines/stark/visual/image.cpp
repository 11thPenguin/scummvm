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

#include "engines/stark/visual/image.h"

#include "common/stream.h"

#include "graphics/pixelformat.h"
#include "graphics/surface.h"

#include "engines/stark/debug.h"
#include "engines/stark/formats/xmg.h"
#include "engines/stark/gfx/driver.h"
#include "engines/stark/gfx/texture.h"
#include "engines/stark/scene.h"
#include "engines/stark/services/services.h"

namespace Stark {

VisualImageXMG::VisualImageXMG(Gfx::Driver *gfx) :
		Visual(TYPE),
		_gfx(gfx),
		_texture(nullptr),
		_width(0),
		_height(0) {
}

VisualImageXMG::~VisualImageXMG() {
	delete _texture;
}

void VisualImageXMG::setHotSpot(const Common::Point &hotspot) {
	_hotspot = hotspot;
}

void VisualImageXMG::load(Common::ReadStream *stream) {
	delete _texture;

	// Decode the XMG
	Graphics::Surface *surface = Formats::XMGDecoder::decode(stream);
	_width = surface->w;
	_height = surface->h;
	_texture = _gfx->createTexture(surface);

	surface->free();
	delete surface;
}

void VisualImageXMG::render(const Common::Point &position) {
	_gfx->drawSurface(_texture, position - _hotspot);
}

} // End of namespace Stark

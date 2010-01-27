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

#include "engines/stark/scene.h"
#include "engines/stark/archive.h"
#include "engines/stark/xmg.h"

namespace Stark {

Scene::Scene(GfxDriver *gfx) : _gfx(gfx) {
	// Open the scene archive
	XARCArchive xarc;
	if (!xarc.open("45/00/00.xarc"))
		warning("couldn't open archive");

	_elements.push_back(SceneElementXMG::load(&xarc, "house_layercenter.xmg", 0, 0));
	//_elements.push_back(SceneElementXMG::load(&xarc, "vista-scapehaze-more-fog3-final.xmg", 0, 0));
	_elements.push_back(SceneElementXMG::load(&xarc, "house_prop01_pillow.xmg", 384, 267));
	_elements.push_back(SceneElementXMG::load(&xarc, "house_prop02_pillow.xmg", 324, 299));
	_elements.push_back(SceneElementXMG::load(&xarc, "house_prop03_pillow.xmg", 141, 312));
	_elements.push_back(SceneElementXMG::load(&xarc, "house_prop4_armrest.xmg", 171, 184));
	_elements.push_back(SceneElementXMG::load(&xarc, "house_prop5_chair.xmg", 170, 164));
	_elements.push_back(SceneElementXMG::load(&xarc, "house_prop6_wall.xmg", 0, 0));
	_elements.push_back(SceneElementXMG::load(&xarc, "house_prop8_pillar.xmg", 534, 0));
}

Scene::~Scene() {
	// Delete all the elements
	Common::Array<SceneElement *>::iterator element = _elements.begin();
	while (element != _elements.end()) {
		delete *element;
		element++;
	}
}

void Scene::render() {
	// setup cam

	// Draw bg

	// Draw other things

	// Render all the scene elements
	Common::Array<SceneElement *>::iterator element = _elements.begin();
	while (element != _elements.end()) {
		// Draw the current element
		(*element)->render(_gfx);

		// Go for the next one
		element++;
	}

	//_gfx->set3DMode();

	// setup lights

	// draw actors

	// draw overlay
}

} // End of namespace Stark

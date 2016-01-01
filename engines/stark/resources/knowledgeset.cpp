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

#include "engines/stark/resources/knowledgeset.h"

#include "engines/stark/formats/xrc.h"
#include "engines/stark/resources/item.h"

namespace Stark {
namespace Resources {

KnowledgeSet::~KnowledgeSet() {
}

KnowledgeSet::KnowledgeSet(Object *parent, byte subType, uint16 index, const Common::String &name) :
				Object(parent, subType, index, name) {
	_type = TYPE;
}

void KnowledgeSet::printData() {
}

Gfx::RenderEntryArray KnowledgeSet::getInventoryRenderEntries() {
	// TODO: Keep and persist inventory items order
	Common::Array<Resources::Item *> inventoryItems = listChildren<Resources::Item>(Resources::Item::kItemSub2);
	Common::Array<Resources::Item *>::iterator it = inventoryItems.begin();
	Gfx::RenderEntryArray result;

	int i = 0;
	for (; it != inventoryItems.end(); ++it, ++i) {
		if (i < 4) continue; 	// HACK: The first 4 elements are UI elements, so skip them for now.
		if ((*it)->isEnabled()) {
			result.push_back((*it)->getRenderEntry(Common::Point(0, 0)));
		}
	}

	return result;
}

} // End of namespace Resources
} // End of namespace Stark

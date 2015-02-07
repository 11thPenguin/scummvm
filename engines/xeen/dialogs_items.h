/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
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

#ifndef XEEN_DIALOGS_ITEMS_H
#define XEEN_DIALOGS_ITEMS_H

#include "xeen/dialogs.h"
#include "xeen/party.h"
#include "xeen/screen.h"

namespace Xeen {

enum ItemsMode {
	ITEMMODE_CHAR_INFO = 0, ITEMMODE_BLACKSMITH = 1, ITEMMODE_2 = 2, ITEMMODE_3 = 3,
	ITEMMODE_RECHARGE = 4, ITEMMODE_5 = 5, ITEMMODE_ENCHANT = 6, ITEMMODE_COMBAT = 7, ITEMMODE_8 = 8, 
	ITEMMODE_9 = 9, ITEMMODE_10 = 10, ITEMMODE_TO_GOLD = 11
};

class ItemsDialog : public ButtonContainer {
private:
	XeenEngine *_vm;
	SpriteResource _iconSprites;
	SpriteResource _equipSprites;
	Character _itemsCharacter;
	Character *_oldCharacter;
	DrawStruct _itemsDrawList[INV_ITEMS_TOTAL];

	ItemsDialog(XeenEngine *vm) : ButtonContainer(), 
		_vm(vm), _oldCharacter(nullptr) {}

	Character *execute(Character *c, ItemsMode mode);

	void loadButtons(ItemsMode mode, Character *&c);

	void blackData2CharData();

	void setEquipmentIcons();

	int calcItemCost(Character *c, int itemIndex, ItemsMode mode, int skillLevel, 
		ItemCategory category);

	int doItemOptions(Character &c, int actionIndex, int itemIndex, 
		ItemCategory category, ItemsMode mode);
public:
	static Character *show(XeenEngine *vm, Character *c, ItemsMode mode);
};

} // End of namespace Xeen

#endif /* XEEN_DIALOGS_ITEMS_H */

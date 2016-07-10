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

#ifndef TITANIC_PET_REMOTE_H
#define TITANIC_PET_REMOTE_H

#include "titanic/pet_control/pet_section.h"
#include "titanic/pet_control/pet_glyphs.h"
#include "titanic/pet_control/pet_control_sub12.h"
#include "titanic/pet_control/pet_gfx_element.h"

namespace Titanic {

class CPetRemoteGlyphs : public CPetGlyphs<CPetGlyph> {
};

class CPetRemote : public CPetSection {
private:
	CPetRemoteGlyphs _items;
	CPetGfxElement _val1;
	CPetGfxElement _val2;
	CPetGfxElement _val3;
	CPetGfxElement _val4;
	CPetGfxElement _val5;
	CPetGfxElement _val6;
	CPetGfxElement _val7;
	CPetGfxElement _val8;
	CPetGfxElement _val9;
	CPetGfxElement _val10;
	CPetGfxElement _val11;
	CPetControlSub12 _sub12;
public:
	/**
	 * Returns true if the object is in a valid state
	 */
	virtual bool isValid(CPetControl *petControl);
};

} // End of namespace Titanic

#endif /* TITANIC_PET_REMOTE_H */

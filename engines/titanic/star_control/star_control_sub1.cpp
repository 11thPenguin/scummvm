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

#include "titanic/star_control/star_control_sub1.h"

namespace Titanic {

CStarControlSub1::CStarControlSub1() :
	_field7DA8(0), _field7DAC(0), _field7DB0(0),
	_field7DB4(1), _field7DB8(0), _field7DBC(0) {
}

void CStarControlSub1::load(SimpleFile *file, int param) {
	if (!param) {
		_sub7.load(file);
		_sub8.load(file);
		_field7DA8 = file->readNumber();
		_field7DAC = file->readNumber();
		_field7DB0 = file->readNumber();
		_field7DB4 = file->readNumber();
		_field7DBC = file->readNumber();
	}
}

bool CStarControlSub1::initDocument() {
	warning("CStarControlSub1::initDocument");
	_starArray.initialize();
	return true;
}

} // End of namespace Titanic

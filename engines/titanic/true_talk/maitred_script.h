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

#ifndef TITANIC_MAITRED_SCRIPT_H
#define TITANIC_MAITRED_SCRIPT_H

#include "titanic/true_talk/tt_npc_script.h"

namespace Titanic {

class MaitreDScript : public TTnpcScript {
public:
	MaitreDScript(int val1, const char *charClass, int v2,
			const char *charName, int v3, int val2);

	virtual int proc6() const;
	virtual void proc7(int v1, int v2);
	virtual int proc10() const;
	virtual bool proc16() const;
	virtual bool proc17() const;
	virtual bool proc18() const;
	virtual int proc21(int v);
	virtual int proc22() const;
	virtual int proc23() const;
	virtual void proc24();
	virtual int proc25() const;
	virtual void proc26();
	virtual int proc37() const;
};

} // End of namespace Titanic

#endif /* TITANIC_MAITRED_SCRIPT_H */

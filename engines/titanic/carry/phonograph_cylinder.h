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

#ifndef TITANIC_PHONOGRAPH_CYLINDER_H
#define TITANIC_PHONOGRAPH_CYLINDER_H

#include "titanic/carry/carry.h"

namespace Titanic {

class CPhonographCylinder : public CCarry {
	DECLARE_MESSAGE_MAP
	bool UseWithOtherMsg(CUseWithOtherMsg *msg);
	bool QueryCylinderMsg(CQueryCylinderMsg *msg);
	bool RecordOntoCylinderMsg(CRecordOntoCylinderMsg *msg);
	bool SetMusicControlsMsg(CSetMusicControlsMsg *msg);
	bool ErasePhonographCylinderMsg(CErasePhonographCylinderMsg *msg);
private:
	CString _string6;
	int _field138;
	int _field13C;
	int _field140;
	int _field144;
	int _field148;
	int _field14C;
	int _field150;
	int _field154;
	int _field158;
	int _field15C;
	int _field160;
	int _field164;
	int _field168;
	int _field16C;
	int _field170;
	int _field174;
	int _field178;
	int _field17C;
	int _field180;
	int _field184;
public:
	CLASSDEF
	CPhonographCylinder();

	/**
	 * Save the data for the class to file
	 */
	virtual void save(SimpleFile *file, int indent) const;

	/**
	 * Load the data for the class from file
	 */
	virtual void load(SimpleFile *file);
};

} // End of namespace Titanic

#endif /* TITANIC_PHONOGRAPH_CYLINDER_H */

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

#ifndef TITANIC_PET_SECTION_H
#define TITANIC_PET_SECTION_H

#include "titanic/messages/mouse_messages.h"
#include "titanic/support/simple_file.h"

namespace Titanic {

enum PetArea {
	PET_INVENTORY = 0, PET_CONVERSATION = 1, PET_REMOTE = 2,
	PET_ROOMS = 3, PET_SAVE = 4, PET_5 = 5, PET_6 = 6
};

class CPetControl;
class CScreenManager;
class CRoomItem;

struct CPetSectionSubData {
	int _field0;
	int _field4;
	int _field8;
	int _fieldC;

	CPetSectionSubData() : _field0(0), _field4(0), _field8(0),
		_fieldC(0) {}
};

class CPetSection {
protected:
	CPetControl *_petControl;
public:
	CPetSection() : _petControl(nullptr) {}
	virtual ~CPetSection() {}

	/**
	 * Sets up the section
	 */
	virtual bool setup(CPetControl *petControl) { return false; }
	
	/**
	 * Sets up the section
	 */
	virtual bool setup() { return false; }

	/**
	 * Draw the section
	 */
	virtual void draw(CScreenManager *screenManager) {}
	
	/**
	 * Get the bounds for the section
	 */
	virtual Rect getBounds() { return Rect(); }
	
	virtual void proc5(int val) {}
	
	/**
	 * Following are handlers for the various messages that the PET can
	 * pass onto the currently active section/area
	 */
	virtual bool MouseButtonDownMsg(CMouseButtonDownMsg *msg) { return false; }
	virtual bool MouseDragStartMsg(CMouseDragStartMsg *msg) { return false; }
	virtual bool MouseDragMoveMsg(CMouseDragMoveMsg *msg) { return false; }
	virtual bool MouseDragEndMsg(CMouseDragEndMsg *msg) { return false; }
	virtual bool MouseButtonUpMsg(CMouseButtonUpMsg *msg) { return false; }
	virtual bool MouseDoubleClickMsg(CMouseDoubleClickMsg *msg) { return false; }
	virtual bool KeyCharMsg(CKeyCharMsg *msg) { return false; }
	virtual bool VirtualKeyCharMsg(CVirtualKeyCharMsg *msg) { return false; }

	virtual int proc14() { return 0; }
	
	/**
	 * Returns item a drag-drop operation has dropped on, if any
	 */
	virtual CGameObject *dragEnd(const Point &pt) const { return nullptr; }
	
	/**
	 * Display a message
	 */
	virtual void displayMessage(const CString &msg);

	/**
	 * Returns true if the object is in a valid state
	 */
	virtual bool isValid(CPetControl *petControl) { return false; }

	/**
	 * Load the data for the class from file
	 */
	virtual void load(SimpleFile *file, int param) {}

	/**
	 * Called after a game has been loaded
	 */
	virtual void postLoad() {}

	/**
	 * Save the data for the class to file
	 */
	virtual void save(SimpleFile *file, int indent) const {}

	/**
	 * Called when a section is switched to
	 */
	virtual void enter(PetArea oldArea) {}
	
	/**
	 * Called when a section is being left, to switch to another area
	 */
	virtual void leave() {}
	
	virtual void proc23() {}

	/**
	 * Called when a new room is entered
	 */
	virtual void enterRoom(CRoomItem *room) {}

	virtual void proc25();
	virtual int proc26() { return 0; }
	virtual void proc27();
	virtual void proc28();
	virtual void proc29();
	virtual void proc30();
	virtual void proc31();
	virtual void proc32() {}
	virtual void proc33() {}
	virtual void proc34() {}
	virtual void proc35() {}
	virtual void proc36() {}
	virtual void proc37() {}
	virtual void proc38(int val) {}
};

} // End of namespace Titanic

#endif /* TITANIC_PET_SECTION_H */

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

#ifndef TITANIC_TT_NPC_SCRIPT_H
#define TITANIC_TT_NPC_SCRIPT_H

#include "titanic/support/simple_file.h"
#include "titanic/true_talk/tt_script_base.h"

namespace Titanic {


class TTNpcScriptBase : public TTScriptBase {
protected:
	int _field54;
	int _val2;
public:
	int _charId;
public:
	TTNpcScriptBase(int charId, const char *charClass, int v2,
		const char *charName, int v3, int val2, int v4,
		int v5, int v6, int v7);

	virtual int proc6() const = 0;
	virtual void proc7(int v1, int v2) = 0;
	virtual int proc8() const = 0;
	virtual int proc9() const = 0;

	/**
	 * Called when the script/id changes
	 */
	virtual ScriptChangedResult scriptChanged(TTScriptBase *roomScript, uint id) = 0;

	virtual int proc11() const = 0;
	virtual int proc12() const = 0;

	int charId() const { return _charId; }
};

class TTNpcScript : public TTNpcScriptBase {
protected:
	byte *_subPtr;
	int _field60;
	int _field64;
	int _field68;
	int _field6C;
	int _field70;
	int _field74;
	int _field78;
	int _field7C;
	int _field80;
	int _array[147];
protected:
	void resetFlags();

	void randomizeFlags();
public:
	TTNpcScript(int charId, const char *charClass, int v2,
		const char *charName, int v3, int val2, int v4,
		int v5, int v6, int v7);

	virtual void proc4(int v);
	virtual int proc6() const;
	virtual void proc7(int v1, int v2);
	virtual int proc8() const;
	virtual int proc9() const;

	/**
	 * Called when the script/id changes
	 */
	virtual ScriptChangedResult scriptChanged(TTScriptBase *roomScript, uint id) {
		return SCR_2;
	}

	virtual int proc11() const;
	virtual int proc12() const;
	virtual bool proc13() const;
	virtual void proc14(int v);
	virtual int proc15() const;
	virtual bool proc16() const;
	virtual bool proc17() const;
	virtual bool proc18() const;
	virtual void proc19(int v);
	virtual void proc20(int v);
	virtual int proc21(int v);
	virtual int proc22() const;
	virtual int proc23() const;
	virtual void proc24() = 0;
	virtual int proc25() const;
	virtual void proc26();
	virtual void save(SimpleFile *file);
	virtual void load(SimpleFile *file);
	virtual void saveBody(SimpleFile *file);
	virtual void loadBody(SimpleFile *file);
	virtual int proc31();
	virtual void proc32();
	virtual void proc33(int v1, int v2);
	virtual int proc34();

	/**
	 * Get the NPC's dial level
	 */
	virtual int getDialLevel(uint dialNum, bool flag = true);

	virtual int proc36() const;
	virtual int proc37() const;

	void preLoad();

	/**
	 * Called with the script and id changes
	 */
	ScriptChangedResult notifyScript(TTScriptBase *npcScript, int id) {
		return scriptChanged(npcScript, id);
	}
};

} // End of namespace Titanic

#endif /* TITANIC_TT_NPC_SCRIPT_H */

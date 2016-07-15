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

#include "common/textconsole.h"
#include "titanic/true_talk/tt_npc_script.h"
#include "titanic/true_talk/true_talk_manager.h"

namespace Titanic {

TTnpcScriptBase::TTnpcScriptBase(int charId, const char *charClass, int v2,
		const char *charName, int v3, int val2, int v4, int v5, int v6, int v7) :
		TTscriptBase(0, charClass, v2, charName, v3, v4, v5, v6, v7),
		_charId(charId), _field54(0), _val2(val2) {
}

/*------------------------------------------------------------------------*/

TTnpcScript::TTnpcScript(int charId, const char *charClass, int v2,
		const char *charName, int v3, int val2, int v4, int v5, int v6, int v7) :
		TTnpcScriptBase(charId, charClass, v2, charName, v3, val2, v4, v5, v6, v7),
		_subPtr(nullptr), _field60(0), _field64(0), _field68(0),
		_field6C(0), _field70(0), _field74(0), _field78(0),
		_field7C(0), _field80(0) {
	CTrueTalkManager::_v2 = 0;
	Common::fill(&_array[0], &_array[147], 0);

	if (!CTrueTalkManager::_v10) {
		Common::fill(&CTrueTalkManager::_v11[0], &CTrueTalkManager::_v11[41], 0);
		CTrueTalkManager::_v10 = true;
	}

	resetFlags();
}

void TTnpcScript::resetFlags() {
	Common::fill(&_array[26], &_array[146], 0);
}

void TTnpcScript::randomizeFlags() {
	warning("TODO");
}

void TTnpcScript::proc4(int v) {
	warning("TODO");
}

void TTnpcScript::proc7(int v1, int v2) {
	warning("TODO");
}

int TTnpcScript::proc8() const {
	return 0;
}

int TTnpcScript::proc9() const {
	return 2;
}

int TTnpcScript::proc11() const {
	return 2;
}

int TTnpcScript::proc12() const {
	return 1;
}

bool TTnpcScript::proc13() const {
	warning("TODO");
	return true;
}

void TTnpcScript::proc14(int v) {
	warning("TODO");
}

int TTnpcScript::proc15() const {
	return 0;
}

bool TTnpcScript::proc16() const {
	return true;
}

bool TTnpcScript::proc17() const {
	return true;
}

bool TTnpcScript::proc18() const {
	return true;
}

void TTnpcScript::proc19(int v) {
	warning("TODO");
}

void TTnpcScript::proc20(int v) {
	warning("TODO");
}

int TTnpcScript::proc21(int v) {
	return v;
}

int TTnpcScript::proc22() const {
	return 0;
}

int TTnpcScript::proc23() const {
	return 0;
}

int TTnpcScript::proc25() const {
	return 0;
}

void TTnpcScript::proc26() {
}

void TTnpcScript::save(SimpleFile *file) {
	file->writeNumber(charId());
	saveBody(file);

	file->writeNumber(4);
	file->writeNumber(_field70);
	file->writeNumber(_field74);
	file->writeNumber(_field78);
	file->writeNumber(_field7C);
	
	file->writeNumber(10);
	for (int idx = 0; idx < 10; ++idx)
		file->writeNumber(_array[idx]);
}

void TTnpcScript::load(SimpleFile *file) {
	loadBody(file);

	int count = file->readNumber();
	_field70 = file->readNumber();
	_field74 = file->readNumber();
	_field78 = file->readNumber();
	_field7C = file->readNumber();

	for (int idx = count; idx > 4; --idx)
		file->readNumber();

	count = file->readNumber();
	for (int idx = 0; idx < count; ++idx) {
		int v = file->readNumber();
		if (idx < 10)
			_array[idx] = v;
	}
}

void TTnpcScript::saveBody(SimpleFile *file) {
	int v = proc31();
	file->writeNumber(v);

	if (v > 0 && _subPtr) {
		warning("TODO");
	}
}

void TTnpcScript::loadBody(SimpleFile *file) {
	int count = file->readNumber();
	preLoad();

	for (int index = 0; index < count; index += 2) {
		int v = file->readNumber();

		if (_subPtr) {
			error("TODO - %d", v);
		}
	}
}

int TTnpcScript::proc31() {
	warning("TODO");
	return 0;
}

void TTnpcScript::proc32() {
	warning("TODO");
}

void TTnpcScript::proc33(int v1, int v2) {
	warning("TODO");
}

int TTnpcScript::proc34() {
	warning("TODO");
	return 0;
}

int TTnpcScript::getDialLevel(uint dialNum, bool flag) {
	warning("TODO");
	return 0;
}

int TTnpcScript::proc36() const {
	return 0;
}

int TTnpcScript::proc37() const {
	return 0;
}

void TTnpcScript::preLoad() {
	if (_subPtr) {
		error("TODO");
	}
}

} // End of namespace Titanic

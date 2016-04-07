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

#include "titanic/game/television.h"
#include "titanic/pet_control/pet_control.h"

namespace Titanic {

BEGIN_MESSAGE_MAP(CTelevision, CGameObject)
	ON_MESSAGE(LeaveViewMsg)
	ON_MESSAGE(ChangeSeasonMsg)
	ON_MESSAGE(EnterViewMsg)
	ON_MESSAGE(PETUpMsg)
	ON_MESSAGE(PETDownMsg)
	ON_MESSAGE(StatusChangeMsg)
	ON_MESSAGE(ActMsg)
	ON_MESSAGE(PETActivateMsg)
	ON_MESSAGE(MovieEndMsg)
	ON_MESSAGE(ShipSettingMsg)
	ON_MESSAGE(TurnOff)
	ON_MESSAGE(TurnOn)
	ON_MESSAGE(LightsMsg)
END_MESSAGE_MAP()

int CTelevision::_v1;
bool CTelevision::_turnOn;
int CTelevision::_v3;
int CTelevision::_v4;
int CTelevision::_v5;
int CTelevision::_v6;

CTelevision::CTelevision() : CBackground(), _fieldE0(1),
	_fieldE4(7), _isOn(false), _fieldEC(0), _fieldF0(0) {
}

void CTelevision::init() {
	_v1 = 531;
	_turnOn = true;
	_v3 = 0;
	_v4 = 27;
	_v5 = 1;
	_v6 = 1;
}

void CTelevision::deinit() {
}

void CTelevision::save(SimpleFile *file, int indent) const {
	file->writeNumberLine(1, indent);
	file->writeNumberLine(_fieldE0, indent);
	file->writeNumberLine(_v1, indent);
	file->writeNumberLine(_fieldE4, indent);
	file->writeNumberLine(_turnOn, indent);
	file->writeNumberLine(_isOn, indent);
	file->writeNumberLine(_v3, indent);
	file->writeNumberLine(_fieldEC, indent);
	file->writeNumberLine(_v4, indent);
	file->writeNumberLine(_fieldF0, indent);
	file->writeNumberLine(_v5, indent);
	file->writeNumberLine(_v6, indent);

	CBackground::save(file, indent);
}

void CTelevision::load(SimpleFile *file) {
	file->readNumber();
	_fieldE0 = file->readNumber();
	_v1 = file->readNumber();
	_fieldE4 = file->readNumber();
	_turnOn = file->readNumber() != 0;
	_isOn = file->readNumber() != 0;
	_v3 = file->readNumber();
	_fieldEC = file->readNumber();
	_v4 = file->readNumber();
	_fieldF0 = file->readNumber();
	_v5 = file->readNumber();
	_v6 = file->readNumber();

	CBackground::load(file);
}

bool CTelevision::LeaveViewMsg(CLeaveViewMsg *msg) {
	clearPet();
	if (_isOn) {
		if (soundFn1(_fieldF0))
			soundFn2(_fieldF0, 0);

		loadFrame(622);
		stopMovie();
		setVisible(0);
		_isOn = false;

		if (compareRoomNameTo("CSGState")) {
			CVisibleMsg visibleMsg(true);
			visibleMsg.execute("Tellypic");
		}
	}

	return true;
}

bool CTelevision::ChangeSeasonMsg(CChangeSeasonMsg *msg) {
	if (msg->_season.compareTo("Autumn")) {
		_v1 = 545;
		_v3 = 0;
	} else if (msg->_season.compareTo("Winter")) {
		_v1 = 503;
		_v3 = 0;
	} else if (msg->_season.compareTo("Spring")) {
		_v1 = 517;
		_v3 = 0;
	} else if (msg->_season.compareTo("Winter")) {
		_v1 = 531;
		_v3 = 0;
	}

	return true; 
}

bool CTelevision::EnterViewMsg(CEnterViewMsg *msg) {
	setPetArea(PET_REMOTE);
	petFn2(2);
	petFn3(0);
	setVisible(0);
	_fieldE0 = 1;

	return true;
}

static const int FRAMES1[9] = { 0, 0, 56, 112, 168, 224, 280, 336, 392 };
static const int FRAMES2[8] = { 0, 55, 111, 167, 223, 279, 335, 391 };

bool CTelevision::PETUpMsg(CPETUpMsg *msg) {
	if (msg->_name == "Television" && _isOn) {
		if (soundFn1(_fieldF0))
			soundFn2(_fieldF0, 0);

		_fieldE0 = _fieldE0 % _fieldE4 + 1;
		stopMovie();
		fn1(FRAMES1[_fieldE0], FRAMES2[_fieldE0], 4);
	}

	return true;
}

bool CTelevision::PETDownMsg(CPETDownMsg *msg) {
	if (msg->_name == "Television" && _isOn) {
		if (soundFn1(_fieldF0))
			soundFn2(_fieldF0, 0);
		if (--_fieldE0 < 1)
			_fieldE0 += _fieldE4;

		_fieldE0 = _fieldE0 % _fieldE4 + 1;
		stopMovie();
		fn1(FRAMES1[_fieldE0], FRAMES2[_fieldE0], 4);
	}

	return true;
}

bool CTelevision::StatusChangeMsg(CStatusChangeMsg *msg) {
	if (_isOn) {
		stopMovie();
		changeStatus(0);
	}

	return true;
}

bool CTelevision::ActMsg(CActMsg *msg) {
	if (msg->_action == "TurnTVOnOff") {
		_isOn = !_isOn;
		if (_isOn) {
			setVisible(true);
			CStatusChangeMsg changeMsg;
			changeMsg.execute(this);
		} else {
			setVisible(_isOn);
			stopMovie();
		}
	}

	return true;
}

bool CTelevision::PETActivateMsg(CPETActivateMsg *msg) {
	if (msg->_name == "Television") {
		CVisibleMsg visibleMsg(_isOn);
		_isOn = !_isOn;

		if (_isOn) {
			setVisible(true);
			fn1(0, 55, 0);
			_fieldE0 = 1;
		} else {
			stopMovie();
			if (soundFn1(_fieldF0))
				soundFn2(_fieldF0, 0);
			
			setVisible(false);
		}

		if (compareRoomNameTo("SGTState"))
			visibleMsg.execute("Tellypic");
	}

	return true;
}

bool CTelevision::MovieEndMsg(CMovieEndMsg *msg) {
	warning("TODO: CMovieEndMsg");
	return true;
}

bool CTelevision::ShipSettingMsg(CShipSettingMsg *msg) {
	_v4 = msg->_value;
	return true;
}

bool CTelevision::TurnOff(CTurnOff *msg) {
	_turnOn = false;
	return true;
}

bool CTelevision::TurnOn(CTurnOn *msg) {
	_turnOn = true;
	return true;
}

bool CTelevision::LightsMsg(CLightsMsg *msg) {
	CPetControl *pet = getPetControl();
	if (pet)
		pet->fn4();

	if (msg->_field8 || !_turnOn)
		_turnOn = true;

	return true;
}

} // End of namespace Titanic

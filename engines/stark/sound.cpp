/* Residual - A 3D game interpreter
 *
 * Residual is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the AUTHORS
 * file distributed with this source distribution.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 *
 * $URL$
 * $Id$
 *
 */

#include "engines/stark/sound.h"
#include "engines/stark/adpcm.h"
#include "engines/stark/archive.h"

namespace Stark {

inline static Common::String readString(Common::SeekableReadStream *stream) {
	Common::String ret = "";
	byte ch;
	while ((ch = stream->readByte()) != 0x20)
		ret += ch;

	return ret;
}

ISS::ISS(Common::SeekableReadStream *str) {
	Common::String codec = "";
	uint16 blockSize, channels, freq;
	uint32 size;

	codec = readString(str);

	if (codec.equals("IMA_ADPCM_Sound")) {

		codec = readString(str);
		blockSize = (uint16)strtol(codec.c_str(), 0, 10);

		readString(str);
		// name ?

		readString(str);
		// ?

		codec = readString(str);
		channels = (uint16)strtol(codec.c_str(), 0, 10) + 1;

		readString(str);
		// ?

		codec = readString(str);
		freq = 44100 / (uint16)strtol(codec.c_str(), 0, 10);

		readString(str);

		readString(str);

		codec = readString(str);
		size = (uint32)strtol(codec.c_str(), 0, 10);

		_stream = new ISS_ADPCMStream(str, DisposeAfterUse::YES, size, freq, channels, blockSize);
	}
}

} // End of namespace Stark

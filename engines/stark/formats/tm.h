/* ResidualVM - A 3D game interpreter
 *
 * ResidualVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the AUTHORS
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

#ifndef STARK_FORMATS_TM_H
#define STARK_FORMATS_TM_H

#include "common/scummsys.h"

namespace Stark {

class ArchiveReadStream;

namespace Gfx {
class TextureSet;
}

namespace Formats {

class BiffObject;

/**
 * A texture set loader able to read '.tm' files
 */
class TextureSetReader {
public:
	/**
	 * Load a texture set from the provided stream.
	 *
	 * The caller is responsible for freeing the texture set.
	 */
	static Gfx::TextureSet *read(ArchiveReadStream *stream);

private:
	static BiffObject *biffObjectBuilder(uint32 type);

};

} // End of namespace Formats
} // End of namespace Stark

#endif // STARK_FORMATS_TM_H

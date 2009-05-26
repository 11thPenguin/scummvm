/* Residual - Virtual machine to run LucasArts' 3D adventure games
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

#include "base/plugins.h"

#include "engines/advancedDetector.h"
#include "common/file.h"

#include "engines/grim/grim.h"

namespace Grim {

struct GrimGameDescription {
	ADGameDescription desc;
};

uint32 GrimEngine::getFeatures() const {
	return _gameDescription->desc.flags;
}

Common::Language GrimEngine::getLanguage() const {
	return _gameDescription->desc.language;
}

}

static const PlainGameDescriptor grimGames[] = {
	{"grim", "Grim Fandango"},
	{"monkey", "Escape From Monkey Island"},
	{0, 0}
};


namespace Grim {

static const GrimGameDescription gameDescriptions[] = {
	{
		// Grim Fandago English version
		{
			"grim",
			0,
			AD_ENTRY1s("grim.tab", "cfb333d6aec260c905151b6b98ef71e8", 362212),
			Common::EN_ANY,
			Common::kPlatformPC,
			ADGF_NO_FLAGS
		},
	},
	{
		// Grim Fandago German version
		{
			"grim",
			0,
			AD_ENTRY1s("grim.tab", "464138caf47e580cbb237dee10674b16", 362212), // by garrythefish
			Common::DE_DEU,
			Common::kPlatformPC,
			ADGF_NO_FLAGS
		},
	},
	{
		// Grim Fandago Spanish version
		{
			"grim",
			0,
			AD_ENTRY1s("grim.tab", "b1460cd029f13718f7f62c2403e047ec", 372709), // by jvprat
			Common::ES_ESP,
			Common::kPlatformPC,
			ADGF_NO_FLAGS
		},
	},


	{ AD_TABLE_END_MARKER }
};

} // End of namespace Grim

static const ADParams detectionParams = {
	// Pointer to ADGameDescription or its superset structure
	(const byte *)Grim::gameDescriptions,
	// Size of that superset structure
	sizeof(Grim::GrimGameDescription),
	// Number of bytes to compute MD5 sum for
	5000,
	// List of all engine targets
	grimGames,
	// Structure for autoupgrading obsolete targets
	0,
	// Name of single gameid (optional)
	"grim",
	// List of files for file-based fallback detection (optional)
	0,
	// Flags
	0
};

class GrimMetaEngine : public AdvancedMetaEngine {
public:
	GrimMetaEngine() : AdvancedMetaEngine(detectionParams) {}

	virtual const char *getName() const {
		return "Grim Engine";
	}

	virtual const char *getOriginalCopyright() const {
		return "LucasArts GrimE Games (C) LucasArts";
	}

	virtual bool createInstance(OSystem *syst, Engine **engine, const ADGameDescription *desc) const;
};

bool GrimMetaEngine::createInstance(OSystem *syst, Engine **engine, const ADGameDescription *desc) const {
	const Grim::GrimGameDescription *gd = (const Grim::GrimGameDescription *)desc;
	if (gd) {
		*engine = new Grim::GrimEngine(syst, gd);
	}
	return gd != 0;
}

#if PLUGIN_ENABLED_DYNAMIC(GRIM)
	REGISTER_PLUGIN_DYNAMIC(GRIM, PLUGIN_TYPE_ENGINE, GrimMetaEngine);
#else
	REGISTER_PLUGIN_STATIC(GRIM, PLUGIN_TYPE_ENGINE, GrimMetaEngine);
#endif

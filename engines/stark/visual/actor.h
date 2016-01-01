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

#ifndef STARK_VISUAL_ACTOR_H
#define STARK_VISUAL_ACTOR_H

#include "math/matrix4.h"
#include "math/ray.h"
#include "math/vector3d.h"

#include "engines/stark/visual/visual.h"

namespace Stark {

namespace Gfx {
class TextureSet;
}

class Model;
class FaceNode;
class SkeletonAnim;


class VisualActor : public Visual {
public:
	static const VisualType TYPE = Visual::kActor;

	VisualActor();
	virtual ~VisualActor();

	void setModel(Model *model);
	void setAnim(SkeletonAnim *anim);
	void setTexture(Gfx::TextureSet *texture);
	void setTime(uint32 time);

	bool intersectRay(const Math::Ray &ray, const Math::Vector3d position, float direction);
	virtual void render(const Math::Vector3d position, float direction) = 0;

protected:
	Model *_model;
	uint32 _time;
	bool _meshIsDirty;

	Math::Matrix4 getModelMatrix(const Math::Vector3d& position, float direction);
};

} // End of namespace Stark

#endif // STARK_VISUAL_ACTOR_H

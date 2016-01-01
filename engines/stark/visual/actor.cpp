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

#include "engines/stark/visual/actor.h"

#include "engines/stark/actor.h"
#include "engines/stark/skeleton.h"
#include "engines/stark/gfx/driver.h"
#include "engines/stark/gfx/texture.h"

#include "common/archive.h"
#include "common/stream.h"

#include <SDL_opengl.h> // HACK: I just want to see something

namespace Stark {

VisualActor::VisualActor() :
		Visual(TYPE),
		_actor(nullptr),
		_time(0) {
}

VisualActor::~VisualActor() {
}

void VisualActor::setMesh(Actor *mesh) {
	_actor = mesh;
}

void VisualActor::setAnim(SkeletonAnim *anim) {
	_actor->setAnim(anim);
}

void VisualActor::setTexture(Gfx::TextureSet *texture) {
	_actor->setTextureSet(texture);
}

void VisualActor::setTime(uint32 time) {
	_time = time;
}

void VisualActor::render(Gfx::Driver *gfx, const Math::Vector3d position, float direction) {
	_actor->getSkeleton()->animate(_time);

	// Prepare vertex list and push to gfx driver
	// HACK: Purely because I just want to see something for now
	gfx->set3DMode();
	glPushMatrix();
	glTranslatef(position.x(), position.y(), position.z());
	glRotatef(90, 1.f, 0.f, 0.f);
	glRotatef(90 - (_actor->getFacingDirection() + direction), 0.f, 1.f, 0.f);

	Skeleton *skeleton = _actor->getSkeleton();
	Common::Array<MeshNode *> meshes = _actor->getMeshes();
	Common::Array<MaterialNode *> mats = _actor->getMaterials();
	const Gfx::TextureSet *texture = _actor->getTextureSet();

	for (Common::Array<MeshNode *>::iterator mesh = meshes.begin(); mesh != meshes.end(); ++mesh) {
		for (Common::Array<FaceNode *>::iterator face = (*mesh)->_faces.begin(); face != (*mesh)->_faces.end(); ++face) {
			// For each triangle to draw
			const Gfx::Texture *tex = texture->getTexture(mats[(*face)->_matIdx]->_texName);
				if (tex) {
					glColor3f(1.f, 1.f, 1.f);
					glEnable(GL_TEXTURE_2D);

					tex->bind();
				} else {
					glColor3f(mats[(*face)->_matIdx]->_r, mats[(*face)->_matIdx]->_g, mats[(*face)->_matIdx]->_b);
					glDisable(GL_TEXTURE_2D);
				}

			glBegin(GL_TRIANGLES);
			for (Common::Array<TriNode *>::iterator tri = (*face)->_tris.begin(); tri != (*face)->_tris.end(); ++tri) {
				// Contains 3 vertices
				// Each vertex relative to a bone coordinate
				// 'move' to join location and rotation, then place the vertex there

				for (int vert = 0; vert < 3; ++vert) {
					int vertIdx;
					if (vert == 0)
						vertIdx = (*tri)->_vert1;
					else if (vert == 1)
						vertIdx = (*tri)->_vert3;
					else
						vertIdx = (*tri)->_vert2;

					Math::Vector3d b1 = (*face)->_verts[vertIdx]->_pos1;
					skeleton->applyBoneTransform((*face)->_verts[vertIdx]->_bone1, b1);

					Math::Vector3d b2 = (*face)->_verts[vertIdx]->_pos2;
					skeleton->applyBoneTransform((*face)->_verts[vertIdx]->_bone2, b2);

					float w = (*face)->_verts[vertIdx]->_boneWeight;
					Math::Vector3d pos = b1 * w + b2 * (1.f - w);

					if (tex)
						glTexCoord2f(-(*face)->_verts[vertIdx]->_texS, (*face)->_verts[vertIdx]->_texT);

					glVertex3f(pos.x(), pos.y(), -pos.z()); // - is LHS->RHS
				}
			}
			glEnd();
		}
	}

	glPopMatrix();
}

} // End of namespace Stark

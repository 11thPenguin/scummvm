// Residual - Virtual machine to run LucasArts' 3D adventure games
// Copyright (C) 2003-2004 The ScummVM-Residual Team (www.scummvm.org)
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA

#include "stdafx.h"
#include "walkplane.h"
#include "textsplit.h"

void Sector::load(TextSplitter &ts) {
	char buf[256];
	int id = 0;

	// Sector NAMES can be null, but ts isn't flexible enough
	if (strlen(ts.currentLine()) > strlen(" sector"))
		ts.scanString(" sector %256s", 1, buf);
	else {
		ts.nextLine();
		strcpy(buf, "");
	}

	ts.scanString(" id %d", 1, &id);
	load0(ts, buf, id);
}

void Sector::load0(TextSplitter &ts, char *name, int id) {
	char buf[256];
	int i = 0;
	float height = 12345.f; // Yaz: this is in the original code...
	Vector3d tempVert;

	_name = name;
	_id = id;
	ts.scanString(" type %256s", 1, buf);

	// Flags used in function at 4A66C0 (buildWalkPlane)

	if (strstr(buf, "walk"))
		_type = 0x1000;

	else if (strstr(buf, "funnel"))
		_type = 0x1100;
	else if (strstr(buf, "camera"))
		_type = 0x2000;
	else if (strstr(buf, "special"))
		_type = 0x4000;
	else if (strstr(buf, "chernobyl"))
		_type = 0x8000;
	else
		error("Unknown sector type '%s' in room setup", buf);

	ts.scanString(" default visibility %256s", 1, buf);
	if (strcmp(buf, "visible") == 0)
		_visible = true;
	else if (strcmp(buf, "invisible") == 0)
		_visible = false;
	else
		error("Invalid visibility spec: %s\n", buf);
	ts.scanString(" height %f", 1, &_height);
	ts.scanString(" numvertices %d", 1, &_numVertices);
	_vertices = new Vector3d[_numVertices + 1];

	ts.scanString(" vertices: %f %f %f", 3, &_vertices[0].x(), &_vertices[0].y(), &_vertices[0].z());
	for (i = 1; i < _numVertices; i++)
		ts.scanString(" %f %f %f", 3, &_vertices[i].x(), &_vertices[i].y(), &_vertices[i].z());

	// Repeat the last vertex for convenience
	_vertices[_numVertices] = _vertices[0];

	_normal = cross(_vertices[1] - _vertices[0], _vertices[_numVertices - 1] - _vertices[0]);
	float length = _normal.magnitude();
	if (length > 0)
		_normal /= length;
}

void Sector::setVisible(bool visible) {
	_visible = visible;
}

bool Sector::isPointInSector(Vector3d point) const {
	// The algorithm: for each edge A->B, check whether the z-component
	// of (B-A) x (P-A) is >= 0.  Then the point is at least in the
	// cylinder above&below the polygon.  (This works because the polygons'
	// vertices are always given in counterclockwise order, and the
	// polygons are always convex.)
	//
	// (I don't know whether the box height actually has to be considered;
	// if not then this will be fine as is.)

	for (int i = 0; i < _numVertices; i++) {
		Vector3d edge = _vertices[i + 1] - _vertices[i];
		Vector3d delta = point - _vertices[i];
		if (edge.x() * delta.y() < edge.y() * delta.x())
			return false;
	}
	return true;
}

Vector3d Sector::projectToPlane(Vector3d point) const {
	if (_normal.z() == 0)
		error("Trying to walk along vertical plane\n");

	// Formula: return p - (n . (p - v_0))/(n . k) k
	Vector3d result = point;
	result.z() -= dot(_normal, point - _vertices[0]) / _normal.z();
	return result;
}

Vector3d Sector::projectToPuckVector(Vector3d v) const {
	if (_normal.z() == 0)
		error("Trying to walk along vertical plane\n");

	Vector3d result = v;
	result.z() -= dot(_normal, v) / _normal.z();
	return result;
}

// Find the closest point on the walkplane to the given point
Vector3d Sector::closestPoint(Vector3d point) const {
	// First try to project to the plane
	Vector3d p2 = point;
	p2 -= (dot(_normal, p2 - _vertices[0])) * _normal;
	if (isPointInSector(p2))
		return p2;

	// Now try to project to some edge
	for (int i = 0; i < _numVertices; i++) {
		Vector3d edge = _vertices[i + 1] - _vertices[i];
		Vector3d delta = point - _vertices[i];
		float scalar = dot(delta, edge) / dot(edge, edge);
		if (scalar >= 0 && scalar <= 1 &&
		    delta.x() * edge.y() > delta.y() * edge.x())
			// That last test is just whether the z-component
			// of delta cross edge is positive; we don't
			// want to return opposite edges.
			return _vertices[i] + scalar * edge;
	}

	// Otherwise, just find the closest vertex
	float minDist = (point - _vertices[0]).magnitude();
	int index = 0;
	for (int i = 1; i < _numVertices; i++) {
		float currDist = (point - _vertices[i]).magnitude();
		if (currDist < minDist) {
			minDist = currDist;
			index = i;
		}
	}
	return _vertices[index];
}

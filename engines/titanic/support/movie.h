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

#ifndef TITANIC_MOVIE_H
#define TITANIC_MOVIE_H

#include "video/video_decoder.h"
#include "titanic/core/list.h"
#include "titanic/core/resource_key.h"

namespace Titanic {

enum MovieState { 
	MOVIE_STOPPED = -1, MOVIE_NONE = 0, MOVIE_FINISHED = 1, MOVIE_FRAME = 2
};

class CVideoSurface;
class CMovie;
class CGameObject;

class CMovieList : public List<CMovie> {
public:
};

class CMovie : public ListItem {
protected:
	MovieState _state;
	int _field10;
public:
	CMovie();
	virtual ~CMovie();

	/**
	 * Plays the movie
	 */
	virtual void play(uint flags, CVideoSurface *surface) = 0;
	
	/**
	 * Plays the movie
	 */
	virtual void play(uint startFrame, uint endFrame, int v3, bool v4) = 0;
	
	virtual void proc10() = 0;
	virtual void proc11() = 0;
	virtual void proc12() = 0;

	/**
	 * Stops the movie
	 */
	virtual void stop() = 0;

	virtual void proc14() = 0;
	virtual void setFrame(uint frameNumber) = 0;
	virtual void proc16() = 0;
	virtual void proc17() = 0;
	virtual void proc18() = 0;

	/**
	 * Get the current movie frame
	 */
	virtual int getFrame() = 0;
	
	virtual void proc20() = 0;
	virtual void *proc21() = 0;

	bool isActive() const;

	bool get10();

	virtual MovieState getState() = 0;
	virtual void update() = 0;
};

class OSMovie : public CMovie {
private:
	Video::VideoDecoder *_video;
	CVideoSurface *_videoSurface;
	int _endFrame;

	/**
	 * Decodes the next frame
	 */
	void decodeFrame();
public:
	CGameObject *_gameObject;
public:
	OSMovie(const CResourceKey &name, CVideoSurface *surface);
	OSMovie(Common::SeekableReadStream *stream, CVideoSurface *surface);
	virtual ~OSMovie();

	/**
	 * Plays the movie
	 */
	virtual void play(uint flags, CVideoSurface *surface);
	
	/**
	 * Plays the movie
	 */
	virtual void play(uint startFrame, uint endFrame, int v3, bool v4);
	
	virtual void proc10();
	virtual void proc11();
	virtual void proc12();

	/**
	 * Stops the movie
	 */
	virtual void stop();
	
	virtual void proc14();

	/**
	 * Set the current frame number
	 */
	virtual void setFrame(uint frameNumber);
	
	virtual void proc16();
	virtual void proc17();
	virtual void proc18();

	/**
	 * Get the current movie frame
	 */
	virtual int getFrame();

	virtual void proc20();
	virtual void *proc21();


	virtual MovieState getState();
	virtual void update();
};

} // End of namespace Titanic

#endif /* TITANIC_MOVIE_H */

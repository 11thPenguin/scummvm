/* ResidualVM - A 3D game interpreter
 *
 * ResidualVM is the legal property of its developers, whose names
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

#ifndef BACKENDS_GRAPHICS_SURFACESDL_GRAPHICS_H
#define BACKENDS_GRAPHICS_SURFACESDL_GRAPHICS_H

#ifdef USE_OPENGL
#include "graphics/opengl/system_headers.h"
#include "graphics/opengl/framebuffer.h"
#include "graphics/opengl/texture.h"
#include "graphics/opengl/surfacerenderer.h"
#endif

#undef ARRAYSIZE

#include "backends/graphics/graphics.h"
#include "backends/graphics/sdl/sdl-graphics.h"
#include "graphics/pixelformat.h"
#include "graphics/scaler.h"
#include "common/array.h"
#include "common/events.h"
#include "common/system.h"
#include "math/rect2d.h"

#include "backends/events/sdl/sdl-events.h"

#include "backends/platform/sdl/sdl-sys.h"

#ifndef RELEASE_BUILD
// Define this to allow for focus rectangle debugging
#define USE_SDL_DEBUG_FOCUSRECT
#endif

/**
 * SDL graphics manager
 */
class SurfaceSdlGraphicsManager : public SdlGraphicsManager, public Common::EventObserver {
public:
	SurfaceSdlGraphicsManager(SdlEventSource *sdlEventSource, SdlWindow *window);
	virtual ~SurfaceSdlGraphicsManager();

	virtual void activateManager();
	virtual void deactivateManager();

	virtual bool hasFeature(OSystem::Feature f);
	virtual void setFeatureState(OSystem::Feature f, bool enable);
	virtual bool getFeatureState(OSystem::Feature f);

	virtual const OSystem::GraphicsMode *getSupportedGraphicsModes() const;
	virtual int getDefaultGraphicsMode() const;
	virtual bool setGraphicsMode(int mode);
	virtual int getGraphicsMode() const;
	virtual void resetGraphicsScale();
#ifdef USE_RGB_COLOR
	virtual Graphics::PixelFormat getScreenFormat() const { return _screenFormat; }
	virtual Common::List<Graphics::PixelFormat> getSupportedFormats() const;
#endif
	virtual void initSize(uint w, uint h, const Graphics::PixelFormat *format = NULL);
	virtual void launcherInitSize(uint w, uint h); // ResidualVM specific method
	virtual void setupScreen(uint gameWidth, uint gameHeight, bool fullscreen, bool accel3d); // ResidualVM specific method
	virtual Graphics::PixelBuffer getScreenPixelBuffer(); // ResidualVM specific method
	virtual int getScreenChangeID() const { return _screenChangeCount; }

	virtual void beginGFXTransaction();
	virtual OSystem::TransactionError endGFXTransaction();

	virtual int16 getHeight();
	virtual int16 getWidth();

protected:
	// PaletteManager API
	virtual void setPalette(const byte *colors, uint start, uint num);
	virtual void grabPalette(byte *colors, uint start, uint num);

public:
	virtual void copyRectToScreen(const void *buf, int pitch, int x, int y, int w, int h);
	virtual Graphics::Surface *lockScreen();
	virtual void unlockScreen();
	virtual void fillScreen(uint32 col);
	virtual void updateScreen();
	virtual void setShakePos(int shakeOffset);
	virtual void setFocusRectangle(const Common::Rect& rect);
	virtual void clearFocusRectangle();

	virtual void showOverlay();
	virtual void hideOverlay();
	virtual Graphics::PixelFormat getOverlayFormat() const { return _overlayFormat; }
	virtual void clearOverlay();
	virtual void grabOverlay(void *buf, int pitch);
	virtual void copyRectToOverlay(const void *buf, int pitch, int x, int y, int w, int h);

	//ResidualVM specific implementions:
	virtual int16 getOverlayHeight() { return _overlayHeight; }
	virtual int16 getOverlayWidth() { return _overlayWidth; }
	void closeOverlay(); // ResidualVM specific method

	/* Render the passed Surfaces besides the game texture.
	 * This is used for widescreen support in the Grim engine.
	 * Note: we must copy the Surfaces, as they are free()d after this call.
	 */
	virtual void setSideTextures(Graphics::Surface *left, Graphics::Surface *right);

	virtual bool showMouse(bool visible);
	virtual void warpMouse(int x, int y);
	virtual void setMouseCursor(const void *buf, uint w, uint h, int hotspotX, int hotspotY, uint32 keycolor, bool dontScale = false, const Graphics::PixelFormat *format = NULL);
	virtual void setCursorPalette(const byte *colors, uint start, uint num);
	virtual bool lockMouse(bool lock); // ResidualVM specific method

#ifdef USE_OSD
	virtual void displayMessageOnOSD(const char *msg);
#endif

	// Override from Common::EventObserver
	bool notifyEvent(const Common::Event &event);

	// SdlGraphicsManager interface
	virtual void notifyVideoExpose();
	virtual void transformMouseCoordinates(Common::Point &point);
	virtual void notifyMousePos(Common::Point mouse);

protected:
	/**
	 * Places where the game can be drawn
	 */
	enum GameRenderTarget {
		kScreen,     /** The game is drawn directly on the screen */
				kSubScreen,  /** The game is drawn to a surface, which is centered on the screen */
				kFramebuffer /** The game is drawn to a framebuffer, which is scaled to fit the screen */
	};

	/** Select the best draw target according to the specified parameters */
	GameRenderTarget selectGameRenderTarget(bool fullscreen, bool accel3d,
	                                        bool engineSupportsArbitraryResolutions,
	                                        bool framebufferSupported,
	                                        bool lockAspectRatio);

	/** Compute the size and position of the game rectangle in the screen */
	Math::Rect2d computeGameRect(GameRenderTarget gameRenderTarget, uint gameWidth, uint gameHeight,
	                             uint effectiveWidth, uint effectiveHeight);

	/** Checks if the render target supports drawing at arbitrary resolutions */
	bool canUsePreferredResolution(GameRenderTarget gameRenderTarget, bool engineSupportsArbitraryResolutions);

	/** Obtain the user configured fullscreen resolution, or default to the desktop resolution */
	Common::Rect getPreferredFullscreenResolution();

#if SDL_VERSION_ATLEAST(2, 0, 0)
	SDL_Renderer *_renderer;
	SDL_Texture *_screenTexture;
	SDL_GLContext _glContext;
	void deinitializeRenderer();
	SDL_Surface *SDL_SetVideoMode(int width, int height, int bpp, Uint32 flags);
#endif

	SDL_Surface *_screen;
	SDL_Surface *_subScreen;
#ifdef USE_RGB_COLOR
	Graphics::PixelFormat _screenFormat;
	Common::List<Graphics::PixelFormat> _supportedFormats;
#endif

#ifdef USE_OPENGL
	bool _opengl;
#endif
	bool _lockAspectRatio;
	bool _fullscreen;

	// overlay
	SDL_Surface *_overlayscreen;
	bool _overlayVisible;
	Graphics::PixelFormat _overlayFormat;
	int _overlayWidth, _overlayHeight;
	bool _overlayDirty;

	uint _desktopW, _desktopH;
	Math::Rect2d _gameRect;

#ifdef USE_OPENGL
	struct OpenGLPixelFormat {
		uint bytesPerPixel;
		uint redSize;
		uint blueSize;
		uint greenSize;
		uint alphaSize;
		int multisampleSamples;

		OpenGLPixelFormat(uint screenBytesPerPixel, uint red, uint blue, uint green, uint alpha, int samples);
	};

	/**
	 * Initialize an OpenGL window matching as closely as possible the required properties
	 *
	 * When unable to create a context with anti-aliasing this tries without.
	 * When unable to create a context with the desired pixel depth this tries lower values.
	 */
	bool createScreenOpenGL(uint effectiveWidth, uint effectiveHeight, GameRenderTarget gameRenderTarget);

	// Antialiasing
	int _antialiasing;

	// Overlay
	Common::Array<OpenGL::Texture *> _overlayTextures;

	OpenGL::Texture *_sideTextures[2];

	void initializeOpenGLContext() const;
	void updateOverlayTextures();
	void drawOverlayOpenGL();
	void drawSideTexturesOpenGL();

	OpenGL::FrameBuffer *_frameBuffer;
	OpenGL::FrameBuffer *createFramebuffer(uint width, uint height);

	OpenGL::SurfaceRenderer *_surfaceRenderer;

#endif

	SDL_Surface *_sideSurfaces[2];

	/** Force full redraw on next updateScreen */
	bool _forceFull;

	int _screenChangeCount;

	void drawOverlay();
	void drawSideTextures();

	bool detectFramebufferSupport();
	void detectDesktopResolution();
};

#endif

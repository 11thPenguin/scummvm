
// Texture Manager

#include "graphics/tinygl/zgl.h"

namespace TinyGL {

static GLTexture *find_texture(GLContext *c, int h) {
	GLTexture *t;

	t = c->shared_state.texture_hash_table[h % TEXTURE_HASH_TABLE_SIZE];
	while (t) {
		if (t->handle == h)
			return t;
		t = t->next;
	}
	return NULL;
}

static void free_texture(GLContext *c, int h) {
	GLTexture *t, **ht;
	GLImage *im;
	int i;

	t = find_texture(c, h);
	if (!t->prev) {
		ht = &c->shared_state.texture_hash_table[t->handle % TEXTURE_HASH_TABLE_SIZE];
		*ht = t->next;
	} else {
		t->prev->next = t->next;
	}
	if (t->next)
		t->next->prev = t->prev;

	for (i = 0; i < MAX_TEXTURE_LEVELS; i++) {
		im = &t->images[i];
		if (im->pixmap)
			gl_free(im->pixmap);
	}

	gl_free(t);
}

GLTexture *alloc_texture(GLContext *c, int h) {
	GLTexture *t, **ht;

	t = (GLTexture *)gl_zalloc(sizeof(GLTexture));

	ht = &c->shared_state.texture_hash_table[h % TEXTURE_HASH_TABLE_SIZE];

	t->next = *ht;
	t->prev = NULL;
	if (t->next)
		t->next->prev = t;
	*ht = t;

	t->handle = h;

	return t;
}

void glInitTextures(GLContext *c) {
	// textures
	c->texture_2d_enabled = 0;
	c->current_texture = find_texture(c, 0);
}

void glopBindTexture(GLContext *c, GLParam *p) {
	int target = p[1].i;
	int texture = p[2].i;
	GLTexture *t;

	assert(target == TGL_TEXTURE_2D && texture >= 0);

	t = find_texture(c, texture);
	if (!t) {
		t = alloc_texture(c, texture);
	}
	c->current_texture = t;
}

void glopTexImage2D(GLContext *c, GLParam *p) {
	int target = p[1].i;
	int level = p[2].i;
	int components = p[3].i;
	int width = p[4].i;
	int height = p[5].i;
	int border = p[6].i;
	int format = p[7].i;
	int type = p[8].i;
	void *pixels = p[9].p;
	GLImage *im;
	unsigned char *pixels1;
	int do_free;
	bool do_free_after_rgb2rgba = false;
	
	// Simply unpack RGB into RGBA with 0 for Alpha.
	// FIXME: This will need additional checks when we get around to adding 24/32-bit backend.
	if (target == TGL_TEXTURE_2D && level == 0 && components == 3 && border == 0) {
		if (format == TGL_RGB) {
			unsigned char *temp = (unsigned char *)gl_malloc(width * height * 4);
			unsigned char *pixPtr = (unsigned char*)pixels;
			for (int i = 0; i < width * height * 4; i += 4) {
				temp[i] = pixPtr[0];
				temp[i + 1] = pixPtr[1];
				temp[i + 2] = pixPtr[2];
				temp[i + 3] = 255;
				pixPtr += 3;
			}
			format = TGL_RGBA;
			pixels = temp;
			do_free_after_rgb2rgba = true;
		} else if (format == TGL_BGR) {
			unsigned char *temp = (unsigned char *)gl_malloc(width * height * 4);
			unsigned char *pixPtr = (unsigned char*)pixels;
			for (int i = 0; i < width * height * 4; i += 4) {
				temp[i] = pixPtr[2];
				temp[i + 1] = pixPtr[1];
				temp[i + 2] = pixPtr[0];
				temp[i + 3] = 255;
				pixPtr += 3;
			}
			format = TGL_RGBA;
			pixels = temp;
			do_free_after_rgb2rgba = true;
		}
	} else if (!(target == TGL_TEXTURE_2D && level == 0 && components == 3 && border == 0
				&& format == TGL_RGBA && type == TGL_UNSIGNED_BYTE)) {
		error("glTexImage2D: combination of parameters not handled");
	}

	do_free = 0;
	if (width != 256 || height != 256) {
		pixels1 = (unsigned char *)gl_malloc(256 * 256 * 4);
		// no interpolation is done here to respect the original image aliasing !
		//gl_resizeImageNoInterpolate(pixels1, 256, 256, (unsigned char *)pixels, width, height);
		// used interpolation anyway, it look much better :) --- aquadran
		gl_resizeImage(pixels1, 256, 256, (unsigned char *)pixels, width, height);
		do_free = 1;
		width = 256;
		height = 256;
	} else {
		pixels1 = (unsigned char *)pixels;
	}

	im = &c->current_texture->images[level];
	im->xsize = width;
	im->ysize = height;
	if (im->pixmap)
		gl_free(im->pixmap);
	im->pixmap = gl_malloc(width * height * 3);
	if (im->pixmap)
		gl_convertRGB_to_5R6G5B8A((unsigned short *)im->pixmap, pixels1, width, height);
	if (do_free)
		gl_free(pixels1);
	if (do_free_after_rgb2rgba)
		gl_free(pixels);
}

// TODO: not all tests are done
void glopTexEnv(GLContext *, GLParam *p) {
	int target = p[1].i;
	int pname = p[2].i;
	int param = p[3].i;

	if (target != TGL_TEXTURE_ENV) {
error:
		error("glTexParameter: unsupported option");
	}

	if (pname != TGL_TEXTURE_ENV_MODE)
		goto error;

	if (param != TGL_DECAL)
		goto error;
}

// TODO: not all tests are done
void glopTexParameter(GLContext *, GLParam *p) {
	int target = p[1].i;
	int pname = p[2].i;
	int param = p[3].i;

	if (target != TGL_TEXTURE_2D) {
error:
		error("glTexParameter: unsupported option");
	}

	switch (pname) {
	case TGL_TEXTURE_WRAP_S:
	case TGL_TEXTURE_WRAP_T:
		if (param != TGL_REPEAT)
			goto error;
		break;
	default:
		;
	}
}

void glopPixelStore(GLContext *, GLParam *p) {
	int pname = p[1].i;
	int param = p[2].i;

	if (pname != TGL_UNPACK_ALIGNMENT || param != 1) {
		error("glPixelStore: unsupported option");
	}
}

} // end of namespace TinyGL

void tglGenTextures(int n, unsigned int *textures) {
	TinyGL::GLContext *c = TinyGL::gl_get_context();
	int max, i;
	TinyGL::GLTexture *t;

	max = 0;
	for (i = 0; i < TEXTURE_HASH_TABLE_SIZE; i++) {
		t = c->shared_state.texture_hash_table[i];
		while (t) {
			if (t->handle > max)
				max = t->handle;
			t = t->next;
		}
	}
	for (i = 0; i < n; i++) {
		textures[i] = max + i + 1;
	}
}

void tglDeleteTextures(int n, const unsigned int *textures) {
	TinyGL::GLContext *c = TinyGL::gl_get_context();
	int i;
	TinyGL::GLTexture *t;

	for (i = 0; i < n; i++) {
		t = TinyGL::find_texture(c, textures[i]);
		if (t) {
			if (t == c->current_texture) {
				tglBindTexture(TGL_TEXTURE_2D, 0);
			}
			TinyGL::free_texture(c, textures[i]);
		}
	}
}

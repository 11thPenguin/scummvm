MODULE := engines/stark

MODULE_OBJS := \
	actor.o \
	adpcm.o \
	archive.o \
	detection.o \
	gfx/coordinate.o \
	gfx/driver.o \
	gfx/opengl.o \
	gfx/tinygl.o \
	scene.o \
	skeleton.o \
	skeleton_anim.o \
	sound.o \
	stark.o \
	xmg.o \
	xrc.o

# Include common rules
include $(srcdir)/rules.mk

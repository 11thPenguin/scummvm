/*
** $Id$
** Auxiliary functions for building Lua libraries
** See Copyright Notice in lua.h
*/


#include "engine/lua/lauxlib.h"
#include "engine/lua/lmem.h"
#include "engine/lua/lstate.h"


/*-------------------------------------------------------
**  Auxiliary buffer
-------------------------------------------------------*/

#define BUFF_STEP	32

#define openspace(size)  if (L->Mbuffnext + (size) > L->Mbuffsize) Openspace(size)

static void Openspace(int32 size) {
	lua_State *l = L;  // to optimize
	int32 base = l->Mbuffbase-l->Mbuffer;
	l->Mbuffsize *= 2;
	if (l->Mbuffnext + size > l->Mbuffsize)  // still not big enough?
		l->Mbuffsize = l->Mbuffnext+size;
	l->Mbuffer = (char *)luaM_realloc(l->Mbuffer, l->Mbuffsize);
	l->Mbuffbase = l->Mbuffer+base;
}

char *luaL_openspace(int32 size) {
	openspace(size);
	return L->Mbuffer + L->Mbuffnext;
}

void luaL_addchar(int32 c) {
	openspace(BUFF_STEP);
	L->Mbuffer[L->Mbuffnext++] = c;
}

void luaL_resetbuffer() {
	L->Mbuffnext = L->Mbuffbase - L->Mbuffer;
}

void luaL_addsize(int32 n) {
	L->Mbuffnext += n;
}

int32 luaL_getsize() {
	return L->Mbuffnext - (L->Mbuffbase - L->Mbuffer);
}

int32 luaL_newbuffer(int32 size) {
	int32 old = L->Mbuffbase - L->Mbuffer;
	openspace(size);
	L->Mbuffbase = L->Mbuffer + L->Mbuffnext;
	return old;
}

void luaL_oldbuffer(int32 old) {
	L->Mbuffnext = L->Mbuffbase - L->Mbuffer;
	L->Mbuffbase = L->Mbuffer + old;
}

char *luaL_buffer() {
	return L->Mbuffbase;
}


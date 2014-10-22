/*
 * test-lua_util.c
 *
 *  Created on: Sep 5, 2014
 *      Author: cny
 */

#include "../libluahc/lua_util.h"
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void test_lua_t2query() {
	lua_State *L;
	char buf[102400] = { 0 };
	printf("0\n");
	L = luaL_newstate();
	printf("0-1,%p,\n", L);
//	luaopen_base(L);
	printf("1\n");
	luaL_dostring(L, "abcz={a=11111,b=2,c=\"sfsd\"};\n abcz2={};");
	printf("2\n");
	//
	lua_getglobal(L, "abcz");
	printf("obj:%d\n", lua_istable(L, -1));
	lua_t2query(L, buf, -2);
	printf("abc:%s\n", buf);
	printf("obj:%d\n", lua_istable(L, -1));
	//
	memset(buf, 0, 102400);
	lua_getglobal(L, "abcz2");
	printf("obj:%d\n", lua_istable(L, -1));
	lua_t2query(L, buf, -2);
	printf("abc:%s\n", buf);
	printf("obj:%d\n", lua_istable(L, -1));
	//
	lua_close(L);
}

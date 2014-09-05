/*
 * lua_uti.c
 *
 *  Created on: Sep 4, 2014
 *      Author: cny
 */
#include "lua_util.h"
#include <stdio.h>
#include <stdlib.h>
int lua_t2query(lua_State* L, char* buf, int idx) {
	lua_pushnil(L);
	int len = 0;
	while (lua_next(L, idx)) {
//		printf("N-->%s:%s\n", lua_tostring(L, -2), lua_tostring(L, -1));
		len += sprintf(buf + len, "%s=%s&", lua_tostring(L, -2),
				lua_tostring(L, -1));
		lua_pop(L, 1);
	}
	if (len) {
		buf[len - 1] = 0; //remove last &
	}
	return 0;
}

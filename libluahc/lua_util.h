/*
 * lua_util.h
 *
 *  Created on: Sep 5, 2014
 *      Author: cny
 */

#ifndef LUAUTIL_H_
#define LUAUTIL_H_
#include <lua.h>
#include "curl_util.h"

CURL_UTIL_EXP int lua_t2query(lua_State* L, char* buf, int idx);

#endif /* LUAUTIL_H_ */

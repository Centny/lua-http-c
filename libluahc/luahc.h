/*
 * luahc.h
 *
 *  Created on: Sep 4, 2014
 *      Author: cny
 */

#ifndef LIBLUAHC_H_
#define LIBLUAHC_H_
#include <lua.h>
#include "curl_util.h"
#include "lua_util.h"
#define MAX_ARG_LEN 102400
#define LUA_LUAHCNAME	"luahc"
#define LUAHC_API LUA_API
LUAHC_API int luaopen_luahc (lua_State *L);
#endif /* LIBLUAHC_H_ */

/*
 * test-luahc.c
 *
 *  Created on: Sep 6, 2014
 *      Author: cny
 */

#include "../libluahc/luahc.h"
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char* ts_01 =
		"\
res=curl_g(\"http://192.168.1.1\");\n\
for key, val in pairs(res) do\n\
 if key~=\"data\" then\n\
  print(key,\":\",val);\n\
 end\n\
end\n\
res=curl_g(\"http://192.168.1.1\",{a=11});\n\
print(res.msg);\n\
";
const char* ts_02 =
		"\
res=curl_p(\"http://192.168.1.1\");\n\
for key, val in pairs(res) do\n\
 if key~=\"data\" then\n\
  print(key,\":\",val);\n\
 end\n\
end\n\
res=curl_p(\"http://192.168.1.1\",{a=11},{hh=111});\n\
print(res.msg);\n\
";
extern int curl_p_(lua_State* L);
extern int curl_g_(lua_State* L);
void curl_gp() {
//	printf("0\n");
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);
	lua_register(L, "curl_g", curl_g_);
	lua_register(L, "curl_p", curl_p_);
	//
	luaL_dostring(L, ts_01);
	printf("err:%s\n", lua_tostring(L, -1));
	//
	luaL_dostring(L, ts_02);
	printf("err:%s\n", lua_tostring(L, -1));
	//
	lua_close(L);
	printf("end\n");
}


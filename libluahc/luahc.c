/*
 * luahc.c
 *
 *  Created on: Sep 4, 2014
 *      Author: cny
 */
#include "luahc.h"

struct curl_slist* lua_to_slist(lua_State* L, int idx) {
	struct curl_slist *hs = NULL;
	lua_pushnil(L);
	char buf[MAX_ARG_LEN] = { 0 };
	while (lua_next(L, idx)) {
		memset(buf, 0, MAX_ARG_LEN);
		sprintf(buf, "%s:%s", lua_tostring(L, -2), lua_tostring(L, -1));
		curl_slist_append(hs, buf);
		lua_pop(L, 1);
	}
	return hs;
}
void lua_res_t_(lua_State* L, int code, const char* msg, CURLres* res) {
	lua_newtable(L);
	//
	lua_pushstring(L, "lcode");
	lua_pushinteger(L, code);
	lua_settable(L, -3);
	//
	if (msg) {
		lua_pushstring(L, "msg");
		lua_pushstring(L, msg);
		lua_settable(L, -3);
	}
	if (res) {
		lua_pushstring(L, "ccode");
		lua_pushinteger(L, res->ccode);
		lua_settable(L, -3);
		//
		lua_pushstring(L, "rcode");
		lua_pushinteger(L, res->rcode);
		lua_settable(L, -3);
		//
		lua_pushstring(L, "ctype");
		lua_pushstring(L, res->ctype);
		lua_settable(L, -3);
		//
		lua_pushstring(L, "clen");
		lua_pushinteger(L, res->clen);
		lua_settable(L, -3);
		//
		if (res->rdata) {
			lua_pushstring(L, "data");
			lua_pushstring(L, res->rdata);
			lua_settable(L, -3);
		}
		if (res->h_start) {
			lua_pushstring(L, "header");
			lua_newtable(L);
			CURLresh* resh = res->h_start;
			while (resh) {
				lua_pushstring(L, resh->key);
				lua_pushstring(L, resh->val);
				lua_settable(L, -3);
				resh = resh->next;
			}
			lua_settable(L, -3);
		}
	}
}
int curl_g(lua_State* L) {
	int alen = lua_gettop(L);
	if (alen < 1) {
		lua_res_t_(L, 1, "invalid arguments", 0);
		return 1;
	}
	struct curl_slist* hs = 0;
	if (alen > 1) {
		if (lua_istable(L, 2)) {
			hs = lua_to_slist(L, 2);
		} else {
			lua_res_t_(L, 1, "header field is not table", 0);
			return 1;
		}
	}
	CURLres* res = curl_get_h(lua_tostring(L, 1), hs);
	lua_res_t_(L, 0, 0, res);
	if (hs) {
		curl_slist_free_all(hs);
	}
	curl_free_res(&res);
	return 1;
}
int curl_p(lua_State* L) {
	int alen = lua_gettop(L);
	if (alen < 1) {
		lua_res_t_(L, 1, "invalid arguments", 0);
		return 1;
	}
	char args[MAX_ARG_LEN] = { 0 };
	if (alen > 1) {
		if (lua_istable(L, 2)) {
			lua_t2query(L, args, 2);
		} else {
			lua_res_t_(L, 1, "argument is not table", 0);
			return 1;
		}
	}
	struct curl_slist* hs = 0;
	if (alen > 2) {
		if (lua_istable(L, 3)) {
			hs = lua_to_slist(L, 3);
		} else {
			lua_res_t_(L, 1, "header field is not table", 0);
			return 1;
		}
	}
	CURLres* res = curl_post_h(lua_tostring(L, 1), args, hs);
	lua_res_t_(L, 0, 0, res);
	if (hs) {
		curl_slist_free_all(hs);
	}
	curl_free_res(&res);
	return 1;
}

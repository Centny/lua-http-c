/*
 * main.c
 *
 *  Created on: Sep 4, 2014
 *      Author: cny
 */

#include <stdio.h>
#include <stdlib.h>
#include <lauxlib.h>
#include <lualib.h>
#include "../libluahc/luahc.h"
#include "../libluahc/curl_util.h"
const char* testfunc = "\
print(add2(1.0,2.0))\
";
void test_curl_get_();
void test_curl_post_();
void test_lua_t2query();
void curl_gp();
void testall() {
	test_curl_get_();
	test_curl_post_();
	test_lua_t2query();
	curl_gp();
}
int main() {
//	char a[100], b[100];
//	sscanf("jjjj:sfsdf", "%[^\\:]:%s", a, b);
//	puts(a);
//	puts(b);
//    lua_State* L = luaL_newstate();
//    luaL_openlibs(L);
//    //将指定的函数注册为Lua的全局函数变量，其中第一个字符串参数为Lua代码
//    //在调用C函数时使用的全局函数名，第二个参数为实际C函数的指针。
//    lua_register(L, "add2", add2);
//    //在注册完所有的C函数之后，即可在Lua的代码块中使用这些已经注册的C函数了。
//    if (luaL_dostring(L,testfunc))
//        printf("Failed to invoke.\n");
//    lua_close(L);
//	puts("abbbbb");
//	test_curl_get_();
//	test_curl_post_();
//	test_lua_t2query();
//	char buf[10240];
	curl_gp();
	return 0;
}

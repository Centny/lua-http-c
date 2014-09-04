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
#include "../libluahc/libluahc.h"
#include "../libluahc/curl_util.h"
const char* testfunc = "\
print(add2(1.0,2.0))\
";

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
	puts("abbbbb");
//	char buf[10240];
	CURLres *res = curl_get("http://www.baidu.com");
	printf("abc:%s,%d,%d\n", res->rdata, strlen(res->rdata), res->rcode);
	curl_sres_head(res);
	curl_free_res(&res);
	return 0;
}

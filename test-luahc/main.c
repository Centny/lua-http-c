/*
 * main.c
 *
 *  Created on: Sep 4, 2014
 *      Author: cny
 */
#include <stdio.h>
void test_curl_get_();
void test_curl_post_();
void test_lua_t2query();
void curl_gp();
void testall() {
	test_curl_get_();
	test_curl_post_();
	test_lua_t2query();
	curl_gp();
	printf("all end....\n");
}
int main() {
//	test_curl_get_();
//	test_curl_post_();
//	test_lua_t2query();
//	curl_gp();
	testall();
	return 0;
}

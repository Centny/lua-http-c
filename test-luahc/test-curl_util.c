/*
 * test-curl_util.c
 *
 *  Created on: Sep 5, 2014
 *      Author: cny
 */
#include "../libluahc/curl_util.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void test_curl_get_() {
	CURLres *res;
	char* hs[] = { "abc:jjj", "jfdd:ss" };
	printf("<--------------test_curl_get_---------------->\n");
	res = curl_get("http://www.baidu.com", 0, 0);
	if (res->ccode) {
		printf("ccode:%d\n", res->ccode);
	} else {
		printf("------------------------------>\n");
		printf("abc:%ld,%d\n", strlen(res->rdata), res->rcode);
		curl_sres_head(res);
	}
	curl_free_res(&res);
	//
	res = curl_get("http://www.baidu.com", hs, 2);
	if (res->ccode) {
		printf("ccode:%d\n", res->ccode);
	} else {
		printf("------------------------------>\n");
		printf("abc:%ld,%d\n", strlen(res->rdata), res->rcode);
		curl_sres_head(res);
	}
	curl_free_res(&res);
	//
	res = curl_get("http://wwk", 0, 0);
	printf("ccode:%d\n", res->ccode);
	curl_free_res(&res);
}

void test_curl_post_() {
	CURLres *res;
	unsigned int len;
	char* hs[] = { "abc:jjj", "jfdd:ss" };
	//
	printf("<--------------test_curl_post_---------------->\n");
	//
	printf("test_curl_post_\n");
	res = curl_post("http://www.baidu.com", 0, 0, 0);
	if (res->ccode) {
		printf("ccode:%d\n", res->ccode);
	} else {
		printf("------------------------------>\n");
		len = strlen(res->rdata);
		printf("abc:%d,%d\n", len, res->rcode);
	}
	curl_free_res(&res);
	//
	printf("test_curl_post_2\n");
	res = curl_post("http://www.baidu.com", "abc=1&jkk=2", 0, 0);
	printf("test_curl_post_2-1\n");
	if (res->ccode) {
		printf("ccode:%d\n", res->ccode);
	} else {
		printf("------------------------------>\n");
		len = strlen(res->rdata);
		printf("abc:%d,%d\n", len, res->rcode);
	}
	curl_free_res(&res);
	//
	printf("test_curl_post_3\n");
	res = curl_post("http://www.baidu.com", "abc=1&jkk=2", hs, 2);
	printf("test_curl_post_3-1\n");
	if (res->ccode) {
		printf("ccode:%d\n", res->ccode);
	} else {
		printf("------------------------------>\n");
		len = strlen(res->rdata);
		printf("abc:%d,%d\n", len, res->rcode);
	}
	curl_free_res(&res);
	//
	res = curl_post("http://wwk", 0, 0, 0);
	printf("ccode:%d\n", res->ccode);
	curl_free_res(&res);
}

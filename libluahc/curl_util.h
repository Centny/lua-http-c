/*
 * curl_util.h
 *
 *  Created on: Sep 4, 2014
 *      Author: cny
 */

#ifndef CURL_UTIL_H_
#define CURL_UTIL_H_
#include <curl/curl.h>

typedef struct CURLresh {
	char key[100], val[100];
	struct CURLresh *pre, *next;
} CURLresh;

typedef struct CURLres {
	CURLcode ccode; 	//curl code
	int rcode; 			//HTTP response code.
	char ctype[100]; 		//content type.
	int clen; 			//content length.
	char* rdata; 		//response data.
	struct CURLresh *h_start;	//the response header link table start node.
	struct CURLresh *h_end;	//the response header link table end node.
} CURLres;
void curl_free_res(CURLres** res);
CURLresh* curl_res_head(CURLres* res, const char* key);
CURLresh* curl_sres_head(CURLres* res);
CURLres* curl_get(const char* url);

#endif /* CURL_UTIL_H_ */

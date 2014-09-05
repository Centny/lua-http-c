/*
 * curl_util.h
 *
 *  Created on: Sep 4, 2014
 *      Author: cny
 */

#ifndef CURL_UTIL_H_
#define CURL_UTIL_H_
#include <curl/curl.h>
#include <string.h>
#include <stdlib.h>
/* using default max response data length, when Content-Length not found */
#define MAX_RESPONSE_LEN 102400
#define MAX_HEAD_LEN 100
/* the CURL response head */
typedef struct CURLresh {
	char key[MAX_HEAD_LEN], val[MAX_HEAD_LEN];
	struct CURLresh *pre, *next;
} CURLresh;
/* the CURL HTTP result */
typedef struct CURLres {
	CURLcode ccode; 	//curl code
	int rcode; 			//HTTP response code.
	char ctype[MAX_HEAD_LEN]; 		//content type.
	int clen; 			//content length.
	char* rdata; 		//response data.
	struct CURLresh *h_start;	//the response header link table start node.
	struct CURLresh *h_end;	//the response header link table end node.
} CURLres;
/* free the response CURLres */
void curl_free_res(CURLres** res);
/* get the head value by name */
CURLresh* curl_res_head(CURLres* res, const char* key);
/* print all head */
CURLresh* curl_sres_head(CURLres* res);
/* send GET HTTP request */
CURLres* curl_get(const char* url, char** header, int hlen);
CURLres* curl_get_h(const char* url, struct curl_slist *header);
/* send POST HTTP request */
//CURLres* curl_post(const char* url);
//CURLres* curl_post(const char* url, const char* args);
CURLres* curl_post(const char* url, const char* args, char** header, int hlen);
CURLres* curl_post_h(const char* url, const char* args,
		struct curl_slist *header);

#endif /* CURL_UTIL_H_ */

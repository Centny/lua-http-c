/*
 * luahc.h
 *
 *  Created on: Sep 4, 2014
 *      Author: cny
 */

#ifndef LIBLUAHC_H_
#define LIBLUAHC_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "curl_util.h"
#include "lua_util.h"
#define MAX_ARG_LEN 102400
int curl_p(lua_State* L);
int curl_g(lua_State* L);
#endif /* LIBLUAHC_H_ */

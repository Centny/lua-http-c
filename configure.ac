dnl Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(libluahc, 1.0.0)

AC_CANONICAL_SYSTEM
AM_INIT_AUTOMAKE()
AC_CONFIG_MACRO_DIR([m4])
LT_INIT

AC_PROG_CC
AC_PROG_LIBTOOL
AX_PROG_LUA([5.1], , , [
       AC_MSG_ERROR([Your system lacks lua >= 5.1])
     ])
AX_LUA_HEADERS(, [
       AC_MSG_ERROR([Your system lacks lua >= 5.1])
     ])
AX_LUA_LIBS(, [
       AC_MSG_ERROR([Your system lacks lua >= 5.1])
     ])
LIBCURL_CHECK_CONFIG([], [7.0], ,  [
       AC_MSG_ERROR([Your system lacks libcurl >= 7.0])
     ])
AC_CONFIG_HEADERS(config.h)
AC_CONFIG_FILES(Makefile libluahc/Makefile test-luahc/Makefile)
AC_OUTPUT


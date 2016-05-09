# kollector - configure.ac
# Copyright (c) 2013-2016 Arkadiusz Bokowy

AC_INIT([kollector], [0.1.0], [arkadiusz.bokowy@gmail.com])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([foreign -Wall -Werror])

AC_PROG_CC
AM_PROG_CC_C_O


AC_ARG_VAR([KINDLE_ROOTDIR], [directory containing Kindle root tree])
AC_ARG_ENABLE([kindle-env],
	[AS_HELP_STRING([--enable-kindle-env[[=DIR]]], [use Kindle environment])], [
		if test "x$enableval" != "xno"; then enable_kindle_env=yes; fi
		if test "x$enableval" != "xno" -a "x$enableval" != "xyes"; then
			AC_SUBST([KINDLE_ROOTDIR], [$enableval])
		fi
	])
AM_CONDITIONAL([ENABLE_KINDLE_ENV], [test "x$enable_kindle_env" = "xyes"])
AM_COND_IF([ENABLE_KINDLE_ENV], [
	AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#ifndef __arm__
		error: Not an ARM compiler!
		#endif]])], [],
		[AC_MSG_FAILURE([ARM-compatible compiler is required])])
	if test "x$KINDLE_ROOTDIR" = "x"; then
		AC_MSG_WARN([Kindle environment enabled, but Kindle root tree location not given!])
		AC_MSG_WARN([Either set the KINDLE_ROOTDIR environmental variable or set the root])
		AC_MSG_WARN([tree location with the --enable-kindle-env option.])
	fi
])


PKG_CHECK_MODULES([GLIB20], [glib-2.0])
PKG_CHECK_MODULES([LIBCURL], [libcurl])
PKG_CHECK_MODULES([SQLITE], [sqlite3])
PKG_CHECK_MODULES([UUID], [uuid])

AC_ARG_WITH([watcher],
	[AS_HELP_STRING([--with-watcher], [watch for documents modification])])
AM_CONDITIONAL([WITH_WATCHER], [test "x$with_watcher" = "xyes"])
AM_COND_IF([WITH_WATCHER], [
	AC_DEFINE([WITH_WATCHER], [1], [Define to 1 if watcher is enabled])
	AC_CHECK_HEADERS([openlipc.h], [], [AC_MSG_ERROR([Header openlipc.h not found!])])
	AC_SUBST([LIPC_LIBS], [-llipc])
])


AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT

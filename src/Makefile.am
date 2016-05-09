# kollector - Makefile.am
# Copyright (c) 2013-2016 Arkadiusz Bokowy

bin_PROGRAMS = kollector

kollector_SOURCES = \
	find.c \
	strrcmp.c \
	main.c

kollector_CFLAGS = \
	@GLIB20_CFLAGS@ \
	@LIBCURL_CFLAGS@ \
	@SQLITE_CFLAGS@ \
	@UUID_CFLAGS@

kollector_LDADD = \
	@GLIB20_LIBS@ \
	@LIBCURL_LIBS@ \
	@SQLITE_LIBS@ \
	@UUID_LIBS@

if WITH_WATCHER
kollector_SOURCES += watcher.c
kollector_LDADD += @LIPC_LIBS@
endif

if ENABLE_KINDLE_ENV
AM_LDFLAGS = \
	-L$(KINDLE_ROOTDIR)/lib \
	-L$(KINDLE_ROOTDIR)/usr/lib
endif

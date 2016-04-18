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

kindle-relink-local: $(kollector_OBJECTS)
	$(CCLD) $(CFLAGS) -o kollector $(kollector_OBJECTS) \
		$(top_srcdir)/../../kindle/lib/libuuid.so \
		$(top_srcdir)/../../kindle/usr/lib/libcurl.so \
		$(top_srcdir)/../../kindle/usr/lib/libglib-2.0.so \
		$(top_srcdir)/../../kindle/usr/lib/libsqlite3.so

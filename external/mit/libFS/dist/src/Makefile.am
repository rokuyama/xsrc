lib_LTLIBRARIES = libFS.la

libFS_la_SOURCES = 	\
	FSCloseFt.c	\
	FSClServ.c	\
	FSConnServ.c	\
	FSErrDis.c	\
	FSErrHndlr.c	\
	FSFlush.c	\
	FSFontInfo.c	\
	FSFtNames.c	\
	FSGetCats.c	\
	FSlibInt.c	\
	FSlibint.h	\
	FSlibos.h	\
	FSListCats.c	\
	FSListExt.c	\
	FSMisc.c	\
	FSNextEv.c	\
	FSOpenFont.c	\
	FSOpenServ.c	\
	FSQGlyphs.c	\
	FSQuExt.c	\
	FSQXExt.c	\
	FSQXInfo.c	\
	FSServName.c	\
	FSSetCats.c	\
	FSSync.c	\
	FSSynchro.c	\
	fs_transport.c

AM_CFLAGS = 			\
	$(CWARNFLAGS)		\
	$(FS_CFLAGS)		\
	$(MALLOC_ZERO_CFLAGS)	\
	-DFS_t 			\
	-DTRANS_CLIENT

AM_CPPFLAGS = -I$(top_srcdir)/include/X11/fonts

libFS_la_LIBADD = $(LTLIBOBJS) $(FS_LIBS)

libFS_la_LDFLAGS = -export-symbols-regex '^FS.*' -version-number 6:0:0 -no-undefined

libFSincludedir = $(includedir)/X11/fonts
libFSinclude_HEADERS = \
	$(top_srcdir)/include/X11/fonts/FSlib.h

if LINT
ALL_LINT_FLAGS=$(LINT_FLAGS) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) \
                $(AM_CPPFLAGS) $(CPPFLAGS) $(AM_CFLAGS)

lint:
	$(LINT) $(ALL_LINT_FLAGS) $(libFS_la_SOURCES) \
	 $(libFS_la_LIBADD) $(LIBS)
endif LINT

if MAKE_LINT_LIB
lintlibdir = $(libdir)

lintlib_DATA = $(LINTLIB)

$(LINTLIB): $(libFS_la_SOURCES)
	$(LINT) -y -oFS -x $(ALL_LINT_FLAGS) $(libFS_la_SOURCES) \
	 $(libFS_la_LIBADD) $(LIBS)
endif MAKE_LINT_LIB

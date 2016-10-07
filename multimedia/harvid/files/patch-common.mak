--- common.mak.orig	2013-06-10 18:42:03 UTC
+++ common.mak
@@ -4,7 +4,7 @@ CFLAGS ?= -Wall -g -O2
 PREFIX ?= /usr/local
 
 bindir ?= $(PREFIX)/bin
-mandir ?= $(PREFIX)/share/man
+mandir ?= $(PREFIX)/man
 libdir ?= $(PREFIX)/lib
 docdir ?= $(PREFIX)/share/doc
 includedir ?=  $(PREFIX)/include
@@ -19,38 +19,10 @@ ARCHINCLUDES=
 ARCHLIBES=
 LIBEXT=so
 
-ifeq ($(ARCH),mingw)
-  CC=i686-w64-mingw32-gcc
-  LD=i686-w64-mingw32-ld
-  AR=i686-w64-mingw32-ar
-  NM=i686-w64-mingw32-nm -B
-  RANLIB=i686-w64-mingw32-ranlib
-  STRIP=i686-w64-mingw32-strip
-  WINEROOT?=$(HOME)/.wine/drive_c/x-prefix
-  PKG_CONFIG_PATH=$(WINEROOT)/lib/pkgconfig/
-  ARCHINCLUDES=-I$(WINEROOT)/include -DHAVE_WINDOWS
-  ARCHLIBES=-lwsock32 -lws2_32 -lpthreadGC2
-  LDFLAGS+=-L$(WINEROOT)/lib/ -L$(WINEROOT)/bin
-  UNAME=mingw
-  LIBEXT=dll
-else
-  RANLIB=ranlib
-  STRIP=strip
-  NM=nm
-  UNAME=$(shell uname)
-  ifeq ($(UNAME),Darwin)
-  ARCHFLAGS=-arch i386 -arch ppc -arch x86_64
-  ARCHFLAGS+=-isysroot /Developer/SDKs/MacOSX10.5.sdk -mmacosx-version-min=10.5
-  ARCHFLAGS+=-headerpad_max_install_names
-  ARCHLIBES+=-sectcreate __DATA __doc_harvid_jpg ../doc/harvid.jpg
-  ARCHLIBES+=-sectcreate __DATA __doc_seek_js ../doc/seek.js
-  LOGODEP=
-  ECHO=echo
-  LIBEXT=dylib
-  NM=nm
-  else
-  ARCHLIBES=-lrt -lpthread
-  LIBEXT=so
-  NM=nm -B
-  endif
-endif
+RANLIB=ranlib
+STRIP=strip
+NM=nm
+UNAME=$(shell uname)
+ARCHLIBES=-lrt -lpthread
+LIBEXT=so
+NM=nm -B

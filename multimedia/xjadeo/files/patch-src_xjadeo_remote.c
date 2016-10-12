--- src/xjadeo/remote.c.orig	2016-10-11 23:41:42 UTC
+++ src/xjadeo/remote.c
@@ -57,7 +57,7 @@
 #include <libavcodec/avcodec.h> // needed for PIX_FMT 
 #include <libavformat/avformat.h>
 #endif
-
+typedef int clockid_t;
 #include <jack/jack.h>
 #include <jack/transport.h>
 

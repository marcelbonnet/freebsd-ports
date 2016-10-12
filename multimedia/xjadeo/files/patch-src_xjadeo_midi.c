--- src/xjadeo/midi.c.orig	2016-10-11 23:41:58 UTC
+++ src/xjadeo/midi.c
@@ -27,7 +27,7 @@
  * the alsa midi code was inspired by the alsa-tools
  * amidi.c, aseqdump.c written by Clemens Ladisch <clemens@ladisch.de>
  */
-
+typedef int clockid_t;
 #include <xjadeo.h>
 #include <unistd.h>
 #include <stdlib.h>

--- src/xjadeo/jack.c.orig	2016-10-11 23:41:29 UTC
+++ src/xjadeo/jack.c
@@ -23,7 +23,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
-
+typedef int clockid_t;
 #include <jack/jack.h>
 #include <jack/transport.h>
 

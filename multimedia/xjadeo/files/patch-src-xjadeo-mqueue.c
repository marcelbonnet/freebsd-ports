--- src/xjadeo/mqueue.c.orig	2013-07-15 23:50:47.000000000 -0300
+++ src/xjadeo/mqueue.c	2013-07-15 23:51:27.000000000 -0300
@@ -26,6 +26,7 @@
 #include <sys/stat.h>
 #include <unistd.h>
 #include <stdarg.h>
+#include <fcntl.h>
 
 
 #include <mqueue.h>

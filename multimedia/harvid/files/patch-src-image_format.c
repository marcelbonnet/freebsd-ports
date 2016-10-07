--- src/image_format.c.orig	2013-06-10 18:42:03 UTC
+++ src/image_format.c
@@ -28,7 +28,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#include <jpeglib.h>
+#include "/usr/local/include/jpeglib.h"
 #include <png.h>
 
 #include <dlog.h>

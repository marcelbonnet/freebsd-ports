--- src/xjadeo/display_x11.c.orig	2016-10-12 00:34:15 UTC
+++ src/xjadeo/display_x11.c
@@ -944,6 +944,7 @@ inline void xv_draw_colorkey(void)
 		}
 	}
 }
+void xv_draw_colorkey(void); //http://stackoverflow.com/questions/19068705/undefined-reference-when-calling-inline-function
 
 void render_xv (uint8_t *mybuffer) {
 

--- src/xjadeo/display.h.orig	2016-10-12 00:41:34 UTC
+++ src/xjadeo/display.h
@@ -25,9 +25,12 @@
 
 /* fast memcpy - see mplayer's libvo/aclib_template.c */
 inline void * fast_memcpy(void * to, const void * from, size_t len);
+void * fast_memcpy(void * to, const void * from, size_t len); //http://stackoverflow.com/questions/19068705/undefined-reference-when-calling-inline-function
 
 /* prototypes in display.c */
 inline void stride_memcpy(void * dst, const void * src, int width, int height, int dstStride, int srcStride);
+void stride_memcpy(void * dst, const void * src, int width, int height, int dstStride, int srcStride);//http://stackoverflow.com/questions/19068705/undefined-reference-when-calling-inline-function
+
 void rgb2argb (uint8_t *rgbabuffer, uint8_t *rgbbuffer, int width, int height);
 void rgb2abgr (uint8_t *rgbabuffer, uint8_t *rgbbuffer, int width, int height);
 

--- libs/ardour/session_ltc.cc.orig	2013-05-27 00:57:09.000000000 -0300
+++ libs/ardour/session_ltc.cc	2013-05-27 00:59:43.000000000 -0300
@@ -332,7 +332,7 @@
 
 		double bufrspdiff = rint(newbuflen - oldbuflen);
 
-		if (abs(bufrspdiff) > newbuflen || abs(bufrspdiff) > oldbuflen) {
+		if (fabs(bufrspdiff) > newbuflen || fabs(bufrspdiff) > oldbuflen) {
 			DEBUG_TRACE (DEBUG::LTC, "LTC TX2: resampling buffer would destroy information.\n");
 			ltc_tx_reset();
 			poff = 0;

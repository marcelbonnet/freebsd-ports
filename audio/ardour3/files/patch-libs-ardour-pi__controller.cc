--- libs/ardour/pi_controller.cc.orig	2013-05-27 00:56:51.000000000 -0300
+++ libs/ardour/pi_controller.cc	2013-05-27 00:58:56.000000000 -0300
@@ -170,7 +170,7 @@
 		speed = fine;
 	    }
 
-	    if (abs(chasetime-slavetime) > pos_threshold) {
+	    if (fabs(chasetime-slavetime) > pos_threshold) {
 		pic->reset( crude );
 		speed = crude;
 		want_locate_val = chasetime;

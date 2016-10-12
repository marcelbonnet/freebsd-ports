--- libs/ardour/mtc_slave.cc.orig	2013-05-27 00:56:46.000000000 -0300
+++ libs/ardour/mtc_slave.cc	2013-05-27 00:58:21.000000000 -0300
@@ -706,7 +706,7 @@
 		snprintf(delta, sizeof(delta), "\u2012\u2012\u2012\u2012");
 	} else {
 		snprintf(delta, sizeof(delta), "\u0394<span foreground=\"green\" face=\"monospace\" >%s%s%" PRIi64 "</span>sm",
-				LEADINGZERO(abs(current_delta)), PLUSMINUS(-current_delta), abs(current_delta));
+				LEADINGZERO(fabs(current_delta)), PLUSMINUS(-current_delta), fabs(current_delta));
 	}
 	return std::string(delta);
 }

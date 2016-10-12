--- libs/ardour/ltc_slave.cc.orig	2013-05-27 00:32:05.000000000 -0300
+++ libs/ardour/ltc_slave.cc	2013-05-27 00:33:33.000000000 -0300
@@ -476,7 +476,7 @@
 		delayedlocked = 0;
 	}
 
-	if (abs(now - last_timestamp) > FLYWHEEL_TIMEOUT) {
+	if (fabs(now - last_timestamp) > FLYWHEEL_TIMEOUT) {
 		DEBUG_TRACE (DEBUG::LTC, "flywheel timeout\n");
 		reset();
 		speed = 0;
@@ -591,7 +591,7 @@
 		snprintf(delta, sizeof(delta), _("flywheel"));
 	} else {
 		snprintf(delta, sizeof(delta), "\u0394<span foreground=\"green\" face=\"monospace\" >%s%s%" PRIi64 "</span>sm",
-				LEADINGZERO(abs(current_delta)), PLUSMINUS(-current_delta), abs(current_delta));
+				LEADINGZERO(fabs(current_delta)), PLUSMINUS(-current_delta), fabs(current_delta));
 	}
 	return std::string(delta);
 }

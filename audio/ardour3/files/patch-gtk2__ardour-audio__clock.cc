--- gtk2_ardour/audio_clock.cc.orig	2013-05-29 12:39:00.000000000 -0300
+++ gtk2_ardour/audio_clock.cc	2013-05-29 12:40:15.000000000 -0300
@@ -1952,7 +1952,7 @@
 		error << string_compose (_("programming error: %1 %2"), "badly formatted timecode clock string", str) << endmsg;
 		return 0;
 	}
-	TC.hours = abs(hours);
+	TC.hours = fabs(hours);
 	TC.rate = _session->timecode_frames_per_second();
 	TC.drop= _session->timecode_drop_frames();
 

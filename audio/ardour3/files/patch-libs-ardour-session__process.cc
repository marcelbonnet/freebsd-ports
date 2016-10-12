--- libs/ardour/session_process.cc.orig	2013-05-27 00:57:42.000000000 -0300
+++ libs/ardour/session_process.cc	2013-05-27 01:00:06.000000000 -0300
@@ -398,7 +398,7 @@
 			if (this_event && this_event->action_frame <= end_frame && this_event->action_frame >= _transport_frame) {
 				/* this isn't quite right for reverse play */
 				frames_moved = (framecnt_t) (this_event->action_frame - _transport_frame);
-				this_nframes = abs (floor(frames_moved / _transport_speed));
+				this_nframes = fabs (floor(frames_moved / _transport_speed));
 			}
 
 			if (this_nframes) {
@@ -589,7 +589,7 @@
 			}
 
 #if 1
-			if (!actively_recording() && (framecnt_t) abs(average_slave_delta) > _slave->resolution()) {
+			if (!actively_recording() && (framecnt_t) fabs(average_slave_delta) > _slave->resolution()) {
 				cerr << "average slave delta greater than slave resolution (" << _slave->resolution() << "), going to silent motion\n";
 				goto silent_motion;
 			}
@@ -634,7 +634,7 @@
 		average_slave_delta /= (int32_t) delta_accumulator_size;
 		if (average_slave_delta < 0L) {
 			average_dir = -1;
-			average_slave_delta = abs(average_slave_delta);
+			average_slave_delta = fabs(average_slave_delta);
 		} else {
 			average_dir = 1;
 		}

--- gtk2_ardour/editor_drag.cc.orig	2013-05-29 12:39:26.000000000 -0300
+++ gtk2_ardour/editor_drag.cc	2013-05-29 12:41:23.000000000 -0300
@@ -1666,7 +1666,7 @@
 
 	char buf[128];
 	Timecode::Time timecode;
-	_editor->session()->sample_to_timecode(abs(_startdrag_video_offset), timecode, true /* use_offset */, false /* use_subframes */ );
+	_editor->session()->sample_to_timecode(fabs(_startdrag_video_offset), timecode, true /* use_offset */, false /* use_subframes */ );
 	snprintf (buf, sizeof (buf), "Video Start:\n%c%02" PRId32 ":%02" PRId32 ":%02" PRId32 ":%02" PRId32, (_startdrag_video_offset<0?'-':' '), timecode.hours, timecode.minutes, timecode.seconds, timecode.frames);
 	_editor->verbose_cursor()->set(buf, event->button.x + 10, event->button.y + 10);
 	_editor->verbose_cursor()->show ();
@@ -1710,8 +1710,8 @@
 	Timecode::Time timecode;
 	Timecode::Time timediff;
 	char buf[128];
-	_editor->session()->sample_to_timecode(abs(offset), timecode, true /* use_offset */, false /* use_subframes */ );
-	_editor->session()->sample_to_timecode(abs(dt), timediff, false /* use_offset */, false /* use_subframes */ );
+	_editor->session()->sample_to_timecode(fabs(offset), timecode, true /* use_offset */, false /* use_subframes */ );
+	_editor->session()->sample_to_timecode(fabs(dt), timediff, false /* use_offset */, false /* use_subframes */ );
 	snprintf (buf, sizeof (buf),
 			"%s\n%c%02" PRId32 ":%02" PRId32 ":%02" PRId32 ":%02" PRId32
 			"\n%s\n%c%02" PRId32 ":%02" PRId32 ":%02" PRId32 ":%02" PRId32

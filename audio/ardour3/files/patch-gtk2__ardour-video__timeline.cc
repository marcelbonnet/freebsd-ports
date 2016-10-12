--- gtk2_ardour/video_timeline.cc.orig	2013-05-29 12:38:34.000000000 -0300
+++ gtk2_ardour/video_timeline.cc	2013-05-29 12:39:51.000000000 -0300
@@ -271,7 +271,7 @@
 	if (vfn==0) cut=0;
 	for (VideoFrames::iterator i = video_frames.begin(); i != video_frames.end(); ++i) {
 		VideoImageFrame *frame = (*i);
-		if (abs(frame->get_video_frame_number()-vfn)<=cut
+		if (fabs(frame->get_video_frame_number()-vfn)<=cut
 		    && frame->get_rightend() == rightend) { return frame; }
 	}
 	return 0;

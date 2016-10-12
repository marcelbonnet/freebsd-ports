--- libs/midi++2/midi++/ipmidi_port.h.orig	2013-05-25 07:23:04.000000000 -0300
+++ libs/midi++2/midi++/ipmidi_port.h	2013-05-25 07:23:33.000000000 -0300
@@ -23,7 +23,7 @@
 #include <iostream>
 #if defined(WIN32)
 #include <winsock.h>
-#elif defined(__FREE_BSD__)
+#elif defined(__FreeBSD__)
 #include <netinet/in.h>
 #include <sys/socket.h>
 #include <sys/_sockaddr_storage.h>

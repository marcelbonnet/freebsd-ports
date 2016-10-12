--- src/xjadeo/ltc-jack.c.orig	2016-10-11 23:41:52 UTC
+++ src/xjadeo/ltc-jack.c
@@ -16,7 +16,7 @@
  * along with this program; if not, write to the Free Software Foundation,
  * Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
-
+typedef int clockid_t;
 #ifdef HAVE_CONFIG_H
 # include <config.h>
 #endif

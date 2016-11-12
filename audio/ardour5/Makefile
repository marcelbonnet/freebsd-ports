# Created by: Marcel Bonnet <marcelbonnet@gmail.com>
# $FreeBSD$

PORTNAME=	ardour5
PORTVERSION=	5.3
CATEGORIES=	audio
DISTNAME=	ardour-distfiles-${PORTVERSION}

MAINTAINER=	marcelbonnet@gmail.com
COMMENT=	Multitrack audio recording and editing

LICENSE=		GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	librubberband.so.2:audio/rubberband \
		libaubio.so:audio/aubio \
		liblrdf.so:textproc/liblrdf \
		libsamplerate.so:audio/libsamplerate \
		liblilv-0.so:audio/lilv-0 \
		libsuil-0.so:audio/suil-0 \
		libserd-0.so:textproc/serd-0 \
		libsord-0.so:textproc/sord-0 \
		libsratom-0.so:textproc/sratom-0 \
		libogg.so:audio/libogg \
		libFLAC.so:audio/flac \
		libjack.so:audio/jack \
		libreadline.so:devel/readline
LIB_DEPENDS+=libcurl.so:ftp/curl
LIB_DEPENDS+=libfftw3f.so:math/fftw3-float
LIB_DEPENDS+=libfontconfig.so:x11-fonts/fontconfig
LIB_DEPENDS+=libfreetype.so:print/freetype2
LIB_DEPENDS+=liblo.so:audio/liblo
LIB_DEPENDS+=libsndfile.so:audio/libsndfile
LIB_DEPENDS+=libtag.so:audio/taglib
LIB_DEPENDS+=libvamp-hostsdk.so:audio/vamp-plugin-sdk
LIB_DEPENDS+=libvamp-sdk.so:audio/vamp-plugin-sdk
BUILD_DEPENDS=	lv2>0:audio/lv2
RUN_DEPENDS=	${LOCALBASE}/include/boost/version.hpp:devel/boost-libs \
		lv2>0:audio/lv2

USE_GITHUB=	yes
GH_ACCOUNT=	marcelbonnet
GH_PROJECT=	ardour-distfiles
GH_TAGNAME=	${PORTVERSION}
USES=		waf pkgconfig python:build tar:bzip2 gettext
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}
USE_GNOME=	gtk20 libxslt libgnomecanvas intltool
USE_GNOME+=atkmm
USE_GNOME+=cairo
USE_GNOME+=cairomm
USE_GNOME+=gdkpixbuf2
USE_GNOME+=glibmm
USE_GNOME+=gtkmm24
USE_GNOME+=libsigc++20
USE_GNOME+=pangomm
USE_XORG+=x11
MAKE_JOBS_SAFE=	yes
PATCH_STRIP=	-p1
CONFIGURE_ARGS=	--mandir=${WRKSRC} \
		--prefix=${STAGEDIR}${PREFIX} \
		--also-include="${LOCALBASE}/include" \
		--dist-target=${DIST_TARGET}

LDFLAGS+=	-L${LOCALBASE}/lib -lexecinfo

PLIST_SUB=	DISTVERSION=${DISTVERSION}
CFLAGS+=	-I${LOCALBASE}/include -I/usr/include
CXXFLAGS+=	-I${LOCALBASE}/include -I/usr/include
CONFIGURE_ENV+=	CC=${CC} CXX=${CXX} \
		LINKFLAGS="${LDFLAGS}"

OPTIONS_DEFINE=		DEBUG

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--debug
.endif

CFLAGS:=	${CFLAGS:N-fno-strict-aliasing}

post-patch:
	${CP} ${FILESDIR}/revision.cc ${WRKSRC}/libs/ardour
	${REINPLACE_CMD} "s|VERSAO|${PORTVERSION}|" ${WRKSRC}/libs/ardour/revision.cc
	${REINPLACE_CMD} "s|_FBSD_MAJOR_|${PORTVERSION:C/([0-9])\.([0-9])/\1/}|" ${WRKSRC}/wscript
	${REINPLACE_CMD} "s|_FBSD_MINOR_|${PORTVERSION:C/([0-9])\.([0-9])/\2/}|" ${WRKSRC}/wscript
	${REINPLACE_CMD} "s|_FBSD_REVISION_|${PORTREVISION}|" ${WRKSRC}/wscript

do-configure:
	(cd ${WRKSRC} && ${CONFIGURE_ENV} ${WAF_CMD} configure ${CONFIGURE_ARGS})

do-build:
	(cd ${WRKSRC} && ${WAF_CMD} build)

post-build:
	(cd ${WRKSRC} && ${WAF_CMD} i18n)

do-install:
	${INSTALL_DATA} ${FILESDIR}/ardour5.desktop ${STAGEDIR}${PREFIX}/share/applications/
	${INSTALL_SCRIPT} ${WRKSRC}/build/gtk2_ardour/ardour5 ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/build/tools/luadevel/ardour5-lua ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/ardour.1 ${STAGEDIR}${PREFIX}/man/man1/
	${GZIP_CMD} ${STAGEDIR}${PREFIX}/man/man1/ardour.1
	(cd ${WRKSRC} && ${WAF_CMD} --destdir=${STAGEDIR}  install)
	(cd ${WRKSRC}/gtk2_ardour/resources && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/${PORTNAME}/resources )
	(cd ${WRKSRC}/gtk2_ardour/themes && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/${PORTNAME}/themes )
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ardour5/engines/libclearlooks.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ardour5/sanityCheck
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ardour5/libqmdsp.so.0.0.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ardour5/vamp/libardourvampplugins.so.0.0.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ardour5/libpbd.so.4.1.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ardour5/libevoral.so.0.0.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ardour5/libtimecode.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ardour5/libaudiographer.so.0.0.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ardour5/LV2/reasonablesynth.lv2/reasonablesynth.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ardour5/LV2/a-comp.lv2/a-comp.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ardour5/LV2/a-delay.lv2/a-delay.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ardour5/LV2/a-eq.lv2/a-eq.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ardour5/LV2/a-reverb.lv2/a-reverb.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ardour5/LV2/a-fluidsynth.lv2/a-fluidsynth.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ardour5/ardour-vst-scanner
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ardour5/ardour-exec-wrapper
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ardour5/libmidipp.so.4.1.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ardour5/libardour.so.3.0.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ardour5/libptformat.so.0.0.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ardour5/backends/libjack_audiobackend.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ardour5/panners/libpan2in2out.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ardour5/panners/libpan1in2out.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ardour5/panners/libpanbalance.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ardour5/panners/libpanvbap.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ardour5/libgtkmm2ext.so.0.8.3
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ardour5/surfaces/libardour_osc.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ardour5/surfaces/libardour_mcp.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ardour5/surfaces/libardour_faderport.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ardour5/surfaces/libardour_generic_midi.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ardour5/libardourcp.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ardour5/luasession
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ardour5/libcanvas.so.0.0.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ardour5/hardour-5.3.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ardour5/ardour-5.3.0
.include <bsd.port.post.mk>

# Created by: Marcel Bonnet <marcelbonnet@gmail.com>
# $FreeBSD$

PORTNAME=	lv2
PORTVERSION=	1.14.0
CATEGORIES=	audio
MASTER_SITES=	http://lv2plug.in/spec/

MAINTAINER=	marcelbonnet@gmail.com
COMMENT=	Extensible audio plugin interface

LICENSE=		ISC
LICENSE_GROUPS=	OSI
LICENSE_NAME=	ISC License (ISC)
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept none

LIB_DEPENDS=	libsndfile.so:audio/libsndfile \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

CONFLICTS=	lv2core-[6]\.[0-9]*

USES=		waf pkgconfig python:build tar:bzip2 gettext-runtime
USE_GNOME=	gtk20 cairo gdkpixbuf2
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes
CONFIGURE_ARGS=	--mandir=${STAGEDIR}${MANPREFIX}/man \
		--prefix=${STAGEDIR}${PREFIX}

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e '/autowaf.build_pc/s|^|#|' ${WRKSRC}/wscript
	@${REINPLACE_CMD} -e 's|{LIBDIR}|{PREFIX}/libdata|' ${WRKSRC}/wscript
	@(cd ${WRKSRC} && ${SED} -e \
		's|@PREFIX@|${PREFIX}| ; \
		 s|@INCLUDEDIR@|${PREFIX}/include| ; \
		 s|@VERSION@|${PORTVERSION}|' < lv2.pc.in > lv2.pc)

do-configure:
	@(cd ${WRKSRC} && ${WAF_CMD} configure ${CONFIGURE_ARGS} --prefix=${STAGEDIR}${PREFIX})
	@${REINPLACE_CMD} -e 's|{LIBDIR}|{PREFIX}/libdata|' ${WRKSRC}/.waf*/waflib/TaskGen.py

do-build:
	@(cd ${WRKSRC} && ${WAF_CMD} build )

do-install:
	@(cd ${WRKSRC} && ${WAF_CMD} install)
#	Copy and sed lv2.pc and lv2core.pc after install, otherwise they will be replaced by waf script
	@(cd ${WRKSRC} && ${INSTALL_DATA} ${WRKSRC}/lv2.pc \
	    ${STAGEDIR}${PREFIX}/libdata/pkgconfig)
	@(cd ${WRKSRC} && ${INSTALL_DATA} ${WRKSRC}/build/lv2/lv2plug.in/ns/lv2core/lv2core.pc \
	    ${STAGEDIR}${PREFIX}/libdata/pkgconfig)
	${REINPLACE_CMD} "s,^prefix=.*,prefix=${PREFIX}," ${STAGEDIR}${PREFIX}/libdata/pkgconfig/lv2.pc
	${REINPLACE_CMD} "s,^includedir=.*,includedir=${PREFIX}/include," ${STAGEDIR}${PREFIX}/libdata/pkgconfig/lv2.pc
	${RM} ${STAGEDIR}${PREFIX}/libdata/pkgconfig/lv2.pc.bak
	${REINPLACE_CMD} "s,^prefix=.*,prefix=${PREFIX}," ${STAGEDIR}${PREFIX}/libdata/pkgconfig/lv2core.pc
	${RM} ${STAGEDIR}${PREFIX}/libdata/pkgconfig/lv2core.pc.bak
#	this file is created by the upstream installer in the wrong place:
	${RM} ${STAGEDIR}${PREFIX}/lib/pkgconfig/lv2core.pc
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/eg-amp.lv2/amp.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/eg-fifths.lv2/fifths.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/eg-metro.lv2/metro.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/eg-midigate.lv2/midigate.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/eg-params.lv2/params.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/eg-sampler.lv2/sampler.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/eg-sampler.lv2/sampler_ui.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/eg-scope.lv2/examploscope.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/eg-scope.lv2/examploscope_ui.so

.include <bsd.port.post.mk>

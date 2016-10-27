# Created by: Marcel Bonnet <marcelbonnet@gmail.com>
# $FreeBSD$

PORTNAME=	lilv
PORTVERSION=	0.16.0
CATEGORIES=	audio
MASTER_SITES=	http://download.drobilla.net/
PKGNAMESUFFIX=	-0

MAINTAINER=	marcelbonnet@gmail.com
COMMENT=	LV2 Plugin Support Library

LICENSE=		ISC
LICENSE_GROUPS=	OSI
LICENSE_NAME=	ISC License (ISC)
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept none

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libserd-0.so:textproc/serd-0 \
		libsord-0.so:textproc/sord-0 \
		libsratom-0.so:textproc/sratom-0
RUN_DEPENDS=	lv2>0:audio/lv2

USES=		waf pkgconfig python:build tar:bzip2
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes
PATCH_STRIP=	-p1
CONFIGURE_ARGS=	--mandir=${STAGEDIR}${MANPREFIX}/man \
		--prefix=${STAGEDIR}${PREFIX}

do-configure:
	@(cd ${WRKSRC} && ${WAF_CMD} configure ${CONFIGURE_ARGS} --prefix=${STAGEDIR}${PREFIX})

do-build:
	@(cd ${WRKSRC} && ${WAF_CMD} build )
	@${REINPLACE_CMD} "s|bld.env\\['LIBDIR'\\],'pkgconfig'|bld.env\\['PREFIX'\\],'${WRKSRC}/libdata/pkgconfig'|" ${WRKSRC}/.waf-*/waflib/extras/autowaf.py
	@${RM} ${WRKSRC}/.waf-*/waflib/extras/autowaf.pyc
	@${RM} ${WRKSRC}/.waf-*/waflib/extras/autowaf.pyc

do-install:
	@(cd ${WRKSRC} && ${WAF_CMD} install)
	@(cd ${WRKSRC} && ${INSTALL_DATA} ${WRKSRC}/build/lilv-0.pc \
	    ${STAGEDIR}${PREFIX}/libdata/pkgconfig)
	${REINPLACE_CMD} "s,^prefix=.*,prefix=${PREFIX}," ${STAGEDIR}${PREFIX}/libdata/pkgconfig/lilv-0.pc
	${RM} ${STAGEDIR}${PREFIX}/libdata/pkgconfig/lilv-0.pc.bak
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lv2bench
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lilv-bench
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lv2info
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lv2ls
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/liblilv-0.so.0.16.0

.include <bsd.port.mk>

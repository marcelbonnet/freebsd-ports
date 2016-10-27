# Created by: Marcel Bonnet <marcelbonnet@gmail.com>
# $FreeBSD$

PORTNAME=	sratom
PORTVERSION=	0.4.0
CATEGORIES=	textproc
MASTER_SITES=	http://download.drobilla.net/
PKGNAMESUFFIX=	-0

MAINTAINER=	marcelbonnet@gmail.com
COMMENT=	Library for serialising LV2 atoms to/from RDF Turtle syntax

LICENSE=		ISC
LICENSE_GROUPS=	OSI
LICENSE_NAME=	ISC License (ISC)
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept none

BUILD_DEPENDS=	${LOCALBASE}/include/lv2.h:audio/lv2
LIB_DEPENDS=	libserd-0.so:textproc/serd-0 \
		libsord-0.so:textproc/sord-0

USES=		waf pkgconfig python:build tar:bzip2
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes
CONFIGURE_ARGS=	--mandir=${STAGEDIR}${MANPREFIX}/man \
		--prefix=${STAGEDIR}${PREFIX}

do-configure:
	@(cd ${WRKSRC} && ${WAF_CMD} configure ${CONFIGURE_ARGS} --prefix=${STAGEDIR}${PREFIX})

do-build:
	@(cd ${WRKSRC} && ${WAF_CMD} build )
	@${REINPLACE_CMD} "s|bld.env\\['LIBDIR'\\],'pkgconfig'|bld.env\\['PREFIX'\\],'${WRKSRC}/libdata/pkgconfig'|" ${WRKSRC}/.waf-*/waflib/extras/autowaf.py
	@${RM} ${WRKSRC}/.waf-*/waflib/extras/autowaf.pyc

do-install:
	@(cd ${WRKSRC}/build && ${INSTALL_DATA} ${WRKSRC}/build/sratom-0.pc \
	    ${STAGEDIR}${PREFIX}/libdata/pkgconfig)
	@${REINPLACE_CMD} "s,^prefix=.*,prefix=${PREFIX}," ${STAGEDIR}${PREFIX}/libdata/pkgconfig/sratom-0.pc
	@${RM} ${STAGEDIR}${PREFIX}/libdata/pkgconfig/sratom-0.pc.bak
	@(cd ${WRKSRC} && ${WAF_CMD} install)
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsratom-0.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsratom-0.so.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsratom-0.so.0.4.0

.include <bsd.port.mk>

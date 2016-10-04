# Created by: Marcel Bonnet <marcelbonnet@gmail.com>
# $FreeBSD$

PORTNAME=	sord
PORTVERSION=	0.10.4
CATEGORIES=	textproc
MASTER_SITES=	http://download.drobilla.net/
PKGNAMESUFFIX=	-0

MAINTAINER=	marcelbonnet@gmail.com
COMMENT=	Lightweight C library for storing RDF data in memory

LICENSE=        ISC
LICENSE_GROUPS= OSI
LICENSE_NAME=   ISC License (ISC)
LICENSE_FILE=   ${WRKSRC}/LICENSE
LICENSE_PERMS=  dist-mirror dist-sell pkg-mirror pkg-sell auto-accept none

LIB_DEPENDS=	libserd-0.so:textproc/serd-0 \
		libpcre.so:devel/pcre

USES=		waf pkgconfig python:build tar:bzip2
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes
CONFIGURE_ARGS=	--mandir=${STAGEDIR}${MANPREFIX}/man \
		--prefix=${STAGEDIR}${PREFIX}

post-extract:
	 ${CP} ${FILESDIR}/patch-LICENSE ${WRKSRC}/LICENSE

do-configure:
	@(cd ${WRKSRC} && ${WAF_CMD} configure ${CONFIGURE_ARGS} --prefix=${STAGEDIR}${PREFIX})

do-build:
	@(cd ${WRKSRC} && ${WAF_CMD} build )
	@${REINPLACE_CMD} "s|bld.env\\['LIBDIR'\\],'pkgconfig'|bld.env\\['PREFIX'\\],'${WRKSRC}/libdata/pkgconfig'|" ${WRKSRC}/.waf-*/waflib/extras/autowaf.py
	@${RM} ${WRKSRC}/.waf-*/waflib/extras/autowaf.pyc

do-install:
	@(cd ${WRKSRC}/build && ${INSTALL_DATA} sord-0.pc \
	    ${STAGEDIR}${PREFIX}/libdata/pkgconfig)
	@${REINPLACE_CMD} "s,^prefix=.*,prefix=${PREFIX}," ${STAGEDIR}${PREFIX}/libdata/pkgconfig/sord-0.pc
	@${RM} ${STAGEDIR}${PREFIX}/libdata/pkgconfig/sord-0.pc.bak
	@(cd ${WRKSRC} && ${WAF_CMD} install)
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/sordi
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/sord_validate
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsord-0.so.0.10.4

.include <bsd.port.mk>

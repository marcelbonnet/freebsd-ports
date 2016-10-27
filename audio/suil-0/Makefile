# Created by: Marcel Bonnet <marcelbonnet@gmail.com>
# $FreeBSD$

PORTNAME=	suil
PORTVERSION=	0.6.6
CATEGORIES=	audio
MASTER_SITES=	http://download.drobilla.net/
PKGNAMESUFFIX=	-0

MAINTAINER=	marcelbonnet@gmail.com
COMMENT=	Lightweight C library for loading and wrapping LV2 plugin UIs

LICENSE=		ISC
LICENSE_GROUPS=	OSI
LICENSE_NAME=	ISC License (ISC)
LICENSE_FILE=	$WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept none

BUILD_DEPENDS=	lv2>0:audio/lv2
RUN_DEPENDS=	lv2>0:audio/lv2

USES=		waf pkgconfig python:build tar:bzip2
USE_LDCONFIG=	${PREFIX}/lib ${PREFIX}/lib/suil${PKGNAMESUFFIX}
USE_GNOME=	gtk20
MAKE_JOBS_SAFE=	yes
PATCH_STRIP=	-p1
CONFIGURE_ARGS=	--mandir=${STAGEDIR}${MANPREFIX}/man \
		--prefix=${STAGEDIR}${PREFIX}

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e '116 d' ${WRKSRC}/wscript
	@${REINPLACE_CMD} "s|conf.env.LIBDIR|'${PREFIX}/lib'|" ${WRKSRC}/wscript

do-configure:
	@(cd ${WRKSRC} && ${WAF_CMD} configure ${CONFIGURE_ARGS} --prefix=${STAGEDIR}${PREFIX})

do-build:
	@${REINPLACE_CMD} "s|bld.env\\['LIBDIR'\\],'pkgconfig'|bld.env\\['PREFIX'\\],'libdata/pkgconfig'|" ${WRKSRC}/.waf-*/waflib/extras/autowaf.py
	@(cd ${WRKSRC} && ${WAF_CMD} build)

do-install:
	@(cd ${WRKSRC} && ${WAF_CMD} install)
	@(cd ${WRKSRC} && ${INSTALL_DATA} ${WRKSRC}/build/suil-0.pc \
	    ${STAGEDIR}${PREFIX}/libdata/pkgconfig)
	${REINPLACE_CMD} "s,^prefix=.*,prefix=${PREFIX}," ${STAGEDIR}${PREFIX}/libdata/pkgconfig/suil-0.pc
	${REINPLACE_CMD} "s,^exec_prefix=.*,exec_prefix=${PREFIX}," ${STAGEDIR}${PREFIX}/libdata/pkgconfig/suil-0.pc
	${REINPLACE_CMD} "s,^libdir=.*,libdir=${PREFIX}/lib," ${STAGEDIR}${PREFIX}/libdata/pkgconfig/suil-0.pc
	${REINPLACE_CMD} "s,^includedir=.*,includedir=${PREFIX}/include," ${STAGEDIR}${PREFIX}/libdata/pkgconfig/suil-0.pc
	${RM} ${STAGEDIR}${PREFIX}/libdata/pkgconfig/suil-0.pc.bak
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsuil-0.so.0.6.6
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/suil-0/libsuil_qt4_in_gtk2.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/suil-0/libsuil_gtk2_in_qt4.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/suil-0/libsuil_x11_in_qt4.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/suil-0/libsuil_x11_in_gtk2.so

.include <bsd.port.post.mk>

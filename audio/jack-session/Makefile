# Created by: Marcel Bonnet <marcelbonnet@gmail.com>
# $FreeBSD$

PORTNAME=	jack-session
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://github.com/marcelbonnet/.../freebsd/ports/distfiles/

MAINTAINER=	marcelbonnet@gmail.com
COMMENT=	A tool for saving and restoring all jack connections

LIB_DEPENDS=	libjack.so:audio/jack

#LICENSE=	BSD
USES=	tar:bzip2
MAKE_JOBS_SAFE=	yes
MANCOMPRESSED=	yes
MAN8=		jack-session.8

PLIST_FILES=	bin/jack-session

MAKE_ARGS:=" HAVE_MAN=YES"

.include <bsd.port.mk>

# Created by: Marcel Bonnet <marcelbonnet@gmail.com>
# $FreeBSD$

PORTNAME=	harvid
PORTVERSION=	0.7.3
CATEGORIES=	multimedia

MAINTAINER=	marcelbonnet@gmail.com
COMMENT=	Extracts still images from movies and serves them via HTTP

LICENSE=		GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${LOCALBASE}/bin/ffmpeg:multimedia/ffmpeg \
		${LOCALBASE}/bin/ffprobe:multimedia/ffmpeg
LIB_DEPENDS=	libpng16.so:graphics/png

USE_GITHUB=	yes
GH_ACCOUNT=	x42
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	v${PORTVERSION}
USES=	gmake jpeg
MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ARGS=	--mandir=${STAGEDIR}${MANPREFIX}/man \
		--prefix=${STAGEDIR}${PREFIX}

.include <bsd.port.pre.mk>

post-install:
	${LN} -s ${PREFIX}/bin/ffmpeg ${STAGEDIR}${PREFIX}/bin/ffmpeg_harvid
	${LN} -s ${PREFIX}/bin/ffprobe ${STAGEDIR}${PREFIX}/bin/ffprobe_harvid
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/harvid

.include <bsd.port.post.mk>

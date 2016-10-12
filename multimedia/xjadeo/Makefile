# Created by: Marcel Bonnet <marcelbonnet@gmail.com>
# $FreeBSD$

PORTNAME=	xjadeo
PORTVERSION=	0.7.4
CATEGORIES=	multimedia

MAINTAINER=	marcelbonnet@gmail.com
COMMENT=	Video player in sync with external source (MTC, LTC, JACK-transport)

LICENSE=		GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjack.so:audio/jack \
		libswscale.so:multimedia/ffmpeg \
		libImlib2.so:graphics/imlib2 \
		libX11.so:x11/libX11 \
		libXau.so:x11/libXau \
		libXdmcp.so:x11/libXdmcp \
		libXext.so:x11/libXext \
		libXpm.so:x11/libXpm \
		libXv.so:x11/libXv \
		libaa.so:graphics/aalib \
		libavcodec.so:multimedia/ffmpeg \
		libavformat.so:multimedia/ffmpeg \
		libavutil.so:multimedia/ffmpeg \
		libfreetype.so:print/freetype2 \
		libiconv.so:converters/libiconv \
		libmp3lame.so:audio/lame \
		libogg.so:audio/libogg \
		liborc-0.4.so:devel/orc \
		libpthread-stubs.so:devel/libpthread-stubs \
		libschroedinger-1.0.so:multimedia/schroedinger \
		libtheoradec.so:multimedia/libtheora \
		libtheoraenc.so:multimedia/libtheora \
		libvorbis.so:audio/libvorbis \
		libvorbisenc.so:audio/libvorbis \
		libvpx.so:multimedia/libvpx \
		libx264.so:multimedia/x264 \
		libxcb.so:x11/libxcb \
		libxvidcore.so:multimedia/xvid \
		liblo.so:audio/liblo

USE_GITHUB=	yes
GH_ACCOUNT=	x42
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	${PORTVERSION}
USES=	gmake iconv
USE_SDL=	sdl
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=yes
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libavutil \
		-I${LOCALBASE}/include/libavcodec \
		-I${LOCALBASE}/include/libavformat \
		-I${LOCALBASE}/include/libswscale
CONFIGURE_ARGS=	--disable-alsamidi \
		--prefix=${STAGEDIR}${PREFIX}

.include <bsd.port.pre.mk>

pre-install:
	${CP} ${WRKSRC}/doc/xjadeorc ${STAGEDIR}${PREFIX}/etc/xjadeorc.sample

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xjadeo
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xjremote

.include <bsd.port.post.mk>

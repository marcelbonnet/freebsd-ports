# Created by: <trasz@FreeBSD.org>
# $FreeBSD: branches/2016Q4/audio/calf/Makefile 412344 2016-04-01 13:29:15Z mat $

PORTNAME=	calf
PORTVERSION=	0.0.60
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://calf-studio-gear.org/files/

MAINTAINER=	marcelbonnet@gmail.com
COMMENT=	Audio plug-in pack for LV2 and JACK environments

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth \
		libjack.so:audio/jack \
		libexpat.so:textproc/expat2
LIB_DEPENDS+=libfontconfig.so:x11-fonts/fontconfig
LIB_DEPENDS+=libfreetype.so:print/freetype2

USES=		autoreconf compiler:c++11-lang gmake libtool pkgconfig gettext-runtime cairo
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		DOCS LASH LV2
OPTIONS_DEFAULT=	LASH LV2
OPTIONS_SUB=		yes

LASH_LIB_DEPENDS=	liblash.so:audio/lash
LASH_CONFIGURE_WITH=	lash
LV2_DESC=		LV2 audio plugin
LV2_BUILD_DEPENDS=	lv2>0:audio/lv2
LV2_RUN_DEPENDS=	lv2>0:audio/lv2
LV2_CONFIGURE_WITH=	lv2

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
CXXFLAGS+=	-finline-limit=80 -finline-functions -finline-functions-called-once
.endif

post-patch:
	@${REINPLACE_CMD} '/<malloc.h>/d' \
		${WRKSRC}/src/ctl_knob.cpp ${WRKSRC}/src/ctl_tube.cpp

.include <bsd.port.post.mk>

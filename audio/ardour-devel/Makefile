# Created by: Marcel Bonnet <marcelbonnet@gmail.com>
# $FreeBSD$

PORTNAME=	ardour-devel
PORTVERSION=	5.3
CATEGORIES=	audio
DISTNAME= ardour5-${PORTVERSION}

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
		libjack.so:audio/jack
BUILD_DEPENDS=	lv2>0:audio/lv2
RUN_DEPENDS=	${LOCALBASE}/include/boost/version.hpp:devel/boost-libs \
		lv2>0:audio/lv2

USE_GITHUB=	yes
GH_ACCOUNT=	marcelbonnet
GH_PROJECT=	ardour
GH_TAGNAME=	devel-${PORTVERSION}
USES=		waf pkgconfig python:build tar:bzip2 gettext
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}
USE_GNOME=	gtk20 libxslt libgnomecanvas intltool
MAKE_JOBS_SAFE=	yes
PATCH_STRIP=	-p1
CONFIGURE_ARGS=	--mandir=${STAGEDIR}${MANPREFIX}/man \
		--prefix=${STAGEDIR}${PREFIX} \
		--also-include="${LOCALBASE}/include" \
		--dist-target=${DIST_TARGET}

LDFLAGS+=	-L${LOCALBASE}/lib -lexecinfo

PLIST_SUB=	DISTVERSION=${DISTVERSION}
CFLAGS+=	-I${LOCALBASE}/include -I/usr/include
CXXFLAGS+=	-I${LOCALBASE}/include -I/usr/include
CONFIGURE_ENV+=	CC=${CC} CXX=${CXX} \
		LINKFLAGS="${LDFLAGS}"

OPTIONS_DEFINE=		DEBUG VST

VST_DESC=		Enable VST plugins support

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--debug
.endif

.if ${PORT_OPTIONS:MVST}
.if ${ARCH} == "x86_64"
IGNORE=		you cannot use VST plugins with a 64 bit host
.endif
CONFIGURE_ARGS+=	--lxvst
BUILD_DEPENDS+=	winegcc:emulators/wine \
		unzip:archivers/unzip \
		gsed:textproc/gsed
LIB_DEPENDS+=	libwine.so:emulators/wine

PLIST_SUB+=	NO_VST="@comment "
PLIST_SUB+=	VST=""
.else
PLIST_SUB+=	NO_VST=""
PLIST_SUB+=	VST="@comment "
.endif

#.if ${PORT_OPTIONS:MNLS}
USES+=			gettext
#PLIST_SUB+=		NLS=""
#.else
#CONFIGURE_ARGS+=	--disable-nls
#PLIST_SUB+=		NLS="@comment "
#.endif

CFLAGS:=	${CFLAGS:N-fno-strict-aliasing}

post-extract:
	${MV} ${WRKDIR}/ardour ${WRKDIR}/${PKGNAME}

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
	${INSTALL_DATA} ${FILESDIR}/ardour5.desktop ${PREFIX}/share/applications/
	${INSTALL_SCRIPT} ${WRKSRC}/build/gtk2_ardour/ardour5 ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/build/tools/luadevel/ardour5-lua ${PREFIX}/bin/
#	${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}
#	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
#	${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}
#	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
#
#	${INSTALL_DATA} ${WRKSRC}/build/gtk2_ardour/ardour3_ui_dark.rc.pre ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/build/gtk2_ardour/ardour3_ui_light.rc.pre ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/build/gtk2_ardour/ardour3_dark_styles.rc ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/build/gtk2_ardour/ardour3_light_styles.rc ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/build/gtk2_ardour/ardour3_dark_fonts.rc ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/build/gtk2_ardour/ardour3_light_fonts.rc ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/build/gtk2_ardour/ardour3_widgets.rc ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/build/gtk2_ardour/ardour.menus ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/build/gtk2_ardour/mnemonic-us.bindings ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/build/gtk2_ardour/ardour3_ui_dark.rc ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/build/gtk2_ardour/ardour3_ui_light.rc ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/ardour3_ui_default.conf ${PREFIX}/etc/${PORTNAME}/
#	${MKDIR} ${PREFIX}/lib/${PORTNAME}
#	${MKDIR} ${PREFIX}/lib/${PORTNAME}/panners
#	${MKDIR} ${PREFIX}/lib/${PORTNAME}/engines
#	${MKDIR} ${PREFIX}/lib/${PORTNAME}/surfaces
#	${MKDIR} ${PREFIX}/lib/${PORTNAME}/vamp
#	${INSTALL_PROGRAM} ${WRKSRC}/build/gtk2_ardour/ardour-3.3 ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/pbd/libpbd.so ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/ardour/libardour.so ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/midi++2/libmidipp.so ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/evoral/libsmf.so ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/evoral/libevoral.so ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/timecode/libtimecode.so ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/surfaces/control_protocol/libardourcp.so ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/surfaces/generic_midi/libardour_generic_midi.so ${PREFIX}/lib/${PORTNAME}/surfaces/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/surfaces/mackie/libardour_mcp.so ${PREFIX}/lib/${PORTNAME}/surfaces/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/surfaces/osc/libardour_osc.so ${PREFIX}/lib/${PORTNAME}/surfaces/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/vamp-sdk/libvamphost.so ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/vamp-sdk/libvampplugin.so ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/qm-dsp/libqmdsp.so ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/taglib/libtaglib.so ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/libltc/libltc.so ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/rubberband/librubberband.so ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/audiographer/libaudiographer.so ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/gtkmm2ext/libgtkmm2ext.so ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/panners/2in2out/libpan2in2out.so ${PREFIX}/lib/${PORTNAME}/panners/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/panners/1in2out/libpan1in2out.so ${PREFIX}/lib/${PORTNAME}/panners/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/panners/vbap/libpanvbap.so ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/clearlooks-newer/libclearlooks.so ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/pbd/libpbd.so.4 ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/pbd/libpbd.so.4.1.0 ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/vamp-plugins/libardourvampplugins.so ${PREFIX}/lib/${PORTNAME}/vamp/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/vamp-plugins/libardourvampplugins.so.0 ${PREFIX}/lib/${PORTNAME}/vamp/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/vamp-plugins/libardourvampplugins.so.0.0.0 ${PREFIX}/lib/${PORTNAME}/vamp/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/ardour/libardour.so.3 ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/ardour/libardour.so.3.0.0. ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/midi++2/libmidipp.so.4 ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/midi++2/libmidipp.so.4.1.0 ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/evoral/libevoral.so.0 ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/evoral/libevoral.so.0.0.0 ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/timecode/libtimecode.so.0 ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/timecode/libtimecode.so.0.0.0 ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/surfaces/control_protocol/libardourcp.so.4 ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/surfaces/control_protocol/libardourcp.so.4.1.0 ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/surfaces/generic_midi/libardour_generic_midi.so.4 ${PREFIX}/lib/${PORTNAME}/surfaces/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/surfaces/generic_midi/libardour_generic_midi.so.4.1.0 ${PREFIX}/lib/${PORTNAME}/surfaces/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/surfaces/mackie/libardour_mcp.so.4 ${PREFIX}/lib/${PORTNAME}/surfaces/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/surfaces/mackie/libardour_mcp.so.4.1.0 ${PREFIX}/lib/${PORTNAME}/surfaces/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/surfaces/osc/libardour_osc.so.4 ${PREFIX}/lib/${PORTNAME}/surfaces/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/surfaces/osc/libardour_osc.so.4.1.0 ${PREFIX}/lib/${PORTNAME}/surfaces/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/vamp-sdk/libvampplugin.so.0 ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/vamp-sdk/libvampplugin.so.0.0.0 ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/vamp-sdk/libvamphost.so.0 ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/vamp-sdk/libvamphost.so.0.0.0 ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/qm-dsp/libqmdsp.so.0 ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/qm-dsp/libqmdsp.so.0.0.0 ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/taglib/libtaglib.so.0 ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/taglib/libtaglib.so.0.0.0 ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/libltc/libltc.so.1 ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/libltc/libltc.so.1.1.1 ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/rubberband/librubberband.so.4 ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/rubberband/librubberband.so.4.1.0 ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/audiographer/libaudiographer.so.0 ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/audiographer/libaudiographer.so.0.0.0 ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/gtkmm2ext/libgtkmm2ext.so.0 ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/gtkmm2ext/libgtkmm2ext.so.0.8.3 ${PREFIX}/lib/${PORTNAME}/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/panners/2in2out/libpan2in2out.so.1 ${PREFIX}/lib/${PORTNAME}/panners/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/panners/2in2out/libpan2in2out.so.1.0.0 ${PREFIX}/lib/${PORTNAME}/panners/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/panners/1in2out/libpan1in2out.so.1 ${PREFIX}/lib/${PORTNAME}/panners/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/panners/1in2out/libpan1in2out.so.1.0.0 ${PREFIX}/lib/${PORTNAME}/panners/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/panners/vbap/libpanvbap.so.1 ${PREFIX}/lib/${PORTNAME}/panners/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/panners/vbap/libpanvbap.so.1.0.0 ${PREFIX}/lib/${PORTNAME}/panners/
#	${INSTALL_LIB} ${WRKSRC}/build/libs/clearlooks-newer/engines/libclearlooks.so ${PREFIX}/lib/${PORTNAME}/engines/
#	${MKDIR} ${DATADIR}
#	${CP} -R ${WRKSRC}/icons ${DATADIR}/
#	${CP} -R ${WRKSRC}/export ${DATADIR}/
#	${CP} -R ${WRKSRC}/midi_maps ${DATADIR}/
#	${CP} -R ${WRKSRC}/mcp ${DATADIR}/
#	${CP} -R ${WRKSRC}/patchfiles ${DATADIR}/
#	${CP} -R ${WRKSRC}/gtk2_ardour/pixmaps ${DATADIR}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/splash.png ${DATADIR}/
#	${MKDIR} ${PREFIX}/share/applications
#	${INSTALL_DATA} ${FILESDIR}/ardour.desktop ${PREFIX}/share/applications/
#	${CP} -R ${WRKSRC}/gtk2_ardour/pixmaps ${DATADIR}/
#	${CP} -R ${WRKSRC}/gtk2_ardour/icons ${DATADIR}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/ArdourMono.ttf ${DATADIR}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/SAE-de-keypad.bindings.in ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/SAE-de-nokeypad.bindings.in ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/SAE-us-keypad.bindings.in ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/SAE-us-nokeypad.bindings.in ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/arcall ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/ardbg ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/ardbg-scons ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/ardev ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/ardev_common.sh.in ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/ardour-sae.menus ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/ardour.menus.in ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/ardour.sh.in ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/ardour2_ui_dark_sae.rc.in ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/ardour2_ui_light_sae.rc.in ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/ardour3.desktop.in ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/ardour3.xml ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/ardour3_fonts.rc.in ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/ardour3_styles.rc.in ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/ardour3_ui_dark.rc.in ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/ardour3_ui_light.rc.in ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/ardour3_widget_list.rc ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/arldd ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/arprof-scons ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/arval ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/arval-scons ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/au_pluginui.mm ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/cocoacarbon.mm ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/editor.bindings ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/editor_xpms ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/ergonomic-us.bindings.in ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/mixer.bindings ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/mnemonic-us.bindings.in ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/mtest.menus ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/mtest_other.menus ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/mtest_shared.menu ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/step_editing.bindings ${PREFIX}/etc/${PORTNAME}/
#	${INSTALL_DATA} ${WRKSRC}/gtk2_ardour/gtk2_ardour3.pot ${PREFIX}/etc/${PORTNAME}/
#
# garantir instalação do man page ardour.1

.include <bsd.port.post.mk>

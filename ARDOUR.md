# Ardour BSD

This port, named `ardour-devel`, is a fork from Ardour. 

My goal is:

- provide the last possible. portable and maintainable port of Ardour
- not to remove the old and stable port of Ardour audio/ardour
   - yes, it is an old one (version 2), but is quite stable, fast and still a good piece of software
   - it is not a stale port, it stil compiling from source

## Ardour BSD: is now 5.3

Doing...

   - wscript patches ... OK
   - make configure ... OK

Updating this markdown file from ardour 3.3 port ...

Please, check it later.

## My Ardour 3.3 Port

I did a lot of work , staged the old ports but, some things happened wrong:

- a lot of new compiler erros (code style)
- aubio new version (compared to the year 2013) need some changes in header files... 

So, I'm trying to port 5.3 .

# New Lib Depends

This project provides many new ports and updates to existing ports (audio/lv2core).

Now it is possible to have full LV2 power (use of LV2 GUIs for plugins) and the
major features included in Ardour 3 when compared to the previous major release:

- MIDI record and playback (works with FreeBSD + linuxsampler or gigedit or qsampler or calf synth plugins ...)
- LV2 plugins with its GUIs (improves audio/calf plugins), see http://lv2plug.in/
- many other new features introduced in Ardour 3

Ardour 2 is not considered old fashion, nor should be droped. Use it if:

- you don't need Ardour 3 new features
- if you have Ardour 2.x projects using EQ automations (in these cases the project won't be compatible with Ardour 3.x)

## Staged

Ordered by build dependency:

- textproc/serd-0
- textproc/sord-0
- audio/lv2 (conflicts with lv2core)
- textproc/sratom-0
- audio/lilv-0
- audio/suil-0
- multimedia/harvid
- multimedia/xjadeo

# Desired Changes to Existing Ports

- audio/slv2
   The author rewrote it as a new library (audio/lilv-0)
- audio/lv2core
   This port should be replaced by the new port audio/lv2 (the whole LV2)
- audio/calf
   Change depency from audio/lv2-core to audio/lv2 (allowing use of LV2 GUIs)

# TODO

- MASTER_SITES ... ok


## History

First port: Ardour 3.3 , july/2013.

I gave up for a while... many things were going around those years, but I'm back.

Here some references (I like to keep 'em for myself), but may interest:

Started playing around with Ardour 3.0 Beta 5:

- 11 Dec 2012 ardour-3.0-beta5-r13072.tar.bz2
- 11 Dec 2012 ardour-3r13630.tar.bz2
- 8 May 2013 ardour3-3.1.tar.bz2
- 26 Jul 2013 ardour3-3.3.tar.bz2

*My Ardour Contrib*

- #0005251 Send patches merged into upstream. http://tracker.ardour.org/view.php?id=5251
- #0005548 got a help with clang code style (marged) http://tracker.ardour.org/view.php?id=5548

*FreeBSD Related PRs*

- 180171 send the six new dependencies, https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=180171
- 180602 send a new helper port (xjadeo jack synced video player)
- 180987 send audio/ardour3

- Announcement, FreeBSD Forums : https://forums.freebsd.org/threads/40040/#post-224960
- FreeBSD Multimedia Mailing List : https://lists.freebsd.org/pipermail/freebsd-multimedia/2013-July/
    - Announcement: https://lists.freebsd.org/pipermail/freebsd-multimedia/2013-July/014136.html

# My Flight Check

## Ports que precisam the Maintainer:

qsynth-0.4.1
qsampler-0.4.0
qjackctl-0.4.2
aubio-0.4.2_1
   textproc/txt2man (aubio +OPT FFMPEG)
audio/rubberband

Message from qsynth-0.4.1:
===>   NOTICE:

The qsynth port currently does not have a maintainer. As a result, it is
more likely to have unresolved issues, not be up-to-date, or even be removed in
the future. To volunteer to maintain this port, please create an issue at:

https://bugs.freebsd.org/bugzilla

More information about port maintainership is available at:

https://www.freebsd.org/doc/en/articles/contributing/ports-contributing.html#maintain-port
Message from qsampler-0.4.0:
===>   NOTICE:

The qsampler port currently does not have a maintainer. As a result, it is
more likely to have unresolved issues, not be up-to-date, or even be removed in
the future. To volunteer to maintain this port, please create an issue at:

https://bugs.freebsd.org/bugzilla

More information about port maintainership is available at:

https://www.freebsd.org/doc/en/articles/contributing/ports-contributing.html#maintain-port
Message from qjackctl-0.4.2:
===>   NOTICE:

The qjackctl port currently does not have a maintainer. As a result, it is
more likely to have unresolved issues, not be up-to-date, or even be removed in
the future. To volunteer to maintain this port, please create an issue at:

https://bugs.freebsd.org/bugzilla

More information about port maintainership is available at:

https://www.freebsd.org/doc/en/articles/contributing/ports-contributing.html#maintain-port

Message from aubio-0.4.2_1:
===>   NOTICE:

The aubio port currently does not have a maintainer. As a result, it is
more likely to have unresolved issues, not be up-to-date, or even be removed in
the future. To volunteer to maintain this port, please create an issue at:

https://bugs.freebsd.org/bugzilla

More information about port maintainership is available at:


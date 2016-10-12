# Back to 2013: Ardour 3.3 port

This repo presents a FreeBSD port for Ardour 3.3,  gitfyi my old ports and finally stage them all.

## Roadmap

- Update Ardour and all these new libs

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


# Ports que precisam the Maintainer:

qsynth-0.4.1
qsampler-0.4.0
qjackctl-0.4.2
aubio-0.4.2_1

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


# Ardour (for FreeBSD)

This port, named `ardour5`, is a fork from Ardour 5.x . 

My goal is:

- provide the last possible. portable and maintainable port of Ardour
- not to remove the old and stable port of Ardour audio/ardour
   - yes, it is an old one (version 2), but is quite stable, fast and still a good piece of software
   - it is not a stale port, it stil compiling from source

## General Status 

*IT WORKS!* for FreeBSD.

### Porting Status

- CNF: make configure . If the port is configured (implies patches, sometimes it is the major part of the whole work).
- BLD: make build . If the port is built.
- INS: make install . It means if the port is configured to be auto installed by the port system
- RUN: application was executed and run fine, after build or installed (manually or via ports system).
- FMT: passed port format validation (portlint) with or without a few WARNs.
- TEST: (ports-mgtm/porttools) tested with port command.
- PR: if I finished the process for submission to the ports tree
- TAG: final tag created in my own git repo, when applicable
- DIS: fetch distfiles

```
Port Name	  CNF	BLD   INS   RUN	  FMT	TEST  PR DIS   TAG
-------------------------------------------------------------------------------
audio/ardour5	  OK	OK    OK    OK	  OK	OK	 OK     5.3
audio/lilv-0	  OK	OK    OK    OK	  OK	
audio/lv2	  OK    OK    OK    OK    OK
audio/suil-0	  OK    OK    OK    OK    OK	OK    Y	 OK
textproc/serd-0	  OK    OK    OK    OK    OK	OK    Y	 OK
textproc/sord-0	  OK    OK    OK    OK    OK	OK    Y	 OK
textproc/sratom-0 OK    OK    OK    OK    OK	OK    Y	 OK
multimedia/harvid OK    OK    OK    OK    OK	OK    Y	 OK
multimedia/xjadeo OK    OK    OK    OK    OK	OK    Y	 OK
```


The PR should be submitted after all ports are tested. I'll make a one and only PR.

### Manual Installation:

After run ```make``` , it will break during stage. After that:

```
$ cd ${WRKSRC} && ./waf --destdir=${STAGEDIR} install
# UID=$(id -u THE_USERNAME_OF_WHO_BUILT)
# cd ${WRKDIR}/stage/usr/local
# find . | cpio -pdmv /usr/local/

Will affect

/usr/local/bin
/usr/local/etc
/usr/local/include
/usr/local/info
/usr/local/lib
/usr/local/libdata
/usr/local/libexec
/usr/local/man
/usr/local/sbin
/usr/local/share
/usr/local/tests

but owned dirs now belongs to the user who built and manually installed the port...

# find . -type d -uid $UID -mtime -26h | xargs chown 0:0
```

#### Manual deinstallation:

```
# find . | sed -e 's,^\./,/usr/local/,g' | xargs rm
```


# New Lib Depends

This project provides many new ports and updates to existing ports (audio/lv2core).

Now it is possible to have full LV2 power (use of LV2 GUIs for plugins) and the
major features included in Ardour when compared to the previous major release:

- MIDI record and playback (works with FreeBSD + linuxsampler or gigedit or qsampler or calf synth plugins ...)
- LV2 plugins with its GUIs (improves audio/calf plugins), see http://lv2plug.in/
- many other new features introduced in Ardour

Ardour 2 is not considered old fashion, nor should be droped. Use it if:

- you don't need recent Ardour new features
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

# ROADMAP

## Ports Without Maintainer

The list of exiting dependencies of Ardour in the ports tree and that
do not have a maintainer, are listed in directory 2adopt .

I'm considering adopt these ports...


## Desired Changes to Existing Ports

- audio/slv2
   The author rewrote it as a new library (audio/lilv-0)
- audio/lv2core
   This port should be replaced by the new port audio/lv2 (the whole LV2)
- audio/calf
   Change depency from audio/lv2-core to audio/lv2 (allowing use of LV2 GUIs)


## History

### Ardour 5.3

Oct, 2016. Started a ports dir in github.

### My Ardour 3.3 Port

I did a lot of work , staged the old ports but, some things happened wrong:

- a lot of new compiler erros (code style)
- aubio new version (compared to the year 2013) need some changes in header files...

So, I'm trying to port 5.3 .

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


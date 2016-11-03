# FreeBSD as a Digital Audio Workstation (DAW)

This information is intended to both audio/music production and FreeBSD lovers who do not want to stay away from his/her beloved OS when doing some fun ( I mean, other fun than the daily fun we do with it!). If you are not a FBSD user, you are invited to give it a try.

*Before reading*, you are recommended to be familiar with the FreeBSD ports system. RTFM :D (freebsd.org , look for Handbook and jump to Ports chapter).

It is recommended that you have a decent Audio interface and supported by some of the FreeBSD audio drivers.

Do not expect to be able to run a DAW with regular audio interfaces (chipped on board). It is possible to do something, but very limited (play a multitrack may be possible in general situations).

Although FreeBSD is very popular in sysadmin world, it is very solid as a Desktop: its USB stack and audio drivers evolved a lot since 2008, when I started to play with FBSD. I would not be surprised if we beat Linux audio world someday.


# DAW Set Up

As you can see, I'm proud of my old machine, but tips may apply to newer systems.

```
CPU: Genuine Intel(R) CPU           T2130  @ 1.86GHz (1862.05-MHz 686-class CPU)
  Origin="GenuineIntel"  Id=0x6ec  Family=0x6  Model=0xe  Stepping=12
  Features=0xbfe9fbff<FPU,VME,DE,PSE,TSC,MSR,PAE,MCE,CX8,APIC,SEP,MTRR,PGE,MCA,CMOV,PAT,CLFLUSH,DTS,ACPI,MMX,FXSR,SSE,SSE2,SS,HTT,TM,PBE>
  Features2=0xc189<SSE3,MON,EST,TM2,xTPR,PDCM>
  AMD Features=0x100000<NX>
  TSC: P-state invariant, performance statistics
real memory  = 2147483648 (2048 MB)
avail memory = 1951944704 (1861 MB)
```

And no GPU.

## Real Time / Preemption

It is known that Linux distros provide a kernel variation: the Linux RT (real time) kernel, for lower latency.

Some info about the FreeBSD architecture:

- man rtprio
- https://www.freebsd.org/doc/en_US.ISO8859-1/books/arch-handbook/smp-design.html

$  rtprio `pgrep -o jackd`
rtprio: normal priority
$  sudo rtprio 0 -`pgrep -o jackd`                                                                
$  rtprio `pgrep -o jackd`
rtprio: realtime priority 0

## Getting Rid of DeNormals

Problem: causes massive CPU usage when Ardour is idle.

Affects Intel CPUs, much more than AMD.

- https://community.ardour.org/node/3277

- Click the Preferences button at top-right or Edit > Preferences.
- Locate tab Audio > DeNormals
- Check "Use DC Bias to protect agains DeNormals"
- choose a processor handlig: "use DenormalsAreZero" - test others.

It shall be useful to protect the whole chain of plugins once affected with DeNormals.

## DSP CPU Utilization

Preferences, tab Misc > DSP CPU Utilization > check number of processors to use.

## OSS 4

*TODO* multimedia mail list: "uadio oss 4"
*TODO* compile kernel without sound(4) and drivers? - add manually /boot/loader.conf

Install ```audio/oss``` - build 2011 at the time of writing, providing OSS version 4.x . Pay attention to its pkg-message.

Also pay attention to binaries, conf files and man pages listed in pkg-plist - so you'll know what may or must be done for tunning.

Add ```oss_enable=YES``` to ```/etc/rc.conf``` .

*TODO* is kernel running OSS 3 yet? I forgot to install oss from ports since rebuild all packages ... clicks become frequent


# USB Audio And MIDI Support

- snd_uaudio(4) 

Right after plug the Audio and/or MIDI USB device, check the output of the next command:

$ dmesg | tail

## Examples

### USB MIDI Controller

The Akai MPK25, USB MIDI Controller, is recognized as a MIDI sequencer:

ugen0.6: <Akai> at usbus0
uaudio0: <Akai Akai MPK25, class 0/0, rev 1.00/1.03, addr 6> on usbus0
uaudio0: No playback.
uaudio0: No recording.
uaudio0: MIDI sequencer.
uaudio0: No HID volume keys found.


# Support

freebsd multimedia mailing list. Send the output of usbconfig for your device. Suppose it is /dev/ugen0.6 :

$ usbconfig -d 0.6 dump_all_config_desc




### USB Audio Device

This is what dmesg output looks like for M-AUDIO Fast Track Pro :

TODO

# Commonly Required Programs

- audio/jack
   Low latency audio server. Allows programs to connect to each other (like adding efx, probe analyzers or VU meters, add virtual instruments...)
- audio/qjackctl
   A nice GUI to audio/jack .
- audio/jack_umidi
   Together with audio/jack, allows the use of a USB MIDI Controller.
- audio/jack-keyboard
   A virtual keyboard (GUI). May be used to play, but also to test and isolate bugs or configs during the whole process of configuring your first DAW.

# Audio Recording

## GUI

- audio/ardour

### Ardour Tips

- http://libremusicproduction.com/tutorials/using-avl-drumkits-fluid-synth-ardour How to draw MIDI drums; link to author's free sampled drum kits; using fluidsynth as Ardour plugin; how to set up.

## CLI

- audio/ecasound
   Multitrack, a lot of features, effects...


# MIDI

- MIDI Player PRO : http://www.selasky.org/hans_petter/midistudio/

## Sampler

- audio/linuxsampler
   Modular MIDI sampler
- audio/qsampler
   C++ GUI to linuxsampler
- http://sourceforge.net/projects/jsampler/ 
   Java GUI to linuxsampler

- audio/bristol
   Bristol is an emulation package for a number of different 'classic' synthesisers.

- audio/fluidsynth 
   - you need soundfonts

- audio/gigedit
	Edit or create gig files to play with linuxsampler

- audio/hydrogen
	Drum machine


### Samples

#### Drums (real drums, very organic sound)

- http://www.bandshed.net/avldrumkits/ The author sampled two different drums with good mics.

The samples are available in 3 formats: h2drumkit for Hydrogen Drum Machine, SFZ which is an open cross-platform sound library format supported in applications like LinuxSampler and Sforzando and lastly in the popular Soundfont2 format. If you are simply looking for drum samples to load in a sampler the zipped SFZ folders also contain all the individual samples.

## Synthesizers

- audio/zynaddsubfx

## MIDI Multitrack Recording

- audio/ardour
   version 2
   version >3 MIDI capabilities
- audio/rosegarden (???)


## MIDI Notation/Score Editor

- audio/musescore


# How To Get It Working

Start jack server to accept audio applications as its clients:

$ jackd -r -doss -r48000 -p1024 -n3 -w16 -C/dev/dsp0.0 -P/dev/dsp0.0 &

Or start jack from qjackctl interface.

Start jack_umidi, creating the named node /dev/umidi0.0 :

$ jack_umidi -d /dev/umidi0.0 -B

Now we need some synth. Start bristol:

$ startBristol -mini -jack -midi seq 

Connect with qjackctl (connections button) or via command line :

$ jack_lsp
...
x:out
asdf

$ jack_connect x:out asdf



===============================
https://forums.freebsd.org/threads/58151/
===============================

Let me share an experience with another user:

Problem: USB Akai MPK 25 MIDI keyboard controller, how to get it working ?

First, we need a driver. And for USB audio class devices, a good guy gaves one: [MAN]snd_uaudio(4)[/MAN].

Let's clarify things talking about how to do it with non USB MIDI Controllers :

??I have a Roland XP-30 synth. It has old MIDI in and out ports (those you need a MIDI cable, get it? I think they still exist!). 

Between this synth and my computer, I need a MIDI port. Generally, you find MIDI in/out ports in your audio card (like my old Audiophile 2496, PCI card) or, in modern days, you find one in USB Audio devices. 

I'm complicating things now... specially because this audio device needs a drive too! But I'll assume you have a USB supported device, like mine.

What need to be done: to connect the Roland's old fashioned MIDI ports to the MIDI in/out of a USB Audio device (in case, I have a M-AUDIO Fast Track Pro). So, the M-AUDIO is supported by uaudio driver. 

Now, install audio/jack_umidi. A very small program that links my synth's MIDI ports to applications.

Now, getting back to USB Akai MPK 25 MIDI keyboard controller :

You don't have physical MIDI ports, but a USB to transfer the raw MIDI data. You gotta make sure that this device is supported by [MAN]uaudio_driver(4)[/MAN] :

[CMD]dmesg | tail[/CMD] right after plug in the USB keyboard/controller. 

The ouput command will point you something: if it is supported, what capabilities the device has (from the point of view of the driver support), like does it Play, Record, is a MIDI device...

[CODE]
ugen0.6: <Akai> at usbus0
uaudio0: <Akai Akai MPK25, class 0/0, rev 1.00/1.03, addr 6> on usbus0
uaudio0: No playback.
uaudio0: No recording.
uaudio0: MIDI sequencer.
uaudio0: No HID volume keys found.
[/CODE]

Nice, it looks capable to use it as a controller!

Some new nodes were created:

[CMD]ls /dev/ | grep umidi[/CMD]

[CODE]
umidi0.0
umidi0.1
umidi0.2
[/CODE]

Now, start jack server - [PORT]audio/jack)[/PORT] :

[CMD]jackd -d oss -r44100 -p256 -n2 -w16 -C/dev/dsp0.0 -P/dev/dsp0.0 &[/CMD]

And [PORT]audio/jack_umidi[/PORT] :

[CMD]jack_umidi -d /dev/umidi0.0 -B[/CMD]

Check the presence of the USB Controller using [PORT]audio/qjackctl [/PORT] or running a CLI utility from jack :

[CMD]jack_lsp[/CMD] , which outputs, in this particular case:

[CODE]
system:capture_1
system:capture_2
system:playback_1
system:playback_2
Akai Akai MPK25 #0:midi.TX
Akai Akai MPK25 #0:midi.RX[/CODE]


Next step is to install some sampler application to get some sound from the USB Controller.

Some sampler Apps:

- [PORT]audio/linuxsampler[/PORT]

Modular MIDI sampler. You may load GIG files (this is old, but cool)

- [PORT]audio/gigedit[/PORT]

Edit or create gig files to play with linuxsampler

- [PORT]audio/qsampler[/PORT]

C++ GUI to linuxsampler

- http://sourceforge.net/projects/jsampler/

Java GUI to linuxsampler

- [PORT]audio/bristol[/PORT] this one is very cool!

Bristol is an emulation package for a number of different 'classic' synthesisers.
I recommend start playing with this one, since it has its own sound lib included, you don not need to get some.

- [PORT]audio/fluidsynth[/PORT]

You need soundfonts (SF2 files). There are editors, but don't know their state for FreeBSD .
??????
If you do not have a or supported controller, or need to test things, part by part, install 

- [PORT]audio/jack-keyboard[/PORT]

A virtual keyboard (GUI). May be used to play, but also to test and isolate bugs or configs during the whole process of configuring your first DAW.

- [PORT]audio/hydrogen[/PORT]

Drum machine

There are a bunch of other ports , the above list is something I used.

If you have technical problems you may try create a new thread. If no solution (drivers are tricky), try an e-mail to the freebsd multimedia mailing list. This list is very focused on development, but it is open for technical user questions! A skilled developer probably will respond you. Send them the next command output:
Suppose the example above, where dmesg points the device node ugen0.6 , 

[CMD]usbconfig -d 0.6 dump_all_config_desc[/CMD]

It is really necessary to figure things out.

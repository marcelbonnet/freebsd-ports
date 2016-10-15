#!/usr/local/bin/bash
source ~/.bashrc 2&>/dev/null
criardistfile `make -VPKGNAME` ~/devel/ports/src/ardour ~/devel/ports/distfiles/ && make DISTDIR=~/devel/ports/distfiles/ makesum

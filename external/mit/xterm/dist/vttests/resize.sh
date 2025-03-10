#!/bin/sh
# $XTermId: resize.sh,v 1.24 2022/04/24 23:36:20 tom Exp $
# -----------------------------------------------------------------------------
# this file is part of xterm
#
# Copyright 1999-2021,2022 by Thomas E. Dickey
#
#                         All Rights Reserved
#
# Permission is hereby granted, free of charge, to any person obtaining a
# copy of this software and associated documentation files (the
# "Software"), to deal in the Software without restriction, including
# without limitation the rights to use, copy, modify, merge, publish,
# distribute, sublicense, and/or sell copies of the Software, and to
# permit persons to whom the Software is furnished to do so, subject to
# the following conditions:
#
# The above copyright notice and this permission notice shall be included
# in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
# OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
# IN NO EVENT SHALL THE ABOVE LISTED COPYRIGHT HOLDER(S) BE LIABLE FOR ANY
# CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
# TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
# SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#
# Except as contained in this notice, the name(s) of the above copyright
# holders shall not be used in advertising or otherwise to promote the
# sale, use or other dealings in this Software without prior written
# authorization.
# -----------------------------------------------------------------------------
# Obtain the current screen size, then resize the terminal to the nominal
# screen width/height, and restore the size.

ESC=""
CSI="${ESC}["
CMD='/bin/echo'
OPT='-n'
SUF=''
: "${TMPDIR=/tmp}"
TMP=`(mktemp "$TMPDIR/xterm.XXXXXXXX") 2>/dev/null` || TMP="$TMPDIR/xterm$$"
eval '$CMD $OPT >$TMP || echo fail >$TMP' 2>/dev/null
{ test ! -f "$TMP" || test -s "$TMP"; } &&
for verb in "printf" "print" ; do
    rm -f "$TMP"
    eval '$verb "\c" >$TMP || echo fail >$TMP' 2>/dev/null
    if test -f "$TMP" ; then
	if test ! -s "$TMP" ; then
	    CMD="$verb"
	    OPT=
	    SUF='\c'
	    break
	fi
    fi
done
rm -f "$TMP"

exec </dev/tty
old=`stty -g`
stty raw -echo min 0  time 5

$CMD $OPT "${CSI}18t${SUF}" > /dev/tty
IFS=';' read -r junk high wide

$CMD $OPT "${CSI}19t${SUF}" > /dev/tty
IFS=';' read -r junk maxhigh maxwide

stty $old

wide=`echo "$wide"|sed -e 's/t.*//'`
maxwide=`echo "$maxwide"|sed -e 's/t.*//'`
original=${CSI}8\;${high}\;${wide}t${SUF}

test "$maxwide" = 0 && maxwide=`expr "$wide" \* 2`
test "$maxhigh" = 0 && maxhigh=`expr "$high" \* 2`

trap '$CMD $OPT "$original" >/dev/tty; exit 1' 1 2 3 15
trap '$CMD $OPT "$original" >/dev/tty' 0

w=$wide
h=$high
a=1
while true
do
#	sleep 1
	echo "resizing to $h by $w"
	$CMD $OPT "${CSI}8;${h};${w}t" >/dev/tty
	if test $a = 1 ; then
		if test "$w" = "$maxwide" ; then
			h=`expr "$h" + "$a"`
			if test "$h" = "$maxhigh" ; then
				a=-1
			fi
		else
			w=`expr "$w" + "$a"`
		fi
	else
		if test "$w" = "$wide" ; then
			h=`expr "$h" + "$a"`
			if test "$h" = "$high" ; then
				a=1
			fi
		else
			w=`expr "$w" + "$a"`
		fi
	fi
done

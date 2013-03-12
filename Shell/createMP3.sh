#! /bin/bash 
set -u
set -e

#takes filename and voiceover dialog string as args, writes mp3s
#example:  sh createMP3.sh audioFilename "The file will say this text"

if [ $# -eq 0 ]; then
	echo "No arguments supplied.  Include desired filename as arg1, text to say as arg2"
else
	NAME=$1
	DIALOG=$2
	say -o $NAME $DIALOG
	lame -h -m m -b 64 $NAME.aiff $NAME.mp3
	rm $NAME.aiff
fi
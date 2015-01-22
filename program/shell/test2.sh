#!/bin/sh
if test $# -eq 0
then 
	echo "Please specify a file!"
else
	gzip $1
mv $1.gz $HOME/dustbin
echo "File $1 is deleted!"
fi


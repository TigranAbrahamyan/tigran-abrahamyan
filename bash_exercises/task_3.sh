#!/bin/bash

if [ $# -eq 0 ]; then
	echo "You need pass a argument"
	exit
fi

for file in $@; do
	if [ -d $file  ]; then
		echo "dir - $file"
	elif [ -f $file ]; then
		echo "file - $file"
	else
		echo "another type"
	fi
done


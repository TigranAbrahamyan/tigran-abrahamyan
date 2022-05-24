#!/bin/bash

if [ $# -eq 0 ]; then
	echo "You need to pass a argument"
	exit
elif [ $# -ge 2 ]; then
	echo "You need to pass only one argument"
	exit
fi

function print_files_with_limited_length() {
	for file in $1/*; do
		withoutFullPath=${file##*/}
		withoutFileExtension=${withoutFullPath%%.*}
		if [ ${#withoutFileExtension} -ge 3 ]; then
			echo "$withoutFullPath"
		fi

		if [ -d $file ]; then
			print_files_with_limited_length $file
		fi
	done
}

print_files_with_limited_length $1


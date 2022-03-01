#!/bin/bash

if [ $# -eq 0 ]; then
        echo "You need to pass a argument"
        exit
elif [ $# -ge 2 ]; then
	echo "You need to pass only one argument"
	exit
fi

function tree_structure_list() {
	for file in $1/*; do
		if [ -d $file ]; then
			echo "dir: $file"
			tree_structure_list $file
		elif [ -f $file ]; then
			echo "file: $file"
		fi
	done
}

tree_structure_list $1


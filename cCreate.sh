#!/bin/bash

for name in $@ ; do
	file=$name'.c'
	if [ ! -f $file ]; then
		touch $file
		days="$(date '+%d %B %Y')"
		contain=$'/**\n*\\file '
		contain+=$file
		contain+=$'\n*\\brief \n*\\author Gaëtan,Lucas\n*\\version 0.1\n*\\date '
		contain+=$days	
		contain+=$' */'	
		echo "$contain" >> $file
		./ctoh.sh
	fi	
done

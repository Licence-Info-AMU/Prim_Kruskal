#!/bin/bash

for name in *.c ; do
	file=${name%%c}h
	if ! [ -e $file ]
	then
		touch $file
		days="$(date '+%d %B %Y')"
		contain=$'/**\n*\\file '
		contain+=$file
		contain+=$'\n*\\brief \n*\\author Gaëtan,Lucas\n*\\version 0.1\n*\\date '
		contain+=$days
		contain+=$'\n*\n*/\n\n#ifndef '
		contain+=${file^^}
		contain+=$'\n#define	'
		contain+=${file^^}
		contain+=$'\n\n#endif	/* '
		contain+=${file^^}
		contain+=$' */'		
		echo "$contain" >> $file
	fi	
done

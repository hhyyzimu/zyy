#!/bin/bash

until
	echo "1-List Directory"
	echo "2-Change Directory"
	echo "3-Edit File"
	echo "4-Remove File"
	echo "5-Exit Menu"

	read choice 
	test $choice = 5

do
	case $choice in
		1)ls;;
		2)echo "enter target directory:"
			read dir
			cd $dir
			;;
		3)echo "enter file name:"
			read file
			vi $file
			;;
		4)echo "remove file name:"
			read file
			rm $file
			;;
		5)echo "Goodbye"
			;;
		*)echo "Illegal option, please input again."
			;;
	esac
done

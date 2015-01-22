#!/bin/bash

num=0
while [ $num -le 10 ]
do
	num=`expr $num + 1`
		if [ $num -eq 5 ]
		then
			continue
		fi
	square=`expr $num \* $num`
	echo $square
done

#!/bin/bash

total=0
num=0
	while [ $num -le 10 ]
	do
		total=`expr $total + $num`
	echo $total
	done

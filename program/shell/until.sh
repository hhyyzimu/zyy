#!/bin/bash
total=0
num=0
	until \[$sum -gt 100\]
	do
		total=` expr $total + $num`
		num=` expr $num + 1`
	done
	echo "The result is $total"

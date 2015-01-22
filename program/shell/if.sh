#!/bin/bash

for((j=1; j<=10; j++))
do
	if(($j%2==1))
	then
		echo "$j"
	fi
done

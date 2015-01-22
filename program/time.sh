#!/bin/bash

start=`date +%s`

for((i = 1; i <= 10; i++))
do
	echo "i = " $i

done
sleep 1s

end=`date +%s`

time1=$[end - start]

echo "time = " $time1

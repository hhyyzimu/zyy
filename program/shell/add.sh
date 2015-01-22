#!/bin/bash

total=0

for((j=1; j<=100; j++));
do
	total=`expr $total + $j`
done

echo "The result is $total"

#for语句中的双括号不能省，最后的分号可有可无，表达式total=`expr $tatal + $j`加号两边的空格不能省，否则会成为字符串的连接

#!/bin/sh
echo "please input x y"
#read x,y

echo $x
echo $y

x=$x
y=$y

#let z=`expr $x + $y`
#let z=`expr 3 + 4`
((z=$1+$2))

echo "The sum is $z"

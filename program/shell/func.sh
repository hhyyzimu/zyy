#!/bin/bash
add()
{
	a=$1
	b=$2
	z=`expr $a + $b`
	echo "The sum is $z"
}
add $1 $2

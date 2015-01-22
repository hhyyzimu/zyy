#!/bin/bash

case $USER in
beichen)
	echo "You are bei chen!";;
liangnian)
	echo "You are liangnian";
	echo "Welcom!";;
root)
	echo "You are root!";
	echo "Welcom";;
*)
	echo "Who are you? $USER?";;
esac

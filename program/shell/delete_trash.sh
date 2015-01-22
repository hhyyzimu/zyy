#!/bin/bash

for i in $HOME/.local/share/Trash/files/*	
do
	rm -rf $i
echo "$i has been deleted!"
done

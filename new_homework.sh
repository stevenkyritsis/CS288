#!/bin/bash

echo -n "Type in the homework number for a new directory:"
read input

if [ "$input" != "\n" ]; then
	mkdir /home/sak76/homework/homework_$input
	cd /home/sak76/homework/homework_$input
	$SHELL
else
	echo "Error!"
fi


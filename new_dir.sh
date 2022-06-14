#!/bin/bash

echo -n "Type in the date for a new directory:"
read input

if [ "$input" != "\n" ]; then
	mkdir /home/sak76/classwork/test_$input
	cd /home/sak76/classwork/test_$input
	$SHELL
else
	echo "Error!"
fi


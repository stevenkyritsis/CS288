#!/bin/bash

array=(one two three four five)
SIZE=${#array[*]}
echo "Array size: $SIZE"
echo "Array items:"
for ((i=0; i < $SIZE ; i++));
do
	printf "%s\n" ${array[i]}
done

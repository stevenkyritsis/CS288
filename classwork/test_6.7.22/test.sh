#!bin/bash

LIST=`ls`

for filename in $LIST
do
	if [ -d $filename ]; then
		echo "$filename is a directory"
	else
		echo "$filename is a file"
	fi
done 

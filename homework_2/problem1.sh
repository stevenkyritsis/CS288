#!/bin/bash

file_path=$1

if [ -d $file_path ]; then
	echo "$file_path is a directory."	

else

	if [ -f $file_path ]; then		
        echo "$file_path is a file."
        filesize=`$(du -b | cut -d '.' -f 1 $file_path)`
        if (($filesize > 1048576)); then
            echo "The file is a large file."
        elif (($filesize > 102400)); then
            echo "The file is a medium file."
        else
            echo "The file is a small file."
        fi
	fi
fi
#!/bin/bash

pathname=$1
user_id=$2

cool()
{
if [ -d $pathname ]; then
    for filename in /*
    do
        #while [ -d filename ];
        #do
        #    if [ -f filename ]; then
        #        echo $filename
        #    fi
        #done;
        if [ -f $filename ]; then
            echo "$filename"
            #permissions=`$(ls -l $filename)`
            #owner=`$(ls -l $filename)`
            #group=`$(ls -l $filename)`

            #echo $permissions

        #elif [ -d $filename ]; then
        #        cool $filename 
        fi

    done;
fi
}

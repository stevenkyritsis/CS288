#!/bin/bash

for temp1 in {A..Z}
do
    for temp2 in {A..Z}
    do
        temp="$temp1$temp2"
        wget https://en.wikipedia.org/wiki/$temp -O ${temp}.html
        lynx -dump –nolist ${temp}.html > ${temp}.txt
        grep -o -E "[a-zA-Z]*" ${temp}.txt | tr '[:upper:]' '[:lower:]' | cut -f1 > ftxt.txt
    done
done
sort ftxt.txt | uniq -c | sort -nr | head -15
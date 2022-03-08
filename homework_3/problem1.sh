#!/bin/bash


for temp1 in {A..Z}
do
    for temp2 in {A..Z}
    do
        temp=$temp1$temp2
        wget https://en.wikipedia.org/wiki/$temp -O ${temp}.html
        html2text ${temp}.html > ${temp}.txt
        #echo $temp1$temp2
    done
done

#    echo `$(grep -o ${temp}.txt|sort ${temp}.txt|uniq -c ${temp}.txt)`

#!/bin/bash

for temp1 in {A..Z}
do
    for temp2 in {A..Z}
    do
        temp=$temp1$temp2
        wget https://en.wikipedia.org/wiki/$temp -O /home/sak76/homework/homework_2/html/${temp}.html
        lynx -dump –nolist /home/sak76/homework/homework_2/html/${temp}.html > /home/sak76/homework/homework_2/txt/${temp}.txt
        grep -o [^a..zA..Z] /home/sak76/homework/homework_2/txt/${temp}.txt | sort | uniq
        #echo $temp1$temp2
    done
done
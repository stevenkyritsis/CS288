#!/bin/bash

for temp1 in {A..Z}
do
    for temp2 in {A..Z}
    do
        temp=$temp1$temp2
        wget https://en.wikipedia.org/wiki/$temp -O /home/sak76/homework/homework_2/html/${temp}.html
        lynx -dump –nolist /home/sak76/homework/homework_2/html/${temp}.html | grep -o "[A-Za-z]*" > /home/sak76/homework/homework_2/txt/${temp}.txt
        grep -o "[A-Za-z]*" /home/sak76/homework/homework_2/txt/${temp}.txt | sort | uniq -c | sort -nr > /home/sak76/homework/homework_2/ftxt/${temp}.txt
    done
done
#grep -o "[A-Za-z]"* /home/sak76/homework/homework_2/txt/*.txt | sort | uniq -c | sort -nr > /home/sak76/homework/homework_2/ftxt/ftxt.txt
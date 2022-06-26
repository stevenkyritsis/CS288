#!/bin/bash

#AA
wget https://en.wikipedia.org/wiki/AA -O /home/sak76/homework/homework_2/web/AA.html
lynx -dump –nolist AA.html > grep -o [:alpha:] | /home/sak76/homework/homework_2/txt/AA.txt

#AB
wget https://en.wikipedia.org/wiki/AB -O /home/sak76/homework/homework_2/web/AB.html
lynx -dump –nolist AB.html > /home/sak76/homework/homework_2/txt/AB.txt

#AC
wget https://en.wikipedia.org/wiki/AC -O /home/sak76/homework/homework_2/web/AC.html
lynx -dump –nolist AC.html > /home/sak76/homework/homework_2/txt/AC.txt

#ZY
wget https://en.wikipedia.org/wiki/ZY -O /home/sak76/homework/homework_2/web/ZY.html
lynx -dump –nolist ZY.html > /home/sak76/homework/homework_2/txt/ZY.txt

#ZZ
wget https://en.wikipedia.org/wiki/ZZ -O /home/sak76/homework/homework_2/web/ZZ.html
lynx -dump –nolist ZZ.html > /home/sak76/homework/homework_2/txt/ZZ.txt
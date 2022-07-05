from urllib.request import urlopen
from bs4 import BeautifulSoup
import re

letters = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
link = "https://en.wikipedia.org/wiki/"
data = ''

for l1 in letters:
    for l2 in letters:
        url=link+l1+l2
        urlobject = urlopen(url)
        contents = urlobject.read().decode("utf-8")
        soup = BeautifulSoup(contents, "html.parser")
        data += soup.get_text()
    
fdata = data.lower()

key =  '[a-z]+'
words = re.findall(key,fdata,flags=re.IGNORECASE)

unique=[]
for word in words:
    if word not in unique:
        unique.append(word)

mydict = {}

for word in unique:
    mydict[word] = words.count(word)

count = 0
for k in sorted(mydict, key=mydict.get, reverse=True):
  print(k, mydict[k])
  count+=1
  if count==15:
    break
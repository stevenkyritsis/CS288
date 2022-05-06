import time
import pymongo
import requests
from bs4 import BeautifulSoup, Tag

f = requests.get("https://finance.yahoo.com/most-active/")

soup = BeautifulSoup(f.text, "html.parser")

tag = soup.find(tbody)

print(tag)
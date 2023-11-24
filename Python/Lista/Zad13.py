import sys
import collections
# python -u Zad13.py "string" <- uzycie skryptu
samogloski = ["a", "e", "i" , "o", "u" , "ó","y", "ą", "ę"]

counter = collections.Counter(str(sys.argv[1])) 

for key,value in counter.items():
    if key in samogloski:
        print(key, ":",value)

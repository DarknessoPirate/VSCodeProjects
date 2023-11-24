import random
plik = "listadanych.txt"
arr =[]
with open(plik,"r") as myFile:
    for lines in myFile:
        a = lines.replace("\n","").split(" ")
        for i in a:
            arr.append(i)

r = random.choice(arr)
print(r)
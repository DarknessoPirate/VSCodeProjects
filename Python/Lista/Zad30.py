with open("tekstdostatystyki.txt") as file:
    s = file.read().upper()

print(s)
myFile = open("wersaliki.txt", "x")

buffer = myFile.write(s)
import collections 

dict = {}

myFile = open("tekstdostatystyki.txt")

buffer = myFile.read().lower().split()

count = collections.Counter(buffer)

print(count)

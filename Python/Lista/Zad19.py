import random
import os

array = []

file = open("C:\\VSCodeProjects\\Python\\Lista\\liczby.txt")
for word in file:
    word = word.strip().split(",")
    for i in word:
        array.append(int(i))
print(f"Array elements: {array}")

x = random.randint(int(input("Podaj początek przedziału:")),int(input("Podaj koniec przedziału:")))
random = random.choice(array)
print(x)
print(f"Random array element: {random}")
file.close()
path = os.getcwd() + "\\wynikizadania.txt"
print(path)
file = open(path, "a")
file.write(str(x) + "\n")
file.write(str(random) + "\n")
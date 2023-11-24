import random

columns = int(input("Podaj liczbe kolumn: "))
rows = int(input("Podaj licbe wierszy: "))
low = int(input("Podaj dol przedzialu: "))
high = int(input("Podaj gore przedzialu: "))
lista = [[random.randint(low,high) for i in range(columns)] for j in range(rows)]

with open("danewygenerowane.txt","a") as file:
    for i in range(rows):
        for j in range(columns):
            file.write(str(lista[i][j]))
            file.write(",")
        file.write("\n")

print(lista)

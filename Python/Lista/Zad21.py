import os

fill = int(input("Podaj liczbe wypelniajaca tabele: "))
tablica = [[fill for i in range(5)] for j in range(7)]

path = os.getcwd()
nazwa = str(input("Podaj path do pliku lub nazwe pliku: "))
f = open(path + "\\" + nazwa, "a")

for j in range(7):
    for i in range(5):
        f.write(str(tablica[j][i]))
        f.write(",")
    f.write("\n")
    
f.close()
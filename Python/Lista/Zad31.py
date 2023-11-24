path = input("Podaj nazwe pliku: ")
n = int(input("Podaj podstawe(liczba): "))
i = 0

def Padding(times):
    s = "*"
    for _ in range(times):
        s += "*"
    return s

with open(path,"a") as file:
    file.write("licznik  suma\n")
    file.write("-----   -----\n")
    a = n
    for i in range(11):
        s1 = len(str(i))
        s11 = Padding(2 - s1) + str(i) + Padding(1)
        s2 = len(str(a))
        s22 = Padding(0) + str(a) + Padding(2-s2)
        file.write(f"{s11} | {s22}\n")
        a += n
        i += 1
lista = []
lista.append(1)
lista.append("string")
lista.append(4.4)
lista2 = [1,2,3]
lista3 = ["banan","gruszka"]
lista.append(lista2)
lista.append(lista3)

listab = []
listab.append(1)
listab.append("aa")
listab.append(4.4)
lista2b = [1,3,3]
lista3b = ["banan","gruszka"]
listab.append(lista2b)
listab.append(lista3b)

print(lista == listab)
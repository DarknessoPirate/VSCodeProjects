import math
b = int(input("Podaj ilosc bokow: "))
l = int(input("Podaj dlugosc boku: "))

A = 1/4 * b * l*l * (1/math.tan(math.pi/b))
print(A)
import math

a = input("Podaj liczbe zespolona w postaci (x,y): ").split(",")
c1 = complex(int(a[0]),int(a[1]))
r = int(a[0])
i = int(a[1])
result = math.sqrt(r*r + i*i)
print(f"Modul liczby zespolonej {c1} = {result}")
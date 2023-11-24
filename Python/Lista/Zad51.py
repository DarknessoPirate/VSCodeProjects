a = input("Podaj pierwsza liczbe zespolona w postaci (x,y): ").split(",")
b = input("Podaj druga liczbe zespolona w postaci (x,y): ").split(",")

c1 = complex(int(a[0]),int(a[1]))
c2 = complex(int(b[0]),int(b[1]))
result = c1/c2
result = complex(round(result.real,5) + round(result.imag,5)*1j)
print(f"{c1} + {c2} = {result}")
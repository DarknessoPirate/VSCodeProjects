import math
a = 7
b = -4
c = complex(2,3)



def modul(a):
    if(type(a) == complex):
        return math.sqrt(a.real*a.real + a.imag*a.imag)
    else:
        return math.sqrt(a*a)

print(modul(a))
print(modul(b))
print(modul(c))

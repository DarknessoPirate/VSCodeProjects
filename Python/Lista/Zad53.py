import cmath
import math

t = input("Podaj liczbe zespolona postaci (x,y): ").split(",")
z = complex(int(t[0]),int(t[1]))
phi = cmath.phase(z)
r = int(t[0])
i = int(t[1])
ratio = phi/2
mag = math.sqrt(r*r + i*i)
result = 2*ratio*math.pi*mag
print(result)
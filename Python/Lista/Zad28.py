

a1 = int(input("Podaj a1 : "))
a2 = int(input("Podaj a2 : "))
b1 = int(input("Podaj b1 : "))
b2 = int(input("Podaj b2 : "))
c1 = int(input("Podaj c1 : "))
c2 = int(input("Podaj c2 : "))

det = a1 * b2 - b1 * a2
Wx = c1 * b2 - b1*c2
Wy = a1 * c2 - c1 * a2
if(det != 0):
    x = Wx/det
    y = Wy/det
    print(f"X:{x}, Y:{y}")

elif(det == 0 and Wx == 0 and Wy == 0):
    print("Uklad nieoznaczony")

elif(det == 0 and (Wx != 0 or Wy != 0 )):
    print("Uklad sprzeczny")
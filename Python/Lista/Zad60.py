import math

class Kolo:
    def __init__(self,radius):  
        self.r = radius

    def pole(self):
        return math.pi * self.r*self.r
    def dlugoscOkregu(self): 
        return 2*math.pi*self.r
    def obwod(self):
        return 2*math.pi*self.r

k = Kolo(5)
print(k.pole(),k.obwod(),k.dlugoscOkregu())
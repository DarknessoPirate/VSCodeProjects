import random
import math
wewn = 0
zewn = 0
def distance(x,y):
    return math.sqrt(x**2 + y**2)


for i in range(1,10000):
    x = random.random()
    y = random.random()
    if(distance(x,y)<=1):
        wewn += 1
    
    else:
        zewn += 1

Pi = wewn / (wewn+zewn) * 4
print(Pi)
import math
import cmath

coefficients = []
result = []
with open("coefficients.txt") as myFile:
    temp = myFile.read().split()
    for i in temp:
        coefficients.append(int(i))

def saveToFile(filename, arr):
    with open(filename,"w") as myFile:
        for i in arr:
            myFile.write(str(i))
            myFile.write("\n")


def quadraticFormula(arr,result):
    a = arr[0]
    b = arr[1]
    c = arr[2]
    delta = b*b - 4*a*c
    print(delta)
    if(delta > 0):
        result.append((-b + math.sqrt(delta))/2*a)
        result.append((-b - math.sqrt(delta))/2*a)
        

    elif(delta == 0):
        result.append(-b/2*a)
        

    elif(delta < 0):
        result.append((-b + cmath.sqrt(delta))/2*a)
        result.append((-b - cmath.sqrt(delta))/2*a)
        

quadraticFormula(coefficients,result)
saveToFile("quadResult.txt",result)

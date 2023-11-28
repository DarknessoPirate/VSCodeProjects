import math
import cmath


def factorial(n):
    if n==0:
        return 1
    return n*factorial(n-1)

def a(alpha, beta,op):
    if(op == '+'):
        return 2*math.sin((alpha + beta)/2)*math.cos((alpha-beta)/2)
    elif(op == '-'):
        return 2*math.sin((alpha - beta)/2)*math.cos((alpha+beta)/2)
    else:
        print("Incorrect operator")

print(f"factorial(5) = {factorial(5)}")

def b(x,n):
    p = 1
    newN = n
    f = 1
    result = 1
    for i in range(n):
        result += (newN*pow(x,p))/factorial(f)
        f += 1
        p += 1
        newN *= n - (i + 1)

    return result

print("b:",b(0.5,7))

def c(a,b,c):
    x1 = (-b - cmath.sqrt(b*b - 4*a*c))/2*a
    x2 = (-b + cmath.sqrt(b*b - 4*a*c))/2*a
    print(f"miejsca zerowe: {x1}, {x2}")

c(3,4,5)

def d(x):
    result = 0
    for i in range(150):
        result += math.pow(x,i)/factorial(i)

    return result
x = 5
print(f"e^{x} = {d(x)}")

def e(a0,n,x):
    result = a0
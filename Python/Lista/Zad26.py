import math

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


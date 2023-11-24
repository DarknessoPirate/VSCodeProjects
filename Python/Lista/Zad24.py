factorial = 1
n = int(input("Podaj liczbe: "))

for i in range(1,n+1):
    factorial *= i

print(factorial)
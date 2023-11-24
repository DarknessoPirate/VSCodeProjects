def silnia(n):
    a = 1
    while(n>1):
        a *= n 
        n -= 1
    return a
print(silnia(4))
def silnia(n):
    if(n == 0 or n == 1):
        return 1
    return n * silnia(n-1)

print(silnia(4))
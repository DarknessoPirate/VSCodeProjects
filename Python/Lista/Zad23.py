word = input("Podaj zdanie/slowo")

if(word == word[::-1]):
    print("Palindrom")

else:
    print("Nie palindrom")
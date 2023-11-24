od = int(input("Podaj od kiedy chcesz szukac(rok): "))
do = int(input("Podaj do kiedy chcesz szukac(rok): "))
result = []
if(od > do):
    print("Nieprawidlowe dane")
elif(od<=do):
    a = 0
    for i in range(od,do+1):
        if(i%4 == 0):
            if(i%100 == 0):
                if(i%400 == 0):
                    result.append(str(i))
                    a += 1
            else:
                result.append(str(i))
                a += 1


print(f"znaleziono {a} wynikow: ")
print(result)


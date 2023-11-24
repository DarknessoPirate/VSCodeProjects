x = input("Gib liczba")

if(x%7==0):
    print("0")
elif(x%7==1):
    print("1")
elif(x%7==2):
    print("2")
elif(x%7==3):
    print("3")
elif(x%7==4):
    print("4")

match x%7:
    case 0:
        print("0")
    case 1:
        print("1")
    case 2:
        print("2")
    case 3:
        print("3")
    case 4:
        print("4")
    case _:
        print("co do chuja")

        


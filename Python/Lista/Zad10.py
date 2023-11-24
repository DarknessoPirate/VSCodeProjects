
list = ["dog", "cat", 1, 2, 1, "cat", "cow", [1,2,3], 4.4, 8,15, 4.4]



x = input("podaj szukany element: ")

if x in str(list):
    print(str(list).count(x))

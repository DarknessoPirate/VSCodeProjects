#filter() - creates a collection of elements from an iterable for which function that we pass it returns two
#filter(function, iterable)


friends = [("Rachel",19),
           ("Tom",18),
           ("John",17),
           ("Dave",16),
           ("Mike",21),
           ("Ross",20)]

age = lambda data:data[1] >= 18

drinking_buddies = list(filter(age, friends))

for i in drinking_buddies:
    print(i)
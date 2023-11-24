########### ARGS

def add(*arguments):   ## creating a function for an undefined number of arguments, only works with tuples
    sum = 0
    for i in arguments:      ## iterating through arguments
        sum += i
    return sum

print(add(1,2,3,4,5,6))

#lista = [1,2,3,4,5,6]
#print(add(lista)) ## doesnt work with lists


########### KWARGS - parameter that will pack all arguments into a dictionary

def hello(**arguments):
    #print("Hello" + arguments['first'] + " " + arguments['last'])
    print("Hello",end =" ")
    for key,value in arguments.items():
        print(value,end =" ")

hello(title="Mr.",first="Giga",second = "Chad", last = "something")
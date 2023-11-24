import random

x= random.randint(1,6) ## random int
y= random.random() ## random float betweem (0,1)

myList = ['rock','paper','scissors']
z = random.choice(myList) ## picks a random element from a sequence

cards = [1,2,3,4,5,6,7,8,9,"J","Q","K","A"]

random.shuffle(cards) ## shuffles the elements in a list

print(x)
print(y)
print(z)
print(cards)
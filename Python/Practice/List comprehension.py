# list comprehension - a way to create a new list with less syntax,
#                      can mimic certain lambda functions

#squares = []
#for i in range (1,11):
#    squares.append(i*i)
#print(squares)

squares = [i*i for i in range (1,11)] ## does the same thing as the loop above but inside a list
print(squares)

students = [100,90,80,70,60,50,40,30,0]

#passed_students = list(filter(lambda x: x>= 60, students))

#passed_students = [i for i in students if i >= 60]
passed_students = [i if i >= 60 else "FAILED" for i  in students]
print(passed_students)
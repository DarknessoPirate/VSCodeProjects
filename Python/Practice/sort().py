# sort() method - used with lists
# sorted() function - used with iterables

names = ["Tom", "Camille", "Michael", "John", "Jack"] 

names.sort() ## sort() can only be used with lists
print(names)
names.sort(reverse=True)
print(names)

students = ("Matthew", "Dominic", "David", "John", "George")
sorted_students = sorted(students) # works with all iterables
print(sorted_students)
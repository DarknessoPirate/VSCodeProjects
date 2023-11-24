#lambda - throwaway function / one use 

# lambda parameters:expression


double = lambda x: x * 2
multiply = lambda x, y: x * y
add = lambda x, y, z: x + y + z
full_name = lambda first_name, last_name: first_name + " " + last_name
age_check = lambda age:True if age>=18 else False
print(double(4))
print(multiply(3,4))
print(add(1,2,3))
print(full_name("Giga", "Chad"))
print(age_check(14))

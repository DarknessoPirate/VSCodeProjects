
#name = "John"
#age= 15
#tuple = ("John", 15)
#print("%s is %d years old!" %(name,age)) ### dont use, use fstring instead
#print(f"{tuple[0]} is {tuple[1]} years old!") ### fstring

#data = ("John", "Doe", 53.44)
#print(f"Hello {data[0]} {data[1]}. Your current balance is ${data[2]} ")

#str.format() - optional method that gives users more control over the output

animal = "cow"
item = "moon"

#print("The" + animal + " jumped over the " + item)
#{} - format field
#print("The {} jumped over the {}".format(animal,item)) 
#print("The {0} jumped over the {1}".format(animal,item)) #positional argument
#print("The {object} jumped over the {thing}".format(object="dog",thing="sun")) 


pi = 3.14159
number = 1000
print("The number pi is {:.2f}".format(pi)) ## sets the precision to the print
print("The number is {:,}".format(number)) ## adds a comma 
print("The number is {:b}".format(number)) ## prints a number in binary
print("The number is {:o}".format(number)) ## prints a number in octal
print("The number is {:x}".format(number)) ## prints a number in hex
print("The number is {:X}".format(number)) ## prints a number in hex(Capital letters)
print("The number is {:e}".format(number)) ## prints a number in scientific notation
print("The number is {:E}".format(number)) ## prints a number in scientific notation(Capital letters)


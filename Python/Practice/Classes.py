
class MyClass:
    variable = None ## class variable (we can set default values)
    name = None

    def __init__(self, number,name):    #constructor
        self.variable = number        # instance variable
        self.name = name     #instance variable

    def function(self):
        print("A message from inside the class")

#MyClass.variable=4 # changing the original default variable in the class
#myobjectxx = MyClass()  # object stores the data
#myobjectyy = MyClass()
#myobjectxx.variable=8

#print(myobjectxx.variable)
#print(myobjectyy.variable)
#myobjectxx.function()
#myobjectyy.function()

object = MyClass(15,"name")  ## 
print(object.variable)
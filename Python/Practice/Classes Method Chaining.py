class Car:

    def turn_on(self):
        print("Engine started")
        return self            ## needs to be added for the chaining to work

    def drive(self):
        print("The car is driving")
        return self 

    def brake(self):
        print("The car brakes")
        return self 

    def turn_off(self):
        print("The car turns off")
        return self 

    

car = Car()
car.turn_on()\
.drive()\
.brake()\
.turn_off() ## calling all the functions 

# \ <----- line continuation symbol

car.turn_on().drive().brake().turn_off() # another way to chain it


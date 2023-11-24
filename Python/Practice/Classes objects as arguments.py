class Car:

    color = None


class Motorycle:
    
    color = None

def change_color(vehicle,color):
    vehicle.color = color

car_1 = Car()
car_2 = Car()
motorcycle_1 = Motorycle()

change_color(car_1,"Blue")
change_color(car_2,"Red")
change_color(motorcycle_1,"Yellow")

print(car_1.color)
print(car_2.color)
print(motorcycle_1.color)
from abc import ABC,abstractmethod

class Vehicle(ABC):

    @abstractmethod
    def go(self):
        pass

class Car(Vehicle):

    def go(self):
        print("The car is driving")

class Motorcycle(Vehicle):

    def go(self):
        print("The motorcycle is driving")



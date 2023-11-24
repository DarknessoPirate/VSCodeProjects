

class Prey:

    def flee(self):
        print("This animal flees")

class Predator:

    def hunt(self):
        print("This animal is hunting")


class Fish(Prey,Predator):
    pass

fish = Fish()
fish.flee()
fish.hunt()
import sys

class StringReverser9000:

    def __init__(self, zdanie):
        self.zdanie = zdanie
        self.reversed = " ".join(self.zdanie.split(" ")[::-1])


object = StringReverser9000("Jeden. Dwa. Trzy. Cztery.")
print(object.reversed)



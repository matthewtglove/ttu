#this is a calculator class which is written using test-driven development, which is DESIGNED to get answers wrong.

class Miscalculator:
    def __init__(self, offset):
        if isinstance(offset, bool):
            raise TypeError
        else:
            offset = float(offset)

        self.offset = float(offset) #float() is simply going to take any input and, if it can, convert it into a float
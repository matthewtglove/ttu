from random import randint

class Potion:
    def __init__(self, ing1: str, ing2: str):
        self.ing1 = ing1
        self.ing2 = ing2
        self.name = "Failed Decoction"
        self.value = 1

        # If you're only using one ingredient, then you're not making a potion!
        if (ing1 == ing2):
            return

        # Checks for successful potion creation
        if (ing1 in ["Vampire's Breath", "Witch's Tongue"] and ing2 in ["Vampire's Breath", "Witch's Tongue"]):
            self.name = "Elixir of Halitosis"
            self.value = randint(10, 50)
        if (ing1 in ["Toe of Frog", "Eye of Newt"] and ing2 in ["Toe of Frog", "Eye of Newt"]):
            self.name = "Philter of Amphibiosity"
            self.value = randint(750, 1000)
        if (ing1 in ["Adder's Fork", "Elephant's Proboscis"] and ing2 in ["Adder's Fork", "Elephant's Proboscis"]):
            self.name = "Draught of Eavesdropping"
            self.value = randint(500, 750)
        if (ing1 in ["Milk", "Marinara Sauce"] and ing2 in ["Milk", "Marinara Sauce"]):
            self.name = "Potion of Regret"
            self.value = randint(2, 40)
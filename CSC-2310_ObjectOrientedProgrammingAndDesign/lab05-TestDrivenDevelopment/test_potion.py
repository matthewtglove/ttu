import unittest
from potion import Potion


class TestPotion(unittest.TestCase):

    '''
    NOTE #1: These tests do not require setUp or tearDown methods, as we are using unique objects in each test.
    If the tests could be performed using equivalent objects, a setUp method would facilitate this.
    If the tests produced any artifacts (e.g. output files), a tearDown method would facilitate this.

    NOTE #2: I have organized these tests in a way that I feel may help in interpreting the intended
    functionality for the underlying code, by showing several combinations at once and what they are
    meant to produce. Realistically, I suggest these first four tests should be broken up into
    multiple, smaller tests.
    '''


    # This method tests for the code that will produce a Potion with the name "Elixir of Halitosis"
    def test_potion_elixir(self):

        # Creating four Potion objects, each with different arguments.
        self.potion_elixir_1 = Potion("Vampire's Breath", "Witch's Tongue")
        self.potion_elixir_2 = Potion("Witch's Tongue", "Vampire's Breath")
        self.potion_elixir_3 = Potion("Witch's Tongue", "Witch's Tongue")
        self.potion_elixir_4 = Potion("Vampire's Breath", "Vampire's Breath")

        # Testing that the combination of arguments produced the correct name.
        self.assertEqual(self.potion_elixir_1.name, "Elixir of Halitosis")
        self.assertEqual(self.potion_elixir_2.name, "Elixir of Halitosis")
        self.assertEqual(self.potion_elixir_3.name, "Failed Decoction")
        self.assertEqual(self.potion_elixir_4.name, "Failed Decoction")


    # This method tests for the code that will produce a Potion with the name "Philter of Amphibiosity"
    def test_potion_philter(self):

        # Creating four Potion objects, each with different arguments.
        self.potion_philter_1 = Potion("Toe of Frog", "Eye of Newt")
        self.potion_philter_2 = Potion("Eye of Newt", "Toe of Frog")
        self.potion_philter_3 = Potion("Eye of Newt", "Eye of Newt")
        self.potion_philter_4 = Potion("Toe of Frog", "Toe of Frog")

        # Testing that the combination of arguments produced the correct name.
        self.assertEqual(self.potion_philter_1.name, "Philter of Amphibiosity")
        self.assertEqual(self.potion_philter_2.name, "Philter of Amphibiosity")
        self.assertEqual(self.potion_philter_3.name, "Failed Decoction")
        self.assertEqual(self.potion_philter_4.name, "Failed Decoction")


    # This method tests for the code that will produce a Potion with the name "Draught of Eavesdropping"
    def test_potion_draught(self):

        # Creating four Potion objects, each with different arguments.
        self.potion_draught_1 = Potion("Adder's Fork", "Elephant's Proboscis")
        self.potion_draught_2 = Potion("Elephant's Proboscis", "Adder's Fork")
        self.potion_draught_3 = Potion("Elephant's Proboscis", "Elephant's Proboscis")
        self.potion_draught_4 = Potion("Adder's Fork", "Adder's Fork")

        # Testing that the combination of arguments produced the correct name.
        self.assertEqual(self.potion_draught_1.name, "Draught of Eavesdropping")
        self.assertEqual(self.potion_draught_2.name, "Draught of Eavesdropping")
        self.assertEqual(self.potion_draught_3.name, "Failed Decoction")
        self.assertEqual(self.potion_draught_4.name, "Failed Decoction")


    # This method tests for the code that will produce a Potion with the name "Potion of Regret"
    def test_potion_potion(self):

        # Creating four Potion objects, each with different arguments.
        self.potion_potion_1 = Potion("Milk", "Marinara Sauce")
        self.potion_potion_2 = Potion("Marinara Sauce", "Milk")
        self.potion_potion_3 = Potion("Marinara Sauce", "Marinara Sauce")
        self.potion_potion_4 = Potion("Milk", "Milk")

        # Testing that the combination of arguments produced the correct name.
        self.assertEqual(self.potion_potion_1.name, "Potion of Regret")
        self.assertEqual(self.potion_potion_2.name, "Potion of Regret")
        self.assertEqual(self.potion_potion_3.name, "Failed Decoction")
        self.assertEqual(self.potion_potion_4.name, "Failed Decoction")


    # This method tests the code that sets the value of "Elixir..."
    def test_elixir_value(self):
        self.potion_elixir = Potion("Vampire's Breath", "Witch's Tongue")
        self.assertTrue(10 <= self.potion_elixir.value <= 50)


    # This method tests the code that sets the value of "Philter..."
    def test_philter_value(self):
        self.potion_philter = Potion("Toe of Frog", "Eye of Newt")
        self.assertTrue(750 <= self.potion_philter.value <= 1000)


    # This method tests the code that sets the value of "Draught..."
    def test_draught_value(self):
        self.potion_draught = Potion("Adder's Fork", "Elephant's Proboscis")
        self.assertTrue(500 <= self.potion_draught.value <= 750)


    # This method tests the code that sets the value of "Potion..."
    def test_potion_value(self):
        self.potion_potion = Potion("Milk", "Marinara Sauce")
        self.assertTrue(2 <= self.potion_potion.value <= 40)


    # This method tests the code that sets the value of "Failed Decoction"
    def test_failure_value(self):
        self.potion_failure = Potion("Hope", "Fear")
        self.assertEqual(self.potion_failure.value, 1)


if __name__ == '__main__':
    unittest.main()

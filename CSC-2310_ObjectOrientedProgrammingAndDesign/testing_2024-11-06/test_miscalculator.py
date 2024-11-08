#this will be the tests for the miscalculator test-driven development project

import unittest
from miscalculator import Miscalculator

class TestMiscalculator(unittest.TestCase):

    def setUp(self):
        self.o1 = Miscalculator(1)


    def tearDown(self):
        pass
    
    def test_created_offset(self):
        self.assertEqual(self.o1.offset, 1)
    

    def test_created_offset_invalid(self):
        with self.assertRaises(TypeError):
            Miscalculator(None)

        with self.assertRaises(TypeError):
            Miscalculator(True)

        with self.assertRaises(TypeError):
            Miscalculator(False)

        with self.assertRaises(TypeError):
            Miscalculator([1, 2])

        with self.assertRaises(TypeError):
            Miscalculator((1, 2))
        
    def test_created_invalid_string(self):
        with self.assertRaises(ValueError):
            Miscalculator("Jim")

    def test_created_valid_string(self): #Test case for if string CAN be converted to float/int
        self.no = Miscalculator("3")
        self.assertEqual(self.no.offset, 3)

    def test_created_valid_string_float(self):
        self.no = Miscalculator("3.5")
        self.assertEqual(self.no.offset, 3.5)



if __name__ == "__main__":
    unittest.main()
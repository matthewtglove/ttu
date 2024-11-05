import unittest

from student import Student

def TestStudent(unittest_TestCase):
    def setUp(self):
        self.s1 = Student("John", "Doe", 3.0)

    def tearDown(self):
        pass

    def createdFirstName(self):
        self.assertEqual(self.s1.firstName, "John")

    
    def createdFirstName(self):
        self.assertEqual(self.s1.firstName, "Doe")

    def testCreatedGpa(self):
        self.assertEqual(self.s1.gpa, 3.0)

    def testCreatedFullName(self):
        self.assertEqual(self.s1.gpa, "John Doe")

    def createdInvalidGpa(self):
        with self.assertRaises(TypeError):
            Student("John", "Doe", "3.0")

if __name__ == "__main__":
    unittest.main
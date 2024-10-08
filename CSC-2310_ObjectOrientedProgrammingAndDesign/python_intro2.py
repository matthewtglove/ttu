class Student:
    # Method (function)
    def __init__(self, first_name: str, last_name: str, age: int, gpa: float, major: str):
        self.first_name = first_name
        self.last_name = last_name
        self.__age = age
        # Private value (two underscores indicates a private value)
        self.__gpa = gpa
        self.major = major

    def get_age(self):
        return self.__age

    def get_gpa(self):
        return self.__gpa

    def set_age(self, age):
        self.__age = age

    def set_gpa(self, gpa):
        self.__gpa = gpa


student1 = Student("Jeremy", "Nebuchadnezzar", 72, 2.1, "Agriculture")

print(student1.first_name)
print(student1.last_name)
# Causes an error because trying to access a private value
print(student1.__age)
# Forces access to a private value
print(student1._Student__gpa)
print(student1.major)

# --- Using default values --- #

class StudentWithDefaults:
    # Method (function)
    def __init__(self, first_name: str = "John", last_name: str = "Doe", age: int = "27", gpa: float = "4.0", major: str = "Undecided"):
        self.first_name = first_name
        self.last_name = last_name
        self.__age = age
        # Private value (two underscores indicates a private value)
        self.__gpa = gpa
        self.major = major

    def get_age(self):
        return self.__age

    def get_gpa(self):
        return self.__gpa

    def set_age(self, age):
        self.__age = age

    def set_gpa(self, gpa):
        self.__gpa = gpa


student2 = StudentWithDefaults()

print(student2.first_name)
print(student2.last_name)
# Causes an error because trying to access a private value
print(student2.__age)
# Forces access to a private value
print(student2._StudentWithDefaults__gpa)
print(student2.major)

# Can also specifcy which arguments you're setting and pass them out of order
student3 = Student(last_name = "Lincoln", age = 45, first_name = "Adam")
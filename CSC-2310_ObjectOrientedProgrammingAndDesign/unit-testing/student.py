class Student:
    def __init__(self, firstName: str, lastName: str, gpa: float):
        self.firstName = firstName
        self.lastName = lastName
        self.__gpa = gpa
    
    @property
    def fullName(self) -> str:
        return self.firstName + ' ' + self.lastName

    

    # body
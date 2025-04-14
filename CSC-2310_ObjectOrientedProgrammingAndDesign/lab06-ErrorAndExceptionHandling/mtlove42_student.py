
'''
This is a simple terminal menu program written by a TA in a previous semester.
The purpose of the program is to contain several errors for you to find and solve.

When run, the program should ask for three inputs:
1.) The index value to look up a student in a list of students.
2.) The total number of days that school has been in session.
3.) The total number of days the student has attended

The program will then return the student's attendance rate.
'''

import json

# Do not modify Student or School unless there is no alternative.
class Student:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def get_attendance_rate(self, days_present, total_days):
        if total_days == 0:
            return 0
        return days_present / total_days

class School:
    def __init__(self):
        self.students = []

    def add_student(self, student):
        self.students.append(student)

    def get_student_name(self, index):
        return self.students[index].name
    def get_student_age(self, index):
        return self.students[index].age

# Most of your work should be done in main()
def main():
    school = School()

    try:
        with open('students.json') as f:
            data = json.load(f)
    except FileNotFoundError:
        print("'students.json' file not found in the working directory.")
        while True:
            try:
                with open(input('What is the name of your student file? ')) as f:
                    data = json.load(f)
                    break
            except FileNotFoundError:
                print("File not found in the working directory.")
                continue
            except json.JSONDecodeError:
                print("File contains invalid JSON.")
                continue
    except json.JSONDecodeError:
        print("'student.json' contains invalid JSON.")
        while True:
            try:
                with open(input('What is the name of your student file? ')) as f:
                    data = json.load(f)
                    break
            except FileNotFoundError:
                print("File not found in the working directory.")
                continue
            except json.JSONDecodeError:
                print("File contains invalid JSON.")
                continue

    for x in data:
        school.add_student(Student(x['Name'], x['Age']))

    while True:
        try:
            index = int(input("Enter the index of the student (-1 to exit): "))
            if index == -1:
                print("Exiting program.")
                break
            name = school.get_student_name(index)
            age = school.get_student_age(index)
            print(name, age, '\n')
        except ValueError:
            print("Invalid input. Please try again.")
            continue
        except IndexError:
            print("Invalid index. Please enter a valid student index.")
            continue

        while True:
            try:
                total_days = int(input('How many days has school been in session this year? '))
            except ValueError:
                print("Invalid input. Please try again.")
            else:
                if total_days <= 0:
                    print("Total days must be greater than zero.")
                    continue
                break
            
        while True:
            try:    
                days_present = int(input('How many days has the student attended school this year? '))
            except ValueError:
                print("Invalid input. Please try again.")
            else:
                if days_present < 0:
                    print("Days present cannot be negative.")
                    continue
                if days_present > total_days:
                    print("There have not been that many days.")
                    continue
                break

        print(name, "'s attendance rate is", school.students[index].get_attendance_rate(days_present, total_days))

if __name__ == "__main__":
    main()

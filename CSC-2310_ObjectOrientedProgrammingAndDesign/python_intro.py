# Comment

# --- Decalre / Assign variables ---

var_1 = 1
var_2 = 1.0
var_3 = "one"

print(var_1)
print(var_2)
print(var_3)

variable_name_convention_is_snake_case = "Use it!"

class ClassNamesArePascalCase:
    class_variable = "A"

# prints <class 'int'>
print(type(var_1))


# --- Lists / Loops / Iteration ---

cool_list = [0, 1, 2, 3, 4]
messed_up_list = [0, 1.0, "Phillip", '?', True]

# Reverses the list. Does not return anything. Literally modifies the list.
cool_list.reverse()

for x in cool_list:
    print(x + 5)

# prints 0 1 2 3 4 (range stops at end value)
for x in range(5):
    print(x)

# prints 3 4 (inclusive starting point, exclusive stopping point)
for x in range(3, 5):
    print(x)

# Important: In Python, scope is determined by your whitespace, not brackets.

# while True:
#     print("Infinite")

x = 0
while x <= 3:
    print("Not infinite")
    x = x + 1

# --- User Input ---

# Note: input takes in input as a string...
user_choice_wrong = input("Please enter a number: ")

# ...so must cast to integer
user_choice = int(input("Please enter a number: "))

if user_choice == 7:
    print("You win!")
if user_choice != 7:
    print("You lose")

print(user_choice)

# --- Functions ---
# "def" for defining a function
def square_num(num):
    return num * num

# Prints 36
print(square_num(6))

# --- Type hints ---

# Specifying the type in the parameter (hey this looks like Typescript hmmmm)
def add_one(num: int):
    return num + 1

# We're expected to use type hints in class 👍

# Specify return types
def subtract_one(num: int) -> int:
    return num - 1
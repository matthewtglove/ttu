/*
	Title:  Lab2.cpp
	Author: YOUR NAME HERE!!!
	Date:  TODAY'S DATE HERE!!!
	Purpose:  Demonstrate your knowledge of recursive functions
*/

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
using namespace std;

// function prototypes for the recursive functions
int sumOfNumbers(int);
bool isMember(int *, int, int);
void stringReverser(string, int);
bool isPalindrome(string);
int multiply(int, int);

const int ARRAY_SIZE = 10;

int main()
{
	int choice, num, num1, num2;
	int myArray[ARRAY_SIZE];
	srand(time(NULL));
	string userString, userStrModified;

	do
	{

		cout << "\n\nWhat do you want to do?\n";
		cout << "\t1.  Sum of Numbers\n";
		cout << "\t2.  IsMember Array Function\n";
		cout << "\t3.  String Reverser\n";
		cout << "\t4.  Palindrome Detector\n";
		cout << "\t5.  Recursive Multiplication\n";
		cout << "\t6.  End the Program\n";
		cout << "CHOOSE 1-6:  ";
		cin >> choice;
		while (choice < 1 || choice > 6)
		{
			cout << "\nInvalid input!  CHOOSE 1-6:  ";
			cin >> choice;
		}
		switch (choice)
		{
		case 1:
			cout << "\n\nSUM OF NUMBERS\n";
			cout << "Enter an integer:  ";
			cin >> num;
			// print out the result of the sumOfNumbers function here
			cout << sumOfNumbers(num) << endl;
			break;

		case 2:
			for (int x = 0; x < ARRAY_SIZE; x++)
			{
				myArray[x] = (rand() % 100) + 1;
			}
			cout << "\n\nISMEMBER ARRAY FUNCTION\n";
			cout << "Enter an integer:  ";
			cin >> num;
			cout << "\nHere are the array values:  ";
			for (int x = 0; x < ARRAY_SIZE; x++)
			{
				cout << myArray[x] << " ";
			}
			cout << endl;
			// print if the value that the user entered is in the array or not here
			if (isMember(myArray, num, ARRAY_SIZE))
			{
				cout << "The value was found in the array!" << endl;
			}
			else
			{
				cout << "No value found in the array." << endl;
			}
			break;

		case 3:
			cout << "\n\nSTRING REVERSER\n";
			cout << "Enter a string and I will reverse it:  ";
			cin.ignore();
			getline(cin, userString);
			// call string reverser function here
			stringReverser(userString, userString.length());
			break;

		case 4:
			cout << "\n\nPALINDROME DETECTOR\n";
			cout << "Enter a string and I will tell you if it is a palindrome:  ";
			cin.ignore();
			getline(cin, userString);

			// change string to be all uppercase
			for (int x = 0; x < userString.length(); x++)
			{
				userString[x] = toupper(userString[x]);
			}

			// remove spaces and commas from string
			userStrModified = userString;
			for (int x = 0; x < userStrModified.size(); x++)
			{
				if (userStrModified[x] == ' ')
				{
					userStrModified.erase(x, 1);
				}
				if (userStrModified[x] == ',')
				{
					userStrModified.erase(x, 1);
				}
			}

			// print out whether the user's string is a palindrome or not here.
			cout << endl;
			if (isPalindrome(userStrModified))
			{
				cout << "Your string " << userString << " is a palindrome! How cool is that!" << endl;
				break;
			}
			cout << "Your string " << userString << " is not a palidrome. Big sad." << endl;
			break;

		case 5:
			cout << "\n\nRECURSIVE MULTIPLICATION\n";
			cout << "Enter in the first integer:  ";
			cin >> num1;
			cout << "\nEnter in the second integer:  ";
			cin >> num2;
			// print out the value returned from the multiply function here
			cout << endl;
			cout << "The product of these two values is: " << multiply(num1, num2) << endl;

			break;
		}
	} while (choice != 6);

	cout << "\n\nGOODBYE!\n\n";
	return 0;
}

int sumOfNumbers(int sum)
{
	// The check to stop the recursion once the sum reaches 0 (aka Base Case)
	if (sum == 0)
	{
		return sum;
	}
	return sum + sumOfNumbers(sum - 1);
}

bool isMember(int *inputArray, int key, int size)
{
	if (size == 0)
	{
		return false;
	}
	if (inputArray[size - 1] == key)
	{
		return true;
	}
	return isMember(inputArray, key, (size - 1));
}

void stringReverser(string inputString, int length)
{
	// The below 4 lines are a completely optional check, they just prevent the program from outputting nothing to the console in the case of an even string
	if (length == 0)
	{
		return;
	}

	cout << inputString[length - 1];

	// The check to stop the recursion entirely
	if (length <= 1)
	{
		return;
	}
	stringReverser(inputString.substr(1, length - 2), length - 2);
	cout << inputString[0];
}

bool isPalindrome(string inputString)
{
	// The check to stop the recursion (if there is only one or 0 more letters to check in the string, then it must be a palidrome!)
	if (inputString.length() <= 1)
	{
		return true;
	}
	if (inputString[0] == inputString[inputString.length() - 1])
	{
		return isPalindrome(inputString.substr(1, inputString.length() - 2));
	}
	return false;
}

int multiply(int num1, int num2)
{
	// The Base Case
	if (num1 == 0)
	{
		return 0;
	}

	return num2 + multiply(num1 - 1, num2);
}
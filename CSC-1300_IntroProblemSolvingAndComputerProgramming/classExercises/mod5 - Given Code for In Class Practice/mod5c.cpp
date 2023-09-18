/*
	Title: mod5c.cpp
	Author: Matthew Love
	Date: 2023-09-15, Fri
	Purpose:  Practice for loops (in-class practice)
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Asks the user if they would like to run the program again. Validates response and only accepts a string begining in 'y' or 'n' (not case sensitive)
bool askRunAgain(string prompt = "Would you like to run this program again? (y/n) ")
{
	while (true)
	{
		cout << prompt;

		// Validates user input - reads only the first character they input
		string input;
		getline(cin, input);
		char runAgainResponse = tolower(input[0]);

		if (runAgainResponse == 'y')
		{
			return true;
			break;
		}
		else if (runAgainResponse == 'n')
		{
			return false;
			break;
		}
	}
}

int main()
{
	cout << "\nDnD Stat Roll\n";
	cout << "1 - Strength\n";
	cout << "2 - Dexterity\n";
	cout << "3 - Constitution\n";
	cout << "4 - Intelligence\n";
	cout << "5 - Wisdom\n";
	cout << "6 - Charisma\n";

	cout << "\nFor your character stats, I am rolling a"
			" 6-sided die until an ODD dice roll \noccurs more "
			"than once OR the total of all dice rolled so far is equal\n"
			"to or exceeds 20, whichever comes first.\n\nIf the total "
			"exceeds 20, then the last dice roll is removed.\n\n"
			"I will then print the result for each ability score.\n\n";

	while (true)
	{
		int total;		  // total for the particular ability
		int oddRollCount; // holds the number of times an ODD roll occurred
		int roll;		  // Value of an individual roll
		int rollIndex;	  // The roll number
		srand(time(0));

		// Rolls random values for each of the 6 abilities
		for (int abilityIndex = 1; abilityIndex <= 6; abilityIndex++)
		{
			// Declares the values so that they're reset for every ability
			total = 0;
			oddRollCount = 0;
			rollIndex = 1;

			// Keeps rolling until 2 odd rolls or the total is 20 or above
			while (oddRollCount < 2 && total < 20)
			{
				roll = ((rand() % 6) + 1); // Random number 1-6
				cout << "roll " << rollIndex << ": " << roll << endl;

				// Checks if odd
				if (roll % 2 == 1)
				{
					oddRollCount++;
				}

				total += roll;
				rollIndex++;
			}

			// If total is above 20, it subtracts the last value
			if (total > 20)
			{
				total -= roll;
			}

			cout << ">>>>> Ability " << abilityIndex << " Score is " << total << endl;
			cout << endl;
		}

		// Gets output of askRunAgain to determine if it should run the full program again (the while loop)
		if (askRunAgain("Roll new abilities? (y/n) "))
		{
			continue; // Runs the while loop again
		}
		else
		{
			break; // Breaks out of the while loop
		}
	}
	return 0;
}
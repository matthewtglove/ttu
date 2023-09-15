/*
	Title:    mod5c.cpp
	Author: Matthew Love
	Date: 2023-09-15, Fri
	Purpose:  Practice for loops (in-class practice)
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int diceRoll()
{
	// seed the random number generator
	srand(time(0));

	return (rand() % 6);
}

// Function for asking the user if they'd like to roll again
bool askRunAgain(string prompt = "Would you like to run this program again? (y/n) ")
{
	while (true)
	{
		cout << prompt;

		// Parses user input - repeats only the first character they input
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
	int total;		  // total for the particular ability
	int oddRollCount; // holds the number of times an ODD roll occurred

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

	// ADD ALL YOUR CODE BELOW
	// MAKE SURE YOU HAVE AT LEAST ONE FOR LOOP AND TWO LOOPS IN TOTAL.
	// USE THE PROVIDED VARIABLES THAT HAVE BEEN DEFINED
	while (true)
	{
		bool abilityConditionMet = false;
		int abilityIndex = 1;
		for (int rollNum = 1; !abilityConditionMet; rollNum++)
		{
			int roll = diceRoll();
			cout << "roll " << rollNum << ": " << roll << endl;
			oddRollCount++;
			total += roll;

			(oddRollCount > 1 || total >= 20) ? abilityConditionMet = true : abilityConditionMet = false;

			if (abilityConditionMet)
			{
				cout << ">>>>> Ability " << abilityIndex << " Score is " << total << endl;
				cout << abilityIndex++;
			}
		}
		if (askRunAgain("Roll again? (y/n) "))
		{
			continue;
		}
		else
		{
			break;
		}
	}

	return 0;
}
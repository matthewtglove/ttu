/*
	Title: mod5b In-Class Practice
	Author: Matthew Love
	Date: 2023-09-15, Fri
	Description: Generate random number between 70 and 770. Calculate sum of random numbers. Ask user to guess the random number. Ask the user if they want to play again after guessing.
*/
#include <iostream>
#include <cstring>
#include <time.h>
using namespace std;

/*
Updates to follow class policy:
	- Not using while(true) and control statements
*/

// Requires the user to input an integer
int reqIntFromUser()
{
	int convertedInput = 0;
	bool successfulConversion = false;
	while (!successfulConversion)
	{
		try
		{
			string input;
			getline(cin, input);
			convertedInput = stoi(input);
			successfulConversion = true;
		}
		catch (...)
		{
			cout << "Please enter an integer: ";
		};
	}
	return convertedInput;
}

// Asks the user if they would like to run the program again. Validates response and only accepts a string begining in 'y' or 'n' (not case sensitive)
bool askRunAgain(string prompt = "Would you like to run this program again? (y/n) ")
{
	bool runAgain;
	bool validInput;
	while (!validInput)
	{
		cout << prompt;

		// Validates user input - reads only the first character they input
		string input;
		getline(cin, input);
		char runAgainResponse = tolower(input[0]);

		if (runAgainResponse == 'y')
		{
			runAgain = true;
			validInput = true;
		}
		else if (runAgainResponse == 'n')
		{
			runAgain = false;
			validInput = true;
		}
	}
	return runAgain;
}

int main()
{
	bool playAgain = false; // Used to rerun do-while loop
	do
	{

		int rnum = 0;  // rnum holds the random number generated
		int trnum = 0; // trnum is set to the total number of random numbers that need to be generated
		int i = 0;	   // i is a counter for the while loop that generates the random numbers
		int guess = 0; // guess will hold the user's guess
		int low = 7;   // low is the lower limit for the random number generated
		int high = 77; // high is the upper limit for the random number generated

		// seed the random number generator
		srand(time(0));

		// generates a random number between the low & high range inclusively
		rnum = rand() % ((high - low) + 1) + low;

		cout << "\n\nGuess a number between " << low << " and " << high << ": ";
		guess = reqIntFromUser();

		// Only completes the while loop so that it will validate if the user entered a number in the valid range (7 to 77). Both 7 & 77 are included in the valid range.
		while (guess < low || guess > high)
		{
			cout << "The number is not in the valid range!\n";
			cout << "Guess a number between " << low << " and " << high << ":  ";
			guess = reqIntFromUser(); // Gets a new guess if they don't guess within the range
		}

		if (guess == rnum)
			cout << "\n\nYou have gained the super power where skittles can shoot from your fingertips!\n\n";
		else
			cout << "\n\nYou get no super powers.  The random number was " << rnum << endl
				 << endl;

		// Uses the boolean returned by askRunAgain() to determine playAgain
		if (askRunAgain("Would you like to play again? (y/n) "))
		{
			playAgain = true;
		}
		else
		{
			playAgain = false;
		}

	} while (playAgain);

	return 0;
}
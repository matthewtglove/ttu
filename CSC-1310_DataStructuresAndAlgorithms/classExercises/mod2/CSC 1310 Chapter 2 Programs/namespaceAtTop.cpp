/*
	Title:  namespaceAtTop.cpp
	Author:  April Crockett
	Date:  8/30/2019
	Purpose:  program with using namespace std; at top
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main ()
{
	const int MIN = 1;
	const int MAX = 101;
	string name;
	
	int count = 0,		//Number of times through the loop to get correct answer
		randomNum,		//Randomly generated number to guess
		userGuess;		//Users guess to discover randomNum
	char userYN;		//Does the user want to keep playing
	
	//seed the random number generator
	srand (time(NULL));
	
	cout << "\n\nWhat is your name?\n";
	getline(cin, name);
	
	
	cout << name <<", are you ready to play (y/n)? ";
	cin >> userYN;
	
	//Loop through game as long as they want to play
	while (userYN == 'y' || userYN == 'Y')
	{
		//Reset count and get a random number
		count = 1;
		randomNum = rand()%(MAX - MIN) + MIN;
		do {
			//Input Validation
			do {
				cout << "\nEnter your guess : ";
				cin >> userGuess;
				if(userGuess < MIN || userGuess >=MAX)
					cout << "\nYou entered an invalid number.  Choose between " << MIN << " and " << MAX << ".";
			} while (userGuess < MIN || userGuess >= MAX);
			
			//Check their guess against RandomNum
			if (userGuess < randomNum)
			{
				cout << "Too Low" << endl;
				count++;
			}
			else if (userGuess > randomNum)
			{
				cout << "Too High" << endl;
				count++;
			}
		} while (userGuess != randomNum);
		cout << "Correct!  You got it in " << count << " tries!" << endl;
		cout << "Are you ready to play again (y/n)? ";
		cin >> userYN;
	}
	return 0;
}
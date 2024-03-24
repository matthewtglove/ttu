/*
	Title:  namespaceThroughoutCode.cpp
	Author:  April Crockett
	Date:  8/30/2019
	Purpose:  to demonstrate what a program would look like if you did not put
	using namespace std; at the top of the code.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

int main ()
{
	const int MIN = 1;
	const int MAX = 101;
	std::string name;
	
	int count = 0,		//Number of times through the loop to get correct answer
		randomNum,		//Randomly generated number to guess
		userGuess;		//Users guess to discover randomNum
	char userYN;		//Does the user want to keep playing
	
	//seed the random number generator
	srand (time(NULL));
	
	std::cout << "\n\nWhat is your name?\n";
	getline(std::cin, name);
	
	
	std::cout << name <<", are you ready to play (y/n)? ";
	std::cin >> userYN;
	
	//Loop through game as long as they want to play
	while (userYN == 'y' || userYN == 'Y')
	{
		//Reset count and get a random number
		count = 1;
		randomNum = rand()%(MAX - MIN) + MIN;
		do {
			//Input Validation
			do {
				std::cout << "\nEnter your guess : ";
				std::cin >> userGuess;
				if(userGuess < MIN || userGuess >=MAX)
					std::cout << "\nYou entered an invalid number.  Choose between " << MIN << " and " << MAX << ".";
			} while (userGuess < MIN || userGuess >= MAX);
			
			//Check their guess against RandomNum
			if (userGuess < randomNum)
			{
				std::cout << "Too Low" << std::endl;
				count++;
			}
			else if (userGuess > randomNum)
			{
				std::cout << "Too High" << std::endl;
				count++;
			}
		} while (userGuess != randomNum);
		std::cout << "Correct!  You got it in " << count << " tries!" << std::endl;
		std::cout << "Are you ready to play again (y/n)? ";
		std::cin >> userYN;
	}
	return 0;
}
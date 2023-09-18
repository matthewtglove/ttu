/*
	Title:  mod4_messedUpP.cpp
	Purpose: In class practice for debugging
	Date:  2023-09-08, Fri
	Author: Matthew Love
*/

#include <iostream>
using namespace std;

int main()
{
	int hungerLevel;
	char answer1, answer2, answer3;
	cout << "\n\nSHOULD YOU EAT IT?";
	cout << "\nOn a scale from 1 to 5 with 1 being not hungry ";
	cout << "at all and 5 being starving, how hungry are you?\n";
	cin >> hungerLevel;

	if (hungerLevel == 1)
		cout << "\nDon\'t eat it.\n";
	else if (hungerLevel == 5)
		cout << "\nEat it no matter what.\n";
	else
	{
		cout << "Has a dog licked it? (y or n)\n";
		cin >> answer1;
		cout << "Is it on someone else's plate? (y or n)\n";
		cin >> answer2;
		cout << "Is if food? (y or n)\n";
		cin >> answer3;

		if ((answer1 == 'y' || answer2 == 'y') && answer3 == 'y')
		{
			cout << "\nEat it anyway. At least it is food.\n";
		}
		else if ((answer2 == 'y' || answer3 == 'y') && answer1 == 'y')
		{
			cout << "\nEat it anyway. Maybe you didn\'t really see the dog lick it.\n";
		}
		else
		{
			cout << "\nBetter not eat it.\n";
		}
	}

	return 0;
}
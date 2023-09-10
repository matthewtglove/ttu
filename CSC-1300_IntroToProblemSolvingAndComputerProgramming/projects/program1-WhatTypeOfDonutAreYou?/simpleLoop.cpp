/*
	Title:  	simpleLoop.cpp
	Date:		8/19/2023
	Author:		April Crockett
	Purpose:	To demonstrate a loop like the one you will need
				for Program 1
				
				Also prints selected lyrics from a crazy old song.
				https://www.youtube.com/watch?v=3Fn36l_z3WY
*/

#include <iostream>
using namespace std;

int main()
{
	bool runagain = true;
	char response; //response must be a char because we want the user to enter 'y' or 'n'
	
	while(runagain)  //you can also write while(runagain==true)
	{
		cout << "\n\nNow you see I\'ve gone completely out of my mind. and.\n";
		cout << "They\'re coming to take me away ha ha.\n";
		cout << "they\'re coming to take me away,\n";
		cout << "Ho ho, hee hee, ha ha, To the happy home\n";
		cout << "with trees and flowers and chirping birds\n";
		cout << "and basket weavers who sit and smile and twiddle\n";
		cout << "their thumbs and toes\n\n";
		
		//ask the user if they want to run the program again.
		cout << "Do you want to run the program again? (y/n)\n";
		cin >> response;
		
		if(response != 'y')  //so this loop will repeat if user entered in anything other than 'y'
			runagain = false;
	}
	return 0;
}
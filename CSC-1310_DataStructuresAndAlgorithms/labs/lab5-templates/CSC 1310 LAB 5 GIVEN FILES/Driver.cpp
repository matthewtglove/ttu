/*****************************************************************
	Title:  	Driver.cpp (given file for LAB 5)
	Date:  		2/25/2021
	Author: 	April Crockett
	Purpose:	CSC 1310 LAB 5 Linked List Practice
******************************************************************/

#include <iostream>
#include <cctype>  //for the toupper function
#include <limits>  //to use numeric_limits
#include "LinkedList.h"
#include "Pickle.h"

using namespace std;

void printPickle();

int main()
{
	LinkedList<Pickle> list;
	int num;
	char response;
	
	//Print some cute pickle art
	printPickle();
	cout << "\nWelcome to the pickle program!\nPress enter to continue!\n";
	cin.get();
	
	//ADD SOME PICKLES
	cout << "\n\nAdding some pickles to the linked list!\n\n";
	Pickle pickle1("Bread-and-butter", false, true);
	list.appendNode(pickle1);
	
	Pickle pickle2("Gherkin", true, true);
	list.appendNode(pickle2);
	
	Pickle pickle3("Kosher Dill", true, false);
	list.appendNode(pickle3);
	
	Pickle pickle4("Hungarian", false, false);
	list.appendNode(pickle4);
	
	Pickle pickle5("Lime", false, false);
	list.appendNode(pickle5);
	
	cout << "\n\nNow printing out the pickles:\n\n";
	list.displayList();
	
	cout << "\n\nWhich pickle do you want to eat (and therefore remove from the list)?\nChoose the node number (1-5):  ";
	cin >> num;
	
	//input validation loop
	while(!cin || num < 1 || num > 5) //!cin tests if the input “good” bit (ios::good) is not true
	{
		cin.clear(); //sets ios::good back to true and all other bits back to false
		/*
			The ignore below will remove all leftover characters or numbers 
			from keyboard buffer to start with fresh input.
			Also, you must #include <limits> to use numeric_limits
		*/
		cin.ignore(numeric_limits<streamsize>::max(),'\n');     
		cout << "\nOops!  You entered something wonky.  Please enter a number 1-5:\t";
		cin >> num;
	}
	
	list.deleteNode(num-1);
	
	cout << "\n\nWould you like to display the list of pickles again? (y/n)\t";
	cin >> response;
	
	//input validation loop
	while(!cin || toupper(response) != 'Y' && toupper(response) != 'N') 
	{
		cin.clear(); 
		cin.ignore(numeric_limits<streamsize>::max(),'\n');     
		cout << "\nOops!  You entered something wonky.  Please enter y or n:\t";
		cin >> response;
	}

	if(toupper(response) == 'Y')
	{
		cout << "\n\nNow printing out the pickles:\n\n";
		list.displayList();
	}
	cout << "Press enter to continue!\n";
	cin.get();
	cout << "\n\n----------------------------------------------------------------------------\n";
	cout << "Have a lovely day!\n(Now the destructor for LinkedList class will be called)\n\n";
	
	return 0;
}

/*
	Function:  printPickle()
	Purpose:   print a cute pickle in ASCII art to the screen
*/
void printPickle()
{
	cout << "                                          ##\n";
	cout << "                                           ##\n";
	cout << "                                        ##########/,\n";
	cout << "                                      ####/#//#//((/////\n";
	cout << "                                    ////#//(#///(////(////(\n";
	cout << "                                   ///(/#//(//////(////(/////\n";
	cout << "                                   /(/(/////(//////((////(////\n";
	cout << "                                   ////(/////(///////(/////////         %.%\n";
	cout << "                                    //////(////(/////*///     //        #%%%%\n";
	cout << "                                     ///(///     //////(//. | ///      ,%%\n";
	cout << "                                      //////*  | ///*%&&(/////(///    %%%\n";
	cout << "                                      ,///(//////((//////(/////(//*%%%%\n";
	cout << "                                       ////(//////(//////(/////(//%,\n";
	cout << "                           %%%         /////(//(/////////(///(////,\n";
	cout << "                          #  %%%%@     /////(/////(///////(///////.\n";
	cout << "                                 .&%%%/////(//////(/////(/(////(//\n";
	cout << "                                     /////(//(///(///////((////(//\n";
	cout << "                                   (//(/(////////(////*//(/////(/\n";
	cout << "                                  /////(///////((///////(/////(/\n";
	cout << "                                 */*/(////////((///////((////(/\n";
	cout << "                                 ///(////////(////////(////(((\n";
	cout << "                                 ///(////////////////(/////(\n";
	cout << "                                  //(/(////////////(/////(*\n";
	cout << "                                   ,(/////((////((/////(\n";
	cout << "                                       //////((////&&&\n";
	cout << "                                        &%%       &%%%\n";
	cout << "                                         %%%       &%%\n";
	cout << "                                          &%%       @&&\n";
	cout << "                                          %&%%     /%&,\n";
}
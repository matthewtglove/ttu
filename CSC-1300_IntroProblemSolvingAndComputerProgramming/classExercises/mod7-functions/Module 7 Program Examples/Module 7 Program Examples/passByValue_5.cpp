/*********************************************
	Title: 		passByValue_5.cpp
	Author:  	April R Crockett
	Date:  		February1 9, 2009
	Purpose:  	This is a menu-driven program 
				that makes a function call
				for each selection the user 
				makes.
**********************************************/

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void showMenu();
void showFees(double, int);

int main()
{
	int choice;  
	int months;  

	// Set up numeric output formatting.
	cout << fixed << showpoint << setprecision(2);

	do
	{
		// Display the menu and get the user's choice.
		showMenu();
		cin >> choice;

		// Validate the menu selection.
		while (choice < 1 || choice > 4)
		{
			cout << "Please enter a valid menu choice: ";
			cin >> choice;
		}

		// If the user does not want to quit, proceed.
		if (choice != 4)
		{
			// Get the number of months.
			cout << "For how many months? ";
			cin >> months;

			// Display the membership fees.
			switch (choice)
			{
				case 1:  
					showFees(40.0, months);
					break;
				case 2:
					showFees(20.0, months);
					break;
				case 3:
					showFees(30.0, months);
			}
		}
	} while (choice != 4);
	
	return 0;
}

/**********************************************************
	Function Name:  	showMenu()
	Function Purpose:	displays the menu
***********************************************************/
void showMenu()
{
   cout << "\n\t\tHealth Club Membership Menu\n\n"
        << "1. Standard Adult Membership\n"
        << "2. Child Membership\n"
        << "3. Senior Citizen Membership\n"
        << "4. Quit the Program\n\n"
        << "Enter your choice: ";
}

/**********************************************************
	Function Name:  	showFees()
	Function Purpose:	The memberRate parameter the 
						monthly membership rate and the 
						months parameter holds the number 
						of months. The function displays 
						the total charges.
***********************************************************/
void showFees(double memberRate, int months)
{
    cout << "The total charges are $"
         << (memberRate * months) << endl;
}



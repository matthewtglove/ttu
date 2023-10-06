/*********************************************
	Title: 		staticLocalVar.cpp
	Author:  	April R Crockett
	Date:  		February1 9, 2009
	Purpose:  	This program uses a static
				local variable
**********************************************/

#include <iostream>
using namespace std;

void showStatic(); // Function prototype

int main()
{
	// Call the showStatic function five times.
	for (int count = 0; count < 5; count++)
		showStatic();
	
	//cout << endl << "statNum: " << statNum << endl;
	return 0;
}

/**********************************************************
	Function Name:  	getBasePay()
	Function Purpose:	statNum is a static local variable. 
						Its value is displayed and then 
						incremented just before the 
						function returns. 
***********************************************************/
void showStatic()
{
	int num = 0;
	static int statNum = 0;
	
	cout << "num is " << num << endl;
	cout << "statNum is " << statNum << endl;
	
	num++;
	statNum++;
}








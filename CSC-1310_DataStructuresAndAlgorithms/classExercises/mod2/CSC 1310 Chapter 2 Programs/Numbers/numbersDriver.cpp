/*
	Title:  numbersDriver.cpp
	Author:  April Crockett
	Purpose: demonstrate a NumbersInt and NumbersDouble class
*/

#include <iostream>
#include "NumbersInt.h"
#include "NumbersDouble.h"
using namespace std;

int main()
{
	int num1, num2;
	double num1f, num2f;
	
	cout << "\n\nEnter in the first floating point number.\n";
	cin >> num1f;
	cout << "\n\nEnter in the second floating point number.\n";
	cin >> num2f;
	
	NumbersDouble myNumsf(num1f, num2f);
	myNumsf.print();
	cout << "\n\nTotal:  " << myNumsf.add();
	cout << "\nAverage:  " << myNumsf.average();
	cout << "\nHighest:  " << myNumsf.getHighest();
	cout << "\nLowest:  " << myNumsf.getLowest();
	myNumsf.swap();
	cout << "\n\nAfter Swapping the values are...\n";
	myNumsf.print();
	
	
	cout << "\n\nEnter in the first integer number.\n";
	cin >> num1;
	cout << "\n\nEnter in the second integer number.\n";
	cin >> num2;
	
	NumbersInt myNums(num1, num2);
	myNums.print();
	cout << "\n\nTotal:  " << myNums.add();
	cout << "\nAverage:  " << myNums.average();
	cout << "\nHighest:  " << myNums.getHighest();
	cout << "\nLowest:  " << myNums.getLowest();
	myNums.swap();
	cout << "\n\nAfter Swapping the values are...\n";
	myNums.print();	
	cout << endl;
	
	return 0;
}
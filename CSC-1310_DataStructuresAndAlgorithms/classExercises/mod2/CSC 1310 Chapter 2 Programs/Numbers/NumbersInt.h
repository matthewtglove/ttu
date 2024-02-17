/*
	Title:  NumbersInt.h
	Author:  April Crockett
	Purpose: demonstrate a Numbers class that specifically works with integers only
*/

#ifndef NUMBERSINT_H
#define NUMBERSINT_H

#include <iostream>
using namespace std;


class NumbersInt
{
	private:
		int number1;
		int number2;
	
	public:
		NumbersInt(int one, int two)
		{
			number1 = one;
			number2 = two;
		}
		int add()
		{
			return number1 + number2;
		}
		
		float average()
		{
			return ((number1 + number2) / 2.0);
		}
		
		void swap()
		{
			int temp = number1;
			number1 = number2;
			number2 = temp;
		}
		
		void print()
		{
			cout << "Number 1: " << number1 << endl;
			cout << "Number 2: " << number2 << endl;
		}
		
		int getHighest()
		{
			if(number1 > number2)
				return number1;
			else if(number2 > number1)
				return number2;
			else
				return -1;
		}
		
		int getLowest()
		{
			if(number1 < number2)
				return number1;
			else if(number2 < number1)
				return number2;
			else
				return -1;
		}
		
		void setNumberOne(int num)
		{
			number1 = num;
		}
		void setNumberTwo(int num)
		{
			number2 = num;
		}
		int getNumberOne()
		{
			return number1;
		}
		int getNumberTwo()
		{
			return number2;
		}

};

#endif
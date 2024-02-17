/*
	Title:  NumbersDouble.h
	Author:  April Crockett
	Purpose: demonstrate a Numbers class that specifically works with doubles only
*/

#ifndef NUMBERSDOUBLE_H
#define NUMBERSDOUBLE_H

#include <iostream>
using namespace std;

class NumbersDouble
{
	private:
		double number1;
		double number2;
	
	public:
		NumbersDouble(double one, double two)
		{
			number1 = one;
			number2 = two;
		}
		double add()
		{
			return number1 + number2;
		}
		
		float average()
		{
			return ((number1 + number2) / 2.0);
		}
		
		void swap()
		{
			double temp = number1;
			number1 = number2;
			number2 = temp;
		}
		
		void print()
		{
			cout << "Number 1: " << number1 << endl;
			cout << "Number 2: " << number2 << endl;
		}
		
		double getHighest()
		{
			if(number1 > number2)
				return number1;
			else if(number2 > number1)
				return number2;
			else
				return -1;
		}
		
		double getLowest()
		{
			if(number1 < number2)
				return number1;
			else if(number2 < number1)
				return number2;
			else
				return -1;
		}
		
		void setNumberOne(double num)
		{
			number1 = num;
		}
		void setNumberTwo(double num)
		{
			number2 = num;
		}
		double getNumberOne()
		{
			return number1;
		}
		double getNumberTwo()
		{
			return number2;
		}

};

#endif
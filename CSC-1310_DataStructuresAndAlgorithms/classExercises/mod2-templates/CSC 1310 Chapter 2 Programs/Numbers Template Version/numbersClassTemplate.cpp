/*
	Title: numbersClassTempalte.cpp
	Author: April Crockett
	Date:  2019
	Purpose: demonstrate a class template
*/

#include <iostream>
using namespace std;

template<typename BooYah>
class Numbers
{
	private:
		BooYah number1;
		BooYah number2;
	
	public:
		Numbers(BooYah one, BooYah two)
		{
			number1 = one;
			number2 = two;
		}
		BooYah add()
		{
			return number1 + number2;
		}
		
		float average()
		{
			return ((number1 + number2) / 2.0);
		}
		
		void swap()
		{
			BooYah temp = number1;
			number1 = number2;
			number2 = temp;
		}
		
		void print()
		{
			cout << "Number 1: " << number1 << endl;
			cout << "Number 2: " << number2 << endl;
		}
		
		BooYah getHighest()
		{
			if(number1 > number2)
				return number1;
			else if(number2 > number1)
				return number2;
			else
				return -1;
		}
		
		BooYah getLowest()
		{
			if(number1 < number2)
				return number1;
			else if(number2 < number1)
				return number2;
			else
				return -1;
		}
		
		void setNumberOne(BooYah num);

		void setNumberTwo(BooYah num)
		{
			number2 = num;
		}
		BooYah getNumberOne()
		{
			return number1;
		}
		BooYah getNumberTwo()
		{
			return number2;
		}

};

template <typename BooYah>
void Numbers::setNumberOne(BooYah num)
{
	number1 = num;
}

int main()
{	
	double num1, num2;
	
	cout << "\n\nEnter in the first floating point number.\n";
	cin >> num1;
	cout << "\n\nEnter in the second floating point number.\n";
	cin >> num2;
	
	Numbers<double> myNums(num1, num2);
	myNums.print();
	cout << "\n\nTotal:  " << myNums.add();
	cout << "\nAverage:  " << myNums.average();
	cout << "\nHighest:  " << myNums.getHighest();
	cout << "\nLowest:  " << myNums.getLowest();
	myNums.swap();
	cout << "\n\nAfter Swapping the values are...\n";
	myNums.print();
	cout << endl;
	
	int num1I, num2I;
	
	cout << "\n\nEnter in the first integer number.\n";
	cin >> num1I;
	cout << "\n\nEnter in the second integer number.\n";
	cin >> num2I;
	
	Numbers<int> myNumsI(num1I, num2I);
	myNumsI.print();
	cout << "\n\nTotal:  " << myNumsI.add();
	cout << "\nAverage:  " << myNumsI.average();
	cout << "\nHighest:  " << myNumsI.getHighest();
	cout << "\nLowest:  " << myNumsI.getLowest();
	myNumsI.swap();
	cout << "\n\nAfter Swapping the values are...\n";
	myNumsI.print();
	cout << endl;
	
	return 0;
}




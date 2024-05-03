/*
	Title:  fibonacci.cpp
	Author:  April Crockett
	Date:  11/1/2018
	Purpose:  Demonstrate fibonacci numbers (simple recursive solution)
*/
#include <iostream>
#include <iomanip>
using namespace std;

double fib(int);

const int SIZE = 300;
int main()
{
	cout << "The first " << SIZE << " Fibonacci numbers are:\n";
	cout << setprecision(63);
	for (int x = 1; x < SIZE; x++)
		cout << "\nSequence #" << x << ": " << fib(x);
	cout << endl;
	return 0;
}

double fib(int n)
{
	if (n == 1 || n == 2)
		return 1;                       // Base case
	else
		return fib(n - 1) + fib(n - 2); // Recursive case
}





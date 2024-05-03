/*
	Title:  fibonacci_dp.cpp
	Author:  April Crockett
	Date:  11/1/2018
	Purpose:  Demonstrate dynamic programming with fibonacci numbers
*/

#include <iostream>
#include <iomanip>
using namespace std;

double fib(int, double*);
const int SIZE = 300;
int main()
{
	double memo[SIZE] = {0};//memoize
	cout << "The first " << SIZE << " Fibonacci numbers are:\n";
	cout << setprecision(64);
	for (int x = 1; x < SIZE; x++)
	{
		cout << "\nSequence #" << x << ": " << fib(x, memo) << "\n";
	}
	cout << endl;
	return 0;
}

double fib(int n, double *memo)
{
	double result;
	if(memo[n] != 0.0)					// BASE CASE 
		return memo[n];
	if (n == 1 || n == 2)
		result = 1;                       // BASE CASE
	else
		result = fib(n - 1, memo) + fib(n - 2, memo); // Recursive case
	memo[n] = result;
	return result;
}





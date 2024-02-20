/*
	Title: stack_STL.cpp
	Author:  April
	Date:  2/18/2019
	Purpose:  demonstrate the stack from the C++ STL
*/

#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> s;
	cout << "\n\nPushing 10, 30, 20, 5, and then 1\n";
	s.push(10);
	s.push(30);
	s.push(20);
	s.push(5);
	s.push(1);
	
	cout << "\nCurrent size of stack:  " << s.size();
	
	cout << "\n\nGetting ready to pop:  " << s.top();
	
	s.pop();
	
	//show the rest of the stack (and pop)
	while(!s.empty())
	{
		cout << "\t" << s.top();
		s.pop();
	}
	cout << endl << endl;
	
	return 0;
}
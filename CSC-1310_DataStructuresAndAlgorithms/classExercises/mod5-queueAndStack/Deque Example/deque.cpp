#include<deque>
#include <iostream>
using namespace std;

int main()
{
	deque<string> colors;
	
	colors.push_front("Blue");
	colors.push_back("Red");
	colors.push_back("Yellow");
	colors.push_back("Orange");
	colors.push_back("Brown");
	colors.push_front("Green");
	
	cout << "\n\nNumber of colors in deque:  " << colors.size() << endl;
	cout << "\n\nFavorite Color is at the front of the deque:  " << colors.front() << endl;
	cout << "Least favorite color is at the back of the deque: " << colors.back() << endl;
	
	cout << "\n\nRemoving the least favorite color.\n";
	colors.pop_back();
	
	cout << "\n\nNumber of colors in deque:  " << colors.size() << endl;
	
	cout << "\n\nRemoving the most favorite color.\n";
	colors.pop_front();
	
	cout << "\n\nNumber of colors in deque:  " << colors.size() << endl;
	
	
	return 0;
	
}









#include <queue>
#include <iostream>
using namespace std;

int main()
{
	queue<string> restaurant_waitlist;
	
	restaurant_waitlist.push("Clint Eastwood");
	restaurant_waitlist.push("Jackie Chan");
	restaurant_waitlist.push("Lee Van Cleef");
	restaurant_waitlist.push("Charles Bronson");
	restaurant_waitlist.push("Sylvester Stallone");
	restaurant_waitlist.push("Chuck Norris");
	
	cout << "\n\nThere are currently " << restaurant_waitlist.size() << " on the wait list for Longhorn Steakhouse.\n";
	cout << "\n\nYay!  There is a table for the person at the top of the list:  " << restaurant_waitlist.front() << endl << endl;
	
	restaurant_waitlist.pop();
	
	cout << "\n\nThere are currently " << restaurant_waitlist.size() << " on the wait list for Longhorn Steakhouse.\n";
	cout << "\n\nYay!  There is a table for the person at the top of the list:  " << restaurant_waitlist.front() << endl << endl;
	
	restaurant_waitlist.pop();
	
	cout << "\n\nThere are currently " << restaurant_waitlist.size() << " on the wait list for Longhorn Steakhouse.\n";
	cout << "\n\nOh no!  The person at the end of the wait list (" << restaurant_waitlist.back() << ") beat everyone up who was in front!\n\n";
	int numGotBeatUp = restaurant_waitlist.size();
	for(int x=1; x < numGotBeatUp; x++)
	{
		restaurant_waitlist.pop();
	}
	cout << "\n\nThere is currently " << restaurant_waitlist.size() << " on the wait list for Longhorn Steakhouse.\n";
	cout << "\n\nYay!  There is a table for the person at the top of the list:  " << restaurant_waitlist.front() << endl << endl;
	
	return 0;
	
}
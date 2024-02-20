// This program demonstrates the STL queue container adapter.
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	const int MAX = 8;	// Max value
	int count;			// Loop counter

	// Define a queue object.
	queue<int> iQueue;

	// Push to the back of the queue a series of numbers.
	cout << "I will now push items...\n";
	for (count = 2; count < MAX; count += 2)
	{
		cout << "Pushing " << count << endl;
		iQueue.push(count);
	}

	// Pop from front of queue and display the numbers.
	cout << "I will now pop items...\n";
	for (count = 2; count < MAX; count += 2)
	{
		cout << "Popping " << iQueue.front() << endl;
		iQueue.pop();
	}
	return 0;
}
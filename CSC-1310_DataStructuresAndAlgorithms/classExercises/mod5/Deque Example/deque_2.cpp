// This program demonstrates the STL deque container.
#include <iostream>
#include <deque>
using namespace std;

int main()
{
   const int MAX = 8;   // Max value
   int count;           // Loop counter
   
   // Create a deque object.
   deque<int> iDeque;

   // Enqueue a series of numbers.
   cout << "\n\nI will now push items to the back of the deque...\n";
   for (count = 2; count < MAX; count += 2)
   {
      cout << "Pushing " << count << endl;
      iDeque.push_back(count);
   }
  
  cout << endl << endl;
   for( int x=0; x<iDeque.size(); x++)
   {
	   cout << "\nItem " << (x+1) << ":  " << iDeque[x] << endl;
   }
   
   
   // Dequeue and display the numbers.
   cout << "\n\nI will now pop items from the front of the deque...\n";
   for (count = 2; count < MAX; count += 2)
   {
      cout << "Popping "<< iDeque.front() << endl;
      iDeque.pop_front();
   }
   
 
   return 0;
}
#include "ArrayMaxHeap.h"
#include <iostream>
#include <string>

using namespace std;

void display(string& anItem)
{
   cout << "Displaying item - " << anItem << endl;
}

int main()
{
   ArrayMaxHeap<string>* heap1Ptr = new ArrayMaxHeap<string>(2); 
   heap1Ptr->insert("10");
   heap1Ptr->insert("20");
   heap1Ptr->insert("30");
   heap1Ptr->insert("40");
   heap1Ptr->insert("50");
   heap1Ptr->insert("60");
   heap1Ptr->insert("70");
   heap1Ptr->insert("80");   
   //         80
   //      /     \
   //     70     60
   //    /  \   /  \
   //   40  30 20  50
   //  /
   // 10
   
   cout << "Heap 1: " << endl;
   while (!heap1Ptr->isEmpty())
   {
      cout << "# of nodes: " << heap1Ptr->getNumberOfNodes() << endl;
      cout << "Height: "     << heap1Ptr->getHeight() << endl;
      cout << "max value: "  << heap1Ptr->peek() << endl;
      cout << "remove: "     << heap1Ptr->remove() << endl << endl;
   }  // end while

   ArrayMaxHeap<string>* heap2Ptr = new ArrayMaxHeap<string>(2);
   heap2Ptr->insert("50");
   heap2Ptr->insert("30");
   heap2Ptr->insert("70");
   heap2Ptr->insert("20");
   heap2Ptr->insert("60");
   heap2Ptr->insert("40");
   heap2Ptr->insert("10");
   heap2Ptr->insert("80");
   //         80
   //      /     \
   //     70     50
   //    /  \   /  \
   //   60  30 40  10
   //  /
   // 20

   cout << "-------------" << endl;
   cout << "Heap 2: " << endl;
   while (!heap2Ptr->isEmpty())
   {
      cout << "# of nodes: " << heap2Ptr->getNumberOfNodes() << endl;
      cout << "Height: "     << heap2Ptr->getHeight() << endl;
      cout << "max value: "  << heap2Ptr->peek() << endl;
      cout << "remove: "     << heap2Ptr->remove() << endl << endl;
   }

   return 0;
}  
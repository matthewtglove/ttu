#include <iostream>
#include "DynIntQueue.h"
using namespace std;

//********************************************
// The constructor creates an empty queue.   *
//********************************************

DynIntQueue::DynIntQueue()
{
   front = NULL;
   rear = NULL;
   numItems = 0;
}

//********************************************
// Destructor                                *
//********************************************

DynIntQueue::~DynIntQueue()
{
   clear();
}

//**********************************************
// Function push_back inserts the value in num *
// at the rear of the queue.                   *
//**********************************************

void DynIntQueue::push_back(int num)
{
   QueueNode *newNode = NULL;

   // Create a new node and store num there.
   newNode = new QueueNode;
   newNode->value = num;
   newNode->next = NULL;

   // Adjust front and rear as necessary.
   if (isEmpty())
   {
      front = newNode;
      rear = newNode;
   }
   else
   {
      rear->next = newNode;
      rear = newNode;
   }

   // Update numItems.
   numItems++;
}

//**********************************************
// Function pop_front removes the value at the   *
// front of the queue, and copies it into num. *
//**********************************************

void DynIntQueue::pop_front(int &num)
{
   QueueNode *temp = NULL;

   if (isEmpty())
   {
      cout << "The queue is empty.\n";
   }
   else
   {
      // Save the front node value in num.
      num = front->value;

      // Remove the front node and delete it.
      temp = front;
      front = front->next;
      delete temp;

      // Update numItems.
      numItems--;
   }
}

//*********************************************
// Function isEmpty returns true if the queue *
// is empty, and false otherwise.             *
//*********************************************

bool DynIntQueue::isEmpty() const
{
    bool status;

    if (numItems > 0)
       status = false;
    else
       status = true;
    return status;
}

//********************************************
// Function clear dequeues all the elements  *
// in the queue.                             *
//********************************************

void DynIntQueue::clear()
{
    int value;   // Dummy variable for dequeue

    while(!isEmpty())
       pop_front(value);
}





#ifndef DYNAMICQUEUE_H
#define DYNAMICQUEUE_H
#include <iostream>
using namespace std;


template <typename T>
class DynamicQueue
{
private:
   // Structure for the queue nodes
   struct QueueNode
   {
      T value;			// Value in a node
      QueueNode *next;	// Pointer to the next node
   };

   QueueNode *front;  // The front of the queue
   QueueNode *rear;   // The rear of the queue
   int numItems;      // Number of items in the queue
public:
   // Constructor
   DynamicQueue();

   // Destructor
   ~DynamicQueue();

   // Queue operations
   void push_back(T);
   void pop_front(T &);
   bool isEmpty() const;
   bool isFull() const;
   void clear();
};

//********************************************
// The constructor creates an empty queue.   *
//********************************************
template <typename T>
DynamicQueue<T>::DynamicQueue()
{
   front = NULL;
   rear = NULL;
   numItems = 0;
}

//********************************************
// Destructor                                *
//********************************************
template <typename T>
DynamicQueue<T>::~DynamicQueue()
{
   clear();
}

//********************************************
// Function push_back inserts the value in num *
// at the rear of the queue.                 *
//********************************************
template <typename T>
void DynamicQueue<T>::push_back(T item)
{
   QueueNode *newNode = NULL;

   // Create a new node and store num there.
   newNode = new QueueNode;
   newNode->value = item;
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
template <typename T>
void DynamicQueue<T>::pop_front(T &item)
{
   QueueNode *temp = NULL;

   if (isEmpty())
   {
      cout << "The queue is empty.\n";
   }
   else
   {
      // Save the front node value in num.
      item = front->value;

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
template <typename T>
bool DynamicQueue<T>::isEmpty() const
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
template <typename T>
void DynamicQueue<T>::clear()
{
    T value;   // Dummy variable for pop_front

    while(!isEmpty())
       pop_front(value);
}
#endif
// Specification file for the QueueLinkedList class
#ifndef QUEUELINKEDLIST_H
#define QUEUELINKEDLIST_H

class QueueLinkedList
{
	private:
		// Declare a structure for the queue linked list
		struct ListNode
		{
			double value;           	// The value in this node
			struct ListNode *next;  	// To point to the next node
		}; 

		ListNode *head;		// queue head pointer
		ListNode *tail;		// queue tail pointer

	public:
		// Constructor
		QueueLinkedList()
		{ 
			head = NULL;
			tail = NULL;
		}

		// Destructor (similar to a typical RemoveAll function)
		~QueueLinkedList();

		// Linked list queue operations
		bool isEmpty();
		int getLength();
		void push_back(double);
		double pop_front();
		double peek();
		void displayQueue() const;
};
#endif
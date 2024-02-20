// Specification file for the StackLinkedList class
#ifndef STACKLINKEDLIST_H
#define STACKLINKEDLIST_H

class StackLinkedList
{
	private:
		// Declare a structure for the list
		struct ListNode
		{
			double value;           	// The value in this node
			struct ListNode *next;  	// To point to the next node
		}; 

		ListNode *top;		// Stack head pointer can be called top

	public:
		// Constructor
		StackLinkedList()
		{ 
			top = NULL; 
		}

		// Destructor (similar to a typical RemoveAll function)
		~StackLinkedList();

		// Linked list operations
		bool isEmpty();
		int getLength();
		void push(double);
		double pop();
		double peek()
		{
			if(!top)
				return -1;
			else
				return top->value;
		}
		void displayStack() const;
};
#endif
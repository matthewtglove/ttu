/*****************************************************************
	Title:  	LinkedList.h - Class Specification File for 
				LinkedList Class
	Date:  		2-8-2019
	Author: 	April Crockett
	Purpose:	A Singly-Linked List implemented in a
				LinkedList class that contains a ListNode
				structure variable
******************************************************************/

#ifndef LinkedList_H
#define LinkedList_H
/*****************************************************************
							LinkedList Class
******************************************************************/
class LinkedList
{
	private:
		// Declare a structure for the list
		struct ListNode
		{
			double value; 
			ListNode *next;  	// To point to the next node
			/*
				because this structure contains a pointer to an object
				of the same type as that being declared, it is 
				called a self-referential data structure
			*/
		}; 

		ListNode *head;		//List head pointer
		ListNode *tail;		//List tail pointer

	public:
		// Constructor
		LinkedList()
		{ 
			head = NULL; 
			tail = NULL;
		}

		// Destructor (deallocates all nodes)
		~LinkedList();

		// Linked list operations
		bool isEmpty();
		int getLength();
		int search(double);
		double getNodeValue(int);
		void appendNode(double);
		void insertNode(int, double);
		void deleteNode(double);
		void displayList() const;
};
#endif
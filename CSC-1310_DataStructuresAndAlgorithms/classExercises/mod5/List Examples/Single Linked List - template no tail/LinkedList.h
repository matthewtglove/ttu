/*****************************************************************
	Title:  	LinkedList.h - Class Specification File for 
				LinkedList Template Class
	Date:  		2-8-2019
	Author: 	April Crockett
	Purpose:	A Singly-Linked List implemented in a
				LinkedList class that contains a ListNode
				structure variable
******************************************************************/
#ifndef LinkedList_H
#define LinkedList_H

/*****************************************************************
					LinkedList Template Class
******************************************************************/
template <typename Booyah>
class LinkedList
{
	private:
		// Declare a structure for the list
		struct ListNode
		{
			Booyah value;           	// The value in this node
			struct ListNode *next;  	// To point to the next node

		}; 
		ListNode *head;		// List head pointer

	public:
		// Constructor
		LinkedList()
		{ 
			head = NULL; 
		}

		// Destructor (similar to a typical RemoveAll function)
		~LinkedList();

		// Linked list operations
		bool isEmpty();
		int getLength();
		void appendNode(Booyah);
		void displayList() const;
		//Booyah getNodeValue(int);
};

template <typename Booyah>
bool LinkedList<Booyah>::isEmpty()
{
	if(!head)
		return true;
	else
		return false;
}

template <typename Booyah>
int LinkedList<Booyah>::getLength()
{
	int counter = 0;
	ListNode *nodePtr;
	
	nodePtr = head;
	
	while(nodePtr)
	{
		counter++;
		nodePtr = nodePtr->next;
	}
	return counter;
}

template <typename Booyah>
void LinkedList<Booyah>::appendNode(Booyah val)
{
	ListNode *newNode;  // To point to a new node
	ListNode *nodePtr;

	// Allocate a new node and store num there.
	newNode = new ListNode;
	newNode->value = val;
	newNode->next = NULL;
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~appendNode:  dynamically created new node & set value";

	// If there are no nodes in the list make newNode the first node.
	if (!head ) 
	{
		head = newNode;
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~appendNode:  new node is head of list";
	}
	else  // Otherwise, insert newNode at end.
	{
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~appendNode:  traversing through list  ";
		//must traverse the list to find the end
		nodePtr = head;
		int counter = 0;
		while(nodePtr->next != NULL)
		{
			cout << "- node " << counter++;
			nodePtr = nodePtr->next;
		}
		//now we are at the end
		nodePtr->next = newNode;
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~appendNode:  new node is at end of list";
	}
}

template <typename Booyah>
void LinkedList<Booyah>::displayList() const
{
	ListNode *nodePtr;  // To move through the list

	if(head != NULL)
	{
		// Position nodePtr at the head of the list.
		nodePtr = head;
		// While nodePtr points to a node, traverse the list.
		while(nodePtr)
		{
			// Display the value in this node.
			cout << nodePtr->value << endl;

			// Move to the next node.
			nodePtr = nodePtr->next;
		}
	}
	else
		cout << "\nThere are no nodes in the list.\n\n";
}

template <typename Booyah>
LinkedList<Booyah>::~LinkedList()
{
	ListNode *nodePtr;   // To traverse the list
	ListNode *nextNode;  // To point to the next node

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr is not at the end of the list...
	while (nodePtr)
	{
		// Save a pointer to the next node.
		nextNode = nodePtr->next;
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~destructor:  deleting node with value " << nodePtr->value;

		// Delete the current node.
		delete nodePtr;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
}





#endif
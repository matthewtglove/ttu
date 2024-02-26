/*
    Title: Lab 4
    Author: Matthew Love
    Date: 2024-02-19, Mon
    Purpose: Creating a linked list
*/

#ifndef LIST_H
#define LIST_H

#include <string>
#include <iostream>
using namespace std;

class List
{
private:
    struct ListNode
    {
        string value;
        ListNode *next;
    };

    ListNode *head;
    ListNode *tail;

public:
    List()
    {
        head = NULL;
        tail = NULL;
    }

    ~List()
    {
        if (!head)
        {
            return;
        }

        ListNode *currentNode = head;
        while (currentNode)
        {
            ListNode *deleteNode = currentNode;
            currentNode = currentNode->next;
            delete deleteNode;
        }
    }

    // !head is used a lot, so this is made for more clarity in every instance
    bool isEmpty()
    {
        return (!head);
    }

    void appendNode(string newValue)
    {
        ListNode *newNode = new ListNode;
        newNode->value = newValue;
        newNode->next = NULL;

        if (isEmpty())
        {
            head = newNode;
            tail = newNode;
            return;
        }

        // Make the CURRENT last node point to the new value (instead of pointing to NULL, like it was before)
        tail->next = newNode;
        // Then, redefine the last node to the new node
        tail = newNode;
    }

    void insertNode(string newValue)
    {
        // This function inserts the new value in the list alphabetically (before the first value that is greater)

        if (isEmpty())
        {
            appendNode(newValue);
            return;
        }

        ListNode *newNode = new ListNode;
        newNode->value = newValue;

        // To handle inserting at the head
        if (head->value > newNode->value)
        {
            // The new node points to the current head
            newNode->next = head;
            // Then, change the head to the new node
            head = newNode;

            return;
        }

        ListNode *currentNode = head;
        // Skipping the head since we have already checked it
        while (currentNode->next->value < newNode->value)
        {
            if (currentNode->next == tail)
            {
                // -5 -> insert: You have a case on line 105 where you call append with the newNode->value but you should delete newNode after this is called since append makes another node in its function.
                appendNode(newNode->value);
                return;
            }
            currentNode = currentNode->next;
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }

    void deleteNode(string deleteValue)
    {
        if (isEmpty())
        {
            cout << "[The list is empty]" << endl;
            return;
        }

        ListNode *currentNode = head;

        ListNode *previousNode;

        while (currentNode->value != deleteValue)
        {
            if (currentNode->next == NULL)
            {
                cout << "[Value not found in list]" << endl;
                return;
            }

            // Only increments previousNode after currentNode is ahead
            {
                // NOTE TO GRADER. Both methods below do the exact same thing. Is the use of a ternary operator acceptable in assignment submissions?

                // First method: Using a ternary operator
                previousNode = ((currentNode == head) ? head : previousNode->next);

                // Second method: Using if-else
                /*
                if (currentNode == head)
                {
                    previousNode = head;
                }
                else
                {
                    previousNode = previousNode->next;
                }
                */
            }
            currentNode = currentNode->next;
        }
        // -5 -> delete: Very clever using the ternary op to assign prevNode; however, you don't have a case to reset the head of the list in the event of deleting the head. This would cause head to point to junk data, resulting in a crash if accessed later. (But its fine in this case since delete is the last thing done with the list.)

        // Set the previous node to the node ahead of the node that is about to be deleted
        previousNode->next = currentNode->next;

        delete currentNode;
    }

    void displayList()
    {
        if (isEmpty())
        {
            cout << "[The list is empty]" << endl;
            return;
        }

        ListNode *currentNode = head;
        while (currentNode)
        {
            cout << currentNode->value << endl;
            currentNode = currentNode->next;
        }
    }
};

#endif
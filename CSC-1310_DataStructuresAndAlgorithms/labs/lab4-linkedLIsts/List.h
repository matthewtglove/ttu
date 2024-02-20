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

    bool isEmpty()
    {
        return (!head);
    }

    void appendNode(string newValue)
    {
        // § dynamically allocate a new ListNode and set the ListNode’s value to the string sent to this function
        // § place the new node at the end of the linked list (use the tail pointer to help!)
        ListNode *newNode;

        newNode = new ListNode;
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
        // Then, make the last value the new value
        tail = newNode;
    }

    void insertNode(string newValue)
    {
        //         accept a string as a parameter
        // § dynamically allocate a new ListNode and set the ListNode’s value to the string sent to  this function
        // § place the new node in the linked list alphabetically based on the string values.
        if (isEmpty())
        {
            appendNode(newValue);
        }
        ListNode *newNode;

        newNode = new ListNode;
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
        //         accept a string as a parameter
        // § traverse the linked list to search for a node with the same value and delete it when found
        if (isEmpty())
        {
            cout << "[The list is empty]" << endl;
            return;
        }

        ListNode *currentNode = head;

        if (head->value == deleteValue)
        {
            head = head->next;
            delete currentNode;
            return;
        }

        while (currentNode->next->value != deleteValue)
        {
            if (currentNode == tail)
            {
                cout << "[Value not found in list]" << endl;
                return;
            }
            currentNode = currentNode->next;
        }

        ListNode *deleteNode = currentNode->next;
        currentNode->next = deleteNode->next;

        delete deleteNode;
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
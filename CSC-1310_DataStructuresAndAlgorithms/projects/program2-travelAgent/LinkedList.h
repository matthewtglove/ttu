/*
    Filename:       LinkedList.h
    Date Created:   2024-02-21, Wed
    Author:         Matthew Love
    Purpose:        A genaric linked list
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

template <typename T>
class LinkedList {
private:
    struct ListNode {
        T value;
        ListNode *next;
    };

    ListNode *head;
    ListNode *tail;
    int nodeCount;

public:
    LinkedList() {
        head = NULL;
        tail = NULL;
        nodeCount = 0;
    }

    ~LinkedList() {
        if (!head) {
            return;
        }

        ListNode *currentNode = head;
        while (currentNode) {
            ListNode *deleteNode = currentNode;
            currentNode = currentNode->next;
            delete deleteNode;
        }

        head = NULL;
        tail = NULL;
        nodeCount = 0;
    }

    bool isEmpty() const {
        return (!head);
    }

    int getLength() const {
        return nodeCount;
    }

    T getNodeValue(int position) const {
        if (isEmpty()) {
            throw runtime_error{"List is empty"};
        }

        // Bad input handling
        if (position < 0) {
            throw out_of_range{"Position is less than 0"};
        }
        if (position > nodeCount) {
            throw out_of_range{"Position exeeds list size"};
        }

        ListNode *node = head;
        for (int i = 0; i < position; i++) {
            node = node->next;
        }

        return node->value;
    }

    void insertNode(T value) {
        nodeCount++;
        ListNode *newNode = new ListNode;
        newNode->value = value;

        // First node
        if (isEmpty()) {
            newNode->next = NULL;
            head = newNode;
            tail = newNode;
            return;
        }

        // This is technically not needed (if we redefined the tail later), but it saves us from having to iterate through the entire list with a value that is greater than every existing value
        if (*tail->value < *newNode->value) {
            // Appends the newNode
            newNode->next = NULL;
            tail->next = newNode;
            tail = newNode;
            return;
        }

        if (*newNode->value < *head->value) {
            // Places the newNode in front
            newNode->next = head;
            head = newNode;
            return;
        }

        ListNode *currentNode = head;
        // Because we cannot place the newNode behind the currentNode, we look ahead and know if we need to place it right after currentNode
        while (*currentNode->next->value < *newNode->value) {
            currentNode = currentNode->next;
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }
};

#endif
/*
    Title: queue.h
    Author: Matthew Love
    Date: 2024-03-20, Wed
    Description: A queue class
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

class Queue {
private:
    struct QueueNode {
        string riderName;
        QueueNode *next;
    };
    int nodesCount;
    QueueNode *head;
    QueueNode *tail;

public:
    Queue() {
        nodesCount = 0;
        head = nullptr;
        tail = nullptr;
    }
    ~Queue() {
        if (!head) {
            return;
        }
        QueueNode *currentNode = head;
        while (currentNode) {
            QueueNode *deleteNode = currentNode;
            currentNode = currentNode->next;
            cout << "Oh shoot, I am sorry, our park is closed so " << deleteNode->riderName << " will not get to ride today." << endl;
            delete deleteNode;
        }
        head = nullptr;
        tail = nullptr;
    }

    bool isEmpty() {
        return (!head);
    }

    void endqueue(string newRider) {
        this->nodesCount++;
        QueueNode *newNode = new QueueNode;
        newNode->riderName = newRider;
        newNode->next = nullptr;

        if (nodesCount == 1) {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }
    void dequeue() {
        nodesCount--;
        if (isEmpty()) {
            cout << "The queue is empty" << endl;
            return;
        }
        QueueNode *deleteNode = head;
        head = head->next;
        delete deleteNode;
    }
};

#endif
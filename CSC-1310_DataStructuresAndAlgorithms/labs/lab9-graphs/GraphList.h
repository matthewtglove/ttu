/*
    Title: GraphList.h
    Author: Matthew Love
    Date: 2024-04-03, Wed
    Purpose: A graph class of type int
*/

#ifndef GRAPHLIST_H
#define GRAPHLIST_H

#include <string>
#include <iostream>
using namespace std;

class GraphList {
private: 
    struct ListNode {
        int value;
        ListNode *next;
    };
    ListNode **headArray;
    int nodeCount;
    int edgeCount;
public:
    GraphList(int nodeCount) {
        if (nodeCount <= 0) {
            cout << "Node count must be greater than 0" << endl;
            return;
        }
        this->nodeCount = nodeCount;
        this->edgeCount = 0;
        headArray = new ListNode *[nodeCount];
        for(int i = 0; i < nodeCount; i++) {
            headArray[i] = new ListNode;            
            headArray[i]->value = i;
            headArray[i]->next = nullptr;
        }
    }

    ~GraphList() {
        for(int i = 0; i < nodeCount; i++) {
            ListNode *currentNode = headArray[i];

            // Deletes from the head of the linked list to the tail
            while(currentNode->next != nullptr) {
                ListNode *tempNode = currentNode;
                currentNode = currentNode->next;
                delete tempNode;
            }
            delete currentNode;
        }

        delete [] headArray;
    }

    void addEdge(int fromNode, int toNode) {
        // Since the node values start at 0, nodeCount will always be 1 greater than the highest node value
        if(fromNode >= nodeCount) {
            cout << "fronNode with value " << fromNode << " does not exist in the graph." << endl;
            return;
        }

        if(toNode >= nodeCount) {
            cout << "toNode with value " << toNode << " does not exist in the graph." << endl;
            return;
        }
        
        cout << "Adding an edge from " << fromNode << " to " << toNode << endl;
        for(int i = 0; i < nodeCount; i++) {
            if(headArray[i]->value == fromNode) {
                ListNode *newNode = new ListNode;
                newNode->value = toNode;

                // Finds the order to insert into the linked list (ascending order)
                ListNode *currentNode = headArray[i];
                while(currentNode->next != nullptr && newNode->value > currentNode->next->value) {
                    currentNode = currentNode->next;
                }
                newNode->next = currentNode->next;
                currentNode->next = newNode;

                edgeCount++;
            }
        }
    }

    void printGraph() {
        cout << "Adjacency List:" << endl;
        for(int i = 0; i < nodeCount; i++) {
            ListNode *currentNode = headArray[i];
            while(currentNode->next != nullptr) {
                cout << currentNode->value << " --> ";
                currentNode = currentNode->next;
            }
            cout << currentNode->value << " --> NULL" << endl;
        }
     }
};

#endif
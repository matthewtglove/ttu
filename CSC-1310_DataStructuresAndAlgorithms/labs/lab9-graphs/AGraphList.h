/*
    Title: GraphList.h
    Author: Matthew Love
    Date: 2024-04-03, Wed
    Purpose: Generates an Adjacency list with input graph data
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
        // TODO: delete each linked list
    }

    void addEdge(int fromNode, int toNode) {
        if(fromNode >= nodeCount) {
            cout << "fronNode with value " << fromNode << " does not exist in the graph." << endl;
            return;
        }
        if(toNode >= nodeCount) {
            cout << "toNode with value " << toNode << " does not exist in the graph." << endl;
            return;
        }
        
        for(int i = 0; i < nodeCount; i++) {
            if(headArray[i]->value == fromNode) {
                ListNode *newNode = new ListNode;
                newNode->value = toNode;

                // Finds the order to insert into the linked list
                ListNode *currentNode = headArray[i];
                while(newNode->value > currentNode->next->value || currentNode->next == nullptr) {
                    currentNode = currentNode->next;
                }
                newNode->next = currentNode->next;
                currentNode->next = newNode;

                edgeCount++;
            }
        }
    }
};

#endif
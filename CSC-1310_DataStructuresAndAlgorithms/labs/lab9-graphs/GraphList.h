/*
    Title: GraphList.h
    Author: Matthew Love
    Date: 2024-04-03, Wed
    Purpose: Generates an Adjacency list with input graph data
*/

#ifndef GRAPHLIST_H
#define GRAPHLIST_H

#include <string>
using namespace std;

class GraphList {
private:
    struct ListNode {
        int value;
        ListNode *next;
    };

    ListNode **headArray;
    int numNodes;
    int numEdges;

public:
    GraphList(int nodeCount) {
        numNodes = 0;
        numEdges = 0;
        //
    }
};

#endif
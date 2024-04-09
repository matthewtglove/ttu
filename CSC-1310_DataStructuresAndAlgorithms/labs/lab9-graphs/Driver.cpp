/*
    Title: Driver.cpp
    Author: Matthew Love
    Date: 2024-04-03, Wed
    Purpose: Generates an Adjacency list with input graph data
*/

#include "GraphList.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inFile;
    inFile.open("graph.txt");
    if(!inFile.good()) {
        cout << "Unable to open file graph.txt" << endl;
        return 1;
    }
    
    // Getting the node count which is on the first line of the file
    int nodeCount;
    inFile >> nodeCount;
    cout << "There are " << nodeCount << " nodes in the graph.\n" << endl;
    GraphList graph(nodeCount);

    int fromNode;
    int toNode;
    // Stops reading the file at blank line or end of file
    while(inFile >> fromNode >> toNode) {        
        graph.addEdge(fromNode, toNode);
    }
    inFile.close();

    cout << endl;
    graph.printGraph();

    return 0;
}
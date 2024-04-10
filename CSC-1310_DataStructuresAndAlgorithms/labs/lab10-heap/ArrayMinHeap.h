/*
    Title: ArrayMinHeap.h
    Author: Matthew Love
    Date: 2024-04-10, Wed
    Purpose: A min head implementation
*/

#include "Creature.h"
#include <iostream>
// Used for log2 and ceil
#include <cmath>
using namespace std;

class ArrayMinHeap {
private:
    Creature *heapArray;
    int capacity;
    int heapSize;

    void swap(Creature *x, Creature *y) {
        Creature temp = *x;
        *x = *y;
        *y = temp;
    }

    // TODO: Need to convert to Creature

    int parent(int i) {
        return (i - 1) / 2;
    }
    int left(int i) {
        return (2 * i) + 1;
    }
    int right(int i) {
        return (2 * i) + 2;
    }

public:
    ArrayMinHeap(int capacity) {
        this->heapSize = 0;
        this->capacity = capacity;
        this->heapArray = new int[capacity];
    }
    ~ArrayMinHeap() {
        delete[] heapArray;
    }

    bool isEmpty() {
        return (heapSize == 0);
    }

    int peek() {
        if (isEmpty()) {
            cout << "Error: the heap is empty." << endl;
            return -1;
        }
        return heapArray[0];
    }

    minHeapify(int i);

    bool remove() {
        if (isEmpty()) {
            cout << "Error: the heap is empty." << endl;
            return false;
        }
        if (heapSize == 1) {
            heapSize--;
            return true;
        }

        int root = heapArray[0];
        heapArray[0] = heapArray[heapSize - 1];
        heapSize--;
        minHeapify(0);
        return true;
    }

    // void minHeapify(int) {
    //     int
    // }
};
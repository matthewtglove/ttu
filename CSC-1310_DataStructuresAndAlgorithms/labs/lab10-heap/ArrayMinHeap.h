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
    int heapCapacity;
    int heapSize;

    void swap(Creature *x, Creature *y) {
        Creature temp = *x;
        *x = *y;
        *y = temp;
    }

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
        this->heapCapacity = capacity;
        this->heapArray = new Creature[capacity];
    }
    ~ArrayMinHeap() {
        delete[] heapArray;
    }

    bool isEmpty() {
        return (heapSize == 0);
    }

    int getNodeCount() {
        return heapSize;
    }

    int getHeight() {
        return ceil(log2(heapSize + 1));
    }

    Creature peek() {
        if (isEmpty()) {
            cout << "Error: the heap is empty." << endl;
            // Returns an empty creature
            return Creature();
        }
        return heapArray[0];
    }

    void minHeapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heapSize && heapArray[l].getName() < heapArray[i].getName()) {
            smallest = l;
        }
        if (r < heapSize && heapArray[r].getName() < heapArray[smallest].getName()) {
            smallest = r;
        }
        if (smallest != i) {
            swap(&heapArray[i], &heapArray[smallest]);
            minHeapify(smallest);
        }
    }

    bool remove(Creature &creature) {
        if (isEmpty()) {
            cout << "Error: the heap is empty." << endl;
            return false;
        }
        if (heapSize == 1) {
            heapSize--;
            return true;
        }

        // To return the creature that is passed in by reference
        creature = heapArray[0];
        // Assigns the last value to the first index in the array
        heapArray[0] = heapArray[heapSize - 1];
        heapSize--;
        // Then fixes the heap so that it follows the rule
        minHeapify(0);
        return true;
    }

    void resizeArray() {
        // Creates new array
        Creature *newArray = new Creature[heapCapacity * 2];
        heapCapacity *= 2;

        // Copies creatures over to the new array
        for (int i = 0; i < heapSize; i++) {
            newArray[i] = heapArray[i];
        }

        // Deletes the old array
        delete[] heapArray;

        // heapArray now points to the new array
        heapArray = newArray;
    }

    void insert(Creature creature) {
        // Don't actually need this check
        // if (isEmpty()) {
        //     heapArray[0] = creature;
        //     heapSize++;
        //     return;
        // }

        if (heapSize == heapCapacity) {
            resizeArray();
        }

        heapArray[heapSize] = creature;
        heapSize++;
    }

    void display() {
        for (int i = 0; i < heapSize; i++) {
            heapArray[i].printCreature();
        }
    }

    void saveToFile() {
        for (int i = 0; i < heapSize; i++) {
            heapArray[i].printCreatureToFile("CreatureOutput.txt");
        }
    }
};
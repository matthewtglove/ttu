/*
    Title: HashTable.h
    Author: Matthew Love
    Date: 2024-03-23
    Purpose: Hash Table implementation
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "HashEntry.h"
#include <iomanip>
using namespace std;

class HashTable {
private:
    int tableSize;
    HashEntry **hashArray;

public:
    HashTable(int size) {
        tableSize = size;
        hashArray = new HashEntry *[tableSize];
        for (int i = 0; i < tableSize; i++) {
            hashArray[i] = NULL;
        }
    }
    ~HashTable() {
        for (int i = 0; i < tableSize; i++) {
            if (hashArray[i] != NULL) {
                HashEntry *previousEntry = NULL;
                HashEntry *entry = hashArray[i];
                while (entry != NULL) {
                    previousEntry = entry;
                    entry = entry->getNext();
                    delete previousEntry;
                }
            }
        }
        delete[] hashArray;
    }

    HashEntry *getEntry(int key) const {
        int bucketIndex = key % tableSize;
        if (hashArray[bucketIndex] == NULL) {
            cout << "ALERT: Bucket index not found for key: " << key << endl;
            return NULL;
        }
        return hashArray[bucketIndex];
    }

    Costume *getValue(int key) const {
        HashEntry *entry = getEntry(key);
        while (entry != NULL && entry->getKey() != key) {
            entry = entry->getNext();
        }
        if (entry == NULL) {
            cout << "ALERT: Entry not found in bucket of key: " << key << endl;
            return NULL;
        }
        return entry->getValue();
    }

    void putValue(int key, Costume *costume) {
        HashEntry *newEntry = new HashEntry(key, costume);
        int bucketIndex = key % tableSize;

        // No collision
        if (hashArray[bucketIndex] == NULL) {
            hashArray[bucketIndex] = newEntry;
            return;
        }

        // Collision
        HashEntry *entry = hashArray[bucketIndex];
        // Traverse through till an empty spot is found in the linked list within the bucket
        while (entry->getNext() != NULL && entry->getKey() != key) {
            entry = entry->getNext();
        }
        // If the key already exists, update its value
        if (entry->getKey() == key) {
            entry->setValue(newEntry->getValue());
        }
        // Otherwise append to the linked list
        entry->setNext(newEntry);
    }

    void removeValue(int key) {
        int bucketIndex = key % tableSize;

        if (hashArray[bucketIndex] == NULL) {
            cout << "ALERT: Did not find key: " << key << endl;
            return;
        }

        HashEntry *entry = hashArray[bucketIndex];
        HashEntry *previousEntry = NULL;
        // Traverse through the linked list in the bucket
        while (entry->getNext() != NULL && entry->getKey() != key) {
            previousEntry = entry;
            entry = entry->getNext();
        }

        // If at the end of the list and it is not the key
        if (entry->getKey() != key) {
            cout << "ALERT: Entry not found in bucket of key: " << key << endl;
            return;
        }

        if (previousEntry == NULL) {
            hashArray[bucketIndex] = entry->getNext();
            delete entry;
            return;
        }

        previousEntry->setNext(entry->getNext());
        delete entry;
    }

    void printHashTable() const {
        cout << "----------" << endl;

        for (int i = 0; i < tableSize; i++) {
            if (hashArray[i] == NULL) {
                cout << setw(8) << "NULL" << endl;
                // Continues to the next iteration of the for loop, skipping the below code
                continue;
            }

            HashEntry *entry = hashArray[i];
            while (entry->getNext() != NULL) {
                cout << " ----->" << setw(8) << *entry->getValue();
                entry = entry->getNext();
            }
            cout << " ----->" << setw(8) << *entry->getValue();
            cout << endl;
        }
        cout << "----------\n"
             << endl;
    }
};

#endif
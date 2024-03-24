/*
	Title:  HashTable.h
	Author:	April Crockett
	Purpose:  	Hash Table Implementation
				Values					-	integers
				Hash Function			-	modulus operator
				Collision resolution	-	linear probing
				
*/
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <iomanip>
using namespace std;

class HashTable
{
	private:
		struct HashEntry{
			int key;
			int value;
			HashEntry* next;
		};
		
		int tableSize;
		HashEntry** hashArray;
		
	public:
		HashTable(int size){
			tableSize = size;
			hashArray = new HashEntry*[tableSize];
			for(int i=0; i<tableSize; i++)
				hashArray[i] = NULL;
		}
		~HashTable()
		{
			for(int i=0; i<tableSize; i++)
			{
				if(hashArray[i] != NULL)
				{
					HashEntry *prevEntry = NULL;
					HashEntry *entry = hashArray[i];
					while(entry != NULL)
					{
						prevEntry = entry;
						entry = entry->next;
						delete prevEntry;
					}
				}
			}
			delete [] hashArray;
		}
		
		int getValue(int key)
		{
			int bucketIndex = key % tableSize;
			if(hashArray[bucketIndex] == NULL)
			{
				return -1;
			}
			else
			{
				HashEntry *entry = hashArray[bucketIndex];
				while(entry != NULL && entry->key != key)
					entry = entry->next;
				if(entry == NULL)
					return -1;
				else
					return entry->value;
			}
		}
		
		void putValue(int key, int value)
		{
			//dynamically allocate a new hash entry
			HashEntry* newHE = new HashEntry;
			newHE->key = key;
			newHE->value = value;
			newHE->next = NULL;
			
			int bucketIndex = key % tableSize;
			cout << "BUCKET " << bucketIndex << endl;
			
			if(hashArray[bucketIndex] == NULL) //no collision
			{
				hashArray[bucketIndex] = newHE;
			}
			else //collision
			{
				HashEntry* entry = hashArray[bucketIndex];
				while(entry->next != NULL)
					entry = entry->next;
				if(entry->key == key)
					entry->value = value; //update the value for this key
				else
					entry->next = newHE;
			}
		}
		
		void removeValue(int key)
		{
			HashEntry *entry;
			HashEntry *prevEntry;
			int bucketIndex = key % tableSize;
			if(hashArray[bucketIndex] != NULL)
			{
				//traverse through list and find matched key
				prevEntry = NULL;
				entry = hashArray[bucketIndex];
				while(entry->next != NULL & entry->key != key)
				{
					prevEntry = entry;
					entry = entry->next;
				}
				if(entry->key == key) //found the key in previous while loop
				{
					if(prevEntry == NULL)
					{
						HashEntry *nextEntry = entry->next;
						delete entry;
						hashArray[bucketIndex] = nextEntry; //re-link list 
					}
					else
					{
						HashEntry *next = entry->next;
						delete entry;
						prevEntry->next = next;
					}
				}
			}		
		}
		
		void printHashTable()
		{
			cout << "----------\n";
			
			for(int i=0; i<tableSize; i++)
			{
				if(hashArray[i] != NULL)
				{
					HashEntry* entry = hashArray[i];
					while(entry->next != NULL)
					{
						cout << "---->" << setw(8) << entry->value;
						entry = entry->next;
					}
					cout << "---->" << setw(8) << entry->value;
					cout << "\n";
				}
				else
					cout << setw(8) << "NULL" << "\n";
			}
			cout << "----------\n\n";
		}
	
};


#endif
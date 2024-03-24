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
		struct HashEntry
		{
			int key;
			int value;
		};
		int tableSize;
		HashEntry* hashArray;
		
	public:
		HashTable(int size){
			tableSize = size;
			hashArray = new HashEntry[tableSize];
			
			//create a "dummy" hashEntry with key & value set to -1
			HashEntry h;
			h.key = -1;
			h.value = -1;
			for(int i=0; i<size; i++)
				hashArray[i] = h;
		}
		~HashTable()
		{
			delete [] hashArray;
		}
		
		int getValue(int key)
		{
			int bucketIndex = key % tableSize;
			while(hashArray[bucketIndex].value != -1 && hashArray[bucketIndex].key != key)
			{
				bucketIndex = (bucketIndex+1) % tableSize;
			}
			if(hashArray[bucketIndex].value == -1)
				return -1;
			else
				return hashArray[bucketIndex].value;
		}
		
		void putValue(int key, int value)
		{
			//Create the new HashEntry with given key & value
			HashEntry h;
			h.key = key;
			h.value = value;
			
			//compute bucket index
			int bucketIndex = key % tableSize;
			cout << "BUCKET " << bucketIndex << endl;
			
			//while there is something already in this bucket and it is a different value
			//note that duplicate values get overwritten but non duplicates get pushed into further buckets
			while(hashArray[bucketIndex].value != -1 && hashArray[bucketIndex].key != key)
			{
				bucketIndex = (bucketIndex+1) % tableSize;
				cout << "BUCKET " << bucketIndex << endl;
			}
			hashArray[bucketIndex] = h;
		}
		
		void printHashTable()
		{
			cout << "----------\n";
			
			for(int i=0; i<tableSize; i++)
			{
				if(hashArray[i].value != -1)
					cout << "|" << setw(8) << hashArray[i].value << "|\n";
				else
					cout << "|" << setw(8) << -1 << "|\n";
			}
			cout << "----------\n\n";
		}
	
};


#endif
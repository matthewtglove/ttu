/*
	Title:  main.cpp
	Plain Box Program
*/

#include <iostream>
#include <string>
#include "PlainBox.h"

using namespace std;

int main()
{

   PlainBox<double> numberBox; // A box to hold a double
   PlainBox<string> nameBox;   // A box to hold a string object
   
   double health = 6.5;
   numberBox.setItem(health);
   
   string secretName = "Rumpelstiltskin";
   nameBox.setItem(secretName);
   
   cout << "\n\nnumberBox.getItem() = " << numberBox.getItem() << endl; //prints 6.5
   cout << "nameBox() = " << nameBox.getItem() << endl; //prints Rumpelstiltskin
   
   return 0;
} 


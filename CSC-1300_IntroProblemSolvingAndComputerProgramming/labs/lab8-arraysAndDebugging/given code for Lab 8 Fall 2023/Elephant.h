/*******************************************************************
	Title:   Elephant.h
	Author:  April R. Crockett - Edited by: Matthew Love
	Date:    October 20, 2023 - Edited on: 2023-10-24, Tue
	Purpose: This program allows the user to enter in
			 10 elephant's names and consumption of each elephant
			 per month.  The program finds & prints the total
			 and average number of pounds eaten by all the
			 elephants as well as the name & consumption amount of
			 the elephant that eats the most.
********************************************************************/

#ifndef ELEPHANT_H
#define ELEPHANT_H

#include <iostream>
#include <string>
using namespace std;

//*****CONSTANT GLOBAL VARIABLES
const int SIZE = 10;

//*****FUNCTION PROTOTYPES
void getElephantData(float[], string[]);
void getStats(float[], float &, float &, int &);

#endif
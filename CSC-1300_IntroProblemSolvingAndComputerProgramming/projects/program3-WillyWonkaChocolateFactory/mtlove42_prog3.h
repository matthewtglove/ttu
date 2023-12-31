/*
    Author: Matthew Love
    Date: 2023-10-28, Sat
    Purpose: Take inventory of the candies made at Willy Wonka's Chocolate Factory, and output details on the totals
*/
#ifndef PROGRAM3_H
#define PROGRAM3_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const double COST_OOMPAS = 7.50;

int getMenuOption();
int requireIntInput(int minRange, int maxRange, string invalidInputMessage);
void addCandy(int &countCandies, int candyType[], string candyFlavor[], float costMaterials[], int numberOompas[], float askingPrice[]);
void calculateTotals(int candyTableType, int countCandies, int candyType[], string candyTypeName[], string candyFlavor[], float costMaterials[], int numberOompas[], float askingPrice[]);
float calculatePrice(int countCandies, float costMaterials[], int numberOompas[]);
void calculateProfit(int candyTableType, int countCandies, int candyType[], string candyTypeName[], float costMaterials[], float askingPrice[]);
float getMaxPrice(int countCandies, float askingPrice[], int &iMaxPrice);

#endif
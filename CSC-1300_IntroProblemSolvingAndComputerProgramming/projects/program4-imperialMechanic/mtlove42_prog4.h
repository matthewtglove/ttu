/*
    Title: mtlove42_prog4
    Author: Matthew Love
    Date: 2023-11-16, Thu
    Purpose: Keep inventory for an Imperial mechanic
*/
#ifndef PROGRAM4_H
#define PROGRAM4_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

const int GARAGE_SIZE = 100;

struct Cost
{
    float numRepairHours;
    float repairHour;
    float parts;
    float materials;
};

struct Vehicles
{
    string name;
    string description;
    bool hasWeapons;
    Cost cost;
};

float convertToFloat(string s);
int requireIntInput(int minRange, int maxRange, string invalidInputMessage);
float requireFloatInput(float minRange, float maxRange, string invalidInputMessage);
bool requireYNInput(string prompt);
int getMenuOption();
int enterVehicles(int countVehicles, Vehicles vehicle[]);
int deleteVehicle(int countVehicles, Vehicles vehicle[]);
bool moveArrayElements(string removedVehicle, bool &userConfirmDelete, int countVehicles, Vehicles vehicle[]);
void printVehicles(int countVehicles, Vehicles vehicle[]);
void printStatistics(int countVehicles, Vehicles vehicle[]);
void saveVehiclesToFile(int countVehicles, Vehicles vehicle[]);

#endif

/*
TODO
- Check for duplicate names before adding vehicle
*/
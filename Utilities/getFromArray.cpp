#include <iostream>
#include <string>
using namespace std;

int getMaxValue(int inputArray[])
{
    int arrayLength = (sizeof(inputArray) / sizeof(int));

    int maxValue = inputArray[0];
    for (int i = 0; i < arrayLength; i++)
    {
        if (inputArray[i] > maxValue)
        {
            maxValue = inputArray[i];
        }
    }

    return maxValue;
}

int findIndexMaxValue(int inputArray[])
{
    int arrayLength = (sizeof(inputArray) / sizeof(int));

    int maxValue = inputArray[0];
    int maxIndex;
    for (int i = 0; i < arrayLength; i++)
    {
        if (inputArray[i] > maxValue)
        {
            maxValue = inputArray[i];
            maxIndex = i;
        }
    }

    return maxIndex;
}

int getMinValue(int inputArray[])
{
    int arrayLength = (sizeof(inputArray) / sizeof(int));

    int minValue = inputArray[0];
    for (int i = 0; i < arrayLength; i++)
    {
        if (inputArray[i] < minValue)
        {
            minValue = inputArray[i];
        }
    }

    return minValue;
}

int findIndexMinValue(int inputArray[])
{
    int arrayLength = (sizeof(inputArray) / sizeof(int));

    int minValue = inputArray[0];
    int minIndex;
    for (int i = 0; i < arrayLength; i++)
    {
        if (inputArray[i] > minValue)
        {
            minValue = inputArray[i];
            minIndex = i;
        }
    }

    return minIndex;
}
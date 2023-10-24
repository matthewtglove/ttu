#include <iostream>
#include <string>
using namespace std;

/*
THESE NEED TO BE FIXED

The sizeof() is generating an error and these are not working
*/

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

int indexOfMaxValue(int inputArray[])
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

int indexOfMinValue(int inputArray[])
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

int getAverage(int inputArray[])
{
    int arrayLength = (sizeof(inputArray) / sizeof(int));

    int arrayTotal;
    for (int i = 0; i < arrayLength; i++)
    {
        arrayTotal += inputArray[i];
    }

    return arrayTotal / arrayLength;
}
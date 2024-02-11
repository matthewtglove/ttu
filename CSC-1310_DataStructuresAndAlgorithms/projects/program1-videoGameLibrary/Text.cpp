#include "Text.h"
#include <iostream>

Text::Text(char *inputText)
{
    char *text = new char[strlen(inputText) + 1];
    strcpy(text, inputText);
    textArray = text;
    textLength = strlen(inputText) + 1;
}

Text::~Text()
{
    delete[] textArray;
    cout << "Text destrucor: Released memory for textArray" << endl;
}

void Text::displayText()
{
    for (int i = 1; i < textLength; i++)
    {
        cout << textArray[i];
    }
}

const char *Text::getText()
{
    return textArray;
}

int Text::getLength()
{
    return textLength;
}
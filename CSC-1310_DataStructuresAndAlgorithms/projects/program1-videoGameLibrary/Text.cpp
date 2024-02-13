#include "Text.h"
#include <iostream>

Text::Text(char *inputText)
{
    textLength = strlen(inputText) + 1;
    char *text = new char[textLength];
    strcpy(text, inputText);
    textArray = text;
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

const char *Text::getText() const
{
    return textArray;
}

int Text::getLength() const
{
    return textLength;
}
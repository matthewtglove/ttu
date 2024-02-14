#include "Text.h"
#include <iostream>

// Building a Text character
Text::Text(char *inputText)
{
    // Considering the null terminator
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

// This string class is so special because it has it's own console output method. Maybe for security?
void Text::displayText()
{
    for (int i = 0; i < textLength; i++)
    {
        cout << textArray[i];
    }
    cout << "";
    cout << flush;
}

const char *Text::getText() const
{
    return textArray;
}

int Text::getLength() const
{
    return textLength;
}
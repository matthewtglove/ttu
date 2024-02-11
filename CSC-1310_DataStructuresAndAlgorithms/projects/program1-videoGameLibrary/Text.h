#ifndef TEXT_H
#define TEXT_H

#include <cstring>
using namespace std;

class Text
{
private:
    const char *textArray;
    int textLength;

public:
    Text(char *inputText);
    ~Text();
    void displayText();
    const char *getText();
    int getLength();
};

#endif
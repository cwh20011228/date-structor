#ifndef _illegalParameter_
#define _illegalParameter_

#include <iostream>
#include <string>
using namespace std;

class illegalParameterValue
{
public:
    illegalParameterValue() : message("Illegal pararmeter value") {}
    illegalParameterValue(const char* theMessage)
    {
        message = theMessage;
    }
    void outputMessage() { cout << message << endl; }

private:
    string message;
};

#endif 
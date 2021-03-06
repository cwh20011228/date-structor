#include <iostream>
#include <string>
using namespace std;

class illegalParameterValue
{
public:
    illegalParameterValue() : message("Illegal parameter value") {}
    illegalParameterValue(const char *theMessage)
    {
        message = theMessage;
    }
    void outputMessage() const { cout << message << endl; }

private:
    string message;
};

int abc(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        throw illegalParameterValue("All parameter should be > 0");
    }
    return a + b + c;
}

int main(void)
{
    try
    {
        cout << abc(2, 0, 4) << endl;
    }
    catch (illegalParameterValue e)
    {
        cout << "The parameters to abc were 2, 0, and 4" << endl;
        cout << " illegalParameterValue expeption thrown" << endl;
        e.outputMessage();
        return 1;
    }
    return 0;
}
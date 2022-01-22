#include <iostream>
using namespace std;

int abc(int a, int b, int c)
{
    if (a < 0 || b < 0 || c < 0)
    {
        throw 1;   /* 抛出异常类型为 int */
    }
    else if (a == 0 || b == 0 || c == 0)
    {
        throw 2;   /* 抛出异常类型为 int */
    }
    else
        return a + b * c;
}

int main(void)
{
    int a, b, c;
    cin >> a >> b >> c;

    try
    {
        cout << abc(a, b, c) << endl;  /* 把可能出现的异常包含在try块中 */
    }
    catch (int errorcode)    /* catch 参数类型 与 抛出异常类型要一致  */
    {
        cout << "Catch Error!" << endl;
        cout << errorcode << endl;
    }

    return 0;
}

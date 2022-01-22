#include <iostream>
using namespace std;

int abc(int a, int b, int c)
{
    if (a < 0 || b < 0 || c < 0)
    {
        throw 1;   /* �׳��쳣����Ϊ int */
    }
    else if (a == 0 || b == 0 || c == 0)
    {
        throw 2;   /* �׳��쳣����Ϊ int */
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
        cout << abc(a, b, c) << endl;  /* �ѿ��ܳ��ֵ��쳣������try���� */
    }
    catch (int errorcode)    /* catch �������� �� �׳��쳣����Ҫһ��  */
    {
        cout << "Catch Error!" << endl;
        cout << errorcode << endl;
    }

    return 0;
}

// ps: 这里只做了指针传参的形式，*/
#include <iostream>
using namespace std;

template <class T>
int count(T *num, T _value, int length) // 通过指针传参
{
    int count_num = 0;
    if (length < 1)
    {
        throw "The array doesn't exit!"; /* 抛出异常类型为 const char*  字符串常量  */
    }
    for (int i = 0; i < length; i++)
    {
        if (num[i] == _value)
            count_num++;
    }

    return count_num;
}

template <class T, int N = 20>
int count(T (&num)[N], T _value) // 通过引用传参
{
    int count_num = 0;
    int length = sizeof(num) / sizeof(num[0]);
    for (int i = 0; i < length; i++)
    {
        if (num[i] == _value)
            count_num++;
    }

    return count_num;
}

int main(void)
{
    int len;
    cin >> len;
    int *n = new int[len];

    int number;
    cin >> number;

    for (int i = 0; i < len; i++)
    {
        n[i] = number;
        if (i == len - 1)
        {
            break;
        }
        cin >> number;
    }

    int _value;
    cin >> _value;

    try
    {
        cout << count(n, _value, len) << endl;
    }
    catch (const char *error)   // 捕获参数应与抛出参数类型一致，这里为 const char*
    {
        cout << "错误！" << endl;
        cout << error << endl;
    }

    return 0;
}
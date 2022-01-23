// ps: 这里只做了指针传参的形式，
// 引用传参还没有做出来
// 思路： 用vector 容器
#include <iostream>
using namespace std;

template <class T>
int count1(T *num, T _value, int length) // 通过指针传参
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

template <class T, int &N>
int count2(T (&num)[N], T _value) // 通过引用传参  引用是数组格式是： type (&数组名) [数组长度]
{
    int count_num = 0;
    /* int length = sizeof(num) / sizeof(num[0]); */
    for (int i = 0; i < N; i++)
    {
        if (num[i] == _value)
            count_num++;
    }

    return count_num;
}

int main(void)
{
    int len = 0;
    cout << "输入数组的长度：";
    cin >> len;
    int *n = new int[len];

    int number;
    cout << "请输入数字：" << endl;
    cin >> number;

    for (int i = 0; i < len; i++)
    {
        n[i] = number;
        if (i == len - 1) // i==数组长度-1 时，不再输入数字，跳出循环
        {
            break;
        }
        cin >> number;
    }

    int _value;
    cout << "输入要查找的数字：";
    cin >> _value;

    try
    {
        cout << _value << "在数组中有" << count1(n, _value, len) << "个！" << endl;
    }
    catch (const char *error) // 捕获参数应与抛出参数类型一致，这里为 const char*
    {
        cout << "错误！" << endl;
        cout << error << endl;
    }

    return 0;
}
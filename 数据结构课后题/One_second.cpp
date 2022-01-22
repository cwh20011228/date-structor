#include <iostream>
using namespace std;

/*template <class T>
int count(T *num, T _value,int length)   // ͨ��ָ�봫��
{
    int count_num = 0;
    for (int i = 0; i< length; i++)
    {
        if (num[i] == _value)
            count_num++;
    }

    return count_num;
}*/

template <class T, int N = 20>
int count(T (&num)[N], T _value)   // ͨ�����ô���
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
    int n[20] = {1, 5, 3, 9, 7, 25, 3, 59, 4, 25, 36, 4, 5, 6, 25, 1, 2, 3, 4, 52};
    // int _number = count(n, 3,20);
    int _number = count(n, 3);
    cout << _number << endl;

    return 0;
}
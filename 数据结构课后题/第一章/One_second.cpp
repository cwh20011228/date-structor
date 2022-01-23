#include <iostream>
using namespace std;

template <class T>
int count(T *num, T _value, int length) // ͨ��ָ�봫��
{
    int count_num = 0;
    for (int i = 0; i < length; i++)
    {
        if (num[i] == _value)
            count_num++;
    }

    return count_num;
}

template <class T, int N = 20>
int count(T (&num)[N], T _value) // ͨ�����ô���     �������鴫�θ�ʽ��type (&������) [�����С]
{
    int count_num = 0;
    //int length = sizeof(num) / sizeof(num[0]);
    for (int i = 0; i < N; i++)
    {
        if (num[i] == _value)
            count_num++;
    }

    return count_num;
}
int main(void)
{
    int n[20] = {1, 5, 3, 9, 7, 25, 3, 59, 4, 25, 36, 4, 5, 6, 25, 1, 2, 3, 4, 52};
    int value;
    cin >> value;
    int _number1 = count(n, value, 20);
    int _number2 = count(n, value);
    cout <<"����һ"<< value << "���ֵĴ���Ϊ��" << _number1 << endl;
    cout <<"������"<< value << "���ֵĴ���Ϊ��" << _number2 << endl;

    return 0;
}
// ps: ����ֻ����ָ�봫�ε���ʽ��*/
#include <iostream>
using namespace std;

template <class T>
int count(T *num, T _value, int length) // ͨ��ָ�봫��
{
    int count_num = 0;
    if (length < 1)
    {
        throw "The array doesn't exit!"; /* �׳��쳣����Ϊ const char*  �ַ�������  */
    }
    for (int i = 0; i < length; i++)
    {
        if (num[i] == _value)
            count_num++;
    }

    return count_num;
}

template <class T, int N = 20>
int count(T (&num)[N], T _value) // ͨ�����ô���
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
    catch (const char *error)   // �������Ӧ���׳���������һ�£�����Ϊ const char*
    {
        cout << "����" << endl;
        cout << error << endl;
    }

    return 0;
}
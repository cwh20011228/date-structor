// ps: ����ֻ����ָ�봫�ε���ʽ��
// ���ô��λ�û��������
// ˼·�� ��vector ����
#include <iostream>
using namespace std;

template <class T>
int count1(T *num, T _value, int length) // ͨ��ָ�봫��
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

template <class T, int &N>
int count2(T (&num)[N], T _value) // ͨ�����ô���  �����������ʽ�ǣ� type (&������) [���鳤��]
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
    cout << "��������ĳ��ȣ�";
    cin >> len;
    int *n = new int[len];

    int number;
    cout << "���������֣�" << endl;
    cin >> number;

    for (int i = 0; i < len; i++)
    {
        n[i] = number;
        if (i == len - 1) // i==���鳤��-1 ʱ�������������֣�����ѭ��
        {
            break;
        }
        cin >> number;
    }

    int _value;
    cout << "����Ҫ���ҵ����֣�";
    cin >> _value;

    try
    {
        cout << _value << "����������" << count1(n, _value, len) << "����" << endl;
    }
    catch (const char *error) // �������Ӧ���׳���������һ�£�����Ϊ const char*
    {
        cout << "����" << endl;
        cout << error << endl;
    }

    return 0;
}
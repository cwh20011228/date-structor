#include <iostream>
using namespace std;

/* ����ĳ��ȱ����ǳ�������Ԥ������Ϊ���鳤�ȷ����ڴ� */
constexpr int LEN = 10; // ����ĳ���

template <class T1, class T2, int N = LEN> /*  ģ��ͷ  */
int count2(T1 (&num)[N], T2 _value)        // ͨ�����ô���    ���ô�������ĸ�ʽ��  type(&������)[���鳤��]
{
    int count_num = 0; /*  ��������_value ���ֵĴ���  */
    if (N < 1)
    {
        throw "Error !"; /* �׳�����Ϊconst char*  */
    }

    for (int i = 0; i < N; i++)
    {
        if (num[i] == _value)
            count_num++;
    }

    return count_num;
}

int main(void)
{
    int n[LEN] = {1, 2, 3, 4, 2, 1, 3, 6, 4, 2}; // ��������

    int _value; // ������Ҫ������
    cout << "������Ҫ�����֣�";
    cin >> _value;

    try
    {

        cout << _value << "���ֵĴ���Ϊ��" << count2(n, _value) << endl;
    }

    catch (const char *error)
    {
        cout << "The array doesn't exit" << endl;
        cout << error << endl;
    }

    return 0;
}

/*
    constexpr int  a = 10;  //*      10 ������ֵ����

    int len ;
    cin>>len;
    constexpr int a = len;   //  *"���ʽ���뺬�г���ֵ -- ���� \"len\"  ��ֵ������������",
    *��constexpr ʧȥ����  ����� len ����Ϊ����
    *const ���� �����ʼ��
    
*/
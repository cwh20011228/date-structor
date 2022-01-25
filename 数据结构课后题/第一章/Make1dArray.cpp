#include <iostream>
using namespace std;

template <class T> // ģ��ͷ
// ����һά����
void make1dArray(T *&x, int numberOfRows)
{ //  xΪָ��new�����ڴ��ָ������� �� numberOfRows Ϊ����ĳ���
    x = new T[numberOfRows];
}

// �ͷ�����Ŀռ�
template <typename T>
void delete1dArray(T *&x)
{
    delete[] x;
    x = nullptr; // �� x ָ��գ���ֹ�û������ѱ��ͷŵĿռ�
}

int main(void)
{
    int *array;       // ����һ��ָ��
    int numberOfRows; // ���鳤��
    cout << "һά����ĳ���Ϊ��";
    cin >> numberOfRows;

    try
    {
        make1dArray(array, numberOfRows); // �ѿ��ܳ��ֵ��쳣����try����
    }

    catch (bad_alloc e)
    {                                    // ������new �����ڴ�ʧ�ܣ� ����һ������Ϊ bad_alloc ���쳣��
        cerr << "Out of Merroy" << endl; // cerr��Ӧ��׼��������������ʾ������Ϣ��д��cerr�������ǲ������
        exit(1);                         // ���������е��³����˳�
    }

    delete1dArray(array); // �����ͷ������ڴ�ĺ���

    return 0;
}
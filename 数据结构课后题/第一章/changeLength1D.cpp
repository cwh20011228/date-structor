#include <iostream>
#include <ctime>
using namespace std;

template <class T>    // ģ��ͷ
T Min(T &a1, T &a2)   //  �������е���Сֵ
{
    return a1 < a2 ? a1 : a2;
}

template <class T>  // ģ��ͷ
T *changeLength1D(T *&x, int oldLength, int newLength)  // oldLength ������ĳ���  �� oldLength ������ĳ���
{
    T *x1 = new T[newLength];   // ����������
    int Length = Min(oldLength, newLength);   // Length �� oldLength�� newLength �н�С��ֵ
    for (int i = 0; i < Length; i++)
    {
        x1[i] = x[i];
    }

    delete[] x;   // �ͷž�����Ŀռ�
    x = nullptr;  // �� xָ�� �գ���ֹ�û������ѱ��ͷŵĿռ�

    return x1;  // ����x1 ָ�룬��������
}

int main(void)
{
    int oldlen;   // ������ĳ���
    cout << "����ĳ���Ϊ��";
    cin >> oldlen;

    int *array;  // ������
    try
    {
        array = new int[oldlen];  // �����ܳ��ֵ��쳣������try����
    }
    catch (bad_alloc erroc)  // new �����ڴ�ʧ�ܣ���������Ϊ bad_alloc ���쳣
    {
        cerr << "array[oldlen] is Out of Merroy" << endl;
        exit(1);  // ������������е����˳�
    }

    srand(time(0));     // srand(time(0)) �����������
    const int MAXSIZE = 20;

    for (int i = 0; i < oldlen; i++)
    {
        array[i] = rand() % MAXSIZE + 1;  // ���� 0~20 �������
    }

    for (int i = 0; i < oldlen; i++) /* �������������Ԫ�ص�ֵ */
    {
        cout << array[i] << "  ";
    }

    int newlen;// ������ĳ���
    cout <<endl<< "�µĳ���Ϊ��";
    cin >> newlen;

    int *array1;   // ������
    try
    {
        array1 = changeLength1D(array, oldlen, newlen);
    }

    catch (bad_alloc erroc)
    {
        cerr << "array[newlen] is Out of Merroy" << endl;
        exit(1);
    }

    catch (...)  // ͨ������ǿ������֪���쳣��ʲô
    {
        cerr << "Out of Merroy" << endl;
        exit(1);
    }

    int length = Min(oldlen, newlen);  //������Ԫ�ظ�ֵ���������еĳ���
    for (int i = 0; i < length; i++)  /* ����������ֵ*/
    {
        cout << array1[i] << "  ";
    }

    delete [] array1;  // �ͷ�����Ŀռ�
    array1 = nullptr;  // ��array1 ָ��գ���ֹ�û������ѱ��ͷŵĿռ�

    return 0;
}

/*
* ps: srand(time(0))  srand�����µ��������ÿ�����µ����ӣ���rand()�õ��������Ҳ�Ͳ�һ��
*    Ϊ��ÿ������һ����һ�������ӣ�������time(0),time(0)�ǵõ���ǰʱ��ֵ
*   srand(time(0))  ���Ǹ�����㷨һ���������ӣ�Ҳ�����㷨���������������������Ժ�ſ��Բ��������,��1970.1.1�������������ʼ����������ӡ�
*/
#include <iostream>
#include <ctime>

using namespace std;

template <class T> // ģ��ͷ
void make2dArray(T **&x, int &numberOfRows, T *&rowSize)
{
    // ������ָ��
    x = new T *[numberOfRows];

    // Ϊÿһ�з���ռ�
    for (int i = 0; i < numberOfRows; i++)
    {
        x[i] = new T[rowSize[i]];
    }
}

template <class T>
void delete2dArray(T **&x, int &numberOfRows)
{
    for (int i = 0; i < numberOfRows; i++)
    {
        delete[] x[i]; // ɾ��������ռ�
    }
    delete[] x; // ɾ����ָ��

    x = nullptr; // ʹxָ�� nulllptr ����ֹ�û����������ѱ��ͷŵĿռ�
}

int main(void)
{
    const int Max = 20;   
    int **array;       
    int _numberOfRows;    // ���������
    cout << "���������������";
    cin >> _numberOfRows;

    int *rowsize;   // ����һ��ָ��
    try
    {
        rowsize = new int[_numberOfRows];  // һά����
    }
    catch (bad_alloc error)
    {
        cerr << "rowsize[_numberOfRows] is Out of Merroy" << endl;
        exit(1);
    }

    unsigned seed;   // ����һ�� unsigned �������洢����
    seed = time(0);  
    srand(seed);

    for (int i = 0; i < _numberOfRows; i++)
    {
        rowsize[i] = rand() % Max + 1;   // ��Χ�� 0~20
    }

    for (int i = 0; i < _numberOfRows; i++)
    {
        cout << rowsize[i] << "  ";   // ע���ӡ��rowsize�����ֵ����֤�Ƿ����
    }

    try
    {
        make2dArray(array, _numberOfRows, rowsize);
    }

    catch (bad_alloc error)
    {
        cerr << "array[numberOfRows][rowsize[i]] is Out of Merroy" << endl;
        exit(1);
    }
    catch (...)
    {
        cerr << "Out of Merroy" << endl;
        exit(1);
    }

    delete2dArray(array, _numberOfRows);

    return 0;
}
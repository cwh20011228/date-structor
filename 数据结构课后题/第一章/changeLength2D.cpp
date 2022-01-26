#include <iostream>
#include <ctime>   // ������ӵ�ͷ�ļ�
#include <iomanip> // �����ʽ����ͷ�ļ�
using namespace std;

template <class T> //  �����������н�С����
T &Min(T &a1, T &a2)
{
    return a1 < a2 ? a1 : a2;
}
//* ps������������������  return ( a > b ? ( a > c ? a : c ) : ( b > c ? b : c ) ) ;
//* ps:����������С������   return ( a < b ? ( a < c ? a : c ) : ( b < c ? b : c ) ) ;

template <class T>
void delete2dArray(T **&x4, int numberOfRows)
{ // ɾ����ά����ռ�
    for (int i = 0; i < numberOfRows; i++)
    {
        delete[] x4[i]; // ɾ���пռ�
    }
    delete[] x4;  // ɾ����ָ��
    x4 = nullptr; // ��x4ָ��գ���ֹ�û����������ѱ��ͷŵĿռ�
}

// ����ά����ĳ��ȴ� [oldnumberOfRows][oldnumberOfColumns] ��Ϊ [newnumberOfRows][newnumberOfColumns]
template <class T>
T **changeLength2D(T **&x, int oldnumberOfRows, int oldnumberOfColumns, int newnumberOfRows, int newnumberOfColumns)
{
    T **x1;
    x1 = new T *[newnumberOfRows]; // ������ָ��
    for (int i = 0; i < newnumberOfRows; i++)
    {
        x1[i] = new T[newnumberOfColumns]; // Ϊÿһ�з���ռ�
    }

    int LengthOfRows = Min(oldnumberOfRows, newnumberOfRows);
    int LengthOfColumns = Min(oldnumberOfColumns, newnumberOfColumns);
    for (int i = 0; i < LengthOfRows; i++)
    {
        for (int j = 0; j < LengthOfColumns; j++)
        {
            x1[i][j] = x[i][j];
        }
    }

    delete2dArray(x, oldnumberOfRows); // �ͷ�x����Ŀռ�

    return x1;
}

template <class T>
void display(T **&x3, int numberOfRows, int numberOfColumns)
{ // �������
    for (int i = 0; i < numberOfRows; i++)
    {
        for (int j = 0; j < numberOfColumns; j++)
        {
            cout << setiosflags(ios::left) << setw(4) << x3[i][j]; // ����룬��� 4
        }
        cout << endl;
    }
}

int main(void)
{
    int lennumberOfRows, lennumberOfColumns; // ��������к���
    cout << "����������к��У�";
    cin >> lennumberOfRows >> lennumberOfColumns;

    int **array;

    try
    {
        array = new int *[lennumberOfRows]; // �����ܳ��ֵ��쳣������try����
    }

    catch (bad_alloc error) // new �����ڴ�ʧ�ܣ���������Ϊ bad_alloc ���쳣
    {
        cerr << "*array[lennumberOfRows] is Out Of Merroy" << endl;
        exit(1); // ������������е����˳�
    }

    try
    {
        for (int i = 0; i < lennumberOfRows; i++)
        {
            array[i] = new int[lennumberOfColumns];
        }
    }

    catch (bad_alloc error)
    {
        cerr << "array[lennumberOfRows][lennumberOfColumns] is Out Of Merroy" << endl;
        exit(1);
    }

    const int MAXSIZE = 30;
    srand(time(0)); // �������
    for (int i = 0; i < lennumberOfRows; i++)
    {
        for (int j = 0; j < lennumberOfColumns; j++)
        {
            array[i][j] = rand() % MAXSIZE + 1; // �������Χ�� 0~MAXSIZE
        }
    }
    // �������
    display(array, lennumberOfRows, lennumberOfColumns);

    int **array1;
    int newlennumberOfRows, newlennumberOfColumns;
    cout << "������������к��У�";
    cin >> newlennumberOfRows >> newlennumberOfColumns;

    try
    {
        array1 = changeLength2D(array, lennumberOfRows, lennumberOfColumns, newlennumberOfRows, newlennumberOfColumns);
    }

    catch (bad_alloc error)
    {
        cerr << "array1[lennumberOfRows][lennumberOfColumns] is Out Of Merroy" << endl;
        exit(1);
    }

    int lenRows = Min(lennumberOfRows, newlennumberOfRows);
    int lenColumns = Min(lennumberOfColumns, newlennumberOfColumns);

    display(array1, lenRows, lenColumns); // �������

    delete2dArray(array1, newlennumberOfRows); //  �ͷ�array1�Ŀռ�

    return 0;
}
#include <iostream>
using namespace std;
// * ps: ����ڱ���ʱ����������һά�Ĵ�Сʱδ֪�ģ���ô����ռ����������ʱ���ò�����new������

/* ��һ�ַ�ʽ��ͨ�����ص�bool���ͣ��ж�����ռ��Ƿ��������*/
/*template<class T>
bool make2dArray(T ** &x,int numberOfRows,int numberOfColumns){
    try{
        // ������ָ��
        x = new T*[numberOfRows];

        // Ϊÿһ�з���ռ�
        for(int i=0;i<numberOfRows;i++){
            x[i]=new T[numberOfColumns];
        }
        return true;
    }
}*/
/* �ڶ��ַ�ʽ��make2dArray ���� ���쳣����ʱʲô�������������߲��� new �׳����κ��쳣  */
template <class T>                                              // ģ��ͷ
void make2dArray(T **&x, int numberOfRows, int numberOfColumns) // xΪָ��new����ռ��ָ������� ��numberOfRows Ϊ������У� numberOfcolumns Ϊ�������
{
    // ������ָ��
    x = new T *[numberOfRows];
    //Ϊÿһ�з���ռ�
    for (int i = 0; i < numberOfRows; i++)
    {
        x[i] = new T[numberOfColumns];
    }
}

template <class T>
void delete2dArray(T **&x, int numberOfRows) // xΪָ��new����ռ��ָ������� ��numberOfRows Ϊ�������
{
    for (int i = 0; i < numberOfRows; i++) // ɾ��������ռ�
    {
        delete[] x[i];
    }

    delete[] x;  // ɾ����ָ��
    x = nullptr; // ��xָ��գ���ֹ�û����������ѱ��ͷŵĿռ�
}
int main(void)
{
    int **array;         // ����һ��ָ��ָ���ָ��
    int numberOfRows;    // ��ά�������
    int numberOfColumns; // ��ά�������
    cout << "��λ����������У�";
    cin >> numberOfRows >> numberOfColumns;

    try
    {
        make2dArray(array, numberOfRows, numberOfColumns);
    }

    catch (bad_alloc error) // new �����ڴ�ʧ�ܣ���������Ϊ bad_alloc ���쳣 ��
    {
        cerr << "Out of Merroy" << endl; // cerr��Ӧ��׼��������������ʾ������Ϣ��д��cerr�������ǲ������
        exit(1);                         // ������������е����˳�
    }
    delete2dArray(array, numberOfRows); // �����ͷſռ亯��

    return 0;
}
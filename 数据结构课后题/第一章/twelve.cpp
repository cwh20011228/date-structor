#include <iostream>
#include <ctime>

using namespace std;

template <class T> // 模板头
void make2dArray(T **&x, int &numberOfRows, T *&rowSize)
{
    // 创建行指针
    x = new T *[numberOfRows];

    // 为每一行分配空间
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
        delete[] x[i]; // 删除行数组空间
    }
    delete[] x; // 删除行指针

    x = nullptr; // 使x指向 nulllptr ，防止用户继续访问已被释放的空间
}

int main(void)
{
    const int Max = 20;   
    int **array;       
    int _numberOfRows;    // 数组的行数
    cout << "输入数组的行数：";
    cin >> _numberOfRows;

    int *rowsize;   // 定义一个指针
    try
    {
        rowsize = new int[_numberOfRows];  // 一维数组
    }
    catch (bad_alloc error)
    {
        cerr << "rowsize[_numberOfRows] is Out of Merroy" << endl;
        exit(1);
    }

    unsigned seed;   // 创建一个 unsigned 变量，存储种子
    seed = time(0);  
    srand(seed);

    for (int i = 0; i < _numberOfRows; i++)
    {
        rowsize[i] = rand() % Max + 1;   // 范围在 0~20
    }

    for (int i = 0; i < _numberOfRows; i++)
    {
        cout << rowsize[i] << "  ";   // 注意打印处rowsize数组的值，验证是否随机
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
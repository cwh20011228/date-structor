#include <iostream>
#include <ctime>   // 随机种子的头文件
#include <iomanip> // 输出格式化的头文件
using namespace std;

template <class T> //  返回两个数中较小的数
T &Min(T &a1, T &a2)
{
    return a1 < a2 ? a1 : a2;
}
//* ps：三个数中最大的数：  return ( a > b ? ( a > c ? a : c ) : ( b > c ? b : c ) ) ;
//* ps:三个数中最小的数：   return ( a < b ? ( a < c ? a : c ) : ( b < c ? b : c ) ) ;

template <class T>
void delete2dArray(T **&x4, int numberOfRows)
{ // 删除二维数组空间
    for (int i = 0; i < numberOfRows; i++)
    {
        delete[] x4[i]; // 删除行空间
    }
    delete[] x4;  // 删除行指针
    x4 = nullptr; // 将x4指向空，防止用户继续访问已被释放的空间
}

// 将二维数组的长度从 [oldnumberOfRows][oldnumberOfColumns] 变为 [newnumberOfRows][newnumberOfColumns]
template <class T>
T **changeLength2D(T **&x, int oldnumberOfRows, int oldnumberOfColumns, int newnumberOfRows, int newnumberOfColumns)
{
    T **x1;
    x1 = new T *[newnumberOfRows]; // 创建行指针
    for (int i = 0; i < newnumberOfRows; i++)
    {
        x1[i] = new T[newnumberOfColumns]; // 为每一行分配空间
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

    delete2dArray(x, oldnumberOfRows); // 释放x数组的空间

    return x1;
}

template <class T>
void display(T **&x3, int numberOfRows, int numberOfColumns)
{ // 输出数组
    for (int i = 0; i < numberOfRows; i++)
    {
        for (int j = 0; j < numberOfColumns; j++)
        {
            cout << setiosflags(ios::left) << setw(4) << x3[i][j]; // 左对齐，域宽 4
        }
        cout << endl;
    }
}

int main(void)
{
    int lennumberOfRows, lennumberOfColumns; // 旧数组的行和列
    cout << "输入数组的行和列：";
    cin >> lennumberOfRows >> lennumberOfColumns;

    int **array;

    try
    {
        array = new int *[lennumberOfRows]; // 将可能出现的异常包含在try块中
    }

    catch (bad_alloc error) // new 分配内存失败，返回类型为 bad_alloc 的异常
    {
        cerr << "*array[lennumberOfRows] is Out Of Merroy" << endl;
        exit(1); // 程序非正常运行导致退出
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
    srand(time(0)); // 随机种子
    for (int i = 0; i < lennumberOfRows; i++)
    {
        for (int j = 0; j < lennumberOfColumns; j++)
        {
            array[i][j] = rand() % MAXSIZE + 1; // 随机数范围在 0~MAXSIZE
        }
    }
    // 输出测试
    display(array, lennumberOfRows, lennumberOfColumns);

    int **array1;
    int newlennumberOfRows, newlennumberOfColumns;
    cout << "输入新数组的行和列：";
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

    display(array1, lenRows, lenColumns); // 输出测试

    delete2dArray(array1, newlennumberOfRows); //  释放array1的空间

    return 0;
}
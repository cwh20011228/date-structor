#include <iostream>
using namespace std;
// * ps: 如果在编译时数组至少有一维的大小时未知的，那么数组空间必须在运行时利用操作符new来创建

/* 第一种方式：通过返回的bool类型，判断数组空间是否分配正常*/
/*template<class T>
bool make2dArray(T ** &x,int numberOfRows,int numberOfColumns){
    try{
        // 创建行指针
        x = new T*[numberOfRows];

        // 为每一行分配空间
        for(int i=0;i<numberOfRows;i++){
            x[i]=new T[numberOfColumns];
        }
        return true;
    }
}*/
/* 第二种方式：make2dArray 函数 在异常出现时什么都不做，调用者捕获 new 抛出的任何异常  */
template <class T>                                              // 模板头
void make2dArray(T **&x, int numberOfRows, int numberOfColumns) // x为指向new分配空间的指针的引用 ，numberOfRows 为数组的行， numberOfcolumns 为数组的列
{
    // 创建行指针
    x = new T *[numberOfRows];
    //为每一行分配空间
    for (int i = 0; i < numberOfRows; i++)
    {
        x[i] = new T[numberOfColumns];
    }
}

template <class T>
void delete2dArray(T **&x, int numberOfRows) // x为指向new分配空间的指针的引用 ，numberOfRows 为数组的行
{
    for (int i = 0; i < numberOfRows; i++) // 删除行数组空间
    {
        delete[] x[i];
    }

    delete[] x;  // 删除行指针
    x = nullptr; // 将x指向空，防止用户继续访问已被释放的空间
}
int main(void)
{
    int **array;         // 定义一个指向指针的指针
    int numberOfRows;    // 二维数组的行
    int numberOfColumns; // 二维数组的列
    cout << "二位数组的行与列：";
    cin >> numberOfRows >> numberOfColumns;

    try
    {
        make2dArray(array, numberOfRows, numberOfColumns);
    }

    catch (bad_alloc error) // new 分配内存失败，返回类型为 bad_alloc 的异常 ，
    {
        cerr << "Out of Merroy" << endl; // cerr对应标准错误流，用于显示错误消息。写到cerr的数据是不缓冲的
        exit(1);                         // 程序非正常运行导致退出
    }
    delete2dArray(array, numberOfRows); // 调用释放空间函数

    return 0;
}
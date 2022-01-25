#include <iostream>
using namespace std;

template <class T> // 模板头
// 创建一维数组
void make1dArray(T *&x, int numberOfRows)
{ //  x为指向new分配内存的指针的引用 ， numberOfRows 为数组的长度
    x = new T[numberOfRows];
}

// 释放数组的空间
template <typename T>
void delete1dArray(T *&x)
{
    delete[] x;
    x = nullptr; // 将 x 指向空，防止用户访问已被释放的空间
}

int main(void)
{
    int *array;       // 定义一个指针
    int numberOfRows; // 数组长度
    cout << "一维数组的长度为：";
    cin >> numberOfRows;

    try
    {
        make1dArray(array, numberOfRows); // 把可能出现的异常放在try块中
    }

    catch (bad_alloc e)
    {                                    // 操作符new 分配内存失败， 返回一个类型为 bad_alloc 的异常，
        cerr << "Out of Merroy" << endl; // cerr对应标准错误流，用于显示错误消息。写到cerr的数据是不缓冲的
        exit(1);                         // 非正常运行导致程序退出
    }

    delete1dArray(array); // 调用释放数组内存的函数

    return 0;
}
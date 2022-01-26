#include <iostream>
#include <ctime>
using namespace std;

template <class T>    // 模板头
T Min(T &a1, T &a2)   //  两个数中的最小值
{
    return a1 < a2 ? a1 : a2;
}

template <class T>  // 模板头
T *changeLength1D(T *&x, int oldLength, int newLength)  // oldLength 旧数组的长度  ， oldLength 新数组的长度
{
    T *x1 = new T[newLength];   // 创建新数组
    int Length = Min(oldLength, newLength);   // Length 是 oldLength与 newLength 中较小的值
    for (int i = 0; i < Length; i++)
    {
        x1[i] = x[i];
    }

    delete[] x;   // 释放旧数组的空间
    x = nullptr;  // 将 x指向 空，防止用户访问已被释放的空间

    return x1;  // 返回x1 指针，用作测试
}

int main(void)
{
    int oldlen;   // 旧数组的长度
    cout << "数组的长度为：";
    cin >> oldlen;

    int *array;  // 旧数组
    try
    {
        array = new int[oldlen];  // 将可能出现的异常包含在try块中
    }
    catch (bad_alloc erroc)  // new 分配内存失败，返回类型为 bad_alloc 的异常
    {
        cerr << "array[oldlen] is Out of Merroy" << endl;
        exit(1);  // 程序非正常运行导致退出
    }

    srand(time(0));     // srand(time(0)) 种下随机种子
    const int MAXSIZE = 20;

    for (int i = 0; i < oldlen; i++)
    {
        array[i] = rand() % MAXSIZE + 1;  // 产生 0~20 的随机数
    }

    for (int i = 0; i < oldlen; i++) /* 测试输出旧数组元素的值 */
    {
        cout << array[i] << "  ";
    }

    int newlen;// 新数组的长度
    cout <<endl<< "新的长度为：";
    cin >> newlen;

    int *array1;   // 新数组
    try
    {
        array1 = changeLength1D(array, oldlen, newlen);
    }

    catch (bad_alloc erroc)
    {
        cerr << "array[newlen] is Out of Merroy" << endl;
        exit(1);
    }

    catch (...)  // 通用性最强，但不知道异常是什么
    {
        cerr << "Out of Merroy" << endl;
        exit(1);
    }

    int length = Min(oldlen, newlen);  //旧数组元素赋值到新数组中的长度
    for (int i = 0; i < length; i++)  /* 输出新数组的值*/
    {
        cout << array1[i] << "  ";
    }

    delete [] array1;  // 释放数组的空间
    array1 = nullptr;  // 将array1 指向空，防止用户访问已被释放的空间

    return 0;
}

/*
* ps: srand(time(0))  srand是种下的随机数，每回种下的种子，用rand()得到的随机数也就不一样
*    为了每回种下一个不一样的种子，所以用time(0),time(0)是得到当前时间值
*   srand(time(0))  就是给这个算法一个启动种子，也就是算法的随机种子数，有这个数以后才可以产生随机数,用1970.1.1至今的秒数，初始化随机数种子。
*/
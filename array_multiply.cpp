#include <iostream>
#include <numeric> // STL算法accumulate的头文件
using std::accumulate;
using std::cin;
using std::cout;
using std::endl;
using std::multiplies; // 乘积

template <class T>
T product(T a[], int n)
{ // 返回数组a[0:n-1] 的累计乘
    T theProduct = 1;
    return accumulate(a, a + n, theProduct, multiplies<T>()); // STL算法accumulate返回值是  theProduct*  a数组各个元素的乘积
}
int main(void)
{
    int length, count = 1;
    int *num = new int[length];
    cout << "数组的长度是:";
    cin >> length;
    for (int i = 0; i < length; i++) // num = {1,2,3,4,5}
    {
        num[i] = count;
        count++;
    }
    cout << "数组的乘积是" << product(num, length) << endl;

    delete[] num;  // 释放new申请的空间
    num = nullptr; // 使num指向空，防止用户访问已被释放的空间

    return 0;
}
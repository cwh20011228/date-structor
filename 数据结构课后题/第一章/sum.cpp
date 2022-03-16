#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// 普通函数
template <class T>
T sum(T a[], int n)
{ // 返回数值数组元素 a[0:n-1] 的和
    T theSum = 0;
    for (int i = 0; i < n; i++)
    {
        theSum += i;
    }
    return theSum;
}

// 递归函数
template <class T>
T rsum(T a[], int n)
{ // 返回数值数组元素 a[0:n-1] 的和
    if (n > 0)
        return rsum(a, n - 1) + a[n - 1];
    return 0;
}

int main(void)
{
    int length;
    int *num = new int[length];
    cout << "数组的大小是";
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        num[i] = i;
    }
    cout << "(递归函数)数组num[0:length]的和为" << rsum(num, length) << endl;
    cout << "(普通函数)数组num[0:length]的和为" << rsum(num, length) << endl;
    delete[] num;
    num = nullptr;

    return 0;
}
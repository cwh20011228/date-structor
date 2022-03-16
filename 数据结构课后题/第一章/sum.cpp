#include <iostream>
#include <numeric>  //  STL 算法 accumulate 的头文件
using std::cin;
using std::cout;
using std::endl;
using std::accumulate;  

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

// STL 算法 accumulate 
template <class T>
T STL_sum(T a[],int n)  
{ // 返回数组 a[0:n-1] 的累计和
    T theSum = 0;
    return accumulate(a,a+n,theSum);   // 算法accumulate 返回值是  theSum + SUM(a[0:n-1])
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
    cout << "(STL算法accumate)数组num[0:length]的和为" << STL_sum(num, length) << endl;
    delete[] num;
    num = nullptr;

    return 0;
}
#include <iostream>
#include <numeric>  //  STL �㷨 accumulate ��ͷ�ļ�
using std::cin;
using std::cout;
using std::endl;
using std::accumulate;  

// ��ͨ����
template <class T>
T sum(T a[], int n)
{ // ������ֵ����Ԫ�� a[0:n-1] �ĺ�
    T theSum = 0;
    for (int i = 0; i < n; i++)
    {
        theSum += i;
    }
    return theSum;
}

// �ݹ麯��
template <class T>
T rsum(T a[], int n)
{ // ������ֵ����Ԫ�� a[0:n-1] �ĺ�
    if (n > 0)
        return rsum(a, n - 1) + a[n - 1];
    return 0;
}

// STL �㷨 accumulate 
template <class T>
T STL_sum(T a[],int n)  
{ // �������� a[0:n-1] ���ۼƺ�
    T theSum = 0;
    return accumulate(a,a+n,theSum);   // �㷨accumulate ����ֵ��  theSum + SUM(a[0:n-1])
}

int main(void)
{
    int length;
    int *num = new int[length];
    cout << "����Ĵ�С��";
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        num[i] = i;
    }
    cout << "(�ݹ麯��)����num[0:length]�ĺ�Ϊ" << rsum(num, length) << endl;
    cout << "(��ͨ����)����num[0:length]�ĺ�Ϊ" << rsum(num, length) << endl;
    cout << "(STL�㷨accumate)����num[0:length]�ĺ�Ϊ" << STL_sum(num, length) << endl;
    delete[] num;
    num = nullptr;

    return 0;
}
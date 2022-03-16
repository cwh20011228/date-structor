#include <iostream>
#include <numeric> // STL�㷨accumulate��ͷ�ļ�
using std::accumulate;
using std::cin;
using std::cout;
using std::endl;
using std::multiplies; // �˻�

template <class T>
T product(T a[], int n)
{ // ��������a[0:n-1] ���ۼƳ�
    T theProduct = 1;
    return accumulate(a, a + n, theProduct, multiplies<T>()); // STL�㷨accumulate����ֵ��  theProduct*  a�������Ԫ�صĳ˻�
}
int main(void)
{
    int length, count = 1;
    int *num = new int[length];
    cout << "����ĳ�����:";
    cin >> length;
    for (int i = 0; i < length; i++) // num = {1,2,3,4,5}
    {
        num[i] = count;
        count++;
    }
    cout << "����ĳ˻���" << product(num, length) << endl;

    delete[] num;  // �ͷ�new����Ŀռ�
    num = nullptr; // ʹnumָ��գ���ֹ�û������ѱ��ͷŵĿռ�

    return 0;
}
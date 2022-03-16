#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int factorial(int n)
{ // 计算 n! 的值
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main(void)
{
    int number;
    cin >> number;
    cout << factorial(number) << endl;

    return 0;
}
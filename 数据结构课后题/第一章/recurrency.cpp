#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int factorial(int n)
{ // ¼ÆËã n!
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
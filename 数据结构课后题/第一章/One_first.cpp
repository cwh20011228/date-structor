#include <iostream>
using namespace std;

void swap(int &x, int &y)
{ // 交换整数x和y
    int temp = x;
    x = y;
    y = temp;
}

void swap(int *x, int *y)
{ // 交换整数x和y
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main(void)
{
    int a = 99, b = 5;
    swap(&a, &b);
    cout << "a=" << a << " b=" << b << endl;

    return 0;
}

/* void swap(int x, int y)
{ // 交换整数x和y
    int temp = x;
    x=y;
    y=temp;
}

此函数并没有交换a与b这两个变量，
    swap函数传进去的是a与b的值，分别赋值给临时变量x,y,之后x与y完成交换，
离开函数后，临时变量x与y被销毁，变量a与b并没有随之改变，还是原来的值。
    因此函数形参的地方应该用 reference & 或 pointer *
*/

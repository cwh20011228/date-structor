#include "currencyOverload.h"

int main(void)
{
    currency g, h(signType::plus, 3, 50), i, j;

    // 使用两种形式的 setValue 来赋值
    g.setValue(signType::minus, 2, 25);
    i.setValue(-6.45);

    // 调用成员函数add 和 output
    j = h + g;
    cout << h << " + " << g << " = " << j << endl;

    // 连续两次调用成员函数add
    j = i + g + h;
    cout << i << " + " << g << " + " << h << " = " << j << endl;

    // 调用成员函数 increament 和 add
    cout << "Increament " << i << " by " << g << " and then add " << h << endl;
    j = (i += g) + h;
    cout << "Result is " << j << endl;
    cout << "Increament object is " << i << endl;

    // 测试异常
    cout << "Attempting to initialize with cents = 152 " << endl;
    try
    {
        i.setValue(signType::plus, 3, 152);
    }
    catch (illegalParameterValue error)
    {
        error.outputMessage();
    }
    return 0;
}
//#include "currency.h" 
#include "NewCurrency.h"   // 提高运行速度
int main(void)
{
    currency g, h(signType::plus, 3, 50), i, j;

    // 使用两种形式的  setValue 来赋值
    g.setValue(signType::minus, 2, 25); //  -$2.25
    i.setValue(-6.45);                  //     -$6.45

    // 调用成员函数 add 和 output
    j = h.add(g);
    h.output();
    cout << " + ";
    g.output();
    cout << " = ";
    j.output();
    cout << endl;

    // 联系调用两次成员函数 add
    j = i.add(g).add(h);
    g.output();
    cout << " + ";
    h.output();
    cout << " + ";
    i.output();
    cout << " = ";
    j.output();
    cout << endl;

    // 调用成员函数 increment 和 add
    j = i.increment(g).add(h);
    h.output();
    cout << " + ";
    g.output();
    cout << " + ";
    i.output();
    cout << " = ";
    j.output();
    cout << endl;

    // 测试异常
    cout << "Attempting to initialize with cents = 152" << endl;
    try
    {
        i.setValue(signType::plus, 3, 152);
    }
    catch (illegalParameterValue e)
    {
        cout << "Caught thrown exception" << endl;
        e.outputMessage();
    }

    return 0;
}
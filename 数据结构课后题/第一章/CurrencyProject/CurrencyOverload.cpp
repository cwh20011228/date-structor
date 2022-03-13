#include "currencyOverload.h"

int main(void)
{
    currency g, h(signType::plus, 3, 50), i, j;

    // ʹ��������ʽ�� setValue ����ֵ
    g.setValue(signType::minus, 2, 25);
    i.setValue(-6.45);

    // ���ó�Ա����add �� output
    j = h + g;
    cout << h << " + " << g << " = " << j << endl;

    // �������ε��ó�Ա����add
    j = i + g + h;
    cout << i << " + " << g << " + " << h << " = " << j << endl;

    // ���ó�Ա���� increament �� add
    cout << "Increament " << i << " by " << g << " and then add " << h << endl;
    j = (i += g) + h;
    cout << "Result is " << j << endl;
    cout << "Increament object is " << i << endl;

    // �����쳣
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
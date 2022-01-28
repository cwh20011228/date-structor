//#include "currency.h" 
#include "NewCurrency.h"   // ��������ٶ�
int main(void)
{
    currency g, h(signType::plus, 3, 50), i, j;

    // ʹ��������ʽ��  setValue ����ֵ
    g.setValue(signType::minus, 2, 25); //  -$2.25
    i.setValue(-6.45);                  //     -$6.45

    // ���ó�Ա���� add �� output
    j = h.add(g);
    h.output();
    cout << " + ";
    g.output();
    cout << " = ";
    j.output();
    cout << endl;

    // ��ϵ�������γ�Ա���� add
    j = i.add(g).add(h);
    g.output();
    cout << " + ";
    h.output();
    cout << " + ";
    i.output();
    cout << " = ";
    j.output();
    cout << endl;

    // ���ó�Ա���� increment �� add
    j = i.increment(g).add(h);
    h.output();
    cout << " + ";
    g.output();
    cout << " + ";
    i.output();
    cout << " = ";
    j.output();
    cout << endl;

    // �����쳣
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
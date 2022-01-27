//#include "myexceptions.h"
#include "illegalPararmeter.h"

enum signType
{
    plus,
    minus,
};
//enum Colour{red,blue,yellow};

class currency
{
public:
    // ���캯��
    currency(signType theSign = signType::plus,
            unsigned long theDollars = 0,
            unsigned int theCents = 0);
    // ��������
    ~currency(){ };
    void setValue(signType, unsigned long, unsigned int);
    void setValue(double);
    signType getSign() const { return sign; }
    unsigned long getDollars() const { return dollars; }
    unsigned int getCents() const { return cents; }
    currency add(const currency &) const;
    currency &increment(const currency &);
    void output() const;

private:
    signType sign;         // ����ķ���
    unsigned long dollars; // ��Ԫ������
    unsigned int cents;    // ���ֵ�����
};

currency::currency(signType thesign, unsigned long theDollars, unsigned int theCents)
{
    // ����һ�� currency �����
    setValue(thesign, theDollars, theCents);
}

void currency::setValue(signType thesign, unsigned long theDollars, unsigned int theCents)
{
    // �����ö�������ݳ�Ա��ֵ
    if (theCents > 99) // ����̫��
        throw illegalParameterValue("Cents should be < 100");
    sign = thesign;
    dollars = theDollars;
    cents = theCents;
}

void currency::setValue(double theAmount)
{
    // �����ö�������ݳ�Ա��ֵ
    if (theAmount < 0)
    {
        sign = signType::minus;
        theAmount = -theAmount;
    }
    else
        sign = signType::plus;

    dollars = (unsigned long)theAmount;                          // ��ȡ��������
    cents = (unsigned int)((theAmount + 0.001 - dollars) * 100); // ��ȡ��λС��
}

currency currency::add(const currency &x) const
{
    // �� x �� *this ���  ��this Ϊ ���ú����Ķ����ָ��
    long a1, a2, a3;
    currency result;

    // �ѵ��ö���ת��Ϊ��������
    a1 = dollars * 100 + cents;
    if (sign == signType::minus)
    {
        a1 = -a1;
    }

    // ��xת��Ϊ��������
    a2 = x.dollars * 100 + x.cents;
    if (x.sign == signType::minus)
    {
        a2 = -a2;
    }

    a3 = a1 + a2;

    // ת��Ϊcurrency����ı��ʽ
    if (a3 < 0)
    {
        result.sign = signType::minus;
        a3 = -a3;
    }
    else
    {
        result.sign = signType::plus;
    }
    result.dollars = a3 / 100;
    result.cents = a3 - result.dollars * 100;

    return result;
}

currency &currency::increment(const currency &x)
{
    // ����x
    *this = add(x);
    return *this;
}

void currency::output() const
{
    // ������ö����ֵ
    if (sign == signType::minus)
        cout << '-';
    cout << '$' << dollars << '.';
    if (cents < 10)
        cout << '0';
    cout << cents;
}

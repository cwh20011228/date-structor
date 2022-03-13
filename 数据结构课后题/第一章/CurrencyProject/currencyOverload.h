#ifndef __CURRENCYOVERLOAD__
#define __CURRENCYOVERLOAD__

#include "illegalPararmeter.h"

enum signType
{
    plus,
    minus,
};

class currency
{
public:
    // ���캯��
    currency(signType theSign = signType::plus,
             unsigned long theDollars = 0,
             unsigned int theCents = 0);
    // ��������
    ~currency(){};
    void setValue(signType, unsigned long, unsigned int);
    void setValue(double);
    signType getSign() const
    {
        if (amount < 0)
            return signType::minus;
        else
            return signType::plus;
    }

    unsigned long getDollars() const
    {
        if (amount < 0)
            return (-amount) / 100;
        else
            return amount / 100;
    }

    unsigned int getCents() const
    {
        if (amount < 0)
            return -amount - getDollars() * 100;
        else
            return amount - getDollars() * 100;
    }

    currency operator+(const currency &) const; // + ʵ��Ϊadd����
    currency &operator+=(const currency &x)     //  += ʵ��Ϊincreament(�۸�����)����
    {
        amount += x.amount;
        return *this;
    }

    void output(ostream &) const;

private:
    long amount;
};

currency::currency(signType theSign, unsigned long theDollars,
                unsigned int theCents)
{ // ����һ��currency �����
    setValue(theSign, theDollars, theCents);
}

void currency::setValue(signType theSign, unsigned long theDollars,
                        unsigned int theCents)
{ // �����ö���ֵ
    if (theCents > 99)
        // ����ֵ̫��
        throw illegalParameterValue("Cents should be < 100");
    amount = theDollars * 100 + theCents;
    if (theSign == signType::minus)
        amount = -amount;
}

void currency::setValue(double theAmount)
{ // �����ö���ֵ
    if (theAmount < 0)
        amount = (long)((theAmount - 0.001) * 100);
    else
        amount = (long)((theAmount + 0.001) * 100);
    // ȡ����ʮλ��
}
currency currency::operator+(const currency &x) const
{ // �Ѳ�������x�͵��ö��� *this ���
    currency result;
    result.amount = amount + x.amount;
    return result;
}

void currency::output(ostream &out) const
{ // �ѻ���ֵ������out
    long theAmount = amount;
    if (theAmount < 0)
    {
        out << '-';
        theAmount = -theAmount;
    }
    long dollars = theAmount / 100;
    out << '$' << dollars << '.';
    int cents = theAmount - dollars * 100;
    if (cents < 0)
    {
        out << '0';
    }
    out << cents;
}

// ���� <<
ostream &operator<<(ostream &out, const currency &x)
{
    x.output(out);
    return out;
}

#endif
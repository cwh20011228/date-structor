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
friend ostream& operator<<(ostream&,const currency&);
public:
    // 构造函数
    currency(signType theSign = signType::plus,
             unsigned long theDollars = 0,
             unsigned int theCents = 0);
    // 析构函数
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

    currency operator+(const currency &) const; // + 实际为add函数
    currency &operator+=(const currency &x)     //  += 实际为increament(价格增幅)函数
    {
        amount += x.amount;
        return *this;
    }

private:
    long amount;
};

currency::currency(signType theSign, unsigned long theDollars,
                unsigned int theCents)
{ // 创建一个currency 类对象
    setValue(theSign, theDollars, theCents);
}

void currency::setValue(signType theSign, unsigned long theDollars,
                        unsigned int theCents)
{ // 给调用对象赋值
    if (theCents > 99)
        // 美分值太大
        throw illegalParameterValue("Cents should be < 100");
    amount = theDollars * 100 + theCents;
    if (theSign == signType::minus)
        amount = -amount;
}

void currency::setValue(double theAmount)
{ // 给调用对象赋值
    if (theAmount < 0)
        amount = (long)((theAmount - 0.001) * 100);
    else
        amount = (long)((theAmount + 0.001) * 100);
    // 取两个十位数
}
currency currency::operator+(const currency &x) const
{ // 把参数对象x和调用对象 *this 相加
    currency result;
    result.amount = amount + x.amount;
    return result;
}

// 重载 <<
ostream &operator<<(ostream &out, const currency &x)
{
    // 把货币值插入流out
    long theAmount = x.amount;
    if (theAmount < 0)
    {
        out << '-';
        theAmount = -theAmount;
    }
    long dollars = theAmount / 100;  // 美元
    out << '$' << dollars << '.';
    int cents = theAmount - dollars * 100;  // 美分
    if (cents < 0)
    {
        out << '0';
    }
    out << cents;

    return out;
}

#endif
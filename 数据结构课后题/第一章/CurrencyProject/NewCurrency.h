#include "illegalPararmeter.h"

enum signType
{
    plus,
    minus
};

class currency
{
public:
    // 构造函数
    currency(signType theSign = signType::plus,
            unsigned long theDollars = 0,
            unsigned int theCents = 0);
    // 析构函数
    ~currency() {}
    void setValue(signType, unsigned long, unsigned int);
    void setValue(double);
    signType getsign() const
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

    currency add(const currency &x) const;
    currency &increment(const currency &x)
    {
        amount += x.amount;
        return *this;
    }
    void output() const;

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

currency currency::add(const currency &x) const
{ // 把x和 *this  相加
    currency y;
    y.amount = amount + x.amount;
    return y;
}

void currency::output() const
{ // 输出调用对象的值
    long theAmount = amount;
    if (theAmount < 0)
    {
        cout << '-';
        theAmount = -theAmount;
    }
    long dollars = theAmount / 100;
    cout << '$' << dollars << '.';
    int cents = theAmount - dollars * 100;
    if (cents < 0)
        cents = 0;
    cout << cents;
}
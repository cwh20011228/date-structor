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
    // 构造函数
    currency(signType theSign = signType::plus,
            unsigned long theDollars = 0,
            unsigned int theCents = 0);
    // 析构函数
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
    signType sign;         // 对象的符号
    unsigned long dollars; // 美元的数量
    unsigned int cents;    // 美分的数量
};

currency::currency(signType thesign, unsigned long theDollars, unsigned int theCents)
{
    // 创建一个 currency 类对象
    setValue(thesign, theDollars, theCents);
}

void currency::setValue(signType thesign, unsigned long theDollars, unsigned int theCents)
{
    // 给调用对象的数据成员赋值
    if (theCents > 99) // 美分太多
        throw illegalParameterValue("Cents should be < 100");
    sign = thesign;
    dollars = theDollars;
    cents = theCents;
}

void currency::setValue(double theAmount)
{
    // 给调用对象的数据成员赋值
    if (theAmount < 0)
    {
        sign = signType::minus;
        theAmount = -theAmount;
    }
    else
        sign = signType::plus;

    dollars = (unsigned long)theAmount;                          // 提取整数部分
    cents = (unsigned int)((theAmount + 0.001 - dollars) * 100); // 提取两位小数
}

currency currency::add(const currency &x) const
{
    // 把 x 和 *this 相加  ，this 为 调用函数的对象的指针
    long a1, a2, a3;
    currency result;

    // 把调用对象转化为符号整数
    a1 = dollars * 100 + cents;
    if (sign == signType::minus)
    {
        a1 = -a1;
    }

    // 把x转化为符号整数
    a2 = x.dollars * 100 + x.cents;
    if (x.sign == signType::minus)
    {
        a2 = -a2;
    }

    a3 = a1 + a2;

    // 转化为currency对象的表达式
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
    // 增加x
    *this = add(x);
    return *this;
}

void currency::output() const
{
    // 输出调用对象的值
    if (sign == signType::minus)
        cout << '-';
    cout << '$' << dollars << '.';
    if (cents < 10)
        cout << '0';
    cout << cents;
}

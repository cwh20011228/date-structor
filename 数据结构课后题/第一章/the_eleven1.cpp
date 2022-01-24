#include <iostream>
using namespace std;

/* 数组的长度必须是常量，在预编译期为数组长度分配内存 */
constexpr int LEN = 10; // 数组的长度

template <class T1, class T2, int N = LEN> /*  模板头  */
int count2(T1 (&num)[N], T2 _value)        // 通过引用传参    引用传递数组的格式：  type(&数组名)[数组长度]
{
    int count_num = 0; /*  计数，数_value 出现的次数  */
    if (N < 1)
    {
        throw "Error !"; /* 抛出类型为const char*  */
    }

    for (int i = 0; i < N; i++)
    {
        if (num[i] == _value)
            count_num++;
    }

    return count_num;
}

int main(void)
{
    int n[LEN] = {1, 2, 3, 4, 2, 1, 3, 6, 4, 2}; // 定义数组

    int _value; // 输入你要的数字
    cout << "输入你要的数字：";
    cin >> _value;

    try
    {

        cout << _value << "出现的次数为：" << count2(n, _value) << endl;
    }

    catch (const char *error)
    {
        cout << "The array doesn't exit" << endl;
        cout << error << endl;
    }

    return 0;
}

/*
    constexpr int  a = 10;  //*      10 是字面值常量

    int len ;
    cin>>len;
    constexpr int a = len;   //  *"表达式必须含有常量值 -- 变量 \"len\"  的值不可用作常量",
    *即constexpr 失去作用  ，因此 len 必须为常量
    *const 常量 必须初始化
    
*/
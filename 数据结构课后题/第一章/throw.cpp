#include <iostream>
using namespace std;

int abc(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)           /*满足某个条件时，显示地抛出一个异常*/
        throw "All parameters should be > 0"; /* 抛出的异常类型为字符串   */
    // throw 404; /* 抛出的是 int */
    /* 满足抛出条件时，则抛出语句后面的都不执行了 */
    return a + b * c;
}

int main(void)
{
    try
    { /* 把可能出现的异常包含在 try 块中  */
        cout << abc(2, 0, 6) << endl;
    }

    catch (int error)
    {
        cout << error << endl;
    }

    catch (const char *e) /* 参数要与抛出的异常类型匹配   */
    {
        cout << "The parameters to abc were 2,0,and 4" << endl;
        cout << "An exception has been thrown" << endl;
        cout << e << endl;
        return 1;
    }
    catch (...) /* 通用性最强，但不知道抛出的异常是什么  */
    {
        cout << "所有的异常都匹配！" << endl;
    }

    return 0;
}

/*
    1.书上这里出现错误：catch (char *e){}
    因为异常的类型为字符串常量，所以 catch 的参数应该为 const char *e
    2.异常处理的执行顺序： (throw)抛出异常 >> 捕获异常(catch()) >> 处理异常(catch块里)
    3.抛出异常由程序员决定什么是异常，是否抛出，抛出什么类型的异常
*/
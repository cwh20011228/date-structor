#include <iostream>
using namespace std;

int abc(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)           /*����ĳ������ʱ����ʾ���׳�һ���쳣*/
        throw "All parameters should be > 0"; /* �׳����쳣����Ϊ�ַ���   */
    // throw 404; /* �׳����� int */
    /* �����׳�����ʱ�����׳�������Ķ���ִ���� */
    return a + b * c;
}

int main(void)
{
    try
    { /* �ѿ��ܳ��ֵ��쳣������ try ����  */
        cout << abc(2, 0, 6) << endl;
    }

    catch (int error)
    {
        cout << error << endl;
    }

    catch (const char *e) /* ����Ҫ���׳����쳣����ƥ��   */
    {
        cout << "The parameters to abc were 2,0,and 4" << endl;
        cout << "An exception has been thrown" << endl;
        cout << e << endl;
        return 1;
    }
    catch (...) /* ͨ������ǿ������֪���׳����쳣��ʲô  */
    {
        cout << "���е��쳣��ƥ�䣡" << endl;
    }

    return 0;
}

/*
    1.����������ִ���catch (char *e){}
    ��Ϊ�쳣������Ϊ�ַ������������� catch �Ĳ���Ӧ��Ϊ const char *e
    2.�쳣�����ִ��˳�� (throw)�׳��쳣 >> �����쳣(catch()) >> �����쳣(catch����)
    3.�׳��쳣�ɳ���Ա����ʲô���쳣���Ƿ��׳����׳�ʲô���͵��쳣
*/
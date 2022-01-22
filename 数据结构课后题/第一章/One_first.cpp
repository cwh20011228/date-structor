#include <iostream>
using namespace std;

void swap(int &x, int &y)
{ // ��������x��y
    int temp = x;
    x = y;
    y = temp;
}

void swap(int *x, int *y)
{ // ��������x��y
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main(void)
{
    int a = 99, b = 5;
    swap(&a, &b);
    cout << "a=" << a << " b=" << b << endl;

    return 0;
}

/* void swap(int x, int y)
{ // ��������x��y
    int temp = x;
    x=y;
    y=temp;
}

�˺�����û�н���a��b������������
    swap��������ȥ����a��b��ֵ���ֱ�ֵ����ʱ����x,y,֮��x��y��ɽ�����
�뿪��������ʱ����x��y�����٣�����a��b��û����֮�ı䣬����ԭ����ֵ��
    ��˺����βεĵط�Ӧ���� reference & �� pointer *
*/

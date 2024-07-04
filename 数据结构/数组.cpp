#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Array
{
public:
    Array(int size=10):mCur{0},mCap{size}
    {
        mpArr = new int[mCap]();

    }
    ~Array()
    {
        delete[] mpArr;
        mpArr=nullptr;
    }
public:
    // ĩβ����Ԫ�� 
    void push_back(int val)
    {
        if(mCur==mCap)
        {
            expand(2*mCap);     // O(n)
        }
        mpArr[mCur++]=val;      // O(1)
    }
    // ĩβɾ��Ԫ��             // O(1)
    void pop_back()
    {
        if(mCur==0)
        {
            return;
        }
        mCur--;
    }
    // ��λ������Ԫ��      // O(n)
    void insert(int pos,int val)
    {
        if(pos<0 || pos>mCur)
        {
            return ;
        }

        if(mCur==mCap)
        {
            expand(2*mCap);
        }

        for(int i=mCur-1;i>=pos;i--)
        {
            mpArr[i+1]=mpArr[i];
        }
        mpArr[pos]=val;
        mCur++;
    }
    // ��λ��ɾ��       // O(n)
    void erase(int pos)
    {
        if(mCur==0 || pos<0 || pos>=mCur)
        {
            return;
        }

        for(int j=pos+1;j<mCur;j++)
        {
            mpArr[j-1]=mpArr[j];
        }
        mCur--;
    }
    // Ԫ�ز�ѯ         O(n)
    int find(int val)
    {
        if(mCur==0)
        {
            return -1;
        }

        for(int i=0;i<mCur;i++)
        {
            if(mpArr[i]==val)
            {
                return i;
            }
        }
        return -1;
    }
    // ��ӡ����
    void show()
    {
        for (int i = 0; i < mCur; i++)
        {
            cout<<mpArr[i]<<" ";
        }
        cout<<endl;
    }
private:
    // �ڲ��������ݽӿ�
    void expand(int size)
    {
        int* arr = new int[size];
        memcpy(arr,mpArr,sizeof(int)*mCap);
        delete[] mpArr;
        mCap=size;
        mpArr=arr;
    }
private:
    int* mpArr;     // ָ������ݵ������ڴ�
    int mCap;      // ���������
    int mCur;       // �������ЧԪ�ظ���
};

int main()
{
    Array arr;
    srand(time(0));
    for(int i=0;i<10;i++)
    {
        arr.push_back(rand()%100);
    }

    arr.show();
    
    arr.pop_back();
    arr.show();

    arr.insert(0,100);
    arr.show();

    arr.insert(10,200);
    arr.show();

    int pos=arr.find(100);
    if(pos!=-1)
    {
        cout<<"�ҵ�Ԫ�أ�Ԫ��λ����"<<pos<<endl;
        arr.erase(pos);
    }
    arr.show();

    return 0;
}
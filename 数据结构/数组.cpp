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
    // 末尾增加元素 
    void push_back(int val)
    {
        if(mCur==mCap)
        {
            expand(2*mCap);     // O(n)
        }
        mpArr[mCur++]=val;      // O(1)
    }
    // 末尾删除元素             // O(1)
    void pop_back()
    {
        if(mCur==0)
        {
            return;
        }
        mCur--;
    }
    // 按位置增加元素      // O(n)
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
    // 按位置删除       // O(n)
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
    // 元素查询         O(n)
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
    // 打印数组
    void show()
    {
        for (int i = 0; i < mCur; i++)
        {
            cout<<mpArr[i]<<" ";
        }
        cout<<endl;
    }
private:
    // 内部数组扩容接口
    void expand(int size)
    {
        int* arr = new int[size];
        memcpy(arr,mpArr,sizeof(int)*mCap);
        delete[] mpArr;
        mCap=size;
        mpArr=arr;
    }
private:
    int* mpArr;     // 指向可扩容的数组内存
    int mCap;      // 数组的容量
    int mCur;       // 数组的有效元素个数
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
        cout<<"找到元素，元素位置是"<<pos<<endl;
        arr.erase(pos);
    }
    arr.show();

    return 0;
}
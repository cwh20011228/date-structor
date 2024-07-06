#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

// 节点类型
struct Node
{
    Node(int data=0):data_(data),next_(nullptr) {}
    int data_;
    Node* next_;
};

// 单链表
class Clink
{
public:
    Clink()
    {
        head_ = new Node();     // 给head_初始化指向头节点
    }
    ~Clink()
    {
        Node* p=head_;
        while(p!=nullptr)
        {
            head_=head_->next_;
            delete p;
            p=head_;
        }
        head_=nullptr;
    }
public:
    // 链表尾插法   O(n)
    void InsertTail(int val)
    {
        // 先找到当前链表的尾部
        Node* p=head_;
        while(p->next_!=nullptr)
        {
            p=p->next_;
        }

        //生成新节点    
        Node* node = new Node(val);
        // 把新节点挂在尾节点的后面
        p->next_=node;
    }
    // 链表头插法   O(1)
    void InsertHead(int val)
    {
        // 生成新节点
        Node* node=new Node(val);

        node->next_=head_->next_;
        head_->next_=node;
    }
    // 链表节点的删除   O(n)
    void Remove(int val)
    {
        Node* q=head_;
        Node* p=head_->next_;
        while(p!=nullptr)
        {
            if(p->data_==val)
            {
                q->next_=p->next_;
                delete p;
                return;
            }
            q=p;
            p=p->next_;
        }
    }
    // 删除多个节点 O(n)
    void RemoveAll(int val)
    {
        Node* q=head_;
        Node* p=head_->next_;
        while(p!=nullptr)
        {
            if(p->data_==val)
            {
                q->next_=p->next_;
                delete p;
                p=q->next_;
            }
            else
            {
                q=p;
                p=p->next_;
            }
        }
    }
    // 链表打印 O(n)
    void show()
    {
        Node* p=head_->next_;
        while(p!=nullptr)
        {
            cout<<p->data_<<"  ";
            p=p->next_;
        }
        cout<<endl;
    }
    // 搜索 O(n)
    bool Find(int val)
    {
        Node* p=head_->next_;
        while(p!=nullptr)
        {
            if(p->data_==val)
            {
                return true;
            }
            p=p->next_;
        }
        return false;
    }
private:
    Node* head_;    // 指向链表的头节点
};


int main(void)
{
    Clink link;
    srand(time(NULL));
    for(int i=0;i<10;i++)
    {
        int val = rand()%100+1;
        link.InsertTail(val);
        cout<<val<<"  ";
    }
    cout<<endl;

    link.InsertHead(23);
    link.InsertHead(23);
    link.InsertTail(23);
    link.show();

    link.RemoveAll(23);
    link.show();
    link.InsertTail(200);
    if(link.Find(200))
    {
        cout<<"true"<<endl;
    }
}
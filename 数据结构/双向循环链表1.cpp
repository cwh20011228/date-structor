#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

//TODO: 不带tail节点的双向循环链表
class DoubleCircleLink
{
public:
    DoubleCircleLink()
    {
        head_ = new Node();
        head_->next_=head_;
        head_->pre_=head_;
    }

    ~DoubleCircleLink()
    {
        Node* p=head_->next_;
        while(p!=head_)
        {
            head_->next_=p->next_;
            p->next_->pre_=head_;
            delete p;
            p=head_->next_;
        }
        delete head_;
        head_=nullptr;
    }

public:
    void InsertHead(int val)
    {
        Node* node = new Node(val);
        node->next_=head_->next_;
        node->pre_=head_;
        head_->next_->pre_=node;
        head_->next_=node;
    }

    void InsertTail(int val)
    {
        Node* node = new Node(val);
        Node* tail_ = head_->pre_;
        node->next_=tail_->next_;
        node->pre_=tail_;
        tail_->next_->pre_=node;
        tail_->next_=node;
    }

    void remove(int val)
    {
        Node* p= head_->next_;
        while(p!=head_)
        {
            if(p->data_==val)
            {
                p->pre_->next_=p->next_;
                p->next_->pre_=p->pre_;
                delete p;
                return ;
            }
            else
            {
                p=p->next_;
            }
        }
    } 

    void removeAll(int val)
    {
        Node* p=head_->next_;
        while(p!=head_)
        {
            if(p->data_==val)
            {
                p->pre_->next_=p->next_;
                p->next_->pre_=p->pre_;
                Node* q = p->next_;
                delete p;
                p=q;
            }
            else
            {
                p=p->next_;
            }
        }
    }

    void show() const
    {
        Node* p=head_->next_;
        while(p!=head_)
        {
            cout<<p->data_<<"   ";
            p=p->next_;
        }
        cout<<endl;
    }

private:
    struct Node
    {
        Node(int data=0)
            :data_(data)
            ,next_(nullptr)
            ,pre_(nullptr)
            { }
        int data_;
        Node* next_;
        Node* pre_;
    };
    Node* head_;

};


int main()
{
    DoubleCircleLink link;

    srand(time(NULL));
for (int i = 0; i < 5; i++)
    {
        int val = rand() % 100 + 1;
        cout << val << "     ";
        link.InsertTail(val);
    }
    link.InsertTail(50);
    link.InsertTail(51);
    cout << 50 << "   " << 51 << "   ";
    for (int i = 0; i < 5; i++)
    {
        int val = rand() % 100 + 1;
        cout << val << "   ";
        link.InsertTail(val);
    }
    cout << endl;

    link.show();

    link.InsertHead(200);
    link.InsertHead(201);
    link.show();

    link.InsertTail(300);
    link.InsertTail(201);
    link.show();

    link.removeAll(201);
    link.show();

}
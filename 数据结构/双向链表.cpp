#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class CircleLink
{
public:
    CircleLink()
    {
        head_ = new Node();
    }
    ~CircleLink()
    {
        Node *p = head_;
        while (p != nullptr)
        {
            head_=head_->next_ ;
            delete p;
            p = head_;
        }
    
    }

public:
    // 尾插
    void InsertTail(int val)
    {
        Node *node = new Node(val);
        Node *p = head_;
        while (p->next_ != nullptr)
        {
            p = p->next_;
        }
        node->pre_ = p;
        p->next_ = node;
    }

    // 头插法
    void InsertHead(int val)
    {
        Node *node = new Node(val);
        node->next_ = head_->next_;
        node->pre_ = head_;
        if (node->next_ != nullptr)
        {
            head_->next_->pre_ = node;
        }
        head_->next_ = node;
        
    }

    // 删除一个值为val的节点
    void Remove(int val)
    {
        Node *p = head_->next_;
        while (p != nullptr)
        {
            if (p->data_ == val)
            {
                p->pre_->next_=p->next_;
                if (p->next_ != nullptr)
                {
                    p->next_->pre_ = p->pre_; 
                }
                delete p;
                return;
            }
            p = p->next_;
        }
    }

    // 删除所有值为val的节点
    void RemoveAll(int val)
    {
        Node *p = head_->next_;
        Node *q = head_;
        while (p != nullptr)
        {
            if (p->data_ == val)
            {
                q->next_ = p->next_;
                if (p->next_ != nullptr)
                {
                    p->next_->pre_ = q;
                    q->next_=p->next_;
                }
                delete p;
                p = q->next_;
            }
            else
            {
                q = p;
                p = p->next_;
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
            else
            {
                p=p->next_;
            }
        }
        return false;
    }

private:
    struct Node
    {
        Node(int data = 0) 
            : data_(data)
            , pre_(nullptr)
            , next_(nullptr) 
        {}

        int data_;
        Node *pre_;
        Node *next_;
    };
    Node *head_; // 头节点
};


int main()
{
    CircleLink link;

    srand(time(NULL));

    for(int i=0;i<10;i++)
    {
        int val=rand()%100+1;
        cout<<val<<"  ";
        link.InsertHead(val);
    }
    cout<<endl;

    link.show();

    link.InsertHead(101);
    link.InsertHead(102);
    link.show();

    link.InsertTail(300);
    link.InsertTail(102);
    link.show();

    link.RemoveAll(300);
    link.show();

    if(link.Find(102))
    {
        cout<<"find"<<endl;
    }
    
}
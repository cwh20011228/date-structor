#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

//TODO: 带tail_节点的双向循环链表
class DoubleCirclrLink
{
public:
    DoubleCirclrLink()
    {
        head_ = new Node();
        tail_ = head_;
        head_->pre_ = head_;
        head_->next_ = head_;
    }

    ~DoubleCirclrLink()
    {
        Node *p = head_->next_;
        while (p != head_)
        {
            head_->next_=p->next_;
            p->next_->pre_=head_;
            delete p;
            p = head_->next_;
        }
        delete head_;
        head_ = nullptr;
    }

public:
    void InsertHead(int val)
    {
        Node *node = new Node(val);
        node->next_ = head_->next_;
        node->pre_ = head_;
        if (head_->next_ != head_)
        {
            head_->next_->pre_ = node;
        }
        else
        {
            tail_ = node;
        }
        head_->next_ = node;
    }

    void InsertTail(int val)
    {
        Node *node = new Node(val);
        node->next_ = tail_->next_;
        node->pre_ = tail_;
        tail_->next_ = node;
        tail_ = node;
    }

    // 移除第一个值为val的节点
    void remove(int val)
    {
        Node *p = head_->next_;
        while (p != head_)
        {
            if (p->data_ == val)
            {
                p->pre_->next_ = p->next_;
                if (p->next_ != head_)
                {
                    p->next_->pre_ = p->pre_;
                }
                else
                {
                    tail_ = p->pre_;
                }
                delete p;
                return;
            }
            else
            {
                p = p->next_;
            }
        }
    }

    // 移除值为val的所有节点
    void removeAll(int val)
    {
        Node *p = head_->next_;
        while (p != head_)
        {
            if (p->data_ == val)
            {
                p->pre_->next_ = p->next_;
                if (p->next_ != head_)
                {
                    p->next_->pre_ = p->pre_;
                    Node *q = p->next_;
                    delete p;
                    p = q;
                }
                else
                {
                    tail_ = p->pre_;
                    delete p;
                    return;
                }
            }
            else
            {
                p = p->next_;
            }
        }
    }

    void show() const
    {
        Node *p = head_->next_;
        while (p != head_)
        {
            cout << p->data_ << "   ";
            p = p->next_;
        }
        cout << endl;
    }

    bool find(int val) const
    {
        Node *p = head_->next_;
        while (p != head_)
        {
            if (p->data_ == val)
            {
                return true;
            }
            else
            {
                p = p->next_;
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
    Node *head_;
    Node *tail_;
};

int main()
{
    DoubleCirclrLink link;

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

    if (link.find(300))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}
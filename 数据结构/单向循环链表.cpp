#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

struct CircleLink
{
public:
    CircleLink()
    {
        head_ = new Node();
        tail_ = head_;
        tail_->next_ = head_;
    }
    ~CircleLink()
    {
        Node *p = head_->next_;
        while (p != head_)
        {
            head_->next_ = p->next_;
            delete p;
            p = head_->next_;
        }
        delete head_;
    }

public:
    // 尾插法   O(1)
    void InsertTail(int val)
    {
        Node *node = new Node(val);
        node->next_ = tail_->next_;
        tail_->next_ = node;
        tail_ = node;
    }
    // 头插法   O(1)
    void InsertHead(int val)
    {
        Node *node = new Node(val);
        node->next_ = head_->next_;
        head_->next_ = node;
        if (node->next_ == head_)
        {
            tail_ = node;
        }
    }
    // 删除     O(n)
    void Remove(int val)
    {
        Node *p = head_->next_;
        Node *q = head_;
        while (p != head_)
        {
            if (p->data_ == val)
            {
                q->next_ = p->next_;
                delete p;
                if (q->next_ == head_)
                {
                    tail_ = q;
                }
                return;
            }
            p = p->next_;
            q = q->next_;
        }
    }
    // 删除多个节点  O(n)
    void RemoveAll(int val)
    {
        Node *p = head_->next_;
        Node *q = head_;
        while (p != head_)
        {
            if (p->data_ == val)
            {
                q->next_ = p->next_;
                delete p;
                p = q->next_;
                if (q->next_ == head_)
                {
                    tail_ = q;
                }
            }
            else
            {
                p = p->next_;
                q = q->next_;
            }
        }
    }
    // 查询     O(n)
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
    // 打印     O(n)
    void show() const
    {
        Node *p = head_->next_;
        while (p != head_)
        {
            cout << p->data_ << "  ";
            p = p->next_;
        }
        cout << endl;
    }
    
private:
    struct Node
    {
        Node(int data = 0) : data_(data), next_(nullptr) {}
        int data_;
        Node *next_;
    };

    Node *head_; // 指向头节点
    Node *tail_; // 指向末尾节点
};

int main()
{
    CircleLink link;

    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        int val = rand() % 100;
        cout << val << "  ";
        link.InsertTail(val);
    }
    cout << endl;

    link.show();

    link.InsertHead(33);
    link.InsertHead(230);
    link.InsertHead(290);
    link.InsertTail(33);
    link.show();

    link.Remove(290);
    link.show();

    link.RemoveAll(33);
    link.show();

    return 0;
}
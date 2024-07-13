#include <iostream>
using namespace std;

struct Node
{
    Node(int data = 0) : data_(data), next_(nullptr) {}
    int data_;
    Node *next_;
};

// 约瑟夫环问题  不带头节点的单向循环链表（head指向第一个有效元素的地址）
void Joseph(Node *head, int k, int m)
{
    Node *p = head;

    Node *q = head;
    // 让q指向末尾节点
    while (q->next_ != head)
    {
        q = q->next_;
    }

    for (int i = 1; i < k; i++)
    {
        q = p;
        p = p->next_;
    }

    for (;;)
    {
        for (int i = 1; i < m; i++)
        {
            q = p;
            p = p->next_;
        }

        cout << p->data_ << "  ";

        if (p == q)
        {
            delete p;
            break;
        }

        q->next_ = p->next_;
        delete p;
        p = q->next_;
    }
}

//  约瑟夫环问题  带头节点的单向循环链表
void JosephHead(Node *head, int k, int m)
{
    Node *p = head;
    Node *q = head;
    for (int i = 0; i < k; i++)
    {
        q = p;
        p = p->next_;
    }

    while (p != q)
    {
        if (p == head)
        {
            q = p;
            p = p->next_;
        }
        for (int i = 1; i < m; i++)
        {
            q = p;
            p = p->next_;
        }

        if (p == head)
        {
            q = p;
            p = p->next_;
        }
        cout << p->data_ << "  ";

        q->next_ = p->next_;
        delete p;
        p = q->next_;
    }
    delete head;
}

// 带头节点的测试代码
int main()
{
    Node *head = new Node;
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);
    Node *n7 = new Node(7);
    Node *n8 = new Node(8);

    head->next_ = n1;
    n1->next_ = n2;
    n2->next_ = n3;
    n3->next_ = n4;
    n4->next_ = n5;
    n5->next_ = n6;
    n6->next_ = n7;
    n7->next_ = n8;
    n8->next_ = head;

    JosephHead(head, 3, 2);
}

#if 0
// 不带头节点的测试代码
int main()
{
    Node *head = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);
    Node *n7 = new Node(7);
    Node *n8 = new Node(8);

    head->next_ = n2;
    n2->next_ = n3;
    n3->next_ = n4;
    n4->next_ = n5;
    n5->next_ = n6;
    n6->next_ = n7;
    n7->next_ = n8;
    n8->next_ = head;

    Joseph(head, 1, 1);

    return 0;
}

#endif
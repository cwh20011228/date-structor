#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

// 节点类型
struct Node
{
    Node(int data = 0) : data_(data), next_(nullptr) {}
    int data_;
    Node *next_;
};

// 单链表
class Clink
{
public:
    Clink()
    {
        head_ = new Node(); // 给head_初始化指向头节点
    }
    ~Clink()
    {
        Node *p = head_;
        while (p != nullptr)
        {
            head_ = head_->next_;
            delete p;
            p = head_;
        }
        head_ = nullptr;
    }

public:
    // 链表尾插法   O(n)
    void InsertTail(int val)
    {
        // 先找到当前链表的尾部
        Node *p = head_;
        while (p->next_ != nullptr)
        {
            p = p->next_;
        }

        // 生成新节点
        Node *node = new Node(val);
        // 把新节点挂在尾节点的后面
        p->next_ = node;
    }
    // 链表头插法   O(1)
    void InsertHead(int val)
    {
        // 生成新节点
        Node *node = new Node(val);

        node->next_ = head_->next_;
        head_->next_ = node;
    }
    // 链表节点的删除   O(n)
    void Remove(int val)
    {
        Node *q = head_;
        Node *p = head_->next_;
        while (p != nullptr)
        {
            if (p->data_ == val)
            {
                q->next_ = p->next_;
                delete p;
                return;
            }
            q = p;
            p = p->next_;
        }
    }
    // 删除多个节点 O(n)
    void RemoveAll(int val)
    {
        Node *q = head_;
        Node *p = head_->next_;
        while (p != nullptr)
        {
            if (p->data_ == val)
            {
                q->next_ = p->next_;
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
        Node *p = head_->next_;
        while (p != nullptr)
        {
            cout << p->data_ << "  ";
            p = p->next_;
        }
        cout << endl;
    }
    // 搜索 O(n)
    bool Find(int val)
    {
        Node *p = head_->next_;
        while (p != nullptr)
        {
            if (p->data_ == val)
            {
                return true;
            }
            p = p->next_;
        }
        return false;
    }

private:
    friend void ReverseLink(Clink &link);
    friend bool GetLastKNode(Clink &link, int k, int &val);
    friend void MergeLink(Clink &link1, Clink &link2);

private:
    Node *head_; // 指向链表的头节点
};

// 单链表逆序
void ReverseLink(Clink &link)
{
    Node *head = link.head_;
    Node *p = head->next_;
    if (p == nullptr)
    {
        return;
    }

    head->next_ = nullptr;

    while (p != nullptr)
    {
        Node *q = p->next_;

        // p指针指向的节点进行头插
        p->next_ = head->next_;
        head->next_ = p;
        p = q;
    }
}

// 单链表倒数第K个节点
bool GetLastKNode(Clink &link, int k, int &val)
{
    Node *head = link.head_;
    Node *pre = head;
    Node *p = head;

    if (k < 1)
    {
        return false;
    }

    // p指针移到正数第k个节点后，p与pre相差k个节点
    for (int i = 0; i < k; i++)
    {
        p = p->next_;
        if (p == nullptr)
        {
            return false;
        }
    }

    // p在整数第k个节点，pre在头节点
    while (p != nullptr)
    {
        p = p->next_;
        pre = pre->next_;
    }

    val = pre->data_;
    return true;
}

// 有序单链表合并
void MergeLink(Clink &link1, Clink &link2)
{
    Node *p = link1.head_->next_;
    Node *q = link2.head_->next_;
    Node *last = link1.head_; // last指向当前合并链表的末尾节点
    link2.head_->next_ = nullptr;

    while (p != nullptr && q != nullptr)
    {
        if (p->data_ >= q->data_)
        {
            last->next_ = q;
            q = q->next_;
            last = last->next_;
        }
        else
        {
            last->next_ = p;
            p = p->next_;
            last = last->next_;
        }
    }
    if (p != nullptr)
    {
        last->next_ = p;
    }
    if (q != nullptr)
    {
        last->next_ = q;
    }
}

// 判断单链表是否存在环，存在返回环的入口节点
bool IsLinkCircle(Node *head, int &val)
{
    Node *fast = head;
    Node *slow = head;
    while (fast != nullptr && fast->next_ != nullptr)
    {
        fast = fast->next_->next_;
        slow = slow->next_;
        if (fast == slow)
        {
            // 快慢指针再次相遇，链表存在环
            fast = head;
            while (fast != slow)
            {
                fast = fast->next_;
                slow = slow->next_;
            }
            // 当fast==slow时，相遇在环的入口节点
            val = slow->data_;
            return true;
        }
    }
    return false;
}

// 判断两个单链表是否相交，如果相交，返回相交节点的值
bool IsLinkHasMerge(Node *head1, Node *head2, int &val)
{
    Node *p = head1->next_;
    Node *q = head2->next_;
    int cnt1 = 0; // head1指向单链表的节点数
    int cnt2 = 0; // head2指向的单链表的节点数
    while (p != nullptr)
    {
        cnt1++;
        p = p->next_;
    }
    while (q != nullptr)
    {
        cnt2++;
        q = q->next_;
    }

    p = head1;
    q = head2;

    if (cnt1 > cnt2) // 第一个链表长
    {
        int offset = cnt1 - cnt2;
        // p先移动相差的节点数
        for (int i = 0; i < offset; i++)
        {
            p = p->next_;
        }
    }
    else // 第二个链表长
    {
        int offset = cnt2 - cnt1;
        // q先移动相差的节点数
        for (int i = 0; i < offset; i++)
        {
            q = q->next_;
        }
    }

    while (p != nullptr && q != nullptr)
    {
        if (p == q)
        {
            val = p->data_;
            return true;
        }
        p = p->next_;
        q = q->next_;
    }

    return false;
}



// 两个单链表是否相交的测试代码
int main()
{
    Node head1;
    Node head2;
    Node n1(25), n2(67), n3(32), n4(18), n5(30);

    head1.next_ = &n1;
    n1.next_ = &n2;
    n2.next_ = &n3;
    n3.next_ = &n4;

    head2.next_ = &n5;
    n5.next_ = &n2;

    int val;
    if (IsLinkHasMerge(&head1, &head2, val) == true)
    {
        cout << "两个链表相交了" << endl;
        cout << "相交节点的值：" << val << endl;
    }
}

#if 0
// 单链表是否存在环的测试代码
int main()
{
    Node head;

    Node n1(25), n2(67), n3(32), n4(18);
    head.next_ = &n1;
    n1.next_ = &n2;
    n2.next_ = &n3;
    n3.next_ = &n4;
    n4.next_ = &n1;

    int val;
    if (IsLinkCircle(&head, val) == true)
    {
        cout << "单链表存在环" << endl;
        cout << "单链表环的入口节点是：" << val << endl;
    }

    return 0;
}
#endif

#if 0
// 单链表合并测试代码
int main()
{
    int arr1[] = {25, 37, 52, 78, 88, 92, 98, 108};
    int arr2[] = {13, 23, 40, 56, 62, 77, 109};

    Clink link1;
    Clink link2;

    for (auto val : arr1)
    {
        link1.InsertTail(val);
    }

    for (auto val : arr2)
    {
        link2.InsertTail(val);
    }
    link1.show();
    link2.show();

    MergeLink(link1, link2);
    link1.show();
    link2.show();

    return 0;
}
#endif

#if 0
int main(void)
{
    Clink link;
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        int val = rand() % 100 + 1;
        link.InsertTail(val);
        cout << val << "  ";
    }
    cout << endl;
    link.show();

    ReverseLink(link);
    link.show();

    int KVal;
    int k = 10;
    if (GetLastKNode(link, k, KVal))
    {
        cout << "倒数第" << k << "个元素: " << KVal << endl;
    }
}
#endif
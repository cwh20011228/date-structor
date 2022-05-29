//
// Created by 30456 on 2022/5/28. （双链表，带头结点）
//

#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>

typedef struct Link *list;
struct Link {
    int data;
    list prior, Next; // prior 指向前驱节点  Next 指向后继节点
};

list InitLink(); // 初始化双链表
/*bool Empty(list p); // 判断双链表是否为空*/
//list InsertNextNode(list p, list s); // 在p后结点插入s结点
list Delete_behind(list p, int K); // 后删，删除第K个结点之后的结点
//void destroy_list(list p); // 删除整个链表
void Display(list p); // 输出双链表各个结点的值
int Length_list(list p); // 双链表的长度
list FindKth(int K, list p); // 双链表p的第K个结点的元素
int FindElem(int elem, list p); // 查找elem在双链表中的位置
void InsertKth_ahead(list p, int K, int elem); // 前插,在第K个结点插入elem,即elem成为第K个结点
void InsertKth_behind(list p, int K, int elem); // 后插，在第K个结点后面插入elem，即称为第K+1个结点
list Delete_ahead(list p, int K); // 删除第K个结点

int main(void) {
    list P_Link = InitLink();
    Display(P_Link);

    int length = Length_list(P_Link);
    printf("双链表的长度为%d\n", length);

    list find_list = FindKth(4, P_Link);
    printf("第4个结点的元素是%d\n", find_list->data);

    int elem;
    printf("查找的元素为:  ");
    scanf("%d", &elem);
    int location = FindElem(elem, P_Link);
    printf("%d在双链表的第%d个结点\n", elem, location);

    // 前插
    printf("(前插)插入的位置和元素分别为：");
    scanf("%d%d", &location, &elem);
    InsertKth_ahead(P_Link, location, elem);
    Display(P_Link);

    // 后插
    printf("(后插)插入的位置和元素分别为：");
    scanf("%d%d", &location, &elem);
    InsertKth_behind(P_Link, location, elem);
    Display(P_Link);

    // 后删
    printf("(后删)删除的位置是：");
    scanf("%d", &location);
    list delete_list = Delete_behind(P_Link, location);
    printf("删除的元素为%d\n", delete_list->data);
    Display(P_Link);

    // 删除第个location结点
    printf("删除的位置是：");
    scanf("%d", &location);
    delete_list = Delete_ahead(P_Link, location);
    printf("删除的元素为%d\n", delete_list->data);
    Display(P_Link);

    return 0;
}

list InitLink() {
    list PtrL; // 头指针
    list p = (list) malloc(sizeof(struct Link)); // 分配一个头结点
    if (p == NULL) return NULL; // 内存不够，返回NULL
    p->prior = NULL; // 头结点的prior 永远指向 NULL
    p->Next = NULL;  // 头结点 之后暂时还没有结点
    PtrL = p; // 头指针指向头结点
    printf("单链表中的元素数量:  ");
    int number, list_elem;
    scanf("%d", &number);
    for (int i = 0; i < number; i++) {
        scanf("%d", &list_elem);
        list s = (list) malloc(sizeof(struct Link));
        s->data = list_elem;
        p->Next = s;
        s->prior = p;
        s->Next = NULL;
        p = p->Next;  // 即 p = s ;  把头指针移到当前新建立的结点
    }
    return PtrL;
}

/*bool Empty(list p) {
    if (p->Next == NULL) {
        printf("双向链表为空。\n");
        return true;
    } else {
        printf("双向链表不为空。\n");
        return false;
    }
}*/

/*list InsertNextNode(list p, list s) {
    list PtrL = p;
    if (PtrL == NULL && s == NULL) // 非法参数
        return NULL;
    s->Next = PtrL->Next;
    if (PtrL->Next) PtrL->Next->prior = s;
    s->prior = p;
    PtrL->Next = s;
    return p;
}*/

list Delete_behind(list p, int K) {
    if (p->Next == NULL) return NULL;
    int i = 0;
    while (p != NULL && i < K) {
        p = p->Next;
        i += 1;
    }
    list q = p->Next; // q为p的后继结点
    if (q->Next == NULL) return NULL;
    p->Next = q->Next;
    if (q->Next != NULL) q->Next->prior = p;
    return q;
}

void Display(list p) {
    while (p) {
        p = p->Next;
        if (p != NULL) printf("%d  ", p->data);
    }
    printf("\n");
}

int Length_list(list p) {
    int count_list = -1;
    while (p) {
        count_list += 1;
        p = p->Next;
    }
    return count_list;
}

list FindKth(int K, list p) {
    int count = -1;
    while (p != NULL && count < K - 1) {
        count += 1;
        p = p->Next;
    }
    if (p == NULL) {
        printf("K值不合法，找不到第K个结点");
        return NULL;
    }
    return p;
}

int FindElem(int elem, list p) {
    int count = 0;
    list s = p->Next;
    while (s != NULL && s->data != elem) {
        count += 1;
        s = s->Next;
    }
    count += 1;
    if (s->data == elem) return count;
    else {
        printf("双链表中找不到元素.  ");
        return -1;
    }
}

void InsertKth_ahead(list p, int K, int elem) {
    int i = 0;
    while (p != NULL && i < K - 1) {
        p = p->Next;
        i += 1;
    }
    list s = (list) malloc(sizeof(struct Link));
    s->data = elem;
    if (p != NULL) {
        s->Next = p->Next;
        p->Next->prior = s;
        s->prior = p;
        p->Next = s;
    }
}

void InsertKth_behind(list p, int K, int elem) {
    int i = 0;
    while (p != NULL && i < K) {
        p = p->Next;
        i += 1;
    }
    list s = (list) malloc(sizeof(struct Link));
    s->data = elem;
    if (p != NULL) {
        s->Next = p->Next;
        if (p->Next) p->Next->prior = s;
        s->prior = p;
        p->Next = s;
    }
}

list Delete_ahead(list p, int K) {
    int i = 0;
    while (p != NULL && i < K) {
        p = p->Next;
        i += 1;
    }
    if (p != NULL) {
        list ahead = p->prior;
        ahead->Next = p->Next;
        if (p->Next != NULL) p->Next->prior = ahead;
    }
    return p;
}

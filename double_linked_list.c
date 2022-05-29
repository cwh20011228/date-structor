//
// Created by 30456 on 2022/5/28. ��˫������ͷ��㣩
//

#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>

typedef struct Link *list;
struct Link {
    int data;
    list prior, Next; // prior ָ��ǰ���ڵ�  Next ָ���̽ڵ�
};

list InitLink(); // ��ʼ��˫����
/*bool Empty(list p); // �ж�˫�����Ƿ�Ϊ��*/
//list InsertNextNode(list p, list s); // ��p�������s���
list Delete_behind(list p, int K); // ��ɾ��ɾ����K�����֮��Ľ��
//void destroy_list(list p); // ɾ����������
void Display(list p); // ���˫�����������ֵ
int Length_list(list p); // ˫����ĳ���
list FindKth(int K, list p); // ˫����p�ĵ�K������Ԫ��
int FindElem(int elem, list p); // ����elem��˫�����е�λ��
void InsertKth_ahead(list p, int K, int elem); // ǰ��,�ڵ�K��������elem,��elem��Ϊ��K�����
void InsertKth_behind(list p, int K, int elem); // ��壬�ڵ�K�����������elem������Ϊ��K+1�����
list Delete_ahead(list p, int K); // ɾ����K�����

int main(void) {
    list P_Link = InitLink();
    Display(P_Link);

    int length = Length_list(P_Link);
    printf("˫����ĳ���Ϊ%d\n", length);

    list find_list = FindKth(4, P_Link);
    printf("��4������Ԫ����%d\n", find_list->data);

    int elem;
    printf("���ҵ�Ԫ��Ϊ:  ");
    scanf("%d", &elem);
    int location = FindElem(elem, P_Link);
    printf("%d��˫����ĵ�%d�����\n", elem, location);

    // ǰ��
    printf("(ǰ��)�����λ�ú�Ԫ�طֱ�Ϊ��");
    scanf("%d%d", &location, &elem);
    InsertKth_ahead(P_Link, location, elem);
    Display(P_Link);

    // ���
    printf("(���)�����λ�ú�Ԫ�طֱ�Ϊ��");
    scanf("%d%d", &location, &elem);
    InsertKth_behind(P_Link, location, elem);
    Display(P_Link);

    // ��ɾ
    printf("(��ɾ)ɾ����λ���ǣ�");
    scanf("%d", &location);
    list delete_list = Delete_behind(P_Link, location);
    printf("ɾ����Ԫ��Ϊ%d\n", delete_list->data);
    Display(P_Link);

    // ɾ���ڸ�location���
    printf("ɾ����λ���ǣ�");
    scanf("%d", &location);
    delete_list = Delete_ahead(P_Link, location);
    printf("ɾ����Ԫ��Ϊ%d\n", delete_list->data);
    Display(P_Link);

    return 0;
}

list InitLink() {
    list PtrL; // ͷָ��
    list p = (list) malloc(sizeof(struct Link)); // ����һ��ͷ���
    if (p == NULL) return NULL; // �ڴ治��������NULL
    p->prior = NULL; // ͷ����prior ��Զָ�� NULL
    p->Next = NULL;  // ͷ��� ֮����ʱ��û�н��
    PtrL = p; // ͷָ��ָ��ͷ���
    printf("�������е�Ԫ������:  ");
    int number, list_elem;
    scanf("%d", &number);
    for (int i = 0; i < number; i++) {
        scanf("%d", &list_elem);
        list s = (list) malloc(sizeof(struct Link));
        s->data = list_elem;
        p->Next = s;
        s->prior = p;
        s->Next = NULL;
        p = p->Next;  // �� p = s ;  ��ͷָ���Ƶ���ǰ�½����Ľ��
    }
    return PtrL;
}

/*bool Empty(list p) {
    if (p->Next == NULL) {
        printf("˫������Ϊ�ա�\n");
        return true;
    } else {
        printf("˫������Ϊ�ա�\n");
        return false;
    }
}*/

/*list InsertNextNode(list p, list s) {
    list PtrL = p;
    if (PtrL == NULL && s == NULL) // �Ƿ�����
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
    list q = p->Next; // qΪp�ĺ�̽��
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
        printf("Kֵ���Ϸ����Ҳ�����K�����");
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
        printf("˫�������Ҳ���Ԫ��.  ");
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

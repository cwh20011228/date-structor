//
// Created by 30456 on 2022/5/19.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Link *list;
struct Link {
    int coefficient; // ϵ��
    int index;       // ָ��
    list Next;
};

void Display(list p); // ����������еĸ���Ԫ��
list InitLink();  // ��ʼ��������
//void Input(list p); // ���뵥���������ֵ
list Merge_list(list La, list Lb); // �ϲ�La,Lb����һԪ����ʽ
void Decrease_list(list p); // ��һԪ����ʽ���ݼ�����
int Length_list(list p); // ������ĳ���
void swap(int *a, int *b); // ����a,b��ֵ
void quick_sort_sub(int *data1, int *data2, int left, int right); // ���ݼ���˳���������
void quick_sort(int *data1, int *data2, int data_size); // ����quick_sort_sub����
int Find(int list_coefficient, int list_index, list p); // ����Ԫ����һԪ����ʽ�е�λ��
list FindK_list(int K, list p); // ���ҵ�K��Ԫ��
void Insert(list p, int i, int list_coefficient, int list_index); // �ڵ�i��������Ԫ��Elem
list Delete(list p, int i, list delete_node); // ɾ����i�����

int main(void) {
    list PtrLA, PtrLB;

    PtrLA = InitLink();
    PtrLB = InitLink();
    printf("LAһԪ����ʽ��");
    Display(PtrLA);
    printf("LBһԪ����ʽ��");
    Display(PtrLB);
    /*int PtrLA_length = Length_list(PtrLA);
    printf("һԪ����ʽ��Ϊ%d\n",PtrLA_length);*/

    printf("LAһԪ����ʽ(�ݼ�˳��)��");
    Decrease_list(PtrLA);
    Display(PtrLA);
    printf("LBһԪ����ʽ(�ݼ�˳��)��");
    Decrease_list(PtrLB);
    Display(PtrLB);

    list PtrLC;
    PtrLC = Merge_list(PtrLA, PtrLB);
    printf("�ϲ�LA,LBһԪ����ʽ�õ�LC(La+Lb=Lc)\n");
    printf("LC=  ");
    Display(PtrLC);

    list K_list = FindK_list(3, PtrLC);
    printf("PtrLCһԪ����ʽ�ĵ�3��Ϊ��%dX^%d\n", K_list->coefficient, K_list->index);

    int list_coefficient, list_index;
    scanf("%d%d", &list_coefficient, &list_index);
    int number_list = Find(list_coefficient, list_index, PtrLC);
    printf("%dX^%d��һԪ����ʽLC�ĵ�%d��\n", list_coefficient, list_index, number_list);

    int order;
    scanf("%d%d%d", &order, &list_coefficient, &list_index);
    printf("��LC�еĵ�%d�����%dX^%d\n", order, list_coefficient, list_index);
    Insert(PtrLC, order, list_coefficient, list_index);
    Display(PtrLC);

    scanf("%d", &order);
    printf("ɾ��LC�еĵ�%d��\n", order);
    list delete_list = (list) malloc(sizeof(struct Link));
    delete_list = Delete(PtrLC, order, delete_list);
    printf("ɾ�����LC=  ");
    Display(PtrLC);
    printf("delete_list = %dX^%d\n", delete_list->coefficient, delete_list->index);

    return 0;
}

void Display(list p) {
    while (p->Next) {
        p = p->Next;
        printf("%dX^%d", p->coefficient, p->index);
        list s;
        if (p->Next != NULL) {
            s = p->Next;
            if (s->coefficient > 0) printf(" + ");
        }
    }
    printf("\n");
}

list InitLink() {
    list PtrL = NULL; //! PtrL is head pointer
    list head = (list) malloc(sizeof(struct Link));
    head->Next = NULL;
    PtrL = head;
    int num_list; // ����ʽ������
    int coefficient_list, index_list; // ����ʽ��ϵ����ָ��
    printf("һԪ����ʽ������: ");
    scanf("%d", &num_list);
    for (int i = 0; i < num_list; i++) {
        list s = (list) malloc(sizeof(struct Link));
        scanf("%d%d", &coefficient_list, &index_list);
        s->coefficient = coefficient_list;
        s->index = index_list;
        s->Next = NULL;
        head->Next = s;
        head = s;
    }
    return PtrL;
}

list Merge_list(list La, list Lb) {
    //! ����������Lc�����ϲ����һԪ����ʽ
    list Lc = NULL; // LcΪͷָ��
    list head = (list) malloc(sizeof(struct Link)); // head is head node
    head->Next = NULL;
    Lc = head;  //  ͷָ��ָ��ͷ���
    list Pc = Lc; // ָ��Pcָ��Lc
    La = La->Next;
    Lb = Lb->Next;
    while (La && Lb) {
        if (La->index > Lb->index) {
            Pc->Next = La;
            Pc = Pc->Next;
            La = La->Next;
        } else if (La->index == Lb->index) {
            list s = (list) malloc(sizeof(struct Link));
            s->Next = NULL;
            s->coefficient = La->coefficient + Lb->coefficient;
            s->index = La->index;
            if (s->coefficient) {
                Pc->Next = s;
                Pc = Pc->Next;
                La = La->Next;
                Lb = Lb->Next;
            } else {
                La = La->Next;
                Lb = Lb->Next;
            }

        } else {
            Pc->Next = Lb;
            Pc = Pc->Next;
            Lb = Lb->Next;
        }
    }
    // ����һԪ����ʽ����һ��ʣ�µ�����
    if (La) Pc->Next = La;
    if (Lb) Pc->Next = Lb;
    return Lc;
}

void Decrease_list(list p) {
    int length_list = Length_list(p);
    int *number_index = (int *) calloc(length_list, sizeof(int));
    int *number_coefficient = (int *) calloc(length_list, sizeof(int));
    if (number_index == NULL) exit(1);
    if (number_coefficient == NULL) exit(1);

    list PtrL = p;
    PtrL = PtrL->Next;
    int i = 0;
    while (PtrL) {
        number_index[i] = PtrL->index;
        number_coefficient[i] = PtrL->coefficient;
        PtrL = PtrL->Next;
        i += 1;
    }

    quick_sort(number_index, number_coefficient, length_list);
    PtrL = p->Next;
    i = 0;
    while (PtrL) {
        PtrL->index = number_index[i];
        PtrL->coefficient = number_coefficient[i];
        PtrL = PtrL->Next;
        i += 1;
    }
    free(number_index);
    free(number_coefficient);
}

int Length_list(list p) {
    int length_list = -1;
    while (p) {
        p = p->Next;
        length_list += 1;
    }
    return length_list;
}

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort_sub(int *data1, int *data2, int left, int right) {
    int pivot = data1[(left + right) / 2];
    int right_index = right;
    int left_index = left;

    while (left_index <= right_index) {
        for (; data1[left_index] > pivot; left_index += 1);
        for (; data1[right_index] < pivot; right_index -= 1);
        if (left_index <= right_index) {
            swap(&data1[left_index], &data1[right_index]);
            swap(&data2[left_index], &data2[right_index]);
            left_index += 1;
            right_index -= 1;
        }
    }
    if (right_index > left) quick_sort_sub(data1, data2, left, right_index);
    if (left_index < right) quick_sort_sub(data1, data2, left_index, right);
}

void quick_sort(int *data1, int *data2, int data_size) {
    quick_sort_sub(data1, data2, 0, data_size - 1);
}

list FindK_list(int K, list p) {
    int i = 0;
    while (p && i < K) {
        p = p->Next;
        i += 1;
    }
    if (i == K) return p;
    else {
        printf("Kֵ���Ϸ�\n");
        return NULL;
    }
}

int Find(int list_coefficient, int list_index, list p) {
    int number_list = 1;
    p = p->Next;
    while (p) {
        if (p->index == list_index && p->coefficient == list_coefficient) {
            break;
        }
        p = p->Next;
        number_list += 1;
    }
    if (p) return number_list;
    else {
        printf("һԪ����ʽ��û�д��");
        return -1;
    }
}

void Insert(list p, int i, int list_coefficient, int list_index) {
    list PtrL = p;
    int number_list = 0;
    while (PtrL != NULL && number_list < i - 1) {
        PtrL = PtrL->Next;
        number_list += 1;
    }
    if (PtrL == NULL) {
        printf("iֵ���Ϸ�\n");
        exit(1);
    } else {
        list s = (list) malloc(sizeof(struct Link));
        s->Next = NULL;
        s->coefficient = list_coefficient;
        s->index = list_index;
        s->Next = PtrL->Next;
        PtrL->Next = s;
    }
}

list Delete(list p, int i, list delete_node) {
    list PtrL = p;
    int number_list = 0;
    while (PtrL && number_list < i - 1) {
        PtrL = PtrL->Next;
        number_list += 1;
    }
    if (PtrL == NULL) {
        printf("iֵ���Ϸ�\n");
        exit(1);
    } else {
        delete_node = PtrL->Next;
        PtrL->Next = delete_node->Next;
    }
    return delete_node;
}


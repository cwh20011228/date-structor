//
// Created by 30456 on 2022/5/19.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Link *list;
struct Link {
    int coefficient; // 系数
    int index;       // 指数
    list Next;
};

void Display(list p); // 输出单链表中的各个元素
list InitLink();  // 初始化单链表
//void Input(list p); // 输入单链表各结点的值
list Merge_list(list La, list Lb); // 合并La,Lb两个一元多项式
void Decrease_list(list p); // 将一元多项式按递减排序
int Length_list(list p); // 单链表的长度
void swap(int *a, int *b); // 交换a,b的值
void quick_sort_sub(int *data1, int *data2, int left, int right); // 按递减的顺序快速排序
void quick_sort(int *data1, int *data2, int data_size); // 调用quick_sort_sub函数
int Find(int list_coefficient, int list_index, list p); // 查找元素在一元多项式中的位置
list FindK_list(int K, list p); // 查找第K个元素
void Insert(list p, int i, int list_coefficient, int list_index); // 在第i个结点插入元素Elem
list Delete(list p, int i, list delete_node); // 删除第i个结点

int main(void) {
    list PtrLA, PtrLB;

    PtrLA = InitLink();
    PtrLB = InitLink();
    printf("LA一元多项式：");
    Display(PtrLA);
    printf("LB一元多项式：");
    Display(PtrLB);
    /*int PtrLA_length = Length_list(PtrLA);
    printf("一元多项式的为%d\n",PtrLA_length);*/

    printf("LA一元多项式(递减顺序)：");
    Decrease_list(PtrLA);
    Display(PtrLA);
    printf("LB一元多项式(递减顺序)：");
    Decrease_list(PtrLB);
    Display(PtrLB);

    list PtrLC;
    PtrLC = Merge_list(PtrLA, PtrLB);
    printf("合并LA,LB一元多项式得到LC(La+Lb=Lc)\n");
    printf("LC=  ");
    Display(PtrLC);

    list K_list = FindK_list(3, PtrLC);
    printf("PtrLC一元多项式的第3项为：%dX^%d\n", K_list->coefficient, K_list->index);

    int list_coefficient, list_index;
    scanf("%d%d", &list_coefficient, &list_index);
    int number_list = Find(list_coefficient, list_index, PtrLC);
    printf("%dX^%d在一元多项式LC的第%d项\n", list_coefficient, list_index, number_list);

    int order;
    scanf("%d%d%d", &order, &list_coefficient, &list_index);
    printf("在LC中的第%d项插入%dX^%d\n", order, list_coefficient, list_index);
    Insert(PtrLC, order, list_coefficient, list_index);
    Display(PtrLC);

    scanf("%d", &order);
    printf("删除LC中的第%d项\n", order);
    list delete_list = (list) malloc(sizeof(struct Link));
    delete_list = Delete(PtrLC, order, delete_list);
    printf("删除后的LC=  ");
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
    int num_list; // 多项式的项数
    int coefficient_list, index_list; // 多项式的系数和指数
    printf("一元多项式的项数: ");
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
    //! 创建单链表Lc，即合并后的一元多项式
    list Lc = NULL; // Lc为头指针
    list head = (list) malloc(sizeof(struct Link)); // head is head node
    head->Next = NULL;
    Lc = head;  //  头指针指向头结点
    list Pc = Lc; // 指针Pc指向Lc
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
    // 两个一元多项式其中一个剩下的项数
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
        printf("K值不合法\n");
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
        printf("一元多项式中没有此项。");
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
        printf("i值不合法\n");
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
        printf("i值不合法\n");
        exit(1);
    } else {
        delete_node = PtrL->Next;
        PtrL->Next = delete_node->Next;
    }
    return delete_node;
}


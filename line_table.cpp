#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 23

typedef struct LNode* List;
struct LNode{
    int Data[MAXSIZE];
    int Last;
};

// ��ʼ��
List MakeEmpty(){
    List PtrL;
    PtrL=(List)malloc(sizeof(struct LNode));
    PtrL->Last = -1;
    return PtrL;
}

// ������Ա��е�Ԫ��
void display(List t){
    for(int i=0;i<=t->Last;i++){
        printf("%d ",t->Data[i]);
    }
    printf("\n");
}

// ���Һ���
int Find(List t,int elem){  // elem ΪҪ���ҵ�Ԫ��
    int i=0;
    while(i<=t->Last && t->Data[i] != elem){
        i++;
    }
    if(i>t->Last) return -1; // -1����û���ҵ�
    else return i+1;
}

// ����Ԫ��
void Insert(List t,int add,int elem){ //add Ϊ����λ�ã�elemΪ����Ԫ��
    for(int i=t->Last;i>add-1;i--){
        t->Data[i+1]=t->Data[i];
    }
    t->Data[add-1]=elem;
    t->Last++;
}

// ɾ��Ԫ��  
void Delete(List t,int add){  // add Ϊɾ��Ԫ��λ��
    for(int i=add-1;i<t->Last;i++){
        t->Data[i]=t->Data[i+1];
    }
    t->Last--;
}

// ����Ԫ��
void change(List t,int elem,int new_elem){
    int i_add=Find(t,elem);
    t->Data[i_add-1]=new_elem;
}

int main(void){
    // ��ʼ�����Ա�
    List PtrL=MakeEmpty();
    for(int i=0;i<MAXSIZE-3;i++){
        PtrL->Data[i]=i;
        PtrL->Last++;
    }
    display(PtrL);

    // ����Ԫ��
    int soulation=Find(PtrL,5);
    printf("5��λ����%d\n",soulation);

    // ���Ԫ��
    Insert(PtrL,6,100);
    display(PtrL);

    // ɾ��Ԫ��
    Delete(PtrL,10);
    display(PtrL);

    // ����Ԫ��
    change(PtrL,12,2000);
    display(PtrL);

    return 0;
}
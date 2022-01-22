#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 23

typedef struct LNode* List;
struct LNode{
    int Data[MAXSIZE];
    int Last;
};

// 初始化
List MakeEmpty(){
    List PtrL;
    PtrL=(List)malloc(sizeof(struct LNode));
    PtrL->Last = -1;
    return PtrL;
}

// 输出线性表中的元素
void display(List t){
    for(int i=0;i<=t->Last;i++){
        printf("%d ",t->Data[i]);
    }
    printf("\n");
}

// 查找函数
int Find(List t,int elem){  // elem 为要查找的元素
    int i=0;
    while(i<=t->Last && t->Data[i] != elem){
        i++;
    }
    if(i>t->Last) return -1; // -1代表没有找到
    else return i+1;
}

// 插入元素
void Insert(List t,int add,int elem){ //add 为插入位置，elem为插入元素
    for(int i=t->Last;i>add-1;i--){
        t->Data[i+1]=t->Data[i];
    }
    t->Data[add-1]=elem;
    t->Last++;
}

// 删除元素  
void Delete(List t,int add){  // add 为删除元素位置
    for(int i=add-1;i<t->Last;i++){
        t->Data[i]=t->Data[i+1];
    }
    t->Last--;
}

// 更改元素
void change(List t,int elem,int new_elem){
    int i_add=Find(t,elem);
    t->Data[i_add-1]=new_elem;
}

int main(void){
    // 初始化线性表
    List PtrL=MakeEmpty();
    for(int i=0;i<MAXSIZE-3;i++){
        PtrL->Data[i]=i;
        PtrL->Last++;
    }
    display(PtrL);

    // 查找元素
    int soulation=Find(PtrL,5);
    printf("5的位置是%d\n",soulation);

    // 添加元素
    Insert(PtrL,6,100);
    display(PtrL);

    // 删除元素
    Delete(PtrL,10);
    display(PtrL);

    // 更改元素
    change(PtrL,12,2000);
    display(PtrL);

    return 0;
}
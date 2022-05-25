#include <stdio.h>
#include <stdlib.h>

//单链表定义
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList;         //结点LNode，结点指针LinkList

//初始化 带头结点
bool InitList(LinkList &L){
    L = (LNode *)malloc(sizeof(LNode));  //分配头结点
    if(L==NULL)
        return false;                    //内存不足
    L->next = NULL;
    return true;
}

//按位序插入 带头结点       不带头结点的需要对i=1的情况进行额外操作，j从j=1开始循环
bool ListInsert(LinkList &L,int i,int e){
    if(i<1)
        return false;
    
    LNode *p;
    int j=0;

    p = L;
    while (p!=NULL && j<i-1)    //循环找到第i-1个结点
    {
        p = p->next;
        j++;
    }

    if(p==NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//后插操作 在p结点之后插入元素e
bool InsertNextNode(LNode *p,int e){
    if(p==NULL)
        return false;

    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s==NULL)
        return false;

    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}
//前插操作 偷天换日
bool InsertPriorNode(LNode *p,int e){
    if(p==NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s==NULL)
        return false;
    
    s->next=p->next;
    p->next=s;
    s->data=p->data;
    p->data=e;

    return true;
}


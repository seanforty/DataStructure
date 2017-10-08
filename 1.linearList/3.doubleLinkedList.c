/*
 +----------------------------------------------------------------------+
 | 双向有链表，每个结点中同时包含指向直接前驱结点和直接后继结点的指针   |
 | 其它操作都与单链表类似。                                             |
 +----------------------------------------------------------------------+
 | Author: Sean  <seanforty@qq.com>                                     |
 +----------------------------------------------------------------------+
 */

#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define TRUE 1
#define FALSE 0
#define ERROR -1

typedef int Status;
typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
    struct Node *prev;
}NODE,*PNODE;

typedef struct List
{
    PNODE pHead;
    PNODE pTail;
}LIST,*PLIST;

//错误提示并退出
void errorInfo(char str[],int errorType)
{
    printf("%s\n",str);
    exit(errorType);
}

//判断结点是否为空, 为空则调用errorInfo()
void mallocErr(PNODE p)
{
    if(NULL==p)
    {
        errorInfo("Error: cannot locate memory!\n",-1);
    }
}

//检查是否为空表，空表返回1，非空返回0
Status isEmpty(PLIST L)
{
    if(NULL==L || NULL==L->pHead || NULL==L->pHead->next)
    {
        return TRUE;
    }else
    {
        return FALSE;
    }
}

//获取指定位置的直接前驱结点
PNODE getPrevNode(PLIST L,int pos)
{
    int i=1;
    PNODE temp = L->pHead;
    while(NULL!=temp->next && i<pos)
    {
        temp = temp->next;
        i++;
    }
    if(i<pos-1)
    {
        errorInfo("pos位置超过链表长度\n",ERROR);
    }else
    {
        return temp;
    }
}

//获取指定位置结点，时间复杂度为O(n)
PNODE getElem(PLIST L,int pos)
{
    PNODE prevNode = getPrevNode(L,pos);
    if(NULL==prevNode->next)
    {
        errorInfo("指定位置超过链表长度\n",ERROR);
    }
    return prevNode->next;
}

//删除指定位置结点，时间复杂度为O(n)
Status listDelete(PLIST L,int pos)
{
    PNODE prevNode = getPrevNode(L,pos);
    if(NULL==prevNode->next)
    {
        errorInfo("指定位置超过链表长度\n",ERROR);
    }else if(NULL==prevNode->next->next)
    {
        PNODE temp = prevNode->next;
        prevNode->next = NULL;
        free(temp);
    }else
    {
        PNODE temp = prevNode->next;
        prevNode->next = prevNode->next->next;
        prevNode->next->prev = prevNode;
        free(temp);
    }
    return OK;
}

//在指定位置插入结点，时间复杂度为O(n)
Status listInsert(PLIST L,int pos,int val)
{
    PNODE prevNode = getPrevNode(L,pos);

    if(NULL==prevNode->next)
    {
        listAdd(L,val);
    }else
    {
        PNODE p = (PNODE)malloc(sizeof(NODE));
        mallocErr(p);

        p->data = val;
        p->prev = prevNode;
        p->next = prevNode->next;
        p->next->prev = p;
        prevNode->next = p;
    }
    return OK;
}

//直接在链表尾部插入新的结点，时间复杂度为O(1)
Status listAdd(PLIST L,int val)
{
    //为新结点分配内存
    PNODE p = (PNODE)malloc(sizeof(NODE));
    mallocErr(p);

    p->data = val;
    p->prev = L->pTail;
    p->next = NULL;
    L->pTail->next = p;
    L->pTail = p;
    return OK;
}

//创建并初始化链表
Status listInit(PLIST L,int arr[],int len)
{
    //声明头针对和尾指针
    PNODE pHead,pTail;

    //给头结构分配内存
    pHead = (PNODE)malloc(sizeof(NODE));
    mallocErr(pHead);

    pTail = pHead;
    pTail->next = NULL;
    pTail->prev = NULL;

    int i = 0;
    for(;i<len;i++)
    {
        //为插入的结点分配内存
        PNODE p = (PNODE)malloc(sizeof(NODE));
        mallocErr(p);

        //与单链表不同的是，需要将结点prev指针指向pTail
        p->data = arr[i];
        p->next = NULL;
        p->prev = pTail;

        pTail->next = p;
        pTail = p;
    }
    L->pHead = pHead;
    L->pTail = pTail;
    return OK;
}

//遍历输出链表
Status listPrint(PLIST L,int from)
{
    if(isEmpty(L))
    {
        errorInfo("此表为空表\n",ERROR);
    }

    if(1==from)
    {
        PNODE temp = L->pHead;
        while(NULL!=temp->next)
        {
            temp = temp->next;
            printf("%d\n",temp->data);
        }
    }else
    {
        PNODE temp = L->pTail;
        while(NULL!=temp->prev)
        {
            printf("%d\n",temp->data);
            temp = temp->prev;
        }
    }

    return OK;
}

Status listClear(PLIST L)
{
    if(isEmpty(L))
    {
        errorInfo("此表为空表\n",ERROR);
    }

    PNODE tmp,temp = L->pHead;
    while(NULL!=temp->next)
    {
        tmp = temp;
        temp = temp->next;
        free(tmp);
    }
    free(temp);
    L->pHead = NULL;
    L->pTail = L->pHead;
    return OK;
}

int main()
{
    //声明一个PLIST并分配内存
    PLIST L=NULL;
    L = (PLIST)malloc(sizeof(LIST));
    if(NULL == L)
    {
        errorInfo("Error in locating momery\n",ERROR);
    }
    L->pHead = L->pTail = NULL;


    //初始化链表
    int len=5, val[5] = {11,22,33,44,55};
    listInit(L,val,len);

    //删除指定位置结点
    listDelete(L,1);

    //在链表尾部添加结点
    listAdd(L,999);

    //在指定位置插入结点
    listInsert(L,7,888);

    //获取指定位置前一结点
    PNODE prevNode = getPrevNode(L,3);
    //printf("直接前驱结点值：%d\n",prevNode->data);

    //从前向后遍历
    printf("从前向后遍历链表\n");
    listPrint(L,1);
    //从后向前遍历
    printf("从后向前遍历链表\n");
    listPrint(L,0);

    //清空表
    listClear(L);
    listPrint(L,1);
}

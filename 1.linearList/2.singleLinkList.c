#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define TRUE 1
#define ERROR 0

typedef int Status;
typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
}NODE,*PNODE;

//错误提示并退出
void errorInfo(char str[])
{
    printf("%s\n",str);
    exit(-1);
}

//判断结点是否为空, 为空则调用errorInfo()
void MallocErr(PNODE res)
{
    if(NULL==res)
    {
        errorInfo("Error: cannot locate memory!\n");
    }
}

//判断指定位置是否为超过链表长度
//头结点为下标为0,最小只能从下标为1处插入
PNODE ListPreNode(const PNODE L,int len,int index)
{
    PNODE PreNode = L;
    int i = 1;
    if(NULL == L->next) //传入链表为空
    {
        errorInfo("传入链表为空!\n");
    }
    if(index>(len+1))
    {
        errorInfo("传入链表下标溢出!");
    }
    if(index<1) //插入位置不合法
    {
        errorInfo("该位置不能插入结点!");
    }else if(index==1)  //插入位置是首结点,返回头结点
    {
        return PreNode;
    }

    while(NULL!=PreNode->next && i<index)
    {
        PreNode = PreNode->next;
        i++;
    }

    return PreNode;
}

//创建并初始化链表
PNODE ListInit(int len,int *val)
{
    PNODE pTail,pHead;
    int i=0;
    pHead = (PNODE)malloc(sizeof(NODE));
    MallocErr(pHead);

    pTail = pHead;
    pHead->next = NULL;

    for(i=0;i<len;i++)
    {
        PNODE p = (PNODE)malloc(sizeof(NODE));
        MallocErr(p);
        p->data = *(val+i);
        p->next = NULL;
        pTail->next = p;
        pTail = p;
    }
    return pHead;
}

//在指定链表在指定位置插入结点
//index要小于等于链表长度
Status ListInsert(PNODE L, int len, int index, int value)
{
    PNODE temp,preNode = ListPreNode(L,len,index);
    PNODE p = (PNODE)malloc(sizeof(NODE));
    MallocErr(p);
    p->data = value;
    p->next = NULL;

    if(NULL==preNode->next)
    {
        preNode->next = p;
    }else
    {
        temp = preNode->next;
        preNode->next = p;
        p->next = temp;
    }
    return OK;
}

Status ListClear(PNODE L)
{
    L->next = NULL;
}

//删除指定位置的结点
//链表不能为空, 指定位置要小于等于链表长度
Status ListDelete(PNODE L,int len,int index)
{
    PNODE temp,preNode = ListPreNode(L,len,index);
    if(NULL == preNode->next)
    {
        errorInfo("当前结点为空\n");
    }
    if(NULL == preNode->next->next)
    {
        preNode->next = NULL;
    }else
    {
        preNode->next = preNode->next->next;
    }
}

//遍历输出链表
Status ListPrint(const PNODE phead)
{
    if(NULL == phead->next)
    {
        printf("链表为空");
        return OK;
    }

    PNODE temp = phead;
    while(NULL != temp->next)
    {
        temp = temp->next;
        printf("%d\n",temp->data);
    }
}

int main()
{
    int len=5, val[5] = {11,22,33,44,55};
    PNODE list,PreNode;
    list = ListInit(len,val);
    //PreNode = ListPreNode(list,7,5);
    //ListInsert(list,5,3,99);
    ListDelete(list,5,6);
    ListPrint(list);
}

/*
 +----------------------------------------------------------------------+
 | 定义结构体，其中成员ElemType变量data存放结点数据，指定变量next存放直 |
 | 接后继结点地址。                                                     |
 | 优点： 插入和删除结点都只需要在指定位置操作，时间复杂度为O(1)        |
 | 缺点： 查找指定位置结点需要遍历链表，时间复杂度为O(n)                |
 +----------------------------------------------------------------------+
 | Author: Sean  <seanforty@qq.com>                                     |
 +----------------------------------------------------------------------+
 */

#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define TRUE 1
#define FALSE 0
#define ERROR 0

typedef int Status;
typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
}NODE,*PNODE;

//错误提示并退出
void errorInfo(char str[],int errorType)
{
    printf("%s\n",str);
    exit(errorType);
}

//判断结点是否为空, 为空则调用errorInfo()
void mallocErr(PNODE res)
{
    if(NULL==res)
    {
        errorInfo("Error: cannot locate memory!\n",-1);
    }
}

//判断表是否为空， 为空返回1，非空返回0
Status isEmpty(PNODE L)
{
    if(NULL == L->next)
    {
        return TRUE;
    }else
    {
        return FALSE;
    }
}

//获取指定位置结点的直接前驱结点
PNODE listPreNode(const PNODE L,int pos)
{
    //检查链表是否为空
    if(isEmpty(L))
    {
        errorInfo("该链表为空\n",ERROR);
    }

    //temp指针向后移动
    int i=1;
    PNODE temp = L->next;
    while(NULL!=temp->next && i<pos)
    {
        temp = temp->next; //node 1
        i ++;//node no1
    }

    //未到pos直接前驱结点位置,已到表尾; 或者pos直接前戏结点为尾结点
    if(i<pos-1 || NULL==temp->next)
    {
        errorInfo("pos位置非法，无法获取其直接前驱结点\n",ERROR);
    }

    return temp;
}

//在指定链表在指定位置插入结点
Status listInsert(PNODE L,int pos, int value)
{
    if(pos<1)
    {
        errorInfo("结点位置不能为0或负数\n",ERROR);
    }

    //获取pos位置结点的直接前驱结点
    PNODE preNode = listPreNode(L,pos);

    //新建一个结点，分配内存并赋值
    PNODE p = (PNODE)malloc(sizeof(NODE));
    mallocErr(p);
    p->data = value;
    p->next = NULL;

    //在指定位置插入此新结点
    PNODE temp = preNode->next;
    preNode->next = p;
    p->next = temp;

    return OK;
}


//清空链表,释放各结点内存空间，时间复杂度为O(n)
Status listClear(PNODE L)
{
    PNODE tmp,temp = L->next;
    //遍历链表，释放各结点内存
    while(NULL!=temp->next)
    {
        tmp = temp->next;
        free(temp);
        temp = tmp;
    }
    //释放尾结点内存，并将tmp/temp临时指针设置为NULL
    free(temp);
    tmp = NULL;
    temp = NULL;
    //链表头指针指向NULL
    L->next = NULL;
    return OK;
}

//删除指定位置的结点，时间复杂度为O(n)
Status listDelete(PNODE L,int pos)
{
    if(pos<1)
    {
        errorInfo("结点位置不能为0或负数\n",ERROR);
    }

    //获取pos位置结点的直接前驱结点
    PNODE preNode = listPreNode(L,pos);

    //如果pos位置结点为尾结点
    if(NULL == preNode->next->next)
    {
        preNode->next = NULL;
    }else
    {
        PNODE p = preNode->next;
        preNode->next = preNode->next->next;

        //释放pos位置结点内存
        free(p);
        p = NULL;
    }
    return OK;
}


//在链表尾部增加结点，时间复杂度为O(n)
Status listAddNode(PNODE L,int val)
{
    //头指针为空时需先初始化链表才能添加结点
    if(isEmpty(L))
    {
        errorInfo("无法在空表中添加结点，请初始化\n",ERROR);
    }

    //temp指针指向链表尾结点
    PNODE temp = L->next;
    while(NULL!=temp->next)
    {
        temp = temp->next;
    }

    //给新结点分配空间，并把地址传递给链表尾结点
    PNODE p = (PNODE)malloc(sizeof(NODE));
    mallocErr(p);
    p->data = val;
    p->next = NULL;
    temp->next = p;

    return OK;
}

//创建并初始化链表，时间复杂度为O(n)
Status listInit(PNODE L,int arr[],int len)
{
    //声明头结点和尾结点指针
    PNODE pTail,pHead;
    //给头结点指针分配内存
    pHead = (PNODE)malloc(sizeof(NODE));
    mallocErr(pHead);

    //默认尾结点指针指向头结点
    pTail = pHead;
    pHead->next = NULL;

    int i=0;
    for(;i<len;i++)
    {
        //为每个结点分配内存
        PNODE p = (PNODE)malloc(sizeof(NODE));
        mallocErr(p);

        p->data = arr[i];
        p->next = NULL;
        pTail->next = p;
        pTail = p;
    }

    //头指针指向头结点
    L->data = 0;
    L->next = pHead;
    return OK;
}

//遍历输出链表，时间复杂度为O(n)
Status listPrint(PNODE L)
{
    if(isEmpty(L))
    {
        errorInfo("要输出的表为空\n",ERROR);
    }

    //将头结点地址传递给temp
    PNODE temp = L->next;
    while(NULL != temp->next)
    {
        temp = temp->next;
        printf("%d\n",temp->data);
    }
    return OK;
}

int main()
{
    //声明指定并分配内存
    PNODE L = NULL;
    L = (PNODE)malloc(sizeof(NODE));
    mallocErr(L);

    //链表初始化长度和值
    int listLen=5;
    int val[5] = {11,22,33,44,55};
    listInit(L,val,listLen);

    //获取直接前驱结点
    PNODE prevNode = listPreNode(L,1);
    printf("prevNode Data = %d\n",prevNode->data);

    //增加结点
    int newNodeData = 999;
    listAddNode(L,newNodeData);

    //删除指定位置结点
    listDelete(L,6);

    //指定位置插入新结点
    listInsert(L,1,555);

    //遍历输出表结点数据
    listPrint(L);

    //清空链表
    listClear(L);

    //遍历输出表结点数据
    listPrint(L);

}

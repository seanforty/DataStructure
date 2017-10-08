/*
 +----------------------------------------------------------------------+
 | 单链表的另一种表示方法，除了定义Node结构体之外，还定义一个List结构体 |
 | 存放链表的头指针和尾指针，这样在链表尾部添加结点时就不需要重新遍历链 |
 | 表，时间复杂度为O(1)                                                 |
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

/*
两个结构体，
一个放结点信息（数据域和指针域）
另一个放链表的头指针和尾指针
优点：
    不需要O(n)遍历直接操作尾结点
*/

typedef int Status;
typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
}NODE,*PNODE;

typedef struct list
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

//在链表尾部增加结点，时间复杂度为O(n)
Status listAddNode(PLIST L,int val)
{
    //头指针为空时需先初始化链表才能添加结点
    if(isEmpty(L->pHead))
    {
        errorInfo("无法在空表中添加结点，请初始化\n",ERROR);
    }

    //给新结点分配空间，并把地址传递给链表尾结点
    PNODE p = (PNODE)malloc(sizeof(NODE));
    mallocErr(p);
    p->data = val;
    p->next = NULL;

    L->pTail->next = p;
    L->pTail = p;

    return OK;
}

//创建并初始化链表，时间复杂度为O(n)
Status listInit(PLIST L,int arr[],int len)
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
    L->pHead = pHead;
    L->pTail = pTail;
    return OK;
}

//遍历输出链表，时间复杂度为O(n)
Status listPrint(PLIST L)
{
    if(isEmpty(L->pHead))
    {
        errorInfo("要输出的表为空\n",ERROR);
    }

    //将头结点地址传递给temp
    PNODE temp = L->pHead;
    while(NULL != temp->next)
    {
        temp = temp->next;
        printf("%d\n",temp->data);
    }
    return OK;
}

int main()
{
    //声明链表并分配内存
    PLIST L = NULL;
    L = (PLIST)malloc(sizeof(LIST));
    mallocErr(L);

    //链表初始化长度和值
    int listLen=5;
    int val[5] = {11,22,33,44,55};
    listInit(L,val,listLen);

    //增加结点
    int newNodeData = 999;
    listAddNode(L,newNodeData);

    //遍历输出表结点数据
    listPrint(L);

}

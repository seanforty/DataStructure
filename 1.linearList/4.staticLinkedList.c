/*
 +----------------------------------------------------------------------+
 | 静态链表是以数组存放链表的各结点，但与线性表的顺序存储不同的是，     |
 | 静态链表用数组下标模拟链表的指针域。                                 |
 | 优点：具备了链表部分优点，如删除/插入结点无需大量移动已有结点        |
 | 缺点：数组长度需要事先声明，没有普通链表灵活。                       |                                             |
 +----------------------------------------------------------------------+
 | Author: Sean  <seanforty@qq.com>                                     |
 +----------------------------------------------------------------------+
 */

#include <stdio.h>
#define MAXSIZE 10
#define OK 1
#define TRUE 1
#define FALSE 0
#define ERROR -1

typedef int Status;
typedef int ElemType;
typedef struct
{
    ElemType data;
    int cur;
}NODE,PNODE[MAXSIZE];

//提示错误并退出
void errorInfo(char str[],int errno)
{
    printf("%s\n",str);
    exit(errno);
}

//初始化链表，NODE组成的数组中，NODE中成员cur指向后面NODE的下标。
//有效元素第一个结点 p[MAXSIZE-1].cur
//备用链表第一个结点 p[0].cur
Status listInit(PNODE p)
{
    int i=0;
    for(;i<MAXSIZE-1;i++)
    {
        p[i].cur = i + 1;
    }
    p[MAXSIZE-1].cur = 0;
    return OK;
}

//获取包含有效数据的链表长度
int getLen(PNODE p)
{
    int i;
    NODE prevNode;
    prevNode = p[MAXSIZE-1];
    while(0!=prevNode.cur)
    {
        prevNode = p[prevNode.cur];
        i++;
    }
    return i;
}

//链表满返回1，未满返回0
Status isFull(PNODE p)
{
    if(p[0].cur == MAXSIZE-1)
    {
        return 1;
    }else
    {
        return 0;
    }
}

//链表空返回1，未空返回0
Status isEmpty(PNODE p)
{
    if(0==p[MAXSIZE-1].cur)
    {
        return 1;
    }else
    {
        return 0;
    }
}

//获取链表尾部结点
//flag=1 有效数据的最后一个结点，
//flag=0,空表的最后一个结点
NODE getLast(PNODE p,int flag)
{
    NODE temp;
    if(flag==1)
    {
        temp = p[MAXSIZE-1];
        while(0!=temp.cur)
        {
            temp = p[temp.cur];
        }
    }else if(flag==0)
    {
        temp = p[0];
        while(temp.cur != MAXSIZE-1)
        {
            temp = p[temp.cur];
        }
    }
    return temp;
}

//指定位置的前一个结点
int getPrevNodeIndex(PNODE p,int pos)
{
    int i=1,currentIndex;
    if(pos>getLen(p) || pos<1)
    {
        errorInfo("指定位置无有效数据",ERROR);
    }else if(pos==1)
    {
        currentIndex = 0;
    }

    NODE prevNode;
    prevNode = p[MAXSIZE-1];
    while(0!=prevNode.cur && i<pos)
    {
        currentIndex = prevNode.cur;
        prevNode = p[prevNode.cur];
        i++;
    }

    return currentIndex;
}

//在链表尾添加结点元素
Status listAdd(PNODE p,int val)
{
    if(isFull(p))
    {
        errorInfo("链表已满",ERROR);
    }

    int tempCur,newNodeCur = p[0].cur;
    p[newNodeCur].data = val;

    //备用链表后移一个结点
    tempCur = p[newNodeCur].cur;
    p[0].cur = tempCur;

    if(0==p[MAXSIZE-1].cur)
    {
        p[MAXSIZE-1].cur = newNodeCur;
        p[newNodeCur].cur = 0;
    }else
    {
        tempCur = p[MAXSIZE-1].cur;
        p[MAXSIZE-1].cur = newNodeCur;
        p[newNodeCur].cur = tempCur;
    }
    return OK;
}

//在指定位置插入结点
Status listInsert(PNODE p, int pos, int val)
{
    if(isFull(p))
    {
        errorInfo("链表已满",ERROR);
    }
    if(pos>getLen(p) || pos<1)
    {
        errorInfo("指定位置无有效数据",ERROR);
    }

    int tempNodeCur, newNodeCur = p[0].cur;
    p[0].cur = p[newNodeCur].cur;

    p[newNodeCur].data = val;

    if(pos=1)
    {
        tempNodeCur = p[MAXSIZE-1].cur;
        p[MAXSIZE-1].cur = newNodeCur;
        p[newNodeCur].cur = tempNodeCur;
    }else
    {
        int prevNodeIndex = getPrevNodeIndex(p,pos);
        tempNodeCur = p[prevNodeIndex].cur;
        p[prevNodeIndex].cur = newNodeCur;
        p[newNodeCur].cur = tempNodeCur;
    }

    return OK;
}

//删除指定位置结点
Status listDelete(PNODE p,int pos)
{
    if(isEmpty(p))
    {
        errorInfo("链表为空",ERROR);
    }
    if(pos>getLen(p) || pos<1)
    {
        errorInfo("指定位置无有效数据",ERROR);
    }

    if(pos==1)
    {
        p[MAXSIZE-1].cur = p[p[MAXSIZE-1].cur].cur;
    }else
    {
        int prevNodeCur = getPrevNodeIndex(p,pos);
        p[prevNodeCur].cur = p[p[prevNodeCur].cur].cur;
    }

    return OK;
}

NODE getNode(PNODE p,int pos)
{
    if(isEmpty(p))
    {
        errorInfo("链表为空",ERROR);
    }
    if(pos>getLen(p) || pos<1)
    {
        errorInfo("指定位置无有效数据",ERROR);
    }

    NODE tempNode = p[MAXSIZE-1];
    int i=0;
    while(i<pos)
    {
        tempNode = p[tempNode.cur];
        i++;
    }
    return tempNode;
}

//遍历输出链表中的值
Status listShow(PNODE p)
{
    NODE tempNode = p[MAXSIZE-1];
    while(0!=tempNode.cur)
    {
        tempNode = p[tempNode.cur];
        printf("%d\n",tempNode.data);
    }
    return OK;
}

Status main()
{
    //声明链表
    PNODE p;
    //初始化链表
    listInit(p);
    //给链表添加结点
    listAdd(p,101);
    listAdd(p,102);
    listAdd(p,103);
    listAdd(p,104);
    listAdd(p,105);

    //指定位置插入结点
    listInsert(p,5,999);

    //指定位置删除结点
    listDelete(p,3);

    listShow(p);
    printf("第3个结点： %d\n",getNode(p,3));
    return 1;
}

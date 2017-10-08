/*
 +----------------------------------------------------------------------+
 | ��̬������������������ĸ���㣬�������Ա��˳��洢��ͬ���ǣ�     |
 | ��̬�����������±�ģ�������ָ����                                 |
 | �ŵ㣺�߱����������ŵ㣬��ɾ��/��������������ƶ����н��        |
 | ȱ�㣺���鳤����Ҫ����������û����ͨ������                       |                                             |
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

//��ʾ�����˳�
void errorInfo(char str[],int errno)
{
    printf("%s\n",str);
    exit(errno);
}

//��ʼ������NODE��ɵ������У�NODE�г�Աcurָ�����NODE���±ꡣ
//��ЧԪ�ص�һ����� p[MAXSIZE-1].cur
//���������һ����� p[0].cur
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

//��ȡ������Ч���ݵ�������
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

//����������1��δ������0
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

//����շ���1��δ�շ���0
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

//��ȡ����β�����
//flag=1 ��Ч���ݵ����һ����㣬
//flag=0,�ձ�����һ�����
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

//ָ��λ�õ�ǰһ�����
int getPrevNodeIndex(PNODE p,int pos)
{
    int i=1,currentIndex;
    if(pos>getLen(p) || pos<1)
    {
        errorInfo("ָ��λ������Ч����",ERROR);
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

//������β��ӽ��Ԫ��
Status listAdd(PNODE p,int val)
{
    if(isFull(p))
    {
        errorInfo("��������",ERROR);
    }

    int tempCur,newNodeCur = p[0].cur;
    p[newNodeCur].data = val;

    //�����������һ�����
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

//��ָ��λ�ò�����
Status listInsert(PNODE p, int pos, int val)
{
    if(isFull(p))
    {
        errorInfo("��������",ERROR);
    }
    if(pos>getLen(p) || pos<1)
    {
        errorInfo("ָ��λ������Ч����",ERROR);
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

//ɾ��ָ��λ�ý��
Status listDelete(PNODE p,int pos)
{
    if(isEmpty(p))
    {
        errorInfo("����Ϊ��",ERROR);
    }
    if(pos>getLen(p) || pos<1)
    {
        errorInfo("ָ��λ������Ч����",ERROR);
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
        errorInfo("����Ϊ��",ERROR);
    }
    if(pos>getLen(p) || pos<1)
    {
        errorInfo("ָ��λ������Ч����",ERROR);
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

//������������е�ֵ
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
    //��������
    PNODE p;
    //��ʼ������
    listInit(p);
    //��������ӽ��
    listAdd(p,101);
    listAdd(p,102);
    listAdd(p,103);
    listAdd(p,104);
    listAdd(p,105);

    //ָ��λ�ò�����
    listInsert(p,5,999);

    //ָ��λ��ɾ�����
    listDelete(p,3);

    listShow(p);
    printf("��3����㣺 %d\n",getNode(p,3));
    return 1;
}

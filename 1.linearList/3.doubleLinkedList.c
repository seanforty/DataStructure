/*
 +----------------------------------------------------------------------+
 | ˫��������ÿ�������ͬʱ����ָ��ֱ��ǰ������ֱ�Ӻ�̽���ָ��   |
 | �����������뵥�������ơ�                                             |
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

//������ʾ���˳�
void errorInfo(char str[],int errorType)
{
    printf("%s\n",str);
    exit(errorType);
}

//�жϽ���Ƿ�Ϊ��, Ϊ�������errorInfo()
void mallocErr(PNODE p)
{
    if(NULL==p)
    {
        errorInfo("Error: cannot locate memory!\n",-1);
    }
}

//����Ƿ�Ϊ�ձ��ձ���1���ǿշ���0
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

//��ȡָ��λ�õ�ֱ��ǰ�����
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
        errorInfo("posλ�ó���������\n",ERROR);
    }else
    {
        return temp;
    }
}

//��ȡָ��λ�ý�㣬ʱ�临�Ӷ�ΪO(n)
PNODE getElem(PLIST L,int pos)
{
    PNODE prevNode = getPrevNode(L,pos);
    if(NULL==prevNode->next)
    {
        errorInfo("ָ��λ�ó���������\n",ERROR);
    }
    return prevNode->next;
}

//ɾ��ָ��λ�ý�㣬ʱ�临�Ӷ�ΪO(n)
Status listDelete(PLIST L,int pos)
{
    PNODE prevNode = getPrevNode(L,pos);
    if(NULL==prevNode->next)
    {
        errorInfo("ָ��λ�ó���������\n",ERROR);
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

//��ָ��λ�ò����㣬ʱ�临�Ӷ�ΪO(n)
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

//ֱ��������β�������µĽ�㣬ʱ�临�Ӷ�ΪO(1)
Status listAdd(PLIST L,int val)
{
    //Ϊ�½������ڴ�
    PNODE p = (PNODE)malloc(sizeof(NODE));
    mallocErr(p);

    p->data = val;
    p->prev = L->pTail;
    p->next = NULL;
    L->pTail->next = p;
    L->pTail = p;
    return OK;
}

//��������ʼ������
Status listInit(PLIST L,int arr[],int len)
{
    //����ͷ��Ժ�βָ��
    PNODE pHead,pTail;

    //��ͷ�ṹ�����ڴ�
    pHead = (PNODE)malloc(sizeof(NODE));
    mallocErr(pHead);

    pTail = pHead;
    pTail->next = NULL;
    pTail->prev = NULL;

    int i = 0;
    for(;i<len;i++)
    {
        //Ϊ����Ľ������ڴ�
        PNODE p = (PNODE)malloc(sizeof(NODE));
        mallocErr(p);

        //�뵥����ͬ���ǣ���Ҫ�����prevָ��ָ��pTail
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

//�����������
Status listPrint(PLIST L,int from)
{
    if(isEmpty(L))
    {
        errorInfo("�˱�Ϊ�ձ�\n",ERROR);
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
        errorInfo("�˱�Ϊ�ձ�\n",ERROR);
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
    //����һ��PLIST�������ڴ�
    PLIST L=NULL;
    L = (PLIST)malloc(sizeof(LIST));
    if(NULL == L)
    {
        errorInfo("Error in locating momery\n",ERROR);
    }
    L->pHead = L->pTail = NULL;


    //��ʼ������
    int len=5, val[5] = {11,22,33,44,55};
    listInit(L,val,len);

    //ɾ��ָ��λ�ý��
    listDelete(L,1);

    //������β����ӽ��
    listAdd(L,999);

    //��ָ��λ�ò�����
    listInsert(L,7,888);

    //��ȡָ��λ��ǰһ���
    PNODE prevNode = getPrevNode(L,3);
    //printf("ֱ��ǰ�����ֵ��%d\n",prevNode->data);

    //��ǰ������
    printf("��ǰ����������\n");
    listPrint(L,1);
    //�Ӻ���ǰ����
    printf("�Ӻ���ǰ��������\n");
    listPrint(L,0);

    //��ձ�
    listClear(L);
    listPrint(L,1);
}

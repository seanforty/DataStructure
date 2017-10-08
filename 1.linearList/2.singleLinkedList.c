/*
 +----------------------------------------------------------------------+
 | ����ṹ�壬���г�ԱElemType����data��Ž�����ݣ�ָ������next���ֱ |
 | �Ӻ�̽���ַ��                                                     |
 | �ŵ㣺 �����ɾ����㶼ֻ��Ҫ��ָ��λ�ò�����ʱ�临�Ӷ�ΪO(1)        |
 | ȱ�㣺 ����ָ��λ�ý����Ҫ��������ʱ�临�Ӷ�ΪO(n)                |
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

//������ʾ���˳�
void errorInfo(char str[],int errorType)
{
    printf("%s\n",str);
    exit(errorType);
}

//�жϽ���Ƿ�Ϊ��, Ϊ�������errorInfo()
void mallocErr(PNODE res)
{
    if(NULL==res)
    {
        errorInfo("Error: cannot locate memory!\n",-1);
    }
}

//�жϱ��Ƿ�Ϊ�գ� Ϊ�շ���1���ǿշ���0
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

//��ȡָ��λ�ý���ֱ��ǰ�����
PNODE listPreNode(const PNODE L,int pos)
{
    //��������Ƿ�Ϊ��
    if(isEmpty(L))
    {
        errorInfo("������Ϊ��\n",ERROR);
    }

    //tempָ������ƶ�
    int i=1;
    PNODE temp = L->next;
    while(NULL!=temp->next && i<pos)
    {
        temp = temp->next; //node 1
        i ++;//node no1
    }

    //δ��posֱ��ǰ�����λ��,�ѵ���β; ����posֱ��ǰϷ���Ϊβ���
    if(i<pos-1 || NULL==temp->next)
    {
        errorInfo("posλ�÷Ƿ����޷���ȡ��ֱ��ǰ�����\n",ERROR);
    }

    return temp;
}

//��ָ��������ָ��λ�ò�����
Status listInsert(PNODE L,int pos, int value)
{
    if(pos<1)
    {
        errorInfo("���λ�ò���Ϊ0����\n",ERROR);
    }

    //��ȡposλ�ý���ֱ��ǰ�����
    PNODE preNode = listPreNode(L,pos);

    //�½�һ����㣬�����ڴ沢��ֵ
    PNODE p = (PNODE)malloc(sizeof(NODE));
    mallocErr(p);
    p->data = value;
    p->next = NULL;

    //��ָ��λ�ò�����½��
    PNODE temp = preNode->next;
    preNode->next = p;
    p->next = temp;

    return OK;
}


//�������,�ͷŸ�����ڴ�ռ䣬ʱ�临�Ӷ�ΪO(n)
Status listClear(PNODE L)
{
    PNODE tmp,temp = L->next;
    //���������ͷŸ�����ڴ�
    while(NULL!=temp->next)
    {
        tmp = temp->next;
        free(temp);
        temp = tmp;
    }
    //�ͷ�β����ڴ棬����tmp/temp��ʱָ������ΪNULL
    free(temp);
    tmp = NULL;
    temp = NULL;
    //����ͷָ��ָ��NULL
    L->next = NULL;
    return OK;
}

//ɾ��ָ��λ�õĽ�㣬ʱ�临�Ӷ�ΪO(n)
Status listDelete(PNODE L,int pos)
{
    if(pos<1)
    {
        errorInfo("���λ�ò���Ϊ0����\n",ERROR);
    }

    //��ȡposλ�ý���ֱ��ǰ�����
    PNODE preNode = listPreNode(L,pos);

    //���posλ�ý��Ϊβ���
    if(NULL == preNode->next->next)
    {
        preNode->next = NULL;
    }else
    {
        PNODE p = preNode->next;
        preNode->next = preNode->next->next;

        //�ͷ�posλ�ý���ڴ�
        free(p);
        p = NULL;
    }
    return OK;
}


//������β�����ӽ�㣬ʱ�临�Ӷ�ΪO(n)
Status listAddNode(PNODE L,int val)
{
    //ͷָ��Ϊ��ʱ���ȳ�ʼ�����������ӽ��
    if(isEmpty(L))
    {
        errorInfo("�޷��ڿձ�����ӽ�㣬���ʼ��\n",ERROR);
    }

    //tempָ��ָ������β���
    PNODE temp = L->next;
    while(NULL!=temp->next)
    {
        temp = temp->next;
    }

    //���½�����ռ䣬���ѵ�ַ���ݸ�����β���
    PNODE p = (PNODE)malloc(sizeof(NODE));
    mallocErr(p);
    p->data = val;
    p->next = NULL;
    temp->next = p;

    return OK;
}

//��������ʼ������ʱ�临�Ӷ�ΪO(n)
Status listInit(PNODE L,int arr[],int len)
{
    //����ͷ����β���ָ��
    PNODE pTail,pHead;
    //��ͷ���ָ������ڴ�
    pHead = (PNODE)malloc(sizeof(NODE));
    mallocErr(pHead);

    //Ĭ��β���ָ��ָ��ͷ���
    pTail = pHead;
    pHead->next = NULL;

    int i=0;
    for(;i<len;i++)
    {
        //Ϊÿ���������ڴ�
        PNODE p = (PNODE)malloc(sizeof(NODE));
        mallocErr(p);

        p->data = arr[i];
        p->next = NULL;
        pTail->next = p;
        pTail = p;
    }

    //ͷָ��ָ��ͷ���
    L->data = 0;
    L->next = pHead;
    return OK;
}

//�����������ʱ�临�Ӷ�ΪO(n)
Status listPrint(PNODE L)
{
    if(isEmpty(L))
    {
        errorInfo("Ҫ����ı�Ϊ��\n",ERROR);
    }

    //��ͷ����ַ���ݸ�temp
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
    //����ָ���������ڴ�
    PNODE L = NULL;
    L = (PNODE)malloc(sizeof(NODE));
    mallocErr(L);

    //�����ʼ�����Ⱥ�ֵ
    int listLen=5;
    int val[5] = {11,22,33,44,55};
    listInit(L,val,listLen);

    //��ȡֱ��ǰ�����
    PNODE prevNode = listPreNode(L,1);
    printf("prevNode Data = %d\n",prevNode->data);

    //���ӽ��
    int newNodeData = 999;
    listAddNode(L,newNodeData);

    //ɾ��ָ��λ�ý��
    listDelete(L,6);

    //ָ��λ�ò����½��
    listInsert(L,1,555);

    //���������������
    listPrint(L);

    //�������
    listClear(L);

    //���������������
    listPrint(L);

}

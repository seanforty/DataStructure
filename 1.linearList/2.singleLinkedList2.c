/*
 +----------------------------------------------------------------------+
 | ���������һ�ֱ�ʾ���������˶���Node�ṹ��֮�⣬������һ��List�ṹ�� |
 | ��������ͷָ���βָ�룬����������β����ӽ��ʱ�Ͳ���Ҫ���±����� |
 | ��ʱ�临�Ӷ�ΪO(1)                                                 |
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
�����ṹ�壬
һ���Ž����Ϣ���������ָ����
��һ���������ͷָ���βָ��
�ŵ㣺
    ����ҪO(n)����ֱ�Ӳ���β���
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

//������β�����ӽ�㣬ʱ�临�Ӷ�ΪO(n)
Status listAddNode(PLIST L,int val)
{
    //ͷָ��Ϊ��ʱ���ȳ�ʼ�����������ӽ��
    if(isEmpty(L->pHead))
    {
        errorInfo("�޷��ڿձ�����ӽ�㣬���ʼ��\n",ERROR);
    }

    //���½�����ռ䣬���ѵ�ַ���ݸ�����β���
    PNODE p = (PNODE)malloc(sizeof(NODE));
    mallocErr(p);
    p->data = val;
    p->next = NULL;

    L->pTail->next = p;
    L->pTail = p;

    return OK;
}

//��������ʼ������ʱ�临�Ӷ�ΪO(n)
Status listInit(PLIST L,int arr[],int len)
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
    L->pHead = pHead;
    L->pTail = pTail;
    return OK;
}

//�����������ʱ�临�Ӷ�ΪO(n)
Status listPrint(PLIST L)
{
    if(isEmpty(L->pHead))
    {
        errorInfo("Ҫ����ı�Ϊ��\n",ERROR);
    }

    //��ͷ����ַ���ݸ�temp
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
    //�������������ڴ�
    PLIST L = NULL;
    L = (PLIST)malloc(sizeof(LIST));
    mallocErr(L);

    //�����ʼ�����Ⱥ�ֵ
    int listLen=5;
    int val[5] = {11,22,33,44,55};
    listInit(L,val,listLen);

    //���ӽ��
    int newNodeData = 999;
    listAddNode(L,newNodeData);

    //���������������
    listPrint(L);

}

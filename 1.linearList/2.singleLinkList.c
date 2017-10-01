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

//������ʾ���˳�
void errorInfo(char str[])
{
    printf("%s\n",str);
    exit(-1);
}

//�жϽ���Ƿ�Ϊ��, Ϊ�������errorInfo()
void MallocErr(PNODE res)
{
    if(NULL==res)
    {
        errorInfo("Error: cannot locate memory!\n");
    }
}

//�ж�ָ��λ���Ƿ�Ϊ����������
//ͷ���Ϊ�±�Ϊ0,��Сֻ�ܴ��±�Ϊ1������
PNODE ListPreNode(const PNODE L,int len,int index)
{
    PNODE PreNode = L;
    int i = 1;
    if(NULL == L->next) //��������Ϊ��
    {
        errorInfo("��������Ϊ��!\n");
    }
    if(index>(len+1))
    {
        errorInfo("���������±����!");
    }
    if(index<1) //����λ�ò��Ϸ�
    {
        errorInfo("��λ�ò��ܲ�����!");
    }else if(index==1)  //����λ�����׽��,����ͷ���
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

//��������ʼ������
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

//��ָ��������ָ��λ�ò�����
//indexҪС�ڵ���������
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

//ɾ��ָ��λ�õĽ��
//������Ϊ��, ָ��λ��ҪС�ڵ���������
Status ListDelete(PNODE L,int len,int index)
{
    PNODE temp,preNode = ListPreNode(L,len,index);
    if(NULL == preNode->next)
    {
        errorInfo("��ǰ���Ϊ��\n");
    }
    if(NULL == preNode->next->next)
    {
        preNode->next = NULL;
    }else
    {
        preNode->next = preNode->next->next;
    }
}

//�����������
Status ListPrint(const PNODE phead)
{
    if(NULL == phead->next)
    {
        printf("����Ϊ��");
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

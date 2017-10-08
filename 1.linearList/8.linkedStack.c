/*
 +----------------------------------------------------------------------+
 | ��ջ���������ƣ�ֻ�ǲ���ֻ�н�ջ�ͳ�ջ�����ܴ������м�����ɾ����� |
 +----------------------------------------------------------------------+
 | Author: Sean  <seanforty@qq.com>                                     |
 +----------------------------------------------------------------------+
 */

#include <stdio.h>
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
}NODE,*PNODE;

typedef struct Stack
{
    PNODE top;
    int length;
}STACK;

//��ʾ�����˳�
void errorInfo(char str[],int errno)
{
    printf("%s\n",str);
    exit(errno);
}

//��ջ
Status isEmpty(STACK *S)
{
    if(S->length == 0)
    {
        return TRUE;
    }else
    {
        return FALSE;
    }
}

//�����ڴ�ʧ��
void mallocErr(PNODE P)
{
    if(NULL==P)
    {
        errorInfo("Error in locating memory\n",ERROR);
    }
}

//��ջ
Status push(STACK *S,int val)
{
    //Ϊ�½������ڴ�
    PNODE p = (PNODE)malloc(sizeof(NODE));
    mallocErr(p);

    //���½��׷�ӵ�ջ����topָ������
    p->data = val;
    p->next = S->top;
    S->top = p;
    S->length ++;
    return OK;
}

//pop
int pop(STACK *S)
{
    if(isEmpty(S))
    {
        printf("��ջ\n",ERROR);
    }

    //get value of top node;
    int val = S->top->data;
    //new PNODE parameter p point to top node;
    PNODE p = S->top;
    //top pointer point to next node;
    S->top = S->top->next;
    //free p
    free(p);
    S->length --;
    return val;
}

//get top value
int getTopValue(const STACK *S)
{
    if(isEmpty(S))
    {
        errorInfo("��ջ\n",ERROR);
    }

    return S->top->data;
}

//clear stack
Status stackClear(STACK *S)
{
    if(isEmpty(S))
    {
        errorInfo("��ջ\n",ERROR);
    }

    PNODE tmp,temp = S->top;
    while(NULL!=temp->next)
    {
        tmp = temp;
        temp = temp->next;
        free(tmp);
    }
    free(temp);
    S->top = NULL;
    S->length = 0;
    return OK;
}

//��ʼ��ջ
Status stackInit(STACK *S,int val[],int len)
{
    if(len<1)
    {
        errorInfo("������Ч\n",ERROR);
    }

    int i=0;
    for(;i<len;i++)
    {
        PNODE p = (PNODE)malloc(sizeof(NODE));
        mallocErr(p);
        p->data = val[i];
        p->next = S->top;
        S->top = p;
    }
    S->length = len;
    return OK;
}

//�������ջ
Status stackShow(const STACK *S)
{
    if(isEmpty(S))
    {
        errorInfo("��ջ\n",ERROR);
    }

    PNODE temp = S->top;
    while(NULL!=temp->next)
    {
        printf("%d\n",temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
    return OK;
}

int main()
{
    //����ջ������ջ��ָ������ΪNULL
    STACK S;
    S.length = 0;
    S.top = NULL;

    //��ʼ��ջ
    int val[5] = {11,22,33,44,55};
    stackInit(&S,val,5);

    //��ջ
    push(&S,777);
    push(&S,888);
    push(&S,999);

    //pop
    printf("POP top value: %d\n",pop(&S));

    //���ջ
    stackShow(&S);

    //get top value
    printf("top value of the stack: %d\n",getTopValue(&S));

    //clear stack
    stackClear(&S);

    printf("stack length: %d\n",S.length);
    printf("stack top : %p\n",S.top);

    //���ջ
    stackShow(&S);

    return 0;
}

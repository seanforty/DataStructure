/*
 +----------------------------------------------------------------------+
 | ջ��˳��洢ʵ�֣�ʹ������洢ջ���ݣ�top�洢ջ���±�                |
 | ջֻ��ջ����������ջ�ͳ�ջ����ջ����������β��                       |
 +----------------------------------------------------------------------+
 | Author: Sean  <seanforty@qq.com>                                     |
 +----------------------------------------------------------------------+
 */

#include <stdio.h>
#define MAXSIZE 10
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR -1

typedef int Status;
typedef int ElemType;
typedef struct node
{
    ElemType data[MAXSIZE];
    int top;
}STACK,*PSTACK;

//��ʾ������Ϣ���˳�
void errorInfo(char str[],int no)
{
    printf("%s\n",str);
    exit(no);
}

//�����ڴ�ʧ����ʾ�����˳�
void mallocErr(PSTACK P)
{
    if(NULL==P)
    {
        errorInfo("Error in locating memory.\n",ERROR);
    }
}

//��ȡջ����
int stackLen(PSTACK P)
{
    return P->top+1;
}

//ջΪ�շ���1��ջ�ǿշ���0
Status isEmpty(PSTACK P)
{
    if(-1==P->top)
    {
        return TRUE;
    }else
    {
        return FALSE;
    }
}

//ջ������1��δ������0
Status isFull(PSTACK P)
{
    if(P->top == MAXSIZE-1)
    {
        return TRUE;
    }else
    {
        return FALSE;
    }
}

//ѹջ��ʱ�临�Ӷ�O(1)
Status push(PSTACK P,int val)
{
    if(isFull(P))
    {
        errorInfo("ջ�������޷�push\n",ERROR);
    }

    P->data[P->top+1] = val;
    P->top ++;
    return OK;
}

//��ջ��ʱ�临�Ӷ�O(1)
Status pop(PSTACK P,ElemType *val)
{
    if(isEmpty(P))
    {
        errorInfo("ջΪ�գ��޷���ջ\n",ERROR);
    }

    *val = P->data[P->top];
    P->top--;
    return OK;
}

//��ȡջ��ֵ��ʱ�临�Ӷ�O(1)
Status getTop(PSTACK P,ElemType *val)
{
    if(isEmpty(P))
    {
        errorInfo("ջΪ�գ��޷���ջ\n",ERROR);
    }

    *val = P->data[P->top];
    return OK;
}

//��ʼ��ջ��ʱ�临�Ӷ�O(n)
Status stackInit(PSTACK P,int val[],int len)
{
    if(len>MAXSIZE || len<1)
    {
        errorInfo("��ʼ��ʧ�ܣ�������Ч\n",ERROR);
    }

    P->top = 0;
    int i = 0;
    for(;i<len;i++)
    {
        P->data[i] = val[i];
        P->top = i;
    }
    return OK;
}

//�������ջ��ʱ�临�Ӷ�O(n)
Status stackShow(PSTACK P)
{
    int i=P->top;
    for(;i>=0;i--)
    {
        printf("%d\n",P->data[i]);
    }
    return OK;
}

//���ջ��ʱ�临�Ӷ�O(1)
Status stackClear(PSTACK P)
{
    P->top = -1;
    return OK;
}

//�ͷ�ջ�ռ䣬ʱ�临�Ӷ�O(1)
Status stackDestroy(PSTACK P)
{
    P->top = -1;
    free(P);
    P = NULL;
}


int main()
{
    PSTACK P;
    P = (PSTACK)malloc(sizeof(STACK));
    mallocErr(P);
    P->top = -1;

    //��ʼ��ջ
    int val[5] = {11,22,33,44,55};
    stackInit(P,val,5);

    //��ʼ�������ջ��
    //printf("Stack top is : %d\n",P->top);

    //ѹջ
    push(P,777);
    push(P,888);
    push(P,999);

    //��ջ
    ElemType popVal;
    pop(P,&popVal);
    printf("POP : %d\n",popVal);

    //�������ջ
    stackShow(P);

    //�ͷ�ջ
    printf("destroy stack\n");
    stackDestroy(P);
    //�������ջ
    stackShow(P);

    return 0;
}

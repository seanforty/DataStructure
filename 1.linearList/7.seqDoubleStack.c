/*
 +----------------------------------------------------------------------+
 | ˫ջ����ͬһ����ռ䣬����Ϊջ�ף��м�Ϊջ������������topָ�롣ָ��  |
 | ������ջ�����ŵ�����ջ���Դ洢�ṹ�ص�Ļ����ϣ�������ÿռ䡣       |
 +----------------------------------------------------------------------+
 | Author: Sean  <seanforty@qq.com>                                     |
 +----------------------------------------------------------------------+
 */

#include <stdio.h>
#define MAXSIZE 20
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR -1

typedef int Status;
typedef int ElemType;
typedef struct node
{
    ElemType data[MAXSIZE];
    int top1;
    int top2;
}STACK;

//��ʾ������Ϣ���˳�
void errorInfo(char str[],int no)
{
    printf("%s\n",str);
    exit(no);
}

//ջΪ�շ���1��ջ�ǿշ���0
Status isEmpty(STACK *S,int sno)
{
    int flag = 0;
    if(1==sno)
    {
        if(S->top1 == -1)
        {
            flag = 1;
        }
    }else if(2==sno)
    {
        if(S->top2 == MAXSIZE)
        {
            flag = 1;
        }
    }else
    {
        errorInfo("sno is invalid\n",ERROR);
    }
    return flag;
}

//ջ������1��δ������0
Status isFull(STACK *S)
{
    if( (S->top1) == (S->top2-1))
    {
        return TRUE;
    }else
    {
        return FALSE;
    }
}

//ѹջ��ʱ�临�Ӷ�O(1)
Status push(STACK *S,int val,int sno)
{
    if(isFull(S))
    {
        errorInfo("ջ�������޷�push\n",ERROR);
    }

    if(1==sno)
    {
        S->data[S->top1+1] = val;
        S->top1 ++;
    }else if(2==sno)
    {
        S->data[S->top2-1] = val;
        S->top2 --;
    }

    return OK;
}

//��ջ��ʱ�临�Ӷ�O(1)
ElemType pop(STACK *S,int sno)
{
    if(isEmpty(S,sno))
    {
        errorInfo("ջΪ�գ��޷���ջ\n",ERROR);
    }

    ElemType val;

    if(1==sno)
    {
        val = S->data[S->top1];
        S->top1 --;
    }else if(2==sno)
    {
        val = S->data[S->top2];
        S->top2 ++;
    }
    return val;
}

//��ȡջ��ֵ��ʱ�临�Ӷ�O(1)
//sno=1 get top value of left stack
//sno=2 get top value of right stack
ElemType getTop(STACK *S,int sno)
{
    int topValue;
    if(isEmpty(S,sno))
    {
        errorInfo("ջΪ�գ��޷���ջ\n",ERROR);
    }
    if(1==sno)
    {
        topValue = S->data[S->top1];
    }else if(2==sno)
    {
        topValue = S->data[S->top2];
    }

    return topValue;
}

//��ʼ��ջ��ʱ�临�Ӷ�O(n)
Status stackInit(STACK *S,int val[],int len,int sno)
{
    if(len>MAXSIZE || len<1)
    {
        errorInfo("��ʼ��ʧ�ܣ�������Ч\n",ERROR);
    }

    if(1==sno)
    {
        S->top1 = len-1;
        int i = 0;
        for(;i<len;i++)
        {
            S->data[i] = val[i];
        }
    }else if(2==sno)
    {
        S->top2 = MAXSIZE - len;
        int i = 0;
        for(;i<len;i++)
        {
            S->data[MAXSIZE-i-1] = val[i];
        }
    }else
    {
        errorInfo("sno is invalid\n",ERROR);
    }
    return OK;
}

//�������ջ��ʱ�临�Ӷ�O(n)
Status stackShow(STACK *S)
{
    int i= S->top1;
    printf("output left stack:\n");
    for(;i>=0;i--)
    {
        printf("%d\n",S->data[i]);
    }
    printf("output right stack:\n");
    for(i=S->top2;i<MAXSIZE;i++)
    {
        printf("%d\n",S->data[i]);
    }


    return OK;
}

//���ջ
//sno=1 clear left stack
//sno=2 clear right stack
//other clear all stack
Status stackClear(STACK *S, int sno)
{
    if(1==sno)
    {
        S->top1 = -1;
    }else if(2==sno)
    {
        S->top2 = MAXSIZE;
    }else
    {
        S->top1 = -1;
        S->top2 = MAXSIZE;
    }
    return OK;
}

int main()
{
    STACK S;
    S.top1 = -1;
    S.top2 = MAXSIZE;

    //��ʼ��ջ
    int val1[4] = {11,22,33,44};
    int val2[3] = {21,22,23};
    stackInit(&S,val1,4,1);
    stackInit(&S,val2,3,2);
    //get top
    printf("Get top value of left stack:%d\n",getTop(&S,1));
    //pop
    printf("Pop stack: %d\n",pop(&S,1));

    //push
    push(&S,666,1);
    push(&S,777,1);
    push(&S,888,2);
    push(&S,999,2);

    //�������ջ
    stackShow(&S);

    //clear stack
    stackClear(&S,3);

    //�������ջ
    stackShow(&S);

    return 0;
}

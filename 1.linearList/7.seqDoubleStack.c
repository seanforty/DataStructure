/*
 +----------------------------------------------------------------------+
 | 双栈利用同一数组空间，两端为栈底，中间为栈顶，设置两个top指针。指针  |
 | 相遇则栈满。优点是在栈线性存储结构特点的基础上，充分利用空间。       |
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

//提示错误信息并退出
void errorInfo(char str[],int no)
{
    printf("%s\n",str);
    exit(no);
}

//栈为空返回1，栈非空返回0
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

//栈满返回1，未满返回0
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

//压栈，时间复杂度O(1)
Status push(STACK *S,int val,int sno)
{
    if(isFull(S))
    {
        errorInfo("栈已满，无法push\n",ERROR);
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

//弹栈，时间复杂度O(1)
ElemType pop(STACK *S,int sno)
{
    if(isEmpty(S,sno))
    {
        errorInfo("栈为空，无法出栈\n",ERROR);
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

//获取栈顶值，时间复杂度O(1)
//sno=1 get top value of left stack
//sno=2 get top value of right stack
ElemType getTop(STACK *S,int sno)
{
    int topValue;
    if(isEmpty(S,sno))
    {
        errorInfo("栈为空，无法出栈\n",ERROR);
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

//初始化栈，时间复杂度O(n)
Status stackInit(STACK *S,int val[],int len,int sno)
{
    if(len>MAXSIZE || len<1)
    {
        errorInfo("初始化失败，数据无效\n",ERROR);
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

//遍历输出栈，时间复杂度O(n)
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

//清空栈
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

    //初始化栈
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

    //遍历输出栈
    stackShow(&S);

    //clear stack
    stackClear(&S,3);

    //遍历输出栈
    stackShow(&S);

    return 0;
}

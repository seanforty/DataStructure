/*
 +----------------------------------------------------------------------+
 | 栈的顺序存储实现，使用数组存储栈数据，top存储栈顶下标                |
 | 栈只在栈顶操作（入栈和出栈），栈顶就是数组尾部                       |
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

//提示错误信息并退出
void errorInfo(char str[],int no)
{
    printf("%s\n",str);
    exit(no);
}

//分配内存失败提示错误并退出
void mallocErr(PSTACK P)
{
    if(NULL==P)
    {
        errorInfo("Error in locating memory.\n",ERROR);
    }
}

//获取栈长度
int stackLen(PSTACK P)
{
    return P->top+1;
}

//栈为空返回1，栈非空返回0
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

//栈满返回1，未满返回0
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

//压栈，时间复杂度O(1)
Status push(PSTACK P,int val)
{
    if(isFull(P))
    {
        errorInfo("栈已满，无法push\n",ERROR);
    }

    P->data[P->top+1] = val;
    P->top ++;
    return OK;
}

//弹栈，时间复杂度O(1)
Status pop(PSTACK P,ElemType *val)
{
    if(isEmpty(P))
    {
        errorInfo("栈为空，无法出栈\n",ERROR);
    }

    *val = P->data[P->top];
    P->top--;
    return OK;
}

//获取栈顶值，时间复杂度O(1)
Status getTop(PSTACK P,ElemType *val)
{
    if(isEmpty(P))
    {
        errorInfo("栈为空，无法出栈\n",ERROR);
    }

    *val = P->data[P->top];
    return OK;
}

//初始化栈，时间复杂度O(n)
Status stackInit(PSTACK P,int val[],int len)
{
    if(len>MAXSIZE || len<1)
    {
        errorInfo("初始化失败，数据无效\n",ERROR);
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

//遍历输出栈，时间复杂度O(n)
Status stackShow(PSTACK P)
{
    int i=P->top;
    for(;i>=0;i--)
    {
        printf("%d\n",P->data[i]);
    }
    return OK;
}

//清空栈，时间复杂度O(1)
Status stackClear(PSTACK P)
{
    P->top = -1;
    return OK;
}

//释放栈空间，时间复杂度O(1)
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

    //初始化栈
    int val[5] = {11,22,33,44,55};
    stackInit(P,val,5);

    //初始化后输出栈顶
    //printf("Stack top is : %d\n",P->top);

    //压栈
    push(P,777);
    push(P,888);
    push(P,999);

    //出栈
    ElemType popVal;
    pop(P,&popVal);
    printf("POP : %d\n",popVal);

    //遍历输出栈
    stackShow(P);

    //释放栈
    printf("destroy stack\n");
    stackDestroy(P);
    //遍历输出栈
    stackShow(P);

    return 0;
}

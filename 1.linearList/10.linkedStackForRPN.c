/*
 +----------------------------------------------------------------------+
 | 链栈跟链表相似，只是操作只有进栈和出栈，不能从链表中间插入和删除结点 |
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
typedef char ElemType;
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

//提示错误并退出
void errorInfo(char str[],int errno)
{
    printf("%s\n",str);
    exit(errno);
}

//空栈
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

//分配内存失败
void mallocErr(PNODE P)
{
    if(NULL==P)
    {
        errorInfo("Error in locating memory\n",ERROR);
    }
}

//进栈
Status push(STACK *S,ElemType val)
{
    //为新结点分配内存
    PNODE p = (PNODE)malloc(sizeof(NODE));
    mallocErr(p);

    //将新结点追加到栈顶，top指针上移
    p->data = val;
    p->next = S->top;
    S->top = p;
    S->length ++;
    return OK;
}

//pop
ElemType pop(STACK *S)
{
    if(isEmpty(S))
    {
        printf("空栈\n",ERROR);
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
ElemType getTopValue(const STACK *S)
{
    if(isEmpty(S))
    {
        errorInfo("空栈\n",ERROR);
    }

    return S->top->data;
}

//clear stack
Status stackClear(STACK *S)
{
    if(isEmpty(S))
    {
        errorInfo("空栈\n",ERROR);
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

//初始化栈
Status stackInit(STACK *S,ElemType val[],int len)
{
    if(len<0)
    {

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

//遍历输出栈
Status stackShow(const STACK *S)
{
    if(isEmpty(S))
    {
        errorInfo("空栈\n",ERROR);
    }

    PNODE temp = S->top;
    while(NULL!=temp->next)
    {
        printf("%c\n",temp->data);
        temp = temp->next;
    }
    printf("%c\n",temp->data);
    return OK;
}

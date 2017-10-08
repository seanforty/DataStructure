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
Status push(STACK *S,int val)
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
int pop(STACK *S)
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
int getTopValue(const STACK *S)
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
Status stackInit(STACK *S,int val[],int len)
{
    if(len<1)
    {
        errorInfo("数据无效\n",ERROR);
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
        printf("%d\n",temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
    return OK;
}

int main()
{
    //声明栈，并将栈顶指针设置为NULL
    STACK S;
    S.length = 0;
    S.top = NULL;

    //初始化栈
    int val[5] = {11,22,33,44,55};
    stackInit(&S,val,5);

    //进栈
    push(&S,777);
    push(&S,888);
    push(&S,999);

    //pop
    printf("POP top value: %d\n",pop(&S));

    //输出栈
    stackShow(&S);

    //get top value
    printf("top value of the stack: %d\n",getTopValue(&S));

    //clear stack
    stackClear(&S);

    printf("stack length: %d\n",S.length);
    printf("stack top : %p\n",S.top);

    //输出栈
    stackShow(&S);

    return 0;
}

/*
 +----------------------------------------------------------------------+
 | 队列的链式结构实现，同单链表类似，只是操作简单一些                   |
 +----------------------------------------------------------------------+
 | Author: Sean  <seanforty@qq.com>                                     |
 +----------------------------------------------------------------------+
 */

#include <stdio.h>
#define OK 1
#define TRUE 1
#define FALSE 0
#define ERROR -1
#define MAXSIZE 100

typedef int Status;
typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
}NODE,*QNODE;

typedef struct Queue
{
    QNODE front;
    QNODE rear;
    int length;
}QUEUE;

void errorInfo(char str[])
{
    printf("%s\n",str);
    exit(-1);
}

void mallocErr(QNODE Q)
{
    if(NULL==Q)
    {
        errorInfo("Error in locating memory.");
    }
}

Status isEmpty(QUEUE *Q)
{
    //if(Q->front == NULL && Q->rear==NULL)
    if(Q->length == 0)
    {
        return TRUE;
    }else
    {
        return FALSE;
    }
}

Status enqueue(QUEUE *Q,ElemType val)
{
    QNODE n = (QNODE)malloc(sizeof(NODE));
    mallocErr(n);
    n->data = val;
    n->next = NULL;

    if(isEmpty(Q))
    {
        Q->front = n;
        Q->rear  = n;
    }else
    {
        Q->rear->next = n;
        Q->rear = n;
    }

    Q->length ++;
    return OK;
}

Status queueShow(QUEUE *Q)
{
    if(isEmpty(Q))
    {
        errorInfo("Queue is empty.");
    }
    QNODE t = Q->front;
    while(NULL!=t->next)
    {
        printf("%d\n",t->data);
        t = t->next;
    }
    printf("%d\n",t->data);
    return OK;
}

Status dequeue(QUEUE *Q,ElemType *val)
{
    if(isEmpty(Q))
    {
        errorInfo("Queue is empty.");
    }

    *val = Q->front->data;
    QNODE t = Q->front;
    if(NULL==Q->front->next)
    {
        Q->front = NULL;
        Q->rear  = NULL;
    }else
    {
        Q->front = Q->front->next;
    }
    free(t);
    t = NULL;
    Q->length --;
    return OK;
}

Status queueInit(QUEUE *Q)
{
    Q->front = NULL;
    Q->rear  = NULL;
    Q->length= 0;
}

Status queueClear(QUEUE *Q)
{
    if(isEmpty(Q))
    {
        errorInfo("Queue is empty.");
    }

    QNODE tmp,t = Q->front;
    while(NULL!=t->next)
    {
        tmp = t;
        t = t->next;
        free(tmp);
    }
    free(t);
    Q->length = 0;
    Q->front  = NULL;
    Q->rear   = NULL;
    return OK;
}

int main()
{
    QUEUE Q;
    queueInit(&Q);

    enqueue(&Q,11);
    enqueue(&Q,22);
    enqueue(&Q,33);
    enqueue(&Q,44);
    enqueue(&Q,55);
    enqueue(&Q,66);

    ElemType t;
    dequeue(&Q,&t);
    printf("dequeue : %d\n",t);

    queueShow(&Q);
    queueClear(&Q);
    queueShow(&Q);
    return 0;
}
















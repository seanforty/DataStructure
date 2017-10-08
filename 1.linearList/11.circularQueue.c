/*
 +----------------------------------------------------------------------+
 | 队列需要在前端出队，尾端入队，在使用数组实现时，如果想保持数组下标为 |
 | 0处放前端，则每次出队操作都需要将数据元素前移。这里使用循环队列实现  |
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
    ElemType data[MAXSIZE];
    int front;
    int rear;
    int length;
}QUEUE;

void errorInfo(char str[])
{
    printf("%s\n",str);
    exit(-1);
}

Status isEmpty(QUEUE *Q)
{
//    if(Q->front == -1 && Q->rear == -1)
//    {
//        return TRUE;
//    }else if(Q->front != -1 && Q->rear != -1)
//    {
//        return FALSE;
//    }else
//    {
//        errorInfo("Pointers of queue is invalid");
//    }
    if(Q->length == 0)
        return TRUE;
    else
        return FALSE;
}

Status isFull(QUEUE *Q)
{
//    if( (MAXSIZE==Q->rear+1) && (0==Q->front) )
//    {
//        return TRUE;
//    }else if(Q->front == Q->rear+1)
//    {
//        return TRUE;
//    }else
//    {
//        return FALSE;
//    }
    if(Q->length == MAXSIZE)
        return TRUE;
    else
        return FALSE;
}

//add data to tail of the queue
Status enqueue(QUEUE *Q,ElemType val)
{
    if(isFull(Q))
    {
        errorInfo("Queue is full.");
    }

    if(isEmpty(Q))
    {
        Q->data[0] = val;
        Q->front = 0;
        Q->rear  = 0;
    }else if(Q->rear == MAXSIZE-1)
    {
        Q->data[0] = val;
        Q->rear = 0;
    }else
    {
        Q->rear++;
        Q->data[Q->rear] = val;
    }
    Q->length++;
    return OK;
}

//pop data
ElemType dequeue(QUEUE *Q)
{
    if(isEmpty(Q))
    {
        errorInfo("Queue is empty.");
    }

    ElemType t = Q->data[Q->front];
    if(Q->front == MAXSIZE-1)
    {
        Q->front = 0;
    }else
    {
        Q->front++;
    }
    Q->length --;
    return t;
}

//initialize the queue, you can also use it to clear queue
Status queueInit(QUEUE *Q)
{
    Q->length = 0;
    Q->front = -1;
    Q->rear = -1;
    return OK;
}

Status queueShow(QUEUE *Q)
{
    int i;
    if(Q->rear>Q->front)
    {
        for(i=Q->front;i<=Q->rear;i++)
        {
            printf("%d\n",Q->data[i]);
        }
    }else if(Q->rear == Q->front)
    {
        printf("%d\n",Q->data[Q->front]);
    }else
    {
        for(i=Q->front;i<MAXSIZE;i++)
        {
            printf("%d\n",Q->data[i]);
        }
        for(i=0;i<Q->rear;i++)
        {
            printf("%d\n",Q->data[i]);
        }
    }
    return OK;
}

int main()
{
    QUEUE Q;
    queueInit(&Q);

    enqueue(&Q,10);
    enqueue(&Q,20);
    enqueue(&Q,30);
    enqueue(&Q,40);
    enqueue(&Q,50);

    show(&Q);
    printf("dequeue : %d\n",dequeue(&Q));
    show(&Q);

    queueShow(&Q);

    return 0;
}

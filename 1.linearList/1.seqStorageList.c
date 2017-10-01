#include <stdio.h>
#define OK 1
#define TRUE 1
#define ERROR 0
#define MAXSIZE 30

typedef int Status;
typedef int ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int length;
}SqList;

Status GetElem(SqList L,int i,ElemType *e)
{
    if( L.length==0 || i<1 || i > L.length )
    {
        return ERROR;
    }else
    {
        *e = L.data[i-1];
        return OK;
    }
}

Status ListInsert(SqList *L,int i,ElemType e)
{
    int j;
    if(i<=1 || i>L->length){
        return ERROR;
    }
    if(L->length == MAXSIZE){
        return ERROR;
    }

    for(j=L->length-1;j>=L->length-i-1;j--)
    {
        L->data[j+1] = L->data[j];
    }
    L->data[i-1] = e;
    L->length++;
    return OK;
}

Status ListDelete(SqList *L,int i,ElemType *e)
{
    int j;
    if(i<1 || i>L->length)
    {
        return ERROR;
    }
    if(L->length==0)
    {
        return ERROR;
    }
    e = L->data[i-1];
    if(i<L->length)
    {   //1,2,3,4,5
        for(j=i-1;i<L->length-1;i++){
            L->data[i] = L->data[i+1];
        }
    }
    L->length --;
    return OK;
}

void show(SqList L)
{
    int i;
    for(i=0;i<L.length;i++)
    {
        printf("%d\n",L.data[i]);
    }
}

int main()
{
    int i;
    SqList L;
    for(i=0;i<10;i++)
    {
        L.data[i] = i*i;
        L.length += 1;
    } // 1 4 9 16 25 36 49 64 81
    int *e;
    ListDelete(&L,4,&e);
    //ListInsert(&L,3,111);
    show(L);
    //GetElem(L,10,&e);
    //printf("%d",e);
    return 0;
}







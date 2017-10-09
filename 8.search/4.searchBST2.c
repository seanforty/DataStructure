/*
 +----------------------------------------------------------------------+
 | 这里实现二叉排序树的插入和删除操作
 +----------------------------------------------------------------------+
 | Author: Sean  <seanforty@qq.com>                                     |
 +----------------------------------------------------------------------+
 */

#include <stdio.h>
#include <malloc.h>
#define OK 1
#define TRUE 1
#define ERROR -1
#define FALSE 0

typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *lchild,*rchild;
}NODE,*PNODE;

//prompt error info and exit.
void errorInfo(char str[])
{
    printf("%s\n",str);
    exit(-1);
}

//prompt error if there is an error in locating memory
void mallocErr(PNODE p)
{
    if(NULL==p)
        errorInfo("Error in locating memory.");
}

//search binary sort tree
int searchBST(PNODE T,int val,PNODE f,PNODE *p)
{
    if(!T)
    {
        *p = f;
        return FALSE;
    }else if(val == T->data)
    {
        *p = T;
        return TRUE;
    }else if(val < T->data)
    {
        return searchBST(T->lchild,val,T,p);
    }else
    {
        return searchBST(T->rchild,val,T,p);
    }
}

int insertBST(PNODE *T,int val)
{
    PNODE p,s;
    if(!searchBST(*T,val,NULL,&p))
    {
        s = (PNODE)malloc(sizeof(NODE));
        mallocErr(s);
        s->data = val;
        s->lchild = s->rchild = NULL;

        if(!p) //p is null
        {
            printf("Create Tree with val:%d\n",val);
            *T = s;
        }else if(val < p->data)
        {
            printf("Insert Key To Tree(left):%d\n",val);
            p->lchild = s;
        }else
        {
            printf("Insert Key To Tree(right):%d\n",val);
            p->rchild = s;
        }
        return TRUE;
    }else
    {
         return FALSE;
    }
}

int main()
{
    PNODE T = NULL,p = NULL;
    insertBST(&T,100);
    insertBST(&T,110);
    insertBST(&T,99);
    insertBST(&T,199);
    insertBST(&T,10);
    insertBST(&T,200);
    insertBST(&T,230);

    return 0;
}


/*
 +----------------------------------------------------------------------+
 | 二叉树的建立和遍历                                     |
 +----------------------------------------------------------------------+
 | Author: Sean  <seanforty@qq.com>                                     |
 +----------------------------------------------------------------------+
 */

#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define ERROR -1
#define OK 1

typedef int Status;
typedef char ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *lp;
    struct Node *rp;
}BiNode,*BiTree;

void errorInfo(char str[])
{
    printf("%s\n",str);
    exit(-1);
}

void mallocErr(BiTree t)
{
    if(NULL==t)
    {
        errorInfo("Error in locating memory.\n");
    }
}

BiTree createBinaryTree(BiTree T)
{
    ElemType ch;
    scanf("%c",&ch);

    if('#'==ch)
    {
        T = NULL;
    }else
    {
        T = (BiTree)malloc(sizeof(BiNode));
        mallocErr(T);
        T->data = ch;
        printf("Your input is : %c\n",ch);
        T->lp = createBinaryTree(T->lp);
        T->rp = createBinaryTree(T->rp);
    }
    return T;
}

//前序遍历 root left right
Status preShowBiTree(BiTree T)
{
    if(T!=NULL)
    {
        printf("%c",T->data);
        preShowBiTree(T->lp);
        preShowBiTree(T->rp);
    }
    return OK;
}

//中序遍历 left root right
Status MidShowBiTree(BiTree T)
{
    if(T!=NULL)
    {
        preShowBiTree(T->lp);
        printf("%c",T->data);
        preShowBiTree(T->rp);
    }
    return OK;
}


//后序遍历left right root
Status MidShowBiTree(BiTree T)
{
    if(T!=NULL)
    {
        preShowBiTree(T->lp);
        preShowBiTree(T->rp);
        printf("%c",T->data);
    }
    return OK;
}

int main()
{
    BiNode *T = NULL;
    printf("Please create a binary tree: \n");
    T = createBinaryTree(T);

    printf("Pre-show this binary tree: \n");
    preShowBiTree(T);
    return 0;
}

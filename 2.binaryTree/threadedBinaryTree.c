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


//枚举类型，默认link 为 0，thread为1
typedef enum {link,thread} PTag;

typedef int Status;
typedef char ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *lp, *rp;
    PTag lt,rt;
}BiNode,*BiTree;

BiTree pre = NULL;

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

//中序遍历 left root right
Status MidShowBiTree(BiTree T)
{
    if(T!=NULL)
    {
        MidShowBiTree(T->lp);
        printf("%c",T->data);
        if(!T->lp)
        {
            T->lt = thread;
            T->lp = pre;
        }
        if(!T->rp)
        {
            pre->rt = thread;
            pre->rp = T;
        }
        pre = T;
        MidShowBiTree(T->rp);
    }
    return OK;
}

int main()
{
    BiNode *T = NULL;
    printf("Please create a binary tree: \n");
    T = createBinaryTree(T);

    printf("Mid-show this binary tree: \n");
    MidShowBiTree(T);
    return 0;
}

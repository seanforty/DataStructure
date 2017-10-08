/*
 +----------------------------------------------------------------------+
 | 二叉排序树查找操作，用前面讲到的建立二叉树的方法建立一个二叉树，然后 |
 | 使用searchBST函数递归搜索。
 +----------------------------------------------------------------------+
 | Author: Sean  <seanforty@qq.com>                                     |
 +----------------------------------------------------------------------+
 */

#include <stdio.h>
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

void errorInfo(char str[])
{
    printf("%s\n",str);
    exit(-1);
}

void mallocErr(PNODE p)
{
    if(NULL==p)
        errorInfo("Error in locating memory.");
}

//gIndex is global parameter, and it increases by one when getGlobalIndex function is called
int gIndex = 0;
int getGlobalIndex()
{
    return gIndex++;
}

//create binary tree (You should input pre-order binary tree)
PNODE createBinaryTree(PNODE T,int arr[])
{
    int i = getGlobalIndex();
    if(0==arr[i])
    {
        T = NULL;
    }else
    {
        T = (PNODE)malloc(sizeof(NODE));
        mallocErr(T);
        T->data = arr[i];
        T->lchild = createBinaryTree(T,arr);
        T->rchild = createBinaryTree(T,arr);
    }

    return T;
}

// in-order traversal binary tree
void midShowBiTree(PNODE T)
{
    if(NULL!=T)
    {
        midShowBiTree(T->lchild);
        printf("%d\n",T->data);
        midShowBiTree(T->rchild);
    }
}

//search binary sort tree
int searchBST(PNODE T,int val,PNODE p)
{
    if(!T)
    {
        return FALSE;
    }else if(val == T->data)
    {
        p = T;
        return TRUE;
    }else if(val < T->data)
    {
        return searchBST(T->lchild,val,p);
    }else
    {
        return searchBST(T->rchild,val,p);
    }
}

int main()
{
    int arr[30] = {62, 58, 47, 35, 0, 37, 0, 0, 51, 0, 0, 0, 88, 73, 0, 0, 99, 93, 0, 0, 0};
    PNODE T;
    T = createBinaryTree(T,arr);
    printf("In-order traversal this binary tree:\n");
    midShowBiTree(T);

    PNODE p;
    int val = 58;
    int res = 0;
    res = searchBST(T,val,p);
    if(TRUE == res)
    {
        printf("Find it:");
        printf("Data is : %d\n",p->data);
        //printf("%d",p->data);
    }else
    {
        printf("Cannot find it:\n");
        //printf("%d",p->data);
    }

    return 0;
}


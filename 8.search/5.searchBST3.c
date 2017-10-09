/*
 +----------------------------------------------------------------------+
 | ����ʵ�ֶ��������������鴴�������ҡ������Լ�ɾ������
 +----------------------------------------------------------------------+
 | Author: Sean  <seanforty@qq.com>                                     |
 +----------------------------------------------------------------------+
 */
 #include <stdio.h>
 #include <stdlib.h>

 #define TRUE 1
 #define FALSE 0
 #define ERROR -1
 #define OK 1

 typedef int Status;
 typedef int ElemType;
 typedef struct Node
 {
    ElemType data;
    struct Node *lchild,*rchild;
 }NODE,*PNODE;

 int globalCount = 0;
 int globalCountAdd()
 {
     return globalCount++;
 }

 void errorInfo(char str[])
 {
     printf("%s\n",str);
     exit(1);
 }

 void mallocErr(PNODE p)
 {
     if(NULL == p)
     {
         errorInfo("Error: can not locate memory.\n");
     }
 }

 //ʹ��ǰ��������д���BST
 PNODE createBST(PNODE T,int arr[])
 {
     int i = globalCountAdd();
     if(0==arr[i])
        T = NULL;
     else
     {
         T = (PNODE)malloc(sizeof(NODE));
         mallocErr(T);
         T->data = arr[i];
         T->lchild = createBST(T,arr);
         T->rchild = createBST(T,arr);
     }
     return T;
 }

 //�������BST
 void inOrderTraverse(PNODE T)
 {
     if(NULL!=T)
     {
         inOrderTraverse(T->lchild);
         printf("%d\n",T->data);
         inOrderTraverse(T->rchild);
     }
 }

 //���ҽ��
 Status searchBST(PNODE T,int val,PNODE *f,PNODE *p)
 {
    if(NULL==T)
    {
        *p = f;
        return FALSE;
    }
    else if(val==T->data)
    {
        *p = T;
        return TRUE;
    }else if(val<T->data)
    {
        return searchBST(T->lchild,val,T,p);
    }else
    {
        return searchBST(T->rchild,val,T,p);
    }
 }

 //������
 Status insertBST(PNODE *T,int val)
 {
    PNODE p,s;
    if(!searchBST(*T,val,NULL,&p))
    {
        s = (PNODE)malloc(sizeof(NODE));
        mallocErr(s);
        s->data = val;
        s->lchild = s->rchild = NULL;

        if(!p)
        {
            printf("Create BST:\n");
            *T = s;
        }else if(val<p->data)
        {
            printf("insert left tree:\n");
            p->lchild = s;
        }else
        {
            printf("insert right tree:\n");
            p->rchild = s;
        }
        return TRUE;
    }else
    {
        return FALSE;
    }
 }

 //ɾ�����
 Status deleteNode(PNODE *p)
 {
     PNODE q,s;
     if( NULL==(*p)->lchild )
     {
        q = *p;
        *p = (*p)->rchild;
        free(q);
     }else if(NULL==(*p)->rchild)
     {
        q = *p;
        *p = (*p)->lchild;
        free(q);
     }else
     {
         q = *p;
         s = (*p)->lchild;
         while(s->rchild)
         {
             q = s;
             s = s->rchild;
         }
         (*p)->data = s->data;
         if(q != *p)
         {
            q->rchild = s->lchild;
         }else
         {
            q->lchild = s->lchild;
         }
         free(s);
     }
     return TRUE;
 }

 //ɾ�����
 Status deleteBST(PNODE *T,int val)
 {
    if(!*T)
        return FALSE;
    else if(val==(*T)->data)
    {
        return deleteNode(T);
    }else if(val<(*T)->data)
    {
        return deleteBST(&(*T)->lchild,val);
    }else
    {
        return deleteBST(&(*T)->rchild,val);
    }
 }


 int main()
 {
    PNODE T = NULL, p=NULL;
    //ǰ���������
    int preOrder[100] = {5,3,1,0,2,0,0,4,0,0,7,6,0,0,9,8,0,0,10,0,0};
    T = createBST(T,preOrder);

//    insertBST(&T,11);
//    insertBST(&T,12);
//    insertBST(&T,13);
//    insertBST(&T,9);
//    insertBST(&T,8);

    deleteBST(&T,7);
    printf("Traverse the tree in-order:\n");
    inOrderTraverse(T);
    return 0;
 }

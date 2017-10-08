/*
 +----------------------------------------------------------------------+
 | ����ṹ�壬���г�Ա����data���������Ա����ݡ�ͨ�������±�ֱ�ӷ��� |
 | ������ַ�����������ݽ��в�����                                     |
 | �ŵ㣺 ����ͨ����ֱַ�ӻ�ȡָ��λ�����ݣ�ʱ�临�Ӷ�ΪO(1)            |
 | ȱ�㣺 �����ɾ����㶼��Ҫ�ƶ��������ݣ�ʱ�临�Ӷ�ΪO(n)            |
 +----------------------------------------------------------------------+
 | Author: Sean  <seanforty@qq.com>                                     |
 +----------------------------------------------------------------------+
 */

#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR -1
#define MAXSIZE 30

typedef int Status;
typedef int ElemType;

/*
����ṹ�壬�洢���Ա��ʵ�ʳ���
*/
typedef struct
{
    ElemType data[MAXSIZE]; //ʹ������洢���Ա����鳤��MAXSIZEΪ���Ա���
    int length; //INTֵ������Ա����ݳ���
}SQLIST,*PSQLIST;

/*
�ж�ָ��λ���Ƿ���Ч
ָ��λ��С��1��������ݳ���ʱ������0�����򷵻�1
*/
Status posCheck(PSQLIST L,int pos)
{


    if(pos<1 || pos>L->length)
    {
        return FALSE;
    }else
    {
        return TRUE;
    }
}

/*
���������ݣ������ݷ���1�������ݷ���0
*/
Status isEmpty(PSQLIST L)
{
    if(L->length==0)
    {
        return TRUE;
    }else
    {
        return FALSE;
    }
}

/*
�����Ƿ�����������������1��δ������0
*/
Status isFull(PSQLIST L)
{
    if(L->length == MAXSIZE)
    {
        return TRUE;
    }else
    {
        return FALSE;
    }
}

/*
���������Ϣ���˳�����
*/
void errorInfo(char str[],int errorType)
{
    printf("%s\n",str);
    exit(errorType);
}


/*
��ȡָ��λ��Ԫ�أ�ͨ����ֱַ�Ӷ�λ��ʱ�临�Ӷ�ΪO(1)
*/
Status GetElem(PSQLIST L,int pos,ElemType *e)
{
    //���pos�Ƿ�Ϸ�
    if(!posCheck(L,pos))
    {
        errorInfo("ָ��λ�÷Ƿ���\n",ERROR);
    }
    //����Ƿ�Ϊ�ձ�
    if(isEmpty(L))
    {
        errorInfo("�ñ�Ϊ�ձ�\n",ERROR);
    }

    *e = L->data[pos-1];
    return OK;
}

/*
��ָ��λ�ò���Ԫ�أ��Բ���λ���������κ��ơ�ʱ�临�Ӷ�ΪO(n)
*/
Status listInsert(PSQLIST L,int pos,ElemType e)
{

    //���pos�Ƿ�Ϸ�
    if(!posCheck(L,pos))
    {
        errorInfo("ָ��λ�÷Ƿ���\n",ERROR);
    }
    //�����Ƿ�����
    if(isFull(L))
    {
        errorInfo("�ñ�������\n",ERROR);
    }

    //�Բ���λ���𣬺���������κ��ƣ�Ȼ����ָ��λ�ò�����
    int j = L->length-1;
    for(;j>=pos-1;j--)
    {
        L->data[j+1] = L->data[j];
    }
    L->data[pos-1] = e;
    L->length++;
    return OK;
}

/*
ɾ��������ָ��λ��Ԫ�ص�ָ��e, ��ָ��λ����ֱ�Ӻ���Ԫ������ǰ�ơ�ʱ�临�Ӷ�ΪO(n)
*/
Status listDelete(PSQLIST L,int pos,ElemType *e)
{
    //���pos�Ƿ�Ϸ�
    if(!posCheck(L,pos))
    {
        errorInfo("ָ��λ�÷Ƿ���\n",ERROR);
    }
    //����Ƿ�Ϊ�ձ�
    if(isEmpty(L))
    {
        errorInfo("�ñ�Ϊ�ձ�\n",ERROR);
    }

    *e = L->data[pos-1];

    //����������һ����㣬����Ľ��ǰ��
    if(pos<L->length)
    {
        int j = pos-1;
        for(;j<L->length-1;j++){
            L->data[j] = L->data[j+1];
        }
    }
    //�����ݳ��ȼ�1
    L->length --;
    return OK;
}

//����ָ����ֵ�������ء�ʱ�临�Ӷ�ΪO(n)
Status locateElem(PSQLIST L,int val,int *index)
{
    if(isEmpty(L))
    {
        errorInfo("Ҫ���ҵı�Ϊ�ձ�\n",ERROR);
    }
    *index = -1;
    int i=0;
    for(;i<L->length;i++)
    {
        if(L->data[i] == val)
        {
            *index = i;
            break;
        }
    }
    if(*index == -1)
    {
        errorInfo("����û��Ҫ�ҵ�ֵ\n",ERROR);
    }
    return OK;
}

/*
��ʼ����
*/
Status listInit(PSQLIST L,int arr[],int len)
{
    //�жϳ�ʼ�������Ƿ񳬹����Ա���
    if(len > MAXSIZE)
    {
        errorInfo("���ݳ��ȳ������Ա��ȣ�\n",ERROR);
    }

    int i=0;
    for(;i<len;i++)
    {
        L->data[i] = arr[i];
    }
    L->length = len;
    return OK;
}

/*
��ձ�
*/
Status clearList(PSQLIST L)
{
    int i = 0;
    for(;i<L->length;i++)
    {
        L->data[i] = NULL;
    }
    L->length = 0;
    return OK;
}

Status destroyList(PSQLIST L)
{
    free(L);
    L = NULL;
}

/*
������ʾ����Ԫ�ء�ʱ�临�Ӷ�ΪO(n)
*/
Status listShow(PSQLIST L)
{
    if(isEmpty(L))
    {
        errorInfo("��Ϊ��\n",ERROR);
    }

    int i=0;
    for(;i<L->length;i++)
    {
        printf("L->data[%d] = %d\n",i,L->data[i]);
    }
    return OK;
}

int main()
{
    //����ָ��������ʼ��ΪNULL
    PSQLIST L=NULL;

    //��ָ��L�����ڴ�
    L = (PSQLIST)malloc(sizeof(SQLIST));
    if(NULL == L)
    {
        errorInfo("ERROR: cannot allocate memory for L!", 1);
    }

    //��ʼ�����Ա�
    ElemType data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    listInit(L,data,10);

    //ɾ��ָ��Ԫ��
    ElemType e;
//    int deletepos = 1;
//    listDelete(L,deletepos,&e);
//    printf("ɾ��λ��Ϊ%d��Ԫ��Ϊ��%d\n",deletepos,e);

    //ָ��λ�����Ԫ��
    int insertpos = 10;
    int insertvalue = 100;
    listInsert(L,insertpos,insertvalue);

    //��ȡָ��λ��Ԫ��
//    GetElem(L,insertpos,&e);
//    printf("��ȡ����Ԫ��Ϊ��%d\n",e);

    //���Ҹ�����Ԫ��ֵ
//    int findpos = -1;
//    int findvalue = 5;
//    locateElem(L,findvalue,&findpos);
//    printf("Ԫ��%d��λ���ǣ� %d\n",findvalue,findpos);

    //�������Ԫ��
    listShow(L);

    //��ձ�
    clearList(L);

    //�������Ԫ��
    listShow(L);

    //�ͷű��ڴ�
    destroyList(L);

    //�������Ԫ��
    listShow(L);

    return 0;
}

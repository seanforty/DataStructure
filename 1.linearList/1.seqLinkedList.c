/*
 +----------------------------------------------------------------------+
 | 定义结构体，其中成员变量data数组存放线性表数据。通过数组下标直接访问 |
 | 各结点地址，并对其数据进行操作。                                     |
 | 优点： 可以通过地址直接获取指定位置数据，时间复杂度为O(1)            |
 | 缺点： 插入和删除结点都需要移动大量数据，时间复杂度为O(n)            |
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
定义结构体，存储线性表和实际长度
*/
typedef struct
{
    ElemType data[MAXSIZE]; //使用数组存储线性表，数组长度MAXSIZE为线性表长度
    int length; //INT值存放线性表数据长度
}SQLIST,*PSQLIST;

/*
判断指定位置是否有效
指定位置小于1或大于数据长度时，返回0，否则返回1
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
检查表无数据，无数据返回1，有数据返回0
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
检查表是否已满，若已满返回1，未满返回0
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
输出错误信息并退出程序
*/
void errorInfo(char str[],int errorType)
{
    printf("%s\n",str);
    exit(errorType);
}


/*
获取指定位置元素，通过地址直接定位，时间复杂度为O(1)
*/
Status GetElem(PSQLIST L,int pos,ElemType *e)
{
    //检查pos是否合法
    if(!posCheck(L,pos))
    {
        errorInfo("指定位置非法！\n",ERROR);
    }
    //检查是否为空表
    if(isEmpty(L))
    {
        errorInfo("该表为空表！\n",ERROR);
    }

    *e = L->data[pos-1];
    return OK;
}

/*
在指定位置插入元素，自插入位置起结点依次后移。时间复杂度为O(n)
*/
Status listInsert(PSQLIST L,int pos,ElemType e)
{

    //检查pos是否合法
    if(!posCheck(L,pos))
    {
        errorInfo("指定位置非法！\n",ERROR);
    }
    //检查表是否已满
    if(isFull(L))
    {
        errorInfo("该表已满！\n",ERROR);
    }

    //自插入位置起，后续结点依次后移，然后在指定位置插入结点
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
删除并返回指定位置元素到指针e, 自指定位置起直接后续元素依次前移。时间复杂度为O(n)
*/
Status listDelete(PSQLIST L,int pos,ElemType *e)
{
    //检查pos是否合法
    if(!posCheck(L,pos))
    {
        errorInfo("指定位置非法！\n",ERROR);
    }
    //检查是否为空表
    if(isEmpty(L))
    {
        errorInfo("该表为空表！\n",ERROR);
    }

    *e = L->data[pos-1];

    //如果不是最后一个结点，后面的结点前移
    if(pos<L->length)
    {
        int j = pos-1;
        for(;j<L->length-1;j++){
            L->data[j] = L->data[j+1];
        }
    }
    //线数据长度减1
    L->length --;
    return OK;
}

//查找指定的值，并返回。时间复杂度为O(n)
Status locateElem(PSQLIST L,int val,int *index)
{
    if(isEmpty(L))
    {
        errorInfo("要查找的表为空表\n",ERROR);
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
        errorInfo("表中没有要找的值\n",ERROR);
    }
    return OK;
}

/*
初始化表
*/
Status listInit(PSQLIST L,int arr[],int len)
{
    //判断初始化数据是否超过线性表长度
    if(len > MAXSIZE)
    {
        errorInfo("数据长度超过线性表长度！\n",ERROR);
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
清空表
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
遍历显示所有元素。时间复杂度为O(n)
*/
Status listShow(PSQLIST L)
{
    if(isEmpty(L))
    {
        errorInfo("表为空\n",ERROR);
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
    //声明指针变量后初始化为NULL
    PSQLIST L=NULL;

    //给指针L分配内存
    L = (PSQLIST)malloc(sizeof(SQLIST));
    if(NULL == L)
    {
        errorInfo("ERROR: cannot allocate memory for L!", 1);
    }

    //初始化线性表
    ElemType data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    listInit(L,data,10);

    //删除指定元素
    ElemType e;
//    int deletepos = 1;
//    listDelete(L,deletepos,&e);
//    printf("删除位置为%d的元素为：%d\n",deletepos,e);

    //指定位置添加元素
    int insertpos = 10;
    int insertvalue = 100;
    listInsert(L,insertpos,insertvalue);

    //获取指定位置元素
//    GetElem(L,insertpos,&e);
//    printf("获取到的元素为：%d\n",e);

    //查找给出的元素值
//    int findpos = -1;
//    int findvalue = 5;
//    locateElem(L,findvalue,&findpos);
//    printf("元素%d的位置是： %d\n",findvalue,findpos);

    //遍历输出元素
    listShow(L);

    //清空表
    clearList(L);

    //遍历输出元素
    listShow(L);

    //释放表内存
    destroyList(L);

    //遍历输出元素
    listShow(L);

    return 0;
}

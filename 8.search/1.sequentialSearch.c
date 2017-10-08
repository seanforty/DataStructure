/*
 +----------------------------------------------------------------------+
 | 顺序查找是最基本的查找方法，从表中第一个或最后一个记录开始逐个查找   |
 | 直接找到为止。时间复杂度为O(n)。查找大量数据时效率较差。
 +----------------------------------------------------------------------+
 | Author: Sean  <seanforty@qq.com>                                     |
 +----------------------------------------------------------------------+
 */

#include <stdio.h>
#define OK 1
#define TRUE 1
#define ERROR -1
#define FALSE 0

//sequential search 1
int sequentialSearch1(int *arr,int len,int val)
{
    int i = 0;
    for(;i<len;i++)
    {
        if(val == arr[i])
        {
            return i;
        }
    }
    return ERROR;
}

//sequential search 2
int sequentialSearch2(int *arr,int len,int val)
{
    arr[-1] = val;
    int i = len-1;
    while(val!=arr[i])
    {
        i--;
    }

    if(0!=i)
    {
        return i;
    }

    return ERROR;
}


int main()
{
    int len = 10;
    int arr[10] = {11,22,33,44,55,66,77,88,99};
    int val;
    scanf("%d",&val);
    //int res = sequentialSearch1(arr,len,val);
    int res = sequentialSearch2(arr,len,val);

    if(-1==res)
    {
        printf("Not found, %d is not in the array.\n",val);
    }else
    {
        printf("Index of the val is : %d\n",res);
    }

    printf("the arr detail:\n");
    int i = 0;
    for(;i<len;i++)
    {
        printf("%d\n",arr[i]);
    }

    return 0;
}

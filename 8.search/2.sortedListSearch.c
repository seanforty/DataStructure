/*
 +----------------------------------------------------------------------+
 | 有序表查找有三种：折半查找、插值查找和斐波那契查找，                 |
 | 插值查找 mid = low + (high-low)*(val-arr[low])/(arr[high]-arr[low])  |
 | 斐波那契查找 mid = low + fibnacci(k-1) -1
 +----------------------------------------------------------------------+
 | Author: Sean  <seanforty@qq.com>                                     |
 +----------------------------------------------------------------------+
 */

#include <stdio.h>
#define OK 1
#define TRUE 1
#define ERROR -1
#define FALSE 0

//迭代实现
int binarySearch1(int *arr,int len,int val)
{
    int low = 0;
    int high = len;
    int mid;

    while(low<high)
    {
        mid = (low+high)/2;
        if(val == arr[mid])
        {
            return mid;
        }else if(val<arr[mid])
        {
            high = mid;
        }else
        {
            low = mid;
        }
    }
    return ERROR;
}

//recursion
int recursionSearch(int *arr,int low,int high,int val)
{
    int mid = (low+high)/2;
    if(val == arr[mid])
        return mid;
    else if(val<arr[mid])
        high = mid;
    else
        low = mid;
    return recursionSearch(arr,low,high,val);
}

//递归实现
int binarySearch2(int *arr,int len,int val)
{
    int low = 0;
    int high = len;
    return recursionSearch(arr,low,high,val);
}

//插值查找
int binarySearch3(int *arr,int len,int val)
{
    if(val>arr[len-1] || val<arr[0])
        return ERROR;

    int low = 0;
    int high = len-1;
    int mid;
    while(low<high)
    {
        mid = low + (high-low)*(val-arr[low])/(arr[high]-arr[low]);
        printf("mid is :%d\n",mid);
        //break;
        if(val==arr[mid])
            return mid;
        else if(val<arr[mid])
            high = mid-1;
        else
            low = mid+1;
    }
    return ERROR;
}

int fibnacci(int pos)
{   //0 1 1 2 3 5 8 13 21
    if(1==pos)
        return 0;
    else if(2==pos)
        return 1;
    else
        return fibnacci(pos-1)+fibnacci(pos-2);
}

//fibnacci search
int fibSearch(int *arr,int len,int val)
{
    int low,high,mid,i,k;
    low = 0;
    high = len-1;
    k = 1;
    while(len>fibnacci(k)-1)
    {
        k++;
    }

    int temp[fibnacci(k)];
    for(i=0;i<len;i++)
    {
        temp[i] = arr[i];
    }
    for(i=len;i<fibnacci(k)-1;i++)
        temp[i] = arr[len-1];

    while(low<=high)
    {
        mid = low + fibnacci(k-1) -1;
        if(val<temp[mid])
        {
            high = mid - 1;
            k = k-1;
        }else if(val>temp[mid])
        {
            low = mid + 1;
            k = k -2;
        }else
        {
            if(mid<len)
                return mid;
            else
                return len;
        }


    }
    return ERROR;
}

int main()
{
    int len = 10;
    int arr[10] = {11,22,33,44,55,66,77,88,99,100};
    int val;

    scanf("%d",&val);

    //int res = binarySearch1(arr,len,val);
    //int res = binarySearch2(arr,len,val);
    //int res = binarySearch3(arr,len,val);
    int res = fibSearch(arr,len,val);

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

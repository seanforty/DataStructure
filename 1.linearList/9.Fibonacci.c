/*
 +----------------------------------------------------------------------+
 | 斐波那契数列的迭代和递归方法实现                                     |
 +----------------------------------------------------------------------+
 | Author: Sean  <seanforty@qq.com>                                     |
 +----------------------------------------------------------------------+
 */

#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define ERROR -1
#define OK 1

//0 1 1 2 3 5 8 13 21 ...
int Fib1(int len)
{
    int a = 0, b = 1;
    if(1==len)
    {
        printf("%d\n",a);
    }else if(2==len)
    {
        printf("%d\n",a);
        printf("%d\n",b);
    }else
    {
        int t,i = 0;
        for(;i<len-2;i++)
        {
            t = a + b;
            a = b;
            b = t;
            printf("%d\n",t);
        }
    }
    return OK;
}

int Fib2(int len)
{
    if(1==len)
    {
        return 0;
    }else if(2==len)
    {
        return 1;
    }else
    {
        return Fib2(len-1) + Fib2(len-2);
    }
}

int main()
{
    //Fib1(40);

    int i = 1;
    for(;i<40;i++)
    {
        printf("%d\n",Fib2(i));
    }

    return 0;
}














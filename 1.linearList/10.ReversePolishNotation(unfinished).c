/*
 +----------------------------------------------------------------------+
 | 后缀表达式       |
 +----------------------------------------------------------------------+
 | Author: Sean  <seanforty@qq.com>                                     |
 +----------------------------------------------------------------------+
 */

#include <stdio.h>
#include "10.linkedStackForRPN.c"

#define MAXSIZE 20
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR -1




int main()
{
    char arr[100] = {'9','3','1','-','3','*','+','10','2','/','+'};

    //声明栈，并将栈顶指针设置为NULL
    STACK S;
    S.length = 0;
    S.top = NULL;



    push(&S,'9');

    stackShow(&S);

    return 0;
}

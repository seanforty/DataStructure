/*
 +----------------------------------------------------------------------+
 | ��׺���ʽ       |
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

    //����ջ������ջ��ָ������ΪNULL
    STACK S;
    S.length = 0;
    S.top = NULL;



    push(&S,'9');

    stackShow(&S);

    return 0;
}

/*************************************************************************
    > File Name: main.c
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年07月06日 星期一 00时22分02秒
 ************************************************************************/

#include <stdio.h>
#include "queue.h"
int main(void) {
    piQueue Q = iQueueInit(3);
    iEnqueue(Q, 5);
    iEnqueue(Q, 34);
    printf("%d\n", iDequeue(Q));
    iEnqueue(Q, 1115);
    printf("%d\n", iDequeue(Q));
    printf("%d\n", iDequeue(Q));
    printf("%d\n", iDequeue(Q));
    return(0);
}

/*************************************************************************
    > File Name: main.c
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年07月05日 星期日 22时18分28秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include "graph.h"
#include "../commom/common.h"

int giGraphNodeNum = 10;
int main(void) {
    int a[2] = {0xf001,2 };
    PrintArray_int(a, 2);
    memset(a, 0, sizeof(int)*2);
    PrintArray_int(a, 2);
    return 0;

}

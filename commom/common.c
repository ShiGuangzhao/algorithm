/*************************************************************************
    > File Name: common.c
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年07月05日 星期日 22时23分14秒
 ************************************************************************/

#include <stdio.h>
void PrintArray_int(int A[], int N, int line = 20) {
    int iii = 0;
    for(iii = 0; iii < line; iii++){
        printf("-");
    }
    printf("\n");
    for(iii = 0; iii < N; iii++) {
        printf("%d\t", A[iii]);
    }
    printf("\n");
    for(iii = 0; iii < line; iii++){
        printf("-");
    }
    printf("\n");
}

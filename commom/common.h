/*************************************************************************
    > File Name: common.h
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年07月05日 星期日 22时25分38秒
 ************************************************************************/

#ifndef _COMMON_H_C
#define _COMMON_H_C
#include <stdlib.h>
#include <string.h>

#define SET_ARRAY0_INT(__array__, __num__) \
    memset((__array__), 0, sizeof(int)* (__num__));

#define PRINT_ERROR_EXIT(__str__) \
    printf("ERROR--FILE: %s, LINE: %d, %s\n", __FILE__, __LINE__, __str__);   \
    exit(-1);

#define PRINT_WARRING(__str__) \
    printf("WARRING--FILE: %s, LINE: %d, %s\n", __FILE__, __LINE__, __str__);

#define LOOP_ADD(__iii__, __begin__, __end__) \
    for(int __iii__ = __begin__; __iii__ < __end__; __iii__++)

#define LOOP_ADD_Inited(__iii__, __begin__, __end__) \
    for(__iii__ = __begin__; __iii__ < __end__; __iii__++)


void PrintArray_int(int A[], int N, int line);

#endif /* COMMON_H_C */

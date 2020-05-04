/*************************************************************************
    > File Name: main.c
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年05月03日 星期日 23时02分19秒
 ************************************************************************/

#include <stdio.h>
#include "separate_chaining.h"

int main() {
    pHashTable temp = InitializeTable(12);
    Insert("123", temp);
    Insert("13", temp);
    Insert("12", temp);
    Insert("23", temp);
    pListNode t;
    if((t = Find("23", temp)) == NULL) {
        printf("NULL\n");
    }
    else {
        printf("结果为%s\n", t->value);
    }
    Delete("23", temp);
    if((t = Find("23", temp)) == NULL) {
        printf("NULL\n");
    }
    else {
        printf("结果为%s\n", t->value);
    }
    Destory(temp);
    return 0;
}

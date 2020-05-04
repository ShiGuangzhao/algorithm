/*************************************************************************
    > File Name: hash.c
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年05月03日 星期日 17时05分26秒
 ************************************************************************/

#include <stdio.h>
int Hash(const char *key, int TableSize) {
    unsigned int HashVal = 0;
    while(*key != '\0')
        HashVal = (HashVal << 5) + *key++;
    return HashVal % TableSize;
}

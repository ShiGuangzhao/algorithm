/*************************************************************************
    > File Name: main.c
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年05月03日 星期日 23时02分19秒
 ************************************************************************/

#include <stdio.h>
#include "open_adressing.h"

int main() {
    pHashTable temp = InitializeTable(111);
    Insert("123", temp);
    Insert("13", temp);
    Insert("12", temp);
    Insert("23", temp);
    Index t = 0;
    t = Find("12", temp);
    if(temp->table[t].state == Deleted) {
        printf("删除\n");
    }
    else if(temp->table[t].state == Used) {
        printf("结果为%s\n", temp->table[t].value);
    }
    else {
        printf("empty\n");
    }
    Delete("12", temp);
    t = Find("12", temp);
    if(temp->table[t].state == Deleted) {
        printf("删除\n");
    }
    else if(temp->table[t].state == Used) {
        printf("结果为%s\n", temp->table[t].value);
    }
    else {
        printf("empty\n");
    }
    Destory(temp);
    return 0;
}

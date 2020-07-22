/*************************************************************************
    > File Name: randomized.c
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年07月21日 星期二 22时01分10秒
 ************************************************************************/

#include <stdio.h>
#define A 48271L
#define M 2147483647L
#define Q (M / A)
#define R (M % A)

static int giSeed = 1;

// 使用种子初始化随机数
void RandInit(int seed) {
    giSeed = seed;
}

// 生成随机数
int Random(void) {
    giSeed = A*(giSeed % Q) - R * giSeed / Q;
    if(giSeed < 0) {
        giSeed += M;
    }
    return giSeed;
}



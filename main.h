/*************************************************************************
    > File Name: main.h
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2019年08月19日 星期一 17时08分10秒
 ************************************************************************/

#ifndef _MAIN_H_C
#define _MAIN_H_C
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
// 从小到大插入排序
void insert_sorting (int str[], int length);
// 从小到大归并排序
void merge_sorting(int str[], int length);
// 二分查找，数组str已经从小到大排序
bool binary_search_sorted(int str[], int length, int number);
// 二分查找，数组str未排序
bool binary_search(int str[], int length, int number);
// 普通乘方
double power(double number, int power);
// 二分法乘方
double binary_power(double number, int power);
// 测试乘方函数
void test_power(void);
// 测试求斐波那契数列函数
void test_feibol(void);
// 测试排序函数
void test_sort(void);
// 初始化随机数产生函数
void rand_init(void);
// 测试查找函数
void test_find_k(void);
#endif /* MAIN_H_C */

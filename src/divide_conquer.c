/*************************************************************************
    > File Name: divide_conquer.c
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2019年08月19日 星期一 17时10分58秒
 ************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

extern void swap (int *a, int *b);
extern void merge(int str[], int length);

/* ********
 * 二分查找
 * ****/
// 二分查找，数组str已经从小到大排序
bool binary_search_sorted(int str[], int length, int number)
{
    if(length > 1) {
        if(str[length/2] > number)
             return binary_search_sorted(str, length/2, number);
        else if(str[length/2] < number)
            return  binary_search_sorted(str + length/2, \
                    length - length/2, number);
        else
            return true;
    }
    else {
        if(str[0] == number)
            return true;
        else
            return false;
    }
}

// 二分查找，数组str未排序
bool binary_search(int str[], int length, int number)
{
    int sorted_str[length];
    for(int i = 0; i < length; i++)
        sorted_str[i] = str[i];
    return binary_search_sorted(sorted_str, length, number);
}

/* *******
 * 乘方
 * *****/
// 普通乘方
double power(double number, int power)
{
    double result = number;
    for(int i = 1; i < power; i++)
        result *= number;
    return result;
}

// 二分法乘方
double binary_power(double number, int power)
{
    if(power > 1) {
        double next_ret = binary_power(number, power/2);
        if(0 == power%2)
            return next_ret*next_ret;
        else
            return next_ret*next_ret*number;
    }
    else
        return number;
}

// 测试乘方函数
void test_power(void)
{
    double number = 0;
    int pow = 0;
    double result;
    double start_time = 0, end_time = 0;
    printf("底数：");
    scanf("%lf", &number);
    printf("乘方数：");
    scanf("%d", &pow);

    start_time = clock();
    result = power(number, pow);
    end_time = clock();
    printf("传统方法结果为%f^%d=%f，时间为%f\n", \
            number, pow, result, end_time-start_time);

    start_time = clock();
    result = binary_power(number, pow);
    end_time = clock();
    printf("二分方法结果为%f^%d=%f，时间为%f\n", \
            number, pow, result, end_time-start_time);
}

/* ************
 * 斐波那契数列求值
 * ******/
// 递归树
double feibol_nn(int n)
{
    if(n > 1)
        return feibol_nn(n - 1) + feibol_nn(n - 2);
    else if(n == 1)
        return 1;
    else if(n == 0)
        return 0;
    else {
        printf("FILE:%s LINE:%d 请检查斐波那契函数输入是否合法", \
                __FILE__, __LINE__);
        return -1;
    }
}

// 顺序求值
double feibol_n(int n)
{
    double feibol[n + 1];
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else if(n > 1) {
        feibol[0] = 0;
        feibol[1] = 1;
        for(int i = 2; i <= n; i++) {
            feibol[i] = feibol[i - 1] + feibol[i - 2];
        }
        return feibol[n];
    }
    else {
        printf("FILE:%s LINE:%d 请检查斐波那契函数输入是否合法", \
                __FILE__, __LINE__);
        return -1;
    }
}

struct matrix22 {
    double a00;
    double a01;
    double a10;
    double a11;
};

const struct matrix22 matrix22_base = {1, 1, 1, 0};

// 计算2x2矩阵乘积 M1 X M2
struct matrix22 matrix22_mutil(struct matrix22 M1, struct matrix22 M2)
{
    struct matrix22 RET;
    RET.a00 = M1.a00 * M2.a00 + M1.a01 * M2.a10;
    RET.a01 = M1.a00 * M2.a01 + M1.a01 * M2.a11;
    RET.a10 = M1.a10 * M2.a00 + M1.a11 * M2.a10;
    RET.a11 = M1.a10 * M2.a01 + M1.a11 * M2.a11;
    return RET;    
}

struct matrix22 math_loop(int n)
{
    if(n == 0) {
        struct matrix22 RET = {0, 0, 0, 0};
        return RET;
    }
    else if(n == 1) {
        return matrix22_base;
    }
    else {
        struct matrix22 temp = math_loop(n/2);
        struct matrix22 RET = matrix22_mutil(temp, temp);
        if(n%2 == 0)
            return RET;
        else
            return matrix22_mutil(RET, matrix22_base);        
    }
}

// 分治法
double feibol_math(int n)
{
    if(n >= 0) {
        return math_loop(n).a10;
    }
    else {
        printf("FILE:%s LINE:%d 请检查斐波那契函数输入是否合法", \
                __FILE__, __LINE__);
        return -1;
    }
}

// 测试求斐波那契数列函数
void test_feibol(void)
{
    int pow = 0;
    double result = 0;
    double start_time = 0, end_time = 0;
    printf("n=");
    scanf("%d", &pow);

    start_time = clock();
    /* result = feibol_nn(pow); */
    end_time = clock();
    printf("递归树方法结果为F[%d]=%lf，时间为%f\n", \
            pow, result, end_time-start_time);

    start_time = clock();
    result = feibol_n(pow);
    end_time = clock();
    printf("直接计算方法结果为F[%d]=%lf，时间为%f\n", \
            pow, result, end_time-start_time);

    start_time = clock();
    result = feibol_math(pow);
    end_time = clock();
    printf("分治法结果为F[%d]=%lf，时间为%f\n", \
            pow, result, end_time-start_time);

}

// 在数列中找第k小的数--使用归并排序
int find_kmax_by_sorting(int str[], int length, int k)
{
    if(k > length || k < 1) {
        printf("FILE:%s: LINE:%d 运行出现错误,查询索引超出范围\n", \
                __FILE__, __LINE__);
        return 0;
    }

    merge(str, length);
    return str[k - 1]; 
}

// 在数列中找第k小的数--使用随机分治算法
int find_kmax_random(int str[], int length, int k)
{
    if(k > length || k < 1) {
        printf("FILE:%s: LINE:%d 运行出现错误,查询索引超出范围\n", \
                __FILE__, __LINE__);
        return 0;
    }

    if(length > 2) {
        int main_at = length - 1;
        int bigger_begin_at = 0;
        int i = 0;

        swap(&str[rand() % length], &str[length - 1]);

        // 找到边界
        for(i = 0; i < length; i++) {
            if(str[i] <= str[main_at])
                bigger_begin_at++;
            else
                break;
        }

        // 大小不对则交换并找到边界
        for(; i < length; i++) {
            if(str[i] <= str[main_at]) {
                swap(&str[i], &str[bigger_begin_at]);
                bigger_begin_at++;
            }
        }

        // 递归
        // bigger_begin_at 是大于主元的数开始的位置
        // 即主元位于第几个
        if(bigger_begin_at == k)
            return str[bigger_begin_at - 1];
        else if(k < bigger_begin_at)
            return find_kmax_random(str, bigger_begin_at - 1, k);
        else
            return find_kmax_random(str + bigger_begin_at, \
                    length - bigger_begin_at, k - bigger_begin_at);
    }
    else if(length == 2) {
        if(k == 1) {
            if(str[0] > str[1])
                return str[1];
            else 
                return str[0];
        }
        else {
            if(str[0] > str[1])
                return str[0];
            else 
                return str[1];
        }

    }
    else
        return str[0];
}

// 测试查找函数
void test_find_k(void)
{
    int length, range;
    printf("数组长度：");
    scanf("%d", &length);
    printf("数组最大值：");
    scanf("%d", &range);
    int str1[length];
    int str2[length];
    double begin, end;
    for(int i = 0; i < length; i++) {
        str1[i] = rand() % range;
        str2[i] = str1[i];
    }
    printf("\n");
    int k = 0;
    int result = 0;
    printf("请输入查找索引，输入0结束查找：");
    scanf("%d", &k);
    while(k != 0) {
        for(int i = 0; i < length; i++) {
            printf("%d\t", str1[i]);
        }
        printf("\n");
        begin = clock();
            result = find_kmax_by_sorting(str1, length, k);
        end = clock();
        printf("排序查找时间为%lf，查找结果为%d\n", \
                end - begin, result);
        begin = clock();
            result = find_kmax_random(str2, length, k);
        end = clock();
        printf("随机分治时间为%lf，查找结果为%d\n", \
                end - begin, result);
        printf("请输入查找索引，输入0结束查找：");
        scanf("%d", &k);
    }

    for(int i = 0; i < length; i++)
        printf("%d\t", str1[i]);
    printf("\n");
}

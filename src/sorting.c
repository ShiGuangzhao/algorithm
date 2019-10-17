/*************************************************************************
    > File Name: sorting.c
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2019年08月11日 星期日 17时02分43秒
 ************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

extern double power(double number, int power);

/* *******
 * 排序算法
 * ***/

// 初始化随机数产生函数
void rand_init(void)
{
    static int rand_inited = 0;
    if(rand_inited == 0) {
        srand(time(NULL));
        rand_inited = 1;
    }
}

void swap (int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

// 从小到大插入排序
void insert_sorting (int str[], int length)
{
    printf("从小到大插入排序\n");
    for(int i = 0; i < length; i++) {
        printf("%d\t", str[i]);
    }
    printf("\n");
    for(int i = 1; i < length; i++) {
        for(int j = i; j > 0; j--) {
            if(str[j-1] > str[j]) {
                swap(&str[j-1], &str[j]);
            }
        }
    }
    for(int i = 0; i < length; i++) {
        printf("%d\t", str[i]);
    }
    printf("\n");
}

void merge(int str[], int length)
{
    /* for(int i = 0; i < length; i++) { */
        /* printf("%d\t", str[i]); */
    /* } */
    /* printf("\n"); */
    if(length > 1) {
        int sizeX = length/2;
        int sizeY = length - length/2;
        int strX[sizeX];
        int strY[sizeY];
        // 将数组分为两部分
        for(int i = 0; i < sizeX; i++) {
            strX[i] = str[i];
        }
        for(int i = 0; i < sizeY; i++) {
            strY[i] = str[i + sizeX];
        }
        // 排序
        merge(strX, sizeX);
        merge(strY, sizeY);
        // 合并
        int x = 0;
        int y = 0;
        int i = 0;
        while(x < sizeX && y < sizeY) {
            if(strX[x] < strY[y])
                str[i] = strX[x++];
            else
                str[i] = strY[y++];
            i++;
        }
        // 比较剩下的项加入到总队列中
        if(y == sizeY)
            for(;x < sizeX; x++) {
                str[i] = strX[x];
                i++;
            }
        else
            for(;y < sizeY; y++) {
                str[i] = strY[y];
                i++;
            }
    }
}

// 从小到大归并排序
void merge_sorting(int str[], int length)
{
    printf("从小到大归并排序\n");
    for(int i = 0; i < length; i++) {
        printf("%d\t", str[i]);
    }
    printf("\n");
    merge(str, length);
    for(int i = 0; i < length; i++) {
        printf("%d\t", str[i]);
    }
    printf("\n");

}

// 从小到大快速排序
void quick_sorting(int str[], int length)
{
    if(length > 2) {
        int main_at = length - 1;
        int bigger_begin_at = 0;
        int i = 0;

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
        if(bigger_begin_at == 1)
            quick_sorting(str + 1, length - 1);
        else if(bigger_begin_at == length)
            quick_sorting(str, length - 1);
        else {
            quick_sorting(str, bigger_begin_at - 1);
            quick_sorting(str + bigger_begin_at, \
                    length - bigger_begin_at);
        }
    }
    else if(length == 2) {
        if(str[1] < str[0])
            swap(&str[1], &str[0]);
    }
}

// 随机快速排序
void quick_sorting_random(int str[], int length)
{
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
        if(bigger_begin_at == 1)
            quick_sorting_random(str + 1, length - 1);
        else if(bigger_begin_at == length)
            quick_sorting_random(str, length - 1);
        else {
            quick_sorting_random(str, bigger_begin_at - 1);
            quick_sorting_random(str + bigger_begin_at, \
                    length - bigger_begin_at);
        }
    }
    else if(length == 2) {
        if(str[1] < str[0])
            swap(&str[1], &str[0]);
    }
}

// 从小到大计数排序
void count_sorting(int A[], int n, int k)
{
    int B[n], C[k];
    int i = 0;
    for(i = 0; i < k; i++)
        C[i] = 0;
    for(i = 0; i < n; i++)
        B[i] = 0;
    // 计数各个数字
    for(i = 0; i < n; i++)
        C[A[i]]++;
    // 阶梯相加
    for(i = 1; i < k; i++)
        C[i] += C[i - 1];
    // 排序
    for(i = n - 1; i >= 0; i--) {
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }
    for(i = 0; i < n; i++)
        A[i] = B[i];
}

struct base_struct {
    int base;
    int data;
};

// 获取最大数的位数
int get_highbit(int str[], int length)
{
    int biggest = str[0];
    for(int i = 1; i < length; i++) {
        if(str[i] > biggest)
            biggest = str[i];
    }
    for(int j = 0; j < (int)sizeof(int)*8; j++) {
        if(biggest < (int)power(2, (float)j))
            return j;
    }
    return 0;
}

// 基数排序子函数计数排序
void count_sorting_forbase(struct base_struct A[], int n, int k)
{
    int B[n], C[k];
    int i = 0;
    for(i = 0; i < k; i++)
        C[i] = 0;
    for(i = 0; i < n; i++)
        B[i] = 0;
    // 计数各个数字
    for(i = 0; i < n; i++)
        C[A[i].base]++;
    // 阶梯相加
    for(i = 1; i < k; i++)
        C[i] += C[i - 1];
    // 排序
    for(i = n - 1; i >= 0; i--) {
        B[C[A[i].base] - 1] = A[i].data;
        C[A[i].base]--;
    }
    for(i = 0; i < n; i++)
        A[i].data = B[i];
}

// 从小到大基数排序
// 为简化，此处仅考虑正整数
// 不计算最佳r，直接设为4
void rodix_sorting(int str[], int length)
{
    int highbit = get_highbit(str, length);
    /* int r = (int)(log(highbit)/log(2)); */
    struct base_struct str_struct[length];
    // 将数据输入结构体中
    for(int i = 0; i < length; i++)
        str_struct[i].data = str[i];
    // 开始循环
    for(int begin_bit = 0; begin_bit < highbit; begin_bit += 4) {
        // 赋基数值
        for(int j = 0; j < length; j++) {
            str_struct[j].base = ((str_struct[j].data >> begin_bit) \
                    & 0x000f);
        }
        // 计数排序
        count_sorting_forbase(str_struct, length, 0x0010);
    }
    // 从结构体中提取数据
    for(int i = 0; i < length; i++)
        str[i] = str_struct[i].data;
}

// 测试排序函数
void test_sort(void)
{
    // 使用随机快速排序前必须调用此函数
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
        str2[i] = rand() % range;
        printf("%d\t", str1[i]);
    }
    printf("\n");
    /* rodix_sorting(str1, length); */
    begin = clock();
    quick_sorting_random(str1, length);
    end = clock();
    printf("快速排序时间为%lf\n", end - begin);
    begin = clock();
    quick_sorting(str2, length);
    end = clock();
    printf("随机快速排序时间为%lf\n", end - begin);
    for(int i = 0; i < length; i++)
        printf("%d\t", str1[i]);
    printf("\n");
}


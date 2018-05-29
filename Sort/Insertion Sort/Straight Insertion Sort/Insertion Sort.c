//Insertion Sort
//直接插入排序
//Version 1.1 20180529
//2018-05-29 14:04:35
//CopyRight ©2018 CuiShuo. All rights reserved.

#include <stdio.h>
#include <time.h>

int main() {
    int length, t, j;
    double duration;
    clock_t start, finish;
    int a[] = {49,38,65,97,76,13,27,49};

    length = sizeof(a)/4;

    start = clock();
    for (int i = 1; i < length; ++i) {
        if (a[i] < a[i-1]) {                //前面的元素比后面大
            t = a[i];

            for (j = i-1; a[j] > t && t >= 0; --j) {  //t>=0 防止下标越界
                a[j+1] = a[j];              //向后移
            }                               //直到找到没有比比较项大的就退出当前循环
            a[j+1] = t;
        }
    }
    finish = clock();
    duration = (double)(finish-start);

    printf("排序结果:");
    for (int k = 0; k < length; ++k) {
        printf("%d ", a[k]);
    }
    printf("\n");

    printf("直接插入排序所需时间: %lf", duration/CLOCKS_PER_SEC);

    return 0;
}
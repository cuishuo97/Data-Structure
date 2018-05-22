//Selection Sort
//简单选择排序
//Version 1.0 20180522
//2018-05-22 16:57:40
//CopyRight ©2018 CuiShuo. All rights reserved.

#include <stdio.h>
#include <time.h>

int main() {
    int length, t, min;
    double duration;
    clock_t start, finish;
    int a[] = {49,38,65,97,76,13,27,49};

    length = sizeof(a)/4;

    start = clock();
    for (int i = 0; i < length-1; ++i) {
        min = i;
        for (int j = i+1; j < length; ++j) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        if (min != i) {
            t = a[min];
            a[min] = a[i];
            a[i] = t;
        }
    }
    finish = clock();
    duration = (double)(finish-start);

    printf("排序结果:");
    for (int k = 0; k < length; ++k) {
        printf("%d ", a[k]);
    }
    printf("\n");

    printf("选择排序所需时间: %lf", duration/CLOCKS_PER_SEC);

    return 0;
}
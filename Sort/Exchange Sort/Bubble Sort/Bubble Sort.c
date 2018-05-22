//Bubble Sort
//冒泡排序
//Version 1.0 20180522
//2018-05-22 15:42:47
//CopyRight ©2018 CuiShuo. All rights reserved.

#include <stdio.h>
#include <time.h>

int main() {
    int length, t, flag = 1;
    double duration;
    clock_t start, finish;
    int a[] = {49,38,65,97,76,13,27,49};

    length = sizeof(a)/4;

    start = clock();
    for (int i = 0; i < length - 1 && flag == 1; ++i) {
        flag = 0;
        for (int j = 0; j < length - 1 - i; ++j) {
            if (a[j] > a[j+1]) {
                flag = 1;
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
        /*printf("第%d次排序后:", i+1);
        for (int k = 0; k < length; ++k) {
            printf("%d ", a[k]);
        }
        printf("\n");*/
    }
    finish = clock();
    duration = (double)(finish-start);

    printf("排序结果:");
    for (int k = 0; k < length; ++k) {
        printf("%d ", a[k]);
    }
    printf("\n");

    printf("冒泡排序所需时间: %lf", duration/CLOCKS_PER_SEC);
    
    return 0;
}
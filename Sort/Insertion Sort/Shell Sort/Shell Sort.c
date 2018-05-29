//Shell's Sort
//希尔排序
//Version 1.0 20180529
//2018-05-29 15:48:55
//CopyRight ©2018 CuiShuo. All rights reserved.

#include <stdio.h>
#include <time.h>

int main() {
    int length, t, j;
    int d;
    double duration;
    clock_t start, finish;
    int a[] = {49,38,65,97,76,13,27,49};

    length = sizeof(a)/4;
    d = length;

    start = clock();
    do {
        d = d/2;
        for (int i = d; i < length; ++i) {
            if (a[i] < a[i-d]) {                //前面的元素比后面大
                t = a[i];

                for (j = i-d; a[j] > t && t >= 0; j = j-d) {  //t>=0 防止下标越界
                    a[j+d] = a[j];              //向后移
                }
                a[j+d] = t;
            }
        }
    }while ( d>= 1);
    finish = clock();
    duration = (double)(finish-start);

    printf("排序结果:");
    for (int k = 0; k < length; ++k) {
        printf("%d ", a[k]);
    }
    printf("\n");

    printf("希尔排序所需时间: %lf", duration/CLOCKS_PER_SEC);

    return 0;
}
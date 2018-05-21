//Binary Search
//Version 1.0 20180424
//2018-04-24 22:14:23
//CopyRight ©2018 CuiShuo. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
//使用前提必须是顺序表有序存储
int list_binarysearch(int *a, int len, int val);           //折半查找
int list_binarysearch_rec(int *a, int low, int high, int val);       //折半查找（递归）

int main() {
    int n;
    int *a;
    printf("请输入数组长度:");
    scanf("%d", &n);
    a = (int *)malloc(sizeof(int) * n);

    printf("\n");

    for (int i = 0; i < n; ++i) {
        printf("请输入第%d个数据:", i+1);
        scanf("%d", &*(a+i));
        printf("\n");
    }

    /*for (int i = 0; i < n; ++i) {
        printf("%d ", *(a+i));
    }*/

    printf("%d\n", list_binarysearch(a, n, 5));
    printf("%d\n", list_binarysearch_rec(a, 0, n-1, 5));     //递归法

    return 0;
}

int list_binarysearch(int *a, int len, int val) {
    int low = 0, high = len - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (*(a+mid) == val) {
            return mid+1;
        }
        else if (*(a+mid) > val) {
            high = mid - 1;
        }
        else  {
            low = mid + 1;
        }
    }
    return -1;
}

int list_binarysearch_rec(int *a, int low, int high, int val) {
    int mid = (low+high)/2;

    if (*(a+mid) == val) {
        return mid+1;
    }
    else if (*(a+mid) > val) {
        return list_binarysearch_rec(a, low, mid-1, val);
    }
    else {
        return list_binarysearch_rec(a, mid+1, high, val);
    }
}
//Array Management Tool
//Version 1.0 20180221
//2018-02-21 19:09:43
//CopyRight ©2018 CuiShuo. All rights reserved.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Array {
    int * pBase;       //存储数组第一个元素的地址
    int len;           //数组所能容纳的最大元素的个数
    int cnt;           //当前数组有效元素的个数
    //int increment;   //自动增长因子
};

void arr_init(struct Array *pArr, int length);               //初始化
bool arr_add(struct Array *pArr, int val);                   //在尾部追加
bool arr_add_range(struct Array *pArr, int a, int b);        //在尾部追加一定序列的整数(Beta)
bool arr_insert(struct Array *pArr, int pos, int val);       //插入（pos的值从1开始）
bool arr_remove(struct Array *pArr, int pos);                //删除
bool arr_removeall(struct Array *pArr);                      //删除全部元素
void arr_sort(struct Array *pArr);                           //从小到大排序
void arr_reverse(struct Array *pArr);                        //倒序
void arr_show(struct Array *pArr);                           //
void arr_sum(struct Array *pArr);                            //求和
void arr_avg(struct Array *pArr);                            //求平均数
void arr_slice(struct Array *pArr, int a, int b);            //切片(Beta)
bool arr_find(struct Array *pArr, int search);               //遍历数组
bool is_empty(struct Array *pArr);
bool is_full(struct Array *pArr);

int main() {
    int arr_num;
    struct Array arr;

    printf("请输入需要新建的数组个数:");
    scanf("%d", &arr_num);

    arr_init(&arr, arr_num);
    arr_show(&arr);

    arr_add(&arr, 1);
    arr_add(&arr, 2);
    arr_add(&arr, 3);
    arr_add(&arr, 4);
    arr_add(&arr, 5);
    
    arr_reverse(&arr);
    arr_show(&arr);

    arr_sort(&arr);
    arr_show(&arr);

    arr_find(&arr, 4);
    arr_sum(&arr);
    arr_avg(&arr);

    arr_add_range(&arr,1,20);
    arr_show(&arr);
    printf("%d %d", arr.len, arr.cnt);
    return 0;
}

void arr_init(struct Array *pArr, int length) {
    pArr->pBase = (int *)malloc(sizeof(int) * length);

    if (NULL == pArr->pBase) {
        printf("memory allocate failed.\n");    //动态内存分配失败
        exit(-1);
    }
    else {
        pArr->len = length;
        pArr->cnt = 0;
    }
}

bool arr_add(struct Array *pArr, int val) {
    if (is_full(pArr)) {
        pArr->pBase = (int *)realloc(pArr->pBase, sizeof(int) * pArr->len+1);    //动态扩大内存
        pArr->pBase[pArr->cnt] = val;
        (pArr->len)++;
        (pArr->cnt)++;
        return true;
    }

    pArr->pBase[pArr->cnt] = val;
    (pArr->cnt)++;
    return true;

}

bool arr_add_range(struct Array *pArr, int a, int b) {     //Beta
    for (int i = a; i < b; ++i) {
        pArr->pBase = (int *)realloc(pArr->pBase, sizeof(int) * pArr->len+1);    //动态扩大内存
        pArr->pBase[pArr->cnt] = i;
        (pArr->len)++;
        (pArr->cnt)++;
    }
    return true;
}

bool arr_insert(struct Array *pArr, int pos, int val) {
    if (is_full(pArr)) {
        //pArr->pBase = (int *)realloc(pArr->pBase, sizeof(int) * pArr->len+1);    //动态扩大内存
        printf("insert failed\n");
        return false;
    }
    if (pos<1 || pos>pArr->cnt+1) {
        printf("insert failed\n");
        return false;
    }
    for (int i = pArr->cnt-1; i >= pos-1; --i) {
        pArr->pBase[i+1] = pArr->pBase[i];
    }
    pArr->pBase[pos-1] = val;
    (pArr->cnt)++;
    printf("insert successfully\n");
    return true;
}

bool arr_remove(struct Array *pArr, int pos) {
    if (is_empty(pArr)) {
        printf("remove failed\n");
        return false;
    }
    if (pos < 1 || pos > pArr->cnt) {
        printf("remove failed\n");
        return false;
    }
    for (int i = pos; i < pArr->cnt; ++i) {
        pArr->pBase[i-1] = pArr->pBase[i];
    }
    pArr->cnt--;
    printf("remove successfully\n");
    return true;
}

bool arr_removeall(struct Array *pArr) {
    if (is_empty(pArr)) {
        printf("remove all array failed\n");
        return false;
    }

    for (int i = 0; i < pArr->cnt; ++i) {
            pArr->pBase[i] = 0;
        }
        pArr->cnt = 0;
        printf("remove all array successfully\n");
        return true;
}

void arr_sort(struct Array *pArr) {
    int i, j, t;

    for (i = 0; i < pArr->cnt; ++i) {
        for (j = i+1; j < pArr->cnt; ++j) {
            if (pArr->pBase[i] > pArr->pBase[j]) {
                t = pArr->pBase[i];
                pArr->pBase[i] = pArr->pBase[j];
                pArr->pBase[j] = t;
            }
        }
    }
}

void arr_reverse(struct Array *pArr) {
    int i = 0;
    int j = pArr->cnt-1;
    int t;

    while (i < j) {
        t = pArr->pBase[i];
        pArr->pBase[i] = pArr->pBase[j];
        pArr->pBase[j] = t;
        ++i;
        --j;
    }
}

void arr_show(struct Array *pArr) {
    if (is_empty(pArr)) {
        printf("array is empty\n");
    }
    else {
        for (int i = 0; i < pArr->cnt; ++i) {
            printf("%d  ", pArr->pBase[i]);
        }
        printf("\n");
    }
}

void arr_sum(struct Array *pArr) {
    int sum = 0;

    if (is_empty(pArr)) {
        printf("array is empty\n");
        return;
    }
    for (int i = 0; i < pArr->cnt; ++i) {
        sum = sum + pArr->pBase[i];
    }

    printf("sum is %d\n", sum);
}

void arr_avg(struct Array *pArr) {
    int sum = 0;
    float avg = 0;

    for (int i = 0; i < pArr->cnt; ++i) {
        sum = sum + pArr->pBase[i];
    }

    avg = sum/pArr->cnt;

    printf("average is %.2f\n", avg);
}

void arr_slice(struct Array *pArr, int a, int b) {    //Beta
    int cnt_new;
    if (is_empty(pArr)) {
        printf("array is empty\n");
        return;
    }
    if(a >= b || a < 0 || b <= 0) {
        printf("invalid argument\n");
        return;
    }
    if (b > pArr->cnt) {
        b = pArr->cnt;
    }
    cnt_new = b - a;
    pArr->cnt = cnt_new;
    //pArr->pBase = (int *)realloc(sizeof(int) * pArr->);
    pArr->pBase = & (pArr->pBase[a]);

}

bool arr_find(struct Array *pArr, int search) {
    int i;

    if (is_empty(pArr)) {
        printf("array is empty\n");
        return false;
    }

    for (i = 0; i < pArr->cnt; ++i) {
        if (search == pArr->pBase[i]) {
            break;
        }
    }
    if (i < pArr->cnt) {
        printf("your search content has be found. %d\n", i+1);
        return true;
    }

    printf("your search content has not be found. \n");
        return false;

}

bool is_empty(struct Array *pArr) {
    if (pArr->cnt == 0) {
        return true;
    }
    return false;
}

bool is_full(struct Array *pArr) {
    if (pArr->cnt == pArr->len) {
        return true;
    }
    return false;
}





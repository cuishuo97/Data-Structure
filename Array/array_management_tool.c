//Array Management Tool
//Version 1.0 20180221
//2018-02-21 20:51:56
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

void arr_init(struct Array *pArr, int length);               //数组初始化
bool arr_add(struct Array *pArr, int val);                   //在尾部追加
bool arr_add_range(struct Array *pArr, int a, int b);        //在尾部追加一定序列的整数(Beta)
bool arr_insert(struct Array *pArr, int pos, int val);       //插入（pos的值从1开始）
bool arr_remove(struct Array *pArr, int pos);                //删除指定元素
bool arr_removeall(struct Array *pArr);                      //删除全部元素
void arr_sort(struct Array *pArr);                           //从小到大排序
void arr_reverse(struct Array *pArr);                        //倒序
void arr_show(struct Array *pArr);                           //输出数组
void arr_sum(struct Array *pArr);                            //求和
void arr_avg(struct Array *pArr);                            //求平均数
void arr_slice(struct Array *pArr, int a, int b);            //切片(Beta)
bool arr_find(struct Array *pArr, int search);               //查找数组元素
bool is_empty(struct Array *pArr);                           //判断数组是否为空
bool is_full(struct Array *pArr);                            //判断数组是否已满

int main() {
    struct Array arr;
    int arr_num;

    printf("Please input the number of arrays you need to build:");
    scanf("%d", &arr_num);

    arr_init(&arr, arr_num);

    arr_add_range(&arr, 1, 6);

    arr_show(&arr);

    /*arr_add(&arr, 1);
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
    arr_avg(&arr);*/

    arr_add_range(&arr,6,21);
    arr_show(&arr);

    return 0;
}

//数组初始化
void arr_init(struct Array *pArr, int length) {
    pArr->pBase = (int *)malloc(sizeof(int) * length);

    if (NULL == pArr->pBase) {
        printf("emory allocate failed.\n");    //动态内存分配失败
        exit(-1);
    }
    else {
        pArr->len = length;
        pArr->cnt = 0;
    }
}

//在尾部追加
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

//在尾部追加一定序列的整数(Beta)
bool arr_add_range(struct Array *pArr, int a, int b) {
    for (int i = a; i < b; ++i) {
        pArr->pBase = (int *)realloc(pArr->pBase, sizeof(int) * pArr->len+1);    //动态扩大内存
        pArr->pBase[pArr->cnt] = i;
        (pArr->len)++;
        (pArr->cnt)++;
    }
    return true;
}

//插入（pos的值从1开始）
bool arr_insert(struct Array *pArr, int pos, int val) {
    if (is_full(pArr)) {
        //pArr->pBase = (int *)realloc(pArr->pBase, sizeof(int) * pArr->len+1);    //动态扩大内存
        printf("insert failed\n");
        return false;
    }
    if (pos<1 || pos>pArr->cnt+1) {
        printf("Invalid argument\n");
        return false;
    }
    for (int i = pArr->cnt-1; i >= pos-1; --i) {
        pArr->pBase[i+1] = pArr->pBase[i];
    }
    pArr->pBase[pos-1] = val;
    (pArr->cnt)++;
    printf("Insert successfully\n");
    return true;
}

//删除指定元素
bool arr_remove(struct Array *pArr, int pos) {
    if (is_empty(pArr)) {
        printf("Remove failed\n");
        return false;
    }
    if (pos < 1 || pos > pArr->cnt) {
        printf("Invalid argument\n");
        return false;
    }
    for (int i = pos; i < pArr->cnt; ++i) {
        pArr->pBase[i-1] = pArr->pBase[i];
    }
    pArr->cnt--;
    printf("Remove successfully\n");
    return true;
}

//删除全部元素
bool arr_removeall(struct Array *pArr) {
    if (is_empty(pArr)) {
        printf("Remove all array failed\n");
        return false;
    }

    for (int i = 0; i < pArr->cnt; ++i) {
            pArr->pBase[i] = 0;
        }
        pArr->cnt = 0;
        printf("Remove all array successfully\n");
        return true;
}

//从小到大排序
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

//倒序
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

//输出数组
void arr_show(struct Array *pArr) {
    if (is_empty(pArr)) {
        printf("Array is empty\n");
    }
    else {
        for (int i = 0; i < pArr->cnt; ++i) {
            printf("%d  ", pArr->pBase[i]);
        }
        printf("\n");
    }
}

//求和
void arr_sum(struct Array *pArr) {
    int sum = 0;

    if (is_empty(pArr)) {
        printf("array is empty\n");
        return;
    }
    for (int i = 0; i < pArr->cnt; ++i) {
        sum = sum + pArr->pBase[i];
    }

    printf("Sum is %d\n", sum);
}

//求平均数
void arr_avg(struct Array *pArr) {
    int sum = 0;
    float avg = 0;

    for (int i = 0; i < pArr->cnt; ++i) {
        sum = sum + pArr->pBase[i];
    }

    avg = sum/pArr->cnt;

    printf("Average is %.2f\n", avg);
}

//切片(Beta)
void arr_slice(struct Array *pArr, int a, int b) {    //Beta
    int cnt_new;
    if (is_empty(pArr)) {
        printf("Array is empty\n");
        return;
    }
    if(a >= b || a < 0 || b <= 0) {
        printf("Invalid argument\n");
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

//查找数组元素
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
        printf("Your search content has be found. %d\n", i+1);
        return true;
    }

    printf("Your search content has not be found. \n");
        return false;

}

//判断数组是否为空
bool is_empty(struct Array *pArr) {
    if (pArr->cnt == 0) {
        return true;
    }
    return false;
}

//判断数组是否已满
bool is_full(struct Array *pArr) {
    if (pArr->cnt == pArr->len) {
        return true;
    }
    return false;
}





//LinkList Traverse
//Version 1.0 20180222
//2018-02-22 15:43:40
//CopyRight ©2018 CuiShuo. All rights reserved.
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;               //数据域
    struct Node * pNext;    //指针域
}NODE, *PNODE;


PNODE list_create (void);
void list_traverse(PNODE pHead);


int main() {
    PNODE pHead = NULL;

    pHead = list_create();  //创建非循环单链表
    list_traverse(pHead);
    return 0;
}

PNODE list_create(void) {
    int len;   //存放有效节点个数
    int val;   //临时存放用户输入节点数据

    PNODE pHead = (PNODE) malloc(sizeof(NODE));  //分配不存放有效数据的头结点
    if (pHead == NULL) {
        printf("Memory allocate failed.\n");    //动态内存分配失败
        exit(-1);
    }

    PNODE pTail = pHead;  //指向头结点
    pTail->pNext = NULL;

    printf("Please input the number of linklist node you need to build:");
    scanf("%d", &len);

    printf("\n");

    for (int i = 0; i < len; ++i) {
        printf("Please input Node %d data:", i+1);
        scanf("%d", &val);

        PNODE pNew = (PNODE) malloc(sizeof(NODE));
        if (pNew == NULL) {
            printf("Memory allocate failed.\n");    //动态内存分配失败
            exit(-1);
        }

        pNew->data = val;
        pTail->pNext = pNew;
        pNew->pNext = NULL;
        pTail = pNew;
    }

    return pHead;
}

void list_traverse(PNODE pHead) {
    PNODE p = pHead->pNext;

    while (p != NULL) {
        printf("%d  ", p->data);
        p = p->pNext;
    }

    printf("\n");
    printf("Traverse complete\n");
}
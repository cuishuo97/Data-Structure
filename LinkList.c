//LinkList Management tool
//Version 2.0 20180331
//2018-03-31 22:10:52
//CopyRight ©2018 CuiShuo. All rights reserved.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;               //数据域
    struct Node * pNext;    //指针域
}NODE, *PNODE;

PNODE list_init (void);                              //单向链表初始化
void list_destory(PNODE pHead);                      //链表销毁(Beta)
bool list_remove(PNODE pHead, int pos);              //删除链表结点(pos的值从1~length)
void list_removevalue(PNODE pHead, int val);         //删除指定值的结点
void list_traverse(PNODE pHead);                     //遍历链表
void list_getElem(PNODE pHead, int pos);             //获取链表中第pos个结点的数据元素(pos的值从1~length)
void list_clear(PNODE pHead);                        //清空链表
void list_reverse(PNODE pHead);                      //链表反转
void list_merge(PNODE pHead_A, PNODE pHead_B);       //合并链表
void list_check(PNODE pHead);                        //查找重复结点并删除
bool list_insert(PNODE pHead, int pos, int val);     //插入链表元素(pos的值从1~length)
void list_headinsert(PNODE pHead, int val);          //头插
void list_tailinsert(PNODE pHead, int val);          //尾插
void list_sort(PNODE pHead);                         //链表升序排序
int list_length(PNODE pHead);                        //获取链表长度
void list_maximum(PNODE pHead);                      //求链表最大值
bool list_is_empty(PNODE pHead);                     //判断链表是否为空

int main() {
    PNODE pHead = NULL;

    pHead = list_init();  //创建非循环单向链表

    list_traverse(pHead);

    return 0;
}

//单向链表初始化
PNODE list_init(void) {
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

//链表销毁(Beta)
void list_destory(PNODE pHead) {
    PNODE p;

    if (pHead == NULL) {
        return;
    }

    while (pHead) {
        p = pHead->pNext;
        free(pHead);
        pHead = p;
    }
}

//删除链表元素
bool list_remove(PNODE pHead, int pos) {
    int i = 0;
    PNODE p = pHead;

    while (p->pNext != NULL && i<pos-1) {
        p = p->pNext;
        ++i;
    }
    if (i > pos-1 || p->pNext == NULL) {
        printf("Remove failed.\n");
        return false;
    }

    PNODE q = p->pNext;
    //删除p后面的结点
    p->pNext = p->pNext->pNext;
    free(q);
    q = NULL;

    printf("Remove complete.\n");
    return true;
}

void list_removevalue(PNODE pHead, int val) {
    PNODE p, q;
    p = pHead;

    while (p->pNext != NULL) {
        if (p->pNext->data == val) {
            q = p->pNext;
            p->pNext = q->pNext;

            p = p->pNext;

            free(q);
            q = NULL;
        }
        else {
            p = p->pNext;
        }
    }
}

//遍历链表
void list_traverse(PNODE pHead) {
    PNODE p = pHead->pNext;

    while (p != NULL) {
        printf("%d  ", p->data);
        p = p->pNext;
    }

    printf("\n");
    printf("Traverse complete.\n");
}

void list_getElem(PNODE pHead, int pos) {
    PNODE p = pHead;
    int i = 0;

    if (list_is_empty(pHead)) {
        printf("The linklist is empty.");
        return;
    }

    while (p->pNext != NULL && i<pos) {
        p = p->pNext;
        ++i;
    }

    if (i > pos || p->pNext == NULL) {
        printf("Search failed.\n");
        return;
    }

    printf("The node %d data is %d.\n", pos, p->data);

}

//清空链表
void list_clear(PNODE pHead) {

    if (pHead == NULL) {
        return;
    }

    PNODE p = pHead->pNext;
    PNODE q;

    while (p != NULL) {
        q = p->pNext;
        free(p);
        p = q;


        //pHead->pNext = q;

        //p = p->pNext;
    }
    pHead->pNext = NULL;
}

//链表翻转
void list_reverse(PNODE pHead) {
    PNODE p, q;

/*  (HuangJingHua)
    p = NULL;
    q = pHead->pNext;
    r = q->pNext;

    while (r != NULL) {
        q->pNext = p;
        p = q;
        q = r;
        r = r->pNext;
    }
    pHead = q;
*/

    p = pHead->pNext;
    pHead->pNext = NULL;
    while (p) {
        q = p->pNext;
        p->pNext = pHead->pNext;
        pHead->pNext = p;
        p = q;
    }
}

//合并链表
void list_merge(PNODE pHead_A, PNODE pHead_B) {
    PNODE p = pHead_A;

    while (p->pNext != NULL) {
        p = p->pNext;
    }

    p->pNext = pHead_B->pNext;
}

//查找重复结点并删除
void list_check(PNODE pHead) {
    PNODE p = pHead->pNext;
    PNODE q, r;

    while (p) {
        q = p;
        while (q->pNext) {
            if (q->pNext->data == p->data) {
                r = q->pNext;
                q->pNext = r->pNext;
                free(r);
            }
            else {
                q = q->pNext;
            }
        }
        p = p->pNext;
    }
}

//插入链表元素(pos的值从1开始)
bool list_insert(PNODE pHead, int pos, int val) {
    int i = 0;
    PNODE p = pHead;

    while (p != NULL && i<pos-1) {
        p = p->pNext;
        ++i;
    }
    if (i > pos-1 || p == NULL) {
        return false;
    }

    PNODE pNew = (PNODE)malloc(sizeof(NODE));

    if (pNew == NULL) {
        printf("Memory allocate failed.\n");    //动态内存分配失败
        exit(-1);
    }

    pNew->data = val;
    PNODE q = p->pNext;
    p->pNext = pNew;
    pNew->pNext = q;

    return true;

}

//头插
void list_headinsert(PNODE pHead, int val) {
    PNODE p, q;

    p = pHead;
    q = pHead->pNext;

    PNODE pNew = (PNODE)malloc(sizeof(NODE));

    pNew->data = val;
    pNew->pNext = q;
    p->pNext = pNew;
}

//尾插
void list_tailinsert(PNODE pHead, int val) {
    PNODE p = pHead;

    while (p->pNext != NULL) {
        p = p->pNext;
    }

    PNODE pNew = (PNODE)malloc(sizeof(NODE));

    pNew->data = val;
    pNew->pNext = NULL;
    p->pNext = pNew;

}

//链表排序
void list_sort(PNODE pHead) {
    PNODE p, q;
    int i, j, t;
    int len = list_length(pHead);


    for (i = 0, p = pHead->pNext; i < len -1; ++i, p = p->pNext) {
        for (j = i+1, q = p->pNext; j < len; ++j, q = q->pNext) {
            if (p->data > q->data) {
                t = p->data;
                p->data = q->data;
                q->data = t;
            }
        }
    }

}

//获取链表长度
int list_length(PNODE pHead) {
    PNODE p = pHead->pNext;
    int n = 0;

    while (p != NULL) {
        ++n;
        p = p->pNext;
    }

    printf("n = %d", n);

    return n;
}

//求链表最大值
void list_maximum(PNODE pHead) {
    PNODE p = pHead->pNext;
    int max = p->data;
    int i = 1;
    int pos;

    while (p) {
        if (max < p->data) {
            max = p->data;
            p = p->pNext;
            pos = i;
        }
        else {
            p = p->pNext;
        }

        ++i;
    }

    printf("Node %d is the maximum value. The maximum value is %d.\n", pos, max);
}

//判断链表是否为空
bool list_is_empty(PNODE pHead) {
    if (pHead->pNext == NULL) {
        return true;
    }
    return false;
}
//LinkQueue
//Version 1.0 20180326
//2018-03-26 21:32:15
//CopyRight ©2018 CuiShuo. All rights reserved.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node * pNext;
}NODE, *PNODE;

typedef struct Queue {
    PNODE pFront;
    PNODE pRear;
}QUEUE, *PQUEUE;

void queue_init(PQUEUE);                  //链式队列初始化
void queue_in(PQUEUE, int);               //入队
bool queue_out(PQUEUE);                   //出队
void queue_traverse(PQUEUE);              //链式队列遍历
bool queue_isempty(PQUEUE);               //判断队列是否为空

int main() {
    QUEUE Que;

    queue_init(&Que);

    queue_in(&Que, 1);
    queue_in(&Que, 2);
    queue_in(&Que, 3);
    queue_in(&Que, 4);
    queue_in(&Que, 5);

    queue_out(&Que);
    queue_out(&Que);

    queue_traverse(&Que);

    return 0;
}

void queue_init(PQUEUE pQue) {
    pQue->pFront = (PNODE)malloc(sizeof(NODE));

    if (pQue->pFront == NULL) {
        printf("Memory allocate failed.\n");
        exit(-1);
    }
    else {
        pQue->pRear = pQue->pFront;
        pQue->pFront->pNext = NULL;
    }
}

void queue_in(PQUEUE pQue, int val) {
    PNODE pNew = (PNODE)malloc(sizeof(NODE));

    pNew->data = val;
    pNew->pNext = NULL;
    pQue->pRear->pNext = pNew;
    pQue->pRear = pNew;


}

bool queue_out(PQUEUE pQue) {
    if (queue_isempty(pQue)) {
        printf("Queue is empty.\n");
        return false;
    }
    else {
        PNODE t = pQue->pFront->pNext;
        pQue->pFront->pNext = t->pNext;
        free(t);
        t = NULL;

        return true;
    }
}

void queue_traverse(PQUEUE pQue) {
    if (queue_isempty(pQue)) {
        printf("Queue is empty.\n");
        return;
    }

    PNODE p = pQue->pFront->pNext;

    while(p != pQue->pRear->pNext) {
        printf("%d ", p->data);
        p = p->pNext;
    }
}

bool queue_isempty(PQUEUE pQue) {
    if (pQue->pFront == pQue->pRear) {
        return true;
    }
    else {
        return false;
    }
}
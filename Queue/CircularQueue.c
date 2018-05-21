//CircularQueue
//Version 1.1 20180426
//2018-04-26 21:43:30
//CopyRight ©2018 CuiShuo. All rights reserved.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue{
    int * pBase;
    int front;
    int rear;
}QUEUE;

void queue_init(QUEUE *);
bool queue_in(QUEUE *, int val);
bool queue_out(QUEUE *);
void queue_traverse(QUEUE *);
bool queue_isfull(QUEUE *);
bool queue_isempty(QUEUE *);


int main() {
    QUEUE Que;

    queue_init(&Que);
    queue_in(&Que, 1);
    queue_in(&Que, 2);
    queue_in(&Que, 3);
    queue_in(&Que, 4);
    queue_in(&Que, 5);
    queue_in(&Que, 6);
    //queue_in(&Que, 7);
    //queue_in(&Que, 8);
    //queue_isfull(&Que);
    queue_traverse(&Que);

    return 0;
}

void queue_init(QUEUE * pQue) {
    pQue->pBase = (int *)malloc(sizeof(int) * 6);
    pQue->front = 0;
    pQue->rear = 0;
}

bool queue_in(QUEUE * pQue, int val) {
    if ( queue_isfull(pQue) ) {
        printf("The queue is full.\n");
        return false;
    }
    else {
        pQue->pBase[pQue->rear] = val;
        pQue->rear = (pQue->rear+1) % 6;
        return true;
    }
}

bool queue_out(QUEUE * pQue) {
    if (queue_isempty(pQue)) {
        printf("The queue is empty");
        return false;
    }
    else {
        pQue->front = (pQue->front + 1) % 6;
        return true;
    }
}

void queue_traverse(QUEUE * pQue) {
    int i = pQue->front;

    while (i != pQue->rear) {
        printf("%d ", pQue->pBase[i]);
        i = (i + 1) % 6;
    }

}

bool queue_isfull(QUEUE * pQue) {
    if ( (pQue->rear + 1) % 6 == pQue->front ) {
        return true;
    }
    else {
        return false;
    }
}

bool queue_isempty(QUEUE * pQue) {
    if (pQue->rear == pQue->front) {
        return true;
    }
    else {
        return false;
    }
}
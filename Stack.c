//Stack
//Version 1.0 20180311
//2018-03-11 14:56:44
//CopyRight ©2018 CuiShuo. All rights reserved.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node * pNext;
}NODE, * PNODE;

typedef struct Stack {
    PNODE pTop;
    PNODE pBottom;
}STACK, * PSTACK;

void stack_init(PSTACK);
void stack_clear(PSTACK);
void stack_push(PSTACK, int);
void stack_traverse(PSTACK);
bool stack_pop(PSTACK);
bool stack_isempty(PSTACK);

int main() {
    STACK Stk;

    stack_init(&Stk);
    stack_push(&Stk, 1);
    stack_push(&Stk, 2);
    stack_push(&Stk, 3);

    stack_traverse(&Stk);

    stack_pop(&Stk);
    stack_traverse(&Stk);

    stack_clear(&Stk);
    stack_traverse(&Stk);

    return 0;
}

void stack_init(PSTACK pStk) {
    pStk->pTop = (PNODE)malloc(sizeof(NODE));

    if (pStk->pTop == NULL) {
        printf("Memory allocate failed.\n");
        exit(-1);
    }
    else {
        pStk->pBottom = pStk->pTop;      //empty node
        pStk->pTop->pNext = NULL;
    }
}

void stack_clear(PSTACK pStk) {
    if (stack_isempty(pStk)) {
        printf("Stack is empty.\n");
        return;
    }
    else {
        PNODE p = pStk->pTop;
        PNODE q = NULL;

        while (p != pStk->pBottom) {
            q = p->pNext;
            free(p);
            p = q;
        }
        pStk->pTop = pStk->pBottom;
    }
}

void stack_push(PSTACK pStk, int val) {
    PNODE pNew = (PNODE)malloc(sizeof(NODE));

    pNew->data = val;
    pNew->pNext = pStk->pTop;
    pStk->pTop = pNew;
}

void stack_traverse(PSTACK pStk) {
    if (stack_isempty(pStk)) {
        printf("Stack is empty.\n");
        return;
    }

    PNODE p = pStk->pTop;

    while (p != pStk->pBottom) {
        printf("%d  ", p->data);
        p = p->pNext;
    }
}

bool stack_pop(PSTACK pStk) {
    if (stack_isempty(pStk)) {
        return false;
    }
    else {
        PNODE t = pStk->pTop;
        pStk->pTop = t->pNext;
        free(t);
        t = NULL;

        return true;
    }
}

bool stack_isempty(PSTACK pStk) {
    if (pStk->pTop == pStk->pBottom) {
        return true;
    }
    else {
        return false;
    }
}
//BFS_
//基于邻接表进行广度优先搜索
//Version 1.0 20180521
//2018-05-21 21:34:51
//CopyRight ©2018 CuiShuo. All rights reserved.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MaxNum 100

bool visited[MaxNum];                               //标志数组，用于区分顶点是否被访问过

typedef struct eNode {                              //边结点
    int adjvex;                                     //邻接点域
    struct eNode * next;                            //邻接下一条边的结点
}edgeNode;

typedef struct vNode {                              //
    char vertex[3];                                 //顶点名称
    edgeNode * firstEdge;                           //与该顶点邻接的第一个结点
}vertexNode, AdjList[MaxNum];

typedef struct {                                    //图
    AdjList adjlist;                                //邻接表
    int vexnum, edgenum;                            //顶点数 边数
}ALGraph;

typedef struct {                                    //循环队列
    int data[MaxNum];
    int front, rear;
}Queue;

void createALGraph(ALGraph * G);                    //创建图
void BFS(ALGraph * G, int i);
void BFST(ALGraph *G);                              //广度优先搜索
void initQueue(Queue *);                            //初始化循环队列
void enQueue(Queue *, int);                         //入队
int deQueue(Queue * q);                             //出队
bool isEmpty(Queue *);                              //判断队空

int main() {
    ALGraph * G;
    G = (ALGraph *)malloc(sizeof(ALGraph));

    createALGraph(G);
    BFST(G);
    return 0;
}

void createALGraph(ALGraph * G) {
    int m, n;

    edgeNode * p1;
    edgeNode * p2;

    printf("请输入顶点数和边数:");
    scanf("%d %d", &G->vexnum, &G->edgenum);
    for (int i = 0; i < G->vexnum; ++i) {
        printf("请输入第%d个顶点名称:", i+1);
        scanf("%s", G->adjlist[i].vertex);
        G->adjlist[i].firstEdge = NULL;             //将该顶点的边表头指针置为空
    }
    printf("请输入边的信息:");
    for (int j = 0; j < G->edgenum; ++j) {
        scanf("%d %d", &m, &n);
        p1 = (edgeNode *)malloc(sizeof(edgeNode));  //生成新边结点
        p1->adjvex = n;                             //m顶点与n顶点邻接
        p1->next = G->adjlist[m].firstEdge;         //使用头插法插入到表头结点的头部
        G->adjlist[m].firstEdge = p1;

        p2 = (edgeNode *)malloc(sizeof(edgeNode));
        p2->adjvex = m;
        p2->next = G->adjlist[n].firstEdge;
        G->adjlist[n].firstEdge = p2;
    }
}

void BFS(ALGraph * G, int i) {
    Queue q;
    edgeNode * p;
    int v;

    printf("遍历结点:%s\n", G->adjlist[i].vertex);
    visited[i] = true;

    initQueue(&q);
    enQueue(&q, i);

    while (!isEmpty(&q)) {
        v = deQueue(&q);
        p = G->adjlist[v].firstEdge;

        while(p) {
            if (visited[p->adjvex] == false) {
                printf("遍历结点:%s\n", G->adjlist[p->adjvex].vertex);
                visited[p->adjvex] = true;
                enQueue(&q, p->adjvex);
            }
            p = p->next;
        }
    }

}

void BFST(ALGraph *G) {
    int v;
    for (v = 0; v < G->vexnum ; ++v) {
        visited[v] = false;
    }
    for (v = 0; v < G->vexnum; ++v) {
        if (!visited[v]) {
            BFS(G, v);
        }
    }
}

void initQueue(Queue * q) {
    q->front = 0;
    q->rear = 0;
}

void enQueue(Queue * q, int i) {
    q->data[q->rear] = i;
    q->rear = (q->rear + 1) % MaxNum;
}

int deQueue(Queue * q) {
    int v;

    q->front = (q->front + 1) % MaxNum;
    v = q->data[q->front];

    return v;
}

bool isEmpty(Queue * q) {
    if (q->front == q->rear) {
        return true;
    }
    else {
        return false;
    }
}
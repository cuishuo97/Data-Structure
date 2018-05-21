//DFS
//基于邻接表进行深度优先搜索
//Version 1.0 20180520
//2018-05-20 23:13:30
//CopyRight ©2018 CuiShuo. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxNum 100                //最大顶点数

bool visited[MaxNum];

typedef struct eNode {              //边结点
    int adjvex;                     //邻接点域
    int weight;                     //权重()
    struct Node * next;             //与该节点邻接的下一个结点
}edgeNode;

typedef struct vNode {              //表头结点
    char vertex[3];                 //结点名称
    edgeNode * firstEdge;           //与该节点邻接的第一个结点
}vertexNode, AdjList[MaxNum];

typedef struct {
    AdjList adjlist;
    int vexnum, edgenum;
}ALGraph;

void createUDGraph(ALGraph * G);    //创建无向图（邻接表）
void DFS(ALGraph * G, int i);
void DFSTraverseAL(ALGraph *G);

int main() {
    ALGraph  * G;
    G = (ALGraph *)malloc(sizeof(ALGraph));
    createUDGraph(G);

    //DFS(G, 0);
    DFSTraverseAL(G);
    return 0;
}

void createUDGraph(ALGraph * G) {
    int m, n;

    edgeNode * p1;
    edgeNode * p2;

    printf("请输入顶点数和边数:");
    scanf("%d %d", &G->vexnum, &G->edgenum);
    for (int i = 0; i < G->vexnum; ++i) {
        printf("请输入%d个结点名称:", i+1);
        scanf("%s", G->adjlist[i].vertex);
        G->adjlist[i].firstEdge = NULL;
    }
    printf("请输入边的信息:");
    for (int j = 0; j < G->edgenum; ++j) {
        scanf("%d %d", &m, &n);
        p1 = (edgeNode *)malloc(sizeof(edgeNode));
        p1->adjvex = n;
        p1->next = G->adjlist[m].firstEdge;
        G->adjlist[m].firstEdge = p1;

        p2 = (edgeNode *)malloc(sizeof(edgeNode));
        p2->adjvex = m;
        p2->next = G->adjlist[n].firstEdge;
        G->adjlist[n].firstEdge = p2;
    }
}

void DFS(ALGraph * G, int i) {
    edgeNode *p;
    printf("遍历结点:%s \n", G->adjlist[i].vertex);

    visited[i] = true;

    p = G->adjlist[i].firstEdge;
    while (p) {
        if (visited[p->adjvex] == false) {
            DFS(G, p->adjvex);
        }
        p = p->next;
    }
}

void DFSTraverseAL(ALGraph *G)
{
    int i ;
    for(i = 0 ; i < G->vexnum ; i++)
    {
        visited[i] = false ;
    }
    for(i = 0 ; i < G->vexnum ; i++)
    {
        if(!visited[i])
        {
            DFS(G , i) ;
        }
    }
}
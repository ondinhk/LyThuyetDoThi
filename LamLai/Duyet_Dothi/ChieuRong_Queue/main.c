#include <stdio.h>
#define MAX_VERTICES 100
#define MAX_EDGES 500
#define MAX_ELEMENTS 200
//Graph
typedef struct
{
    int n, m;
    int A[MAX_VERTICES][MAX_EDGES];
} Graph;
void init_graph(Graph *G, int n, int m)
{
    int i, j;
    G->n = n;
    G->m = m;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            G->A[i][j] = 0;
}
void add_edges(Graph *G, int e, int u, int v)
{
    G->A[u][e] = 1;
    G->A[v][e] = 1;
}
int adjacent(Graph *G, int u, int v)
{
    int e;
    for (e = 1; e <= G->m; e++)
        if (G->A[u][e] == 1 && G->A[v][e] == 1)
            return 1;
    return 0;
}
//List
typedef struct
{
    int size;
    int data[MAX_ELEMENTS];
} List;
void make_null(List *L)
{
    L->size = 0;
}
void push_back(List *L, int X)
{
    L->data[L->size] = X;
    L->size++;
}
int element_at(List *L, int pos)
{
    return L->data[pos - 1];
}
//Neighbors
List neighbors(Graph *G, int x)
{
    List list;
    make_null(&list);
    int y;
    for (y = 1; y <= G->n; y++)
        if (adjacent(G, x, y) && x != y)
            push_back(&list, y);
    return list;
}
//Queue
typedef struct
{
    int front, rear;
    int data[MAX_ELEMENTS];
} Queue;
void make_null_queue(Queue *Q)
{
    Q->front = 0;
    Q->rear = -1;
}
void push(Queue *Q, int X)
{
    Q->rear++;
    Q->data[Q->rear] = X;
}
int top(Queue *Q)
{
    return Q->data[Q->front];
}
void pop(Queue *Q)
{
    Q->front++;
}
int empty_queue(Queue *Q)
{
    return (Q->front > Q->rear);
}
//Duyet theo chieu rong Queue
void breadth_firts_search(Graph *G)
{
    Queue Q;
    int mark[MAX_ELEMENTS];
    make_null_queue(&Q);
    int i, j;
    for (j = 1; j <= G->n; j++)
        mark[j] = 0;
    for (i = 1; i <= G->n; i++)
    {
        if (mark[i] == 0)
        {
            push(&Q, i);
            mark[i] = 1;
            while (!empty_queue(&Q))
            {
                int x = top(&Q);
                List list = neighbors(G, x);
                printf("%d ", x);
                pop(&Q);
                for (j = 1; j <= list.size; j++)
                {
                    int y = element_at(&list, j);
                    if (mark[y] == 0)
                    {
                        mark[y] = 1;
                        push(&Q, y);
                    }
                }
            }
        }
    }
}

int main()
{
    freopen("dothi.txt", "r", stdin);
    Graph G;
    int n, m, u, v, e, i;
    scanf("%d%d", &n, &m);
    init_graph(&G, n, m);
    for (e = 1; e <= m; e++)
    {
        scanf("%d%d", &u, &v);
        add_edges(&G, e, u, v);
    }
    printf("Duyet:\n");
    breadth_firts_search(&G);
    return 0;
}

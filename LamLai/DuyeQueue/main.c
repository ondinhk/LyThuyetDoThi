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
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            G->A[i][j] = 0;
}
void add_edge(Graph *G, int e, int u, int v)
{
    G->A[u][e] = 1;
    G->A[v][e] = 1;
}
int adjacent(Graph *G, int x, int y)
{
    int e;
    for (e = 1; e <= G->m; e++)
    {
        if (G->A[x][e] == 1 && G->A[y][e] == 1)
            return 1;
    }
    return 0;
}
//List
typedef struct
{
    int size;
    int data[MAX_ELEMENTS];
} List;
void makenull_list(List *L)
{
    L->size = 0;
}
void push_back(List *L, int x)
{
    L->data[L->size] = x;
    L->size++;
}
int element_at(List *L, int i)
{
    return L->data[i - 1];
}
//neighbors
List neighbors(Graph *G, int x)
{
    int y;
    List list;
    makenull_list(&list);
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
void makenull_queue(Queue *Q)
{
    Q->front = 0;
    Q->rear = -1;
}
void push(Queue *Q, int x)
{
    Q->rear++;
    Q->data[Q->rear] = x;
}
void pop(Queue *Q)
{
    Q->front++;
}
int top(Queue *Q)
{
    return Q->data[Q->front];
}
int empty(Queue *Q)
{
    return (Q->front > Q->rear);
}
void breath_first_search(Graph *G)
{
    Queue Q;
    int mark[MAX_VERTICES];
    makenull_queue(&Q);
    int i, j;
    for (j = 1; j <= G->n; j++)
        mark[j] = 0;
    for (i = 1; i <= G->n; i++)
    {
        if (mark[i] == 0)
        {
            push(&Q, i);
            mark[i] = 1;
            while (!empty(&Q))
            {
                int x = top(&Q);
                List L = neighbors(G, x);
                printf("%d ", x);
                pop(&Q);
                for (j = 1; j <= L.size; j++)
                {
                    int y = element_at(&L, j);
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
    int i, j, u, v, m, n;
    scanf("%d%d", &n, &m);
    init_graph(&G, n, m);
    for (i = 1; i <= G.m; i++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, i, u, v);
    }
    breath_first_search(&G);

    return 0;
}

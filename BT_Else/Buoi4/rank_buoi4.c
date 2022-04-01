#include <stdio.h>
#define MAX_VERTICES 50
#define MAX_ELEMENTS 50
#define MAX_EDGES 50
typedef struct
{
    int n, m;
    int A[MAX_EDGES][MAX_EDGES];
} Graph;
typedef struct
{
    int size;
    int data[MAX_ELEMENTS];
} List;
//Graph
void init_graph(Graph *G, int n)
{
    int i, j;
    G->n = n;
    for (i = 1; i <= G->n; i++)
    {
        for (j = 1; j <= G->n; j++)
            G->A[i][j] = 0;
    }
}
void add_edge(Graph *G, int u, int v)
{
    G->A[u][v] = 1;
}

//List
void make_null_list(List *L)
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
void copy_list(List *S1, List *S2)
{
    int i;
    make_null_list(S1);
    for (i = 1; i <= S2->size; i++)
    {
        int u = element_at(S2, i);
        push_back(S1, u);
    }
}
//Rank Graph
int rank[100];
void Ranking(Graph *G)
{
    int d[MAX_VERTICES];
    int x, u;
    for (u = 1; u <= G->n; u++)
        d[u] = 0;
    for (x = 1; x <= G->n; x++)
        for (u = 1; u <= G->n; u++)
            if (G->A[x][u] != 0)
                d[u]++;
    List S1, S2;
    make_null_list(&S1);
    for (u = 1; u <= G->n; u++)
        if (d[u] == 0)
            push_back(&S1, u);
    int k = 0, i;
    while (S1.size > 0)
    {
        make_null_list(&S2);
        for (i = 1; i <= S1.size; i++)
        {
            int u = element_at(&S1, i);
            rank[u] = k;
            int v;
            for (v = 1; v <= G->n; v++)
            {
                if (G->A[u][v] != 0)
                {
                    d[v]--;
                    if (d[v] == 0)
                        push_back(&S2, v);
                }
            }
        }
        copy_list(&S1, &S2);
        k++;
    }
    for (u = 1; u <= G->n; u++)
    {
        printf("%d ", rank[u]);
    }
}
int main()
{
    freopen("dothi.txt", "r", stdin);
    int u, v, i, n, m;
    Graph G;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    Ranking(&G);
    return 0;
}
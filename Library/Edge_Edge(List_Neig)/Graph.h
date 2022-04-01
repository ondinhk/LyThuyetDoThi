#include <stdio.h>
#define MAX_VERTICES 100
typedef struct
{
    int n;
    int A[MAX_VERTICES][MAX_VERTICES];
} Graph;

void init_Graph(Graph *G, int n)
{
    int i, j;
    G->n = n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            G->A[i][j] = 0;
}
void add_edge(Graph *G, int x, int y)
{
    G->A[x][y] = 1;
    G->A[y][x] = 1;
}
void add_edge_direct(Graph *G, int x, int y)
{
    G->A[x][y] = 1;
}
//KT y ke x
int adjacent(Graph *G, int x, int y)
{
    return G->A[x][y] != 0;
}
int degree(Graph *G, int x)
{
    int i, deg = 0;
    for (i = 1; i <= G->n; i++)
        if (G->A[x][i] == 1)
            deg++;
    return deg;
}
int degree_multi_arc(Graph *G, int x)
{
    int i, deg = 0;
    for (i = 0; i <= G->n; i++)
        if (G->A[x][i] == 1)
            deg += G->A[x][i];
    return deg;
}

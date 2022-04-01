#include <stdio.h>
#include "List.h"
#define MAX_VERTICES 100
typedef struct
{
    int n;
    List adj[MAX_VERTICES];
} Graph;

//Makenull list
void init_Graph(Graph *G, int n) //n so dinh
{
    int i;
    G->n = n;
    for (i = 1; i <= n; i++)
        Makenull_List(&G->adj[i]);
}

//Add cung e=(x,y)
void add_edge(Graph *G, int x, int y)
{
    push_back(&G->adj[x], y);
    push_back(&G->adj[y], x);
}

//y co ke x ??
int adjacent(Graph *G, int x, int y)
{
    int i;
    for (i = 1; i <= G->adj[x].size; i++)
        if (Retrieve(&G->adj[x], i) == y)
            return 1;
    return 0;
}

//Bac cua x
int degree(Graph *G, int x)
{
    return G->adj[x].size;
}
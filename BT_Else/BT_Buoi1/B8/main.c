#include <stdio.h>
#define MAX_VERTICES 500
#define MAX_EDGES 100
#define MAX_ELEMENT 200
typedef struct
{
    int arr[MAX_ELEMENT];
    int size;
} List;
void make_null(List *L)
{
    L->size = 0;
}
void push_back(List *L, int X)
{
    L->arr[L->size] = X;
    L->size++;
}
int element_at(List L, int i)
{
    return L.arr[i - 1];
}
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
void add_edges(Graph *G, int e, int x, int y)
{
    G->A[x][e] = 1;
    G->A[y][e] = 1;
}
int degree(Graph *G, int x)
{
    int i, deg = 0;
    for (i = 1; i <= G->m; i++)
        if (G->A[x][i] == 1)
            deg++;
    return deg;
}
List arrDegree(Graph *G)
{
    int e, j;
    List list;
    make_null(&list);
    for (e = 1; e <= G->n; e++)
        push_back(&list, degree(G, e));
    return list;
}
int max_num(List L)
{
    int i, max = element_at(L, 1);
    for (i = 2; i <= L.size; i++)
    {
        if (max < element_at(L, i))
            max = element_at(L, i);
	//	printf("%d\t",max);
	}
	return max;
}
int main()
{
    freopen("dothi.txt", "r", stdin);
    Graph G;
    int e, n, m, u, v;
    scanf("%d%d", &n, &m);
    init_graph(&G, n, m);
    for (e = 1; e <= m; e++)
    {
        scanf("%d%d", &u, &v);
        add_edges(&G, e, u, v);
    }
    List L = arrDegree(&G);
    for(e=1;e<=L.size;e++)
    {
		printf("%d ",element_at(L,e));
	}
	printf("L.size=%d",L.size);
	printf("%d", max_num(L));
    return 0;
}

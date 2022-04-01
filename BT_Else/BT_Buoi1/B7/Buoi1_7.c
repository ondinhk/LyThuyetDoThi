#include <stdio.h>
#define MAX_EDGEDS 500
#define MAX_VERTICES 100
#define MAX_ELEMENT 500
typedef int ElementType;

typedef struct
{
    int n, m;
    int A[MAX_VERTICES][MAX_EDGEDS];
} Graph;
//makenull Graph
void init_graph(Graph *G, int n, int m)
{
    int i, j;
    G->n = n;
    G->m = m;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            G->A[i][j] = 0;
}
//them e=(x,y)
void add_edge(Graph *G, int e, int x, int y)
{
    G->A[x][e] = 1;
    G->A[y][e] = 1;
}
//y co ke x khong
int adjacent(Graph *G, int x, int y)
{
    int i;
    for (i = 1; i <= G->m; i++)
        if (G->A[x][i] == 1 && G->A[y][i] == 1)
            return 1;
    return 0;
}
//BAC
int degree(Graph *G, int x)
{
    int i, deg = 0;
    for (i = 1; i <= G->m; i++)
        if (G->A[x][i] == 1)
            deg++;
    return deg;
}
//---------------------------------------
typedef struct
{
    ElementType data[MAX_ELEMENT];
    int size;
} List;
//makunull
void make_null(List *L)
{
    L->size = 0;
}
//add
void push_back(List *L, ElementType X)
{
    L->data[L->size] = X;
    L->size++;
}
ElementType element_at(List *L, int i)
{
    return L->data[i - 1];
}
//-----------------------------------------
//danh sach dinh ke cua x
List neighbors(Graph *G, int x)
{
    List list;
    int i;
    make_null(&list);
    for (i = 1; i <= G->n; i++)
        if (adjacent(G, x, i) && x != i)
            push_back(&list, i);
    return list;
}
//Tim giao
void giao(Graph *G, int x, int y)
{
    List listx = neighbors(G, x);
    List listy = neighbors(G, y);
    int i, j, count = 0;
    for (i = 1; i <= listx.size; i++)
    {
        for (j = 1; j <= listy.size; j++)
        {
            if (element_at(&listx, i) == element_at(&listy, j))
            {
                printf("%d ", element_at(&listx, i));
                count++;
            }
        }
    }
    if (count == 0)
        printf("KHONG CHUNG DOI THU");
}
int main()
{
    freopen("dothi.txt", "r", stdin);
    int e, u, v, m, n, i, j,x,y;
    Graph G;
    List L;
    scanf("%d%d", &n, &m);
    init_graph(&G, n, m);
    for (e = 1; e <= m; e++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, e, u, v);
    }
    scanf("%d%d",&x,&y);
    //    for (i = 1; i <= n; i++)
    //    {
    //        for (j = 1; j <= m; j++)
    //            printf("%d ", G.A[i][j]);
    //        printf("\n");
    //    }
    //Danh sach ke cua cac dinh
        for(i=1;i<=n;i++)
    {
    	List list=neighbors(&G,i);
    	printf("Cac dinh ke cua [%d]:",i);
    	for(j=1;j<=list.size;j++)
    	{
    		printf("%d ",element_at(&list,j));
		}
		printf("\n");
	}
    giao(&G,x,y);
    return 0;
}

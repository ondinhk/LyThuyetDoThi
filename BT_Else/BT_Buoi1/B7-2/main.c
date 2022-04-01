#include <stdio.h>
#define MAX_ELEMENTS 500
#define MAX_EDGES 200
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
int element_at(List *L, int i)
{
    return L->data[i - 1];
}
//-----------------
//Graph
typedef struct
{
    int n;
    int A[MAX_EDGES][MAX_EDGES];
} Graph;
void init_graph(Graph *G, int n)
{
    int i, j;
    G->n = n;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            G->A[i][j] = 0;
        }
    }
}
int adjacent(Graph *G, int x, int y)
{
    return G->A[x][y]!=0;
}
List neighbors(Graph *G, int x)
{
    List list;
    make_null(&list);
    int i;
    for (i = 1; i <= G->n; i++)
        if (adjacent(G, x, i) && x != i)
            push_back(&list, i);
    return list;
}
int giao(Graph *G, int x, int y)
{
    List listx = neighbors(G, x);
    List listy = neighbors(G, y);
    int i, j, count = 0;
    for (i = 1; i <= listx.size; i++)
        for (j = 1; j <= listy.size; j++)
            if (element_at(&listx, i) == element_at(&listy, j))
                count++;
    return count;
}
int main()
{
    freopen("matran.txt", "r", stdin);
    int n, x, i, j,temp;
    Graph G;
    scanf("%d", &n);
    init_graph(&G, n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &x);
            //printf("%d ", x);
            G.A[i][j] = x;
        }
        //printf("\n");
    }
//    for(i=1;i<=n;i++)
//    {
//    	List list=neighbors(&G,i);
//    	printf("Cac dinh ke cua [%d]:",i);
//    	for(j=1;j<=list.size;j++)
//    	{
//    		printf("%d ",element_at(&list,j));
//		}
//		printf("\n");
//	}
	scanf("%d%d",&i,&j);
   	temp=giao(&G,i,j);
   	printf("%d",temp);
    return 0;
}

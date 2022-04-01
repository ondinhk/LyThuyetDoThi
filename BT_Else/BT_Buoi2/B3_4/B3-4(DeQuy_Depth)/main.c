#include<stdio.h>
#define MAX_VERTICES 100
#define MAX_EDGES 500
#define MAX_ELEMENTS 100
typedef int ElementType;
//Graph
typedef struct{
	int n,m;
	int A[MAX_VERTICES][MAX_EDGES];
	int mark[MAX_VERTICES];
	int count;
}Graph;
void init_graph(Graph *G,int n,int m)
{
	int i,j;
	G->n=n;
	G->m=m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			G->A[i][j]=0;
}

void add_edge(Graph *G, int e, int x,int y)
{
	G->A[x][e]=1;
	G->A[y][e]=1;
}
int adjacent(Graph *G,int x,int y)
{
	int e;
	for(e=1;e<=G->m;e++)
		if(G->A[x][e]==1 && G->A[y][e])
			return 1;
	return 0;
}
//List
typedef struct{
	int size;
	int Data[MAX_ELEMENTS];
}List;
void make_null(List *L)
{
	L->size=0;
}
void push_back(List *L,ElementType X)
{
	L->Data[L->size]=X;
	L->size++;
}
ElementType element_at(List *L,int i)
{
	return L->Data[i-1];
}
//Neighbors
List neighbors(Graph *G,int x)
{
	int y;
	List list;
	make_null(&list);
	for(y=1;y<=G->n;y++)
		if(adjacent(G,x,y) && x!=y)
			push_back(&list,y);
	return list;
}
//Duyet theo chieu sau DeQuy
void traversal(Graph* G,int x)
{
	if(G->mark[x]==1){
		return;
	}
//	printf("%d\n",x);
	G->count++;
	G->mark[x]=1;
	List L=neighbors(G,x);
	int j;
	for(j=1;j<=L.size;j++)
	{
		int y=element_at(&L,j);
		traversal(G,y);
	}
}
void depth_first_search(Graph *G)
{
	int i;
	for(i=1;i<=G->n;i++)
		G->mark[i]=0;
	traversal(G,1);
}
//main
int main()
{
	freopen("dothi.txt","r",stdin);
	Graph G;
	int n, m, u, v, e;
	scanf("%d%d", &n, &m);
	init_graph(&G,n,m);
	G.count=0;
	for (e = 1; e <= m; e++) 
	{
		scanf("%d%d", &u, &v);
		add_edge(&G ,e ,u , v);
	}
	depth_first_search(&G);
	if(G.count==G.n)
		printf("DUOC");
	else
		printf("KHONG");
	return 0;
}

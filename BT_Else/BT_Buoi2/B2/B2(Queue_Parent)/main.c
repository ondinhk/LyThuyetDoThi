#include<stdio.h>
#define MAX_VERTICES 100
#define MAX_EDGES 500
#define MAX_ELEMENTS 100
typedef int ElementType;
//Graph
typedef struct{
	int n,m;
	int A[MAX_VERTICES][MAX_EDGES];
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
void make_zero(List *L)
{
	int i;
	for(i=0;i<L->size;i++)
	{
		L->Data[i]=0;
	}
}
//Neighbors
List neighbors(Graph *G,int x)
{
	int y;
	List list;
	make_null(&list);
	for(y=1;y<=G->n;y++)
	{	
		if(adjacent(G,x,y) && x!=y)
			push_back(&list,y);
	}
	return list;
}
//Queue
typedef struct{
	int front,rear;
	ElementType Data[MAX_ELEMENTS];
}Queue;
void make_null_queue(Queue *Q)
{
	Q->front=0;
	Q->rear=-1;
}
void push(Queue *Q,int X)
{
	Q->rear++;
	Q->Data[Q->rear]=X;
}
int top(Queue *Q)
{
	return Q->Data[Q->front];
}
void pop(Queue *Q)
{
	Q->front++;
}
int empty(Queue *Q)
{
	return (Q->front > Q->rear);
}
//Duyet theo chieu rong
void breath_first_search(Graph *G)
{
	Queue Q;
	List parent;
	int mark[MAX_VERTICES];
	make_null_queue(&Q);
	make_null(&parent);
	int i,j;
	for(j=1;j<=G->n;j++)
		mark[j]=0;
	for(i=1;i<=G->n;i++)
	{
		if(mark[i]==0)
		{
			push(&Q,i);
			mark[i]=1;
			while(!empty(&Q))
			{
				int x=top(&Q);
				List L=neighbors(G,x);
				printf("%d\n",x);
				pop(&Q);
				for(j=1;j<=L.size;j++)
				{
					int y=element_at(&L,j);
					if(mark[y]==0)
					{
						mark[y]=1;
						push(&Q,y);
					}
				}
			}
		}
	}
}
//main
int main()
{
	freopen("dothi.txt","r",stdin);
	Graph G;
	List L,N;
	int n, m, u, v, e;
	int i;
	scanf("%d%d", &n, &m);
	init_graph(&G,n,m);
	for (e = 1; e <= m; e++) 
	{
		scanf("%d%d", &u, &v);
		add_edge(&G ,e ,u , v);
	}
	breath_first_search(&G);
	return 0;
}

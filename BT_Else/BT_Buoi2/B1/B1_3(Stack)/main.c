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
		if(adjacent(G,x,y))
			push_back(&list,y);
	return list;
}
//Stack
typedef struct{
	int data[MAX_ELEMENTS];
	int size;
}Stack;
void make_null_stack(Stack* S)
{
	S->size=0;
}
void push(Stack *S,int X)
{
	S->data[S->size]=X;
	S->size++;
}
int top(Stack *S)
{
	return S->data[S->size - 1];
}
void pop(Stack *S)
{
	S->size--;
}
int empty(Stack *S)
{
	return S->size==0;
}
//Duyet theo chieu sau Satck
void depth_first_search(Graph *G)
{
	Stack S;
	int mark[MAX_VERTICES];
	make_null_stack(&S);
	int i,j;
	for(j=1;j<=G->n;j++)
		mark[j]=0;
	for(i=1;i<=G->n;i++)
	{
		push(&S,i);
		while(!empty(&S))
		{
			int x=top(&S);
			pop(&S);
			if(mark[x]!=0)
				continue;
			printf("%d\n",x);
			mark[x]=1;
			List list=neighbors(G,x);
			for(j=1;j<=list.size;j++)
			{
				int y=element_at(&list,j);
				push(&S,y);
			}
		}
	}
}

//main
int main()
{
	freopen("dothi.txt","r",stdin);
	Graph G;
	int n, m, u, v, e;
	scanf("%d%d", &n, &m);
	init_graph(&G,n,m);
	for (e = 1; e <= m; e++) 
	{
		scanf("%d%d", &u, &v);
		add_edge(&G ,e ,u , v);
	}
	depth_first_search(&G);
	return 0;
}

#include<stdio.h>
#define MAXN 100
#define NO_EDGE 0
#define INFINITY 999999
typedef struct
{
    int n,m;
    int L[MAXN][MAXN];
    int mark[MAXN];
    int pi[MAXN];
    int p[MAXN];
} Graph;
void init_graph(Graph *G, int n, int m)
{
	G->n=n;
	G->m=m;
    int i, j;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            G->L[i][j] = NO_EDGE;
}
void add_edge(Graph *G, int u, int v, int w)
{
    G->L[u][v] = w;
}
void Dijkstra(Graph *G, int s)
{
    int i, j, it;
    for (i = 1; i <= G->n; i++)
    {
        G->pi[i] = INFINITY;
        G->mark[i] = 0;
    }
    G->pi[s] = 0;
    G->p[s] = -1;
    for (it = 1; it < G->n; it++)
    {
        int min_pi = INFINITY;
        for (j = 1; j <= G->n; j++)
        {
            if (G->mark[j] == 0 && G->pi[j] < min_pi)
            {
            	//printf("min_pi:%d\n",min_pi);
                min_pi = G->pi[j];
                i = j;
            }
        }
        G->mark[i] = 1;
        for (j = 1; j <= G->n; j++)
        {
            if (G->L[i][j] != NO_EDGE && G->mark[j] == 0)
            {
                if (G->pi[i] + G->L[i][j] < G->pi[j])
                {
                    G->pi[j] = G->pi[i] + G->L[i][j];
                    G->p[j] = i;
                    //printf("---p[%d]:%d\n",j,G->p[j]);
                }
            }
        }
    }
}
int main()
{
	freopen("dothi.txt","r",stdin);
	int i,j,n,m,u,v,w;
	int path[MAXN];
	int k=0;
	Graph G;
	scanf("%d%d",&n,&m);
	init_graph(&G,n,m);
	for(i=1;i<=G.n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		add_edge(&G,u,v,w);
	}
	for(i=1;i<=G.n;i++)
	{
		for(j=1;j<=G.m;j++)
			printf("%d ",G.L[i][j]);
		printf("\n");
	}
	Dijkstra(&G,1);
	int f=4;
	int current=f;
	while(current != -1)
	{
		path[k]=current;
		k++;
		current=G.p[current];
	}
	for(i=k-1;i>=0;i--)
	{
		printf("%d ",path[i]);
	}
	printf("p[%d]=%d",f,G.pi[f]);
	return 0;
}

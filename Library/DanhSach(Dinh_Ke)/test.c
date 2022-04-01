#include "Graph.h"

int main()
{
	int n, i, j;
	int u, v; // edge u,v
	freopen("dothi.txt", "r", stdin);
	Graph G;
	scanf("%d", &n);
	init_Graph(&G, n);
	for (i = 0; i <= n; i++)
	{
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	for (i = 1; i <= G.n; i++)
	{
		for (j = 1; j <= G.adj[i].size; j++)
		{
			printf("%d ", Retrieve(&G.adj[i], j));
		}
		printf("\n");
	}
	return 0;
}

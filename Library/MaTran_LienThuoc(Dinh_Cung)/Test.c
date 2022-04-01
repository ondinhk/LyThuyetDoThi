#include <stdio.h>
#include "Graph.h"
#include"List.h"
List Neighbors(Graph *G, int x)
{
    int y;
    List list;
    Makenull_List(&list);
    for (y = 1; y <= G->n; y++)
    {
        if (adjacent(G, x, y))
            push_back(&list, y);
    }
    return list;
}
int main(int argc, char *argv[])
{
	int i, u, j, v, n, m;
	Graph G;
	if (argc < 2)
	{
		printf("Hay go: %s <tenfile>", argv[0]);
		return 1;
	}
	FILE *file = fopen(argv[1], "r");
	fscanf(file, "%d%d", &n, &m);
	create_Graph(&G, n, m);
	for (i = 1; i <= m; i++)
	{
		fscanf(file, "%d%d", &u, &v);
		add(&G, i, u, v);
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			printf("%d ", G.A[i][j]);
		}
		printf("\n");
	}
	for (i = 1; i <= n; i++)
	{
		printf("Deg(%d)== %d\n", i, degree(&G, i));
	}
	//Liet ke danh sach ke cac dinh
    for (i = 1; i <= G.n; i++)
    {
        List L = Neighbors(&G, i);
        printf("Danh sach cac dinh ke cua %d: [ ", i);
        for (j = 1; j <= L.size; j++)
            printf("%d ", Retrieve(&L, j));
        printf("]\n");
    }
    
    return 0;
}

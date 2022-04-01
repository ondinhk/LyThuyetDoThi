#define MAX_VERTICES 100
#define MAX_EDGES 500

typedef struct
{
	int n, m; // n so dinh, m so canh
	// Ma tran dinh-cung
	int A[MAX_VERTICES][MAX_EDGES];
} Graph;

//Create graph
void init_graph(Graph *G, int n, int m)
{
	int i, j;
	G->n = n;
	G->m = m;
	for (i = 1; i < n; i++)
		for (j = 1; j < m; j++)
			G->A[i][j] = 0;
}

//Add cung e=(x,y) vao G
void add_edge(Graph *G, int e, int x, int y)
{
	G->A[x][e] = 1;
	G->A[y][e] = 1;
}

// x co lien ke y ko?
// 1 Cot co 2 hang == 1 thi x,y lien ke
int adjacent(Graph *G, int x, int y)
{
	int i;
	for (i = 1; i <= G->m; i++)
	{
		if (G->A[x][i] == 1 && G->A[y][i] == 1)
			return 1;
	}
	return 0;
}

//Tinh bac cua mot dinh x
int degree(Graph *G, int x)
{
	int i, count = 0;
	for (i = 1; i <= G->m; i++)
		if (G->A[x][i] == 1)
			count++;
	return count;
}
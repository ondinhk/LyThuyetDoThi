#include "Graph.h"
#include "D:\LyThuyetDoThi\Struct\Arr_List\List.h"
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
int main()
{
    FILE *p = fopen("dothi.txt", "r");
    Graph G;
    int i, u, v, n, j;
    fscanf(p, "%d", &n);
    init_Graph(&G, n);
    for (i = 1; i <= n; i++)
    {
        fscanf(p, "%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d ", G.A[i][j]);
        }
        printf("\n");
    }
    for (i = 1; i <= n; i++)
    {
        printf("deg(%d)= %d\n", i, degree(&G, i));
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

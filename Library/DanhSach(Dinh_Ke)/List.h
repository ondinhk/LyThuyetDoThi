#define MAX_ELEMENT 100
typedef int ElementType;
typedef struct
{
    ElementType A[MAX_ELEMENT];
    int size;
} List;

void Makenull_List(List *L)
{
    L->size = 0;
}
void push_back(List *L, ElementType x)
{
    L->A[L->size] = x;
    L->size++;
}
ElementType Retrieve(List *L, int i)
{
    return L->A[i - 1];
}
ElementType sizeList(List *L)
{
    return L->size;
}

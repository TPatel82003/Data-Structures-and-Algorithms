#include <stdio.h>
#include <stdlib.h>
struct NODE
{
    int DATA;
    struct NODE *LEFT, *RIGHT;
} *ROOT_NODE = NULL;
struct NODE *NEW_NODE(int DATA)
{
    struct NODE *NEW_N = (struct NODE *)malloc(sizeof(struct NODE));
    NEW_N->DATA = DATA;
    NEW_N->LEFT = NULL;
    NEW_N->RIGHT = NULL;
    return NEW_N;
}
struct NODE *INSERT_NODE(struct NODE *ROOT, int DATA)
{
    if (ROOT == NULL)
        return NEW_NODE(DATA);
    else if (ROOT->DATA > DATA)
        ROOT->LEFT = INSERT_NODE(ROOT->LEFT, DATA);
    else
        ROOT->RIGHT = INSERT_NODE(ROOT->RIGHT, DATA);
    return ROOT;
}
void TREE_SORT(struct NODE *TEMP)
{
    if (TEMP != NULL)
    {
        TREE_SORT(TEMP->LEFT);
        printf("%d ", TEMP->DATA);
        TREE_SORT(TEMP->RIGHT);
    }
}
int main()
{
    printf("ENTER NUMBER OF ELEMENT : ");
    int NUM;
    scanf("%d", &NUM);
    int ARR[NUM];
    for (int i = 0; i < NUM; i++)
    {
        int A;
        scanf("%d", &A);
        ROOT_NODE = INSERT_NODE(ROOT_NODE, A);
    }
    printf("SORTED : ");
    TREE_SORT(ROOT_NODE);
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int countDigit(long long n)
{
    return floor(log10(n) + 1);
}
int INDEX = 0;
// [ O O ] TirthPatel3108
//    -
//    ~
struct NODE
{
    int DATA;
    struct NODE *NEXT;
} * HEAD[10];
// O---------------------------O
// | INSERT VALUE IN LINK LIST |
// O---------------------------O
void CREATE_NODE(int DATA, int HASH)
{
    struct NODE *NEW_NODE = (struct NODE *)malloc(sizeof(struct NODE));
    NEW_NODE->DATA = DATA;
    if (HEAD[HASH] == NULL)
    {
        HEAD[HASH] = NEW_NODE;
        HEAD[HASH]->NEXT = NULL;
        return;
    }
    else if (HEAD[HASH]->DATA >= DATA)
    {
        NEW_NODE->NEXT = HEAD[HASH];
        HEAD[HASH] = NEW_NODE;
    }
    else
    {
        struct NODE *TEMP;
        TEMP = HEAD[HASH];
        while (TEMP->NEXT != NULL && TEMP->NEXT->DATA <= DATA)
            TEMP = TEMP->NEXT;
        NEW_NODE->NEXT = TEMP->NEXT;
        TEMP->NEXT = NEW_NODE;
    }
}
void PRINT(int *ARR, struct NODE *TEMP)
{
    while (TEMP != NULL)
    {
        printf("%d", TEMP->DATA);
        ARR[INDEX++] = TEMP->DATA;
        if (TEMP->NEXT != NULL)
            printf("->");
        TEMP = TEMP->NEXT;
    }
    printf("\n");
}
int FIND_HASH(int NUM, int K)
{
    int DIGIT_;
    for (int i = 1; i <= K; i++)
    {
        DIGIT_ = NUM % 10;
        NUM /= 10;
    }
    return DIGIT_;
}
int main()
{
    printf("ENTER NUMBER OF ELEMENT : ");
    int NUM;
    scanf("%d", &NUM);
    int ARR[NUM];
    int MAX_DIG = 0;
    int FINAL_ARR[NUM];
    printf("ENTER %d ELEMENT : ", NUM);
    for (int i = 0; i < NUM; i++)
    {
        scanf("%d", &ARR[i]);
    }
    for (int i = 0; i < NUM; i++)
    {
        if (countDigit(ARR[i]) > MAX_DIG)
            MAX_DIG = countDigit(ARR[i]);
    }
    for (int i = 0; i < NUM; i++)
    {
        int HASH_ = FIND_HASH(ARR[i], MAX_DIG);
        CREATE_NODE(ARR[i], HASH_);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("HEAD[%d] : ", i);
        PRINT(FINAL_ARR, HEAD[i]);
    }
    printf("SORTED LIST : ");
    for (int i = 0; i < INDEX; i++)
    {
        printf("%d ", FINAL_ARR[i]);
    }
}

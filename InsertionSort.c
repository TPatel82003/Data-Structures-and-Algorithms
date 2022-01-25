#include <stdio.h>
#include <stdlib.h>
void INSERTION_SORT(int *ARR, int LEN)
{
    for (int i = 1; i < LEN; i++)
    {
        int CURRENT_ELEM_ = ARR[i];
        int ITER_ = i - 1;
        while (CURRENT_ELEM_ < ARR[i] && ITER_ >= 0)
        {
            ARR[ITER_ + 1] = ARR[ITER_];
            ITER_--;
        }
        ARR[ITER_ + 1] = CURRENT_ELEM_;
    }
}
void DISPLAY(int ARR[], int LEN)
{
    printf("SORTED ARRAY : ");
    for (int i = 0; i < LEN; i++)
    {
        printf("%d ", ARR[i]);
    }
    printf("\n");
}
int main()
{
    printf("ENTER NUMBER OF ELEMENT : ");
    int NUM;
    scanf("%d", &NUM);
    int ARR[NUM];
    for (int i = 0; i < NUM; i++)
    {
        scanf("%d", &ARR[i]);
    }
    INSERTION_SORT(ARR, NUM);
    DISPLAY(ARR, NUM);
}
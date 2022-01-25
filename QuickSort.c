#include <stdio.h>
#include <stdlib.h>
void swap(int *X_, int *Y_)
{
    int temp = *X_;
    *X_ = *Y_;
    *Y_ = temp;
}
void QUICK_SORT(int *ARR, int BEG, int END)
{
    if (BEG < END)
    {
        int PART_ = PARTITION(ARR, BEG, END);
        QUICK_SORT(ARR, BEG, PART_ - 1);
        QUICK_SORT(ARR, PART_ + 1, END);
    }
}
int PARTITION(int *ARR, int BEG, int END)
{
    int PIVOT_ = ARR[END];
    int PINDEX_ = BEG;
    for (int i = BEG; i < END; i++)
    {
        if (ARR[i] <= PIVOT_)
        {
            swap(&ARR[i], &ARR[PINDEX_]);
            PINDEX_++;
        }
    }
    swap(&ARR[PINDEX_], &ARR[END]);
    return PINDEX_;
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
    QUICK_SORT(ARR, 0, NUM - 1);
    DISPLAY(ARR, NUM);
}
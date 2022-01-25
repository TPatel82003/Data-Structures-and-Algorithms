#include <stdio.h>
#include <stdlib.h>
void swap(int *X_, int *Y_)
{
    int temp = *X_;
    *X_ = *Y_;
    *Y_ = temp;
}
void SHELL_SORT(int *ARR, int LEN)
{
    for (int GAP = LEN / 2; GAP > 0; GAP /= 2)
    {
        printf("GAP : %d\n", GAP);
        for (int J = GAP; J < LEN; J++)
        {
            int LAST_ELEM_ = ARR[J];
            int COMPARE_ELEM_INDEX = 0;
            for (COMPARE_ELEM_INDEX = J; COMPARE_ELEM_INDEX >= GAP && ARR[COMPARE_ELEM_INDEX - GAP] > LAST_ELEM_; COMPARE_ELEM_INDEX -= GAP)
            {
                ARR[COMPARE_ELEM_INDEX] = ARR[COMPARE_ELEM_INDEX - GAP];
            }
            ARR[COMPARE_ELEM_INDEX] = LAST_ELEM_;
            DISPLAY(ARR, LEN);
        }
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
    SHELL_SORT(ARR, NUM);
    DISPLAY(ARR, NUM);
}
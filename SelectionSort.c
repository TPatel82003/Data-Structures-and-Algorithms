#include <stdio.h>
#include <stdlib.h>
void SELECTION_SORT(int *ARR, int NUM) // [COMPLEXITY : O(N*2) 60% EFFICIENT THAN BUBBLE]
{
    for (int i = 0; i < NUM; i++)
    {
        int SMALLET_POS_ = SMALLEST(ARR, i, NUM);
        int TEMP = ARR[SMALLET_POS_];
        ARR[SMALLET_POS_] = ARR[i];
        ARR[i] = TEMP;
    }
}
int SMALLEST(int ARR[], int START, int END)
{
    int SMALLE_ELEM_ = ARR[START];
    int SMALLE_POS_ = START;
    for (int i = START + 1; i < END; i++)
    {
        if (ARR[i] < SMALLE_ELEM_)
        {
            SMALLE_ELEM_ = ARR[i];
            SMALLE_POS_ = i;
        }
    }
    return SMALLE_POS_;
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
    SELECTION_SORT(ARR, NUM);
    DISPLAY(ARR, NUM);
}
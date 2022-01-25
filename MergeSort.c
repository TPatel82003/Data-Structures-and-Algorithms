#include <stdio.h>
#include <stdlib.h>
void MERGE(int *ARR, int BEG, int MID, int END, int NUM) //[COMPLEXITY : O(N*log(N)) SPACE EXTRA : O(N)]
{
    int TEMP[NUM], I = BEG, J = MID + 1, K = BEG;
    while (I <= MID && J <= END)
    {
        if (ARR[I] <= ARR[J])
        {
            TEMP[K] = ARR[I];
            I++;
            K++;
        }
        else
        {
            TEMP[K] = ARR[J];
            K++;
            J++;
        }
    }
    while (I <= MID)
    {
        TEMP[K] = ARR[I];
        I++;
        K++;
    }
    while (J <= END)
    {
        TEMP[K] = ARR[J];
        K++;
        J++;
    }
    for (int i = BEG; i < K; i++)
    {
        ARR[i] = TEMP[i];
    }
}
void MERGE_SORT(int *ARR, int BEG, int END, int NUM)
{
    if (BEG < END)
    {
        int MID = (BEG + END) / 2;
        MERGE_SORT(ARR, BEG, MID, NUM);
        MERGE_SORT(ARR, MID + 1, END, NUM);
        MERGE(ARR, BEG, MID, END, NUM);
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
    MERGE_SORT(ARR, 0, NUM - 1, NUM);
    DISPLAY(ARR, NUM);
}
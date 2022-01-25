#include <stdio.h>
#include <stdlib.h>
void BUBBLE_SORT(int *ARR, int LEN) //[COMPLEXITY  : O(N*2)]
{
    int FLAG = 0; 
    for (int i = 0; i < LEN - 1; i++)
    {
        for (int j = i + 1; j < LEN; j++)
        {
            if (ARR[i] > ARR[j])
            {
                FLAG = 1;
                int TEMP = ARR[i];
                ARR[i] = ARR[j];
                ARR[j] = TEMP;
            }
        }
        if(FLAG)
        return;
    }
}
void DISPALY(int ARR[], int LEN)
{
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
    BUBBLE_SORT(ARR, NUM);
    DISPALY(ARR,NUM);
}
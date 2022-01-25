#include <stdio.h>
#include <stdlib.h>
#define __LOOP(N) for (int i = 0; i < N; i++)
void COUNTIING_SORT(int *ARR, int BASE_, int SIZE_)
{
    int CNT[10], OUTPUT_[SIZE_];
    __LOOP(10)
    CNT[i] = 0;
    __LOOP(SIZE_)
    CNT[(ARR[i] / BASE_) % 10]++;
    for (int i = 1; i < 10; i++)
        CNT[i] += CNT[i - 1];
    for (int i = SIZE_ - 1; i >= 0; i--)
    {
        OUTPUT_[CNT[(ARR[i] / BASE_) % 10] - 1] = ARR[i];
        CNT[(ARR[i] / BASE_) % 10]--;
    }
    __LOOP(SIZE_)
    ARR[i] = OUTPUT_[i];
}
void RADIX_SORT(int *ARR, int MAX_, int SIZE_)
{
    for (int i = 1; MAX_ / i > 0; i *= 10)
    {
        COUNTIING_SORT(ARR, i, SIZE_);
    }
    for (int i = 0; i < SIZE_; i++)
    {
        printf("%d ", ARR[i]);
    }
}
int GET_MAX(int ARR[], int SIZE_)
{
    int MAX_ = INT_MIN;
    __LOOP(SIZE_)
    {
        if (MAX_ < ARR[i])
            MAX_ = ARR[i];
    }
    return MAX_;
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
    int MAX_ = GET_MAX(ARR, NUM);
    RADIX_SORT(ARR, MAX_, NUM);
}
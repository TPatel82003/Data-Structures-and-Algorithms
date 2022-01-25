#include <stdio.h>
#define MAX_SIZE 10
int QUEUE[MAX_SIZE];
int FRONT = -1;
int REAR = -1;
int QINSERT(int NUM)
{
    if (REAR == (MAX_SIZE - 1))
        printf("QUEUE IS OVERFLOW");
    else
    {
        if (FRONT == -1)
        {
            FRONT = 0;
            REAR = 0;
        }
        else
            REAR++;
        QUEUE[REAR] = NUM;
        printf("%d : INSERTED IN QUEUE\n", NUM);
    }
}
int QDELETE()
{
    if (FRONT == -1 || FRONT > REAR)
    {
        printf("UNDERFLOW\n");
    }
    else
    {
        printf("%d : DELETED FROM QUEUE\n", QUEUE[FRONT]);
        FRONT = FRONT + 1;
    }
}
void VALUES()
{
    if (!(FRONT > REAR))
    {
        printf("QUEUE : ");
        for (int i = FRONT; i <= REAR; i++)
        {
            printf("%d ", QUEUE[i]);
        }
        printf("\n");
    }
    else
        printf("QUEUE IS EMPTY\n");
}
int main()
{
    QINSERT(12);
    QINSERT(13);
    QINSERT(14);
    VALUES();
    QDELETE();
    QDELETE();
    QDELETE();
    VALUES();
}
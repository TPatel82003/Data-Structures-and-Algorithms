#include <stdio.h>
#define MAX_SIZE 10
char QUEUE[MAX_SIZE];
int FRONT = -1;
int REAR = -1;
int QINSERT(int NUM)
{
    if (FRONT == 0 && REAR == MAX_SIZE - 1 || FRONT == REAR + 1)
    {
        printf("QUEUE IS OVERLOW\n");
        return 0;
    }
    else
    {
        if (FRONT == -1)
        {
            FRONT = 0;
            REAR = 0;
        }
        else
        {
            if (REAR == MAX_SIZE - 1)
            {
                REAR = 0;
            }
            else
                REAR++;
        }
        QUEUE[REAR] = NUM;
    }
}
int QDELETE()
{
    if (FRONT == -1)
    {
        printf("QUEUE IS UNDERFLOW\n");
    }
    else
    {
        printf("%d : IS DELETED FROM QUEUE\n", QUEUE[FRONT]);
        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else
        {
            if (FRONT == MAX_SIZE - 1)
                FRONT = 0;
            else
                FRONT++;
        }
    }
}
int DISPLAY()
{
    int FRONT_POSITION = FRONT;
    int REAR_POSITION = REAR;
    if (FRONT_POSITION <= REAR_POSITION)
    {
        while (FRONT_POSITION <= REAR_POSITION)
        {
            printf("%d ", QUEUE[FRONT_POSITION]);
            FRONT_POSITION++;
        }
    }
    else
    {
        while (FRONT <= MAX_SIZE - 1)
        {
            printf("%d ", QUEUE[FRONT_POSITION]);
            FRONT_POSITION++;
        }
        FRONT_POSITION = 0;
        while (FRONT_POSITION <= REAR_POSITION)
        {
            printf("%d ", QUEUE[FRONT_POSITION]);
            FRONT_POSITION++;
        }
    }
    printf("\n");
}
int main()
{
    // MAIN OPERTAION QINSERT AND QDELETE
    for (int i = 0; i < 10; i++)
    {
        QINSERT(i + 1);
    }
    DISPLAY();
    for (int i = 0; i < 5; i++)
    {
        QDELETE();
    }
    DISPLAY();
}
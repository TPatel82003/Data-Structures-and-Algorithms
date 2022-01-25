#include <stdio.h>
#define MAX_SIZE 100
int QUEUE[MAX_SIZE];
int FRONT = -1;
int REAR = -1;
int INSERT_REAR(int NUM)
{
    if ((FRONT == 0 && REAR == MAX_SIZE - 1) || (FRONT == REAR + 1))
        printf("QUEUE IS OVERFLOW");
    if (FRONT == -1)
    {
        FRONT = 0;
        REAR = 0;
    }
    else if (REAR == MAX_SIZE - 1)
        REAR = 0;
    else
        REAR++;
    QUEUE[REAR] = NUM;
}
int INSERT_FRONT(int NUM)
{
    if ((FRONT == 0 && REAR == MAX_SIZE - 1) || (FRONT == REAR + 1))
        printf("QUEUE IS OVERFLOW");
    if (FRONT == -1)
    {
        FRONT = 0;
        REAR = 0;
    }
    else if (FRONT == 0)
        FRONT = MAX_SIZE - 1;
    else
        FRONT -= 1;

    QUEUE[FRONT] = NUM;
}
int DELETE_FRONT()
{
    if (FRONT == -1)
        printf("QUEUE IS UNDERFLOW");
    else
    {
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
int DELETE_REAR()
{
    if (FRONT == -1)
        printf("QUEUE IS UNDERFLOW");
    else
    {
        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else
        {
            if (REAR == 0)
            {
                REAR = MAX_SIZE - 1;
            }
            else
                REAR -= 1;
        }
    }
}
void DISPLAY()
{
    int FRONT_POSITION = FRONT;
    int REAR_POSITION = REAR;
    if (FRONT == -1)
    {
        printf("Queue is empty\n");
    }
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
        while (FRONT_POSITION <= MAX_SIZE - 1)
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
    INSERT_REAR(15);
    INSERT_FRONT(16);
    INSERT_REAR(17);
    INSERT_FRONT(40);
    DISPLAY();
}
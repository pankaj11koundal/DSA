#include <stdio.h>
#include <stdlib.h>

#define max 50;
int front = -1, rear = -1;

void Enqueue(int Q[], int size)
{
    int val;
    printf("Enter the value you want to insert in the queue: ");
    scanf("%d", &val);
    if (rear + 1 == size)
    {
        printf("Unable to enqueue, queue is full\n");
    }
    else if (rear == -1 && front == -1)
    {
        rear = 0;
        front = 0;
    }
    else
    {
        rear++;
    }
    Q[rear] = val;
}

void Dequeue(int Q[])
{
    if (front == -1 && rear == -1)
    {
        printf("Unable to dequeue, queue is empty\n");
    }
    else if (front == rear)
    {
        rear = -1;
        front = -1;
    }
    else
    {
        front++;
    }
}

void Display(int Q[])
{
    if (front == -1 && rear == -1)
    {
        printf("Nothing to show, queue is empty\n");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("Element in the queue at position %d is %d\n", i + 1, Q[i]);
        }
    }
}

void main()
{
    int size, Q[50], op;

    printf("Enter the size of the queue: ");
    scanf("%d", &size);

    while (1)
    {
        printf("Choose the option from below: \n");
        printf("1) Enqueue\n");
        printf("2) Dequeue\n");
        printf("3) Display\n");
        printf("4) Exit: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            Enqueue(Q, size);
            break;
        case 2:
            Dequeue(Q);
            break;
        case 3:
            Display(Q);
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("Wrong choice entered");
            break;
        }
    }
}
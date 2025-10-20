#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int queue_array[SIZE];
int front = -1;
int rear = -1;
int item, choice;

void EnQueueFront()
{
    if (front == -1 && rear == SIZE - 1)
    {
        printf("Queue Overflow\n");
    }

    printf("Inset the element in queue : ");
    scanf("%d", &item);

    if ((front == -1))
    {
        front = rear = 0;
    }
    else if (front == 0)
    {
        front = SIZE - 1;
    }
    else
    {
        front = front - 1;
    }
    queue_array[front] = item;
}

void EnQueueRear()
{
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
    {
        printf("Queue Overflow\n");
    }

    printf("Inset the element in queue : ");
    scanf("%d", &item);

    if (front == -1)
    {
        front = rear = 0;
    }
    else if (rear == SIZE - 1)
    {
        rear = 0;
    }
    else
    {
        rear = rear + 1;
    }
    queue_array[rear] = item;
}

void DeQueueFront()
{
    if (front == -1)
    {
        printf("Queue Underflow \n");
    }

    printf("Element deleted from queue is : %d\n", queue_array[front]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == SIZE - 1)
    {
        front = 0;
    }
    else
    {
        front = front + 1;
    }
}

void DeQueueRear()
{
    if (rear == -1)
    {
        printf("Queue Underflow \n");
    }

    printf("Element deleted from queue is : %d\n", queue_array[rear]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (rear == 0)
    {
        rear = SIZE - 1;
    }
    else
    {
        rear = rear - 1;
    }
}

void Display()
{
    if (front == -1)
        printf("Queue is empty\n");
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("Element %d : %d\n", i, queue_array[i]);
        }
    }
}

void main()
{
    while (1)
    {
        printf("Enter 1 insert element at front of the queue\n");
        printf("Enter 2 insert element at rear of the queue\n");
        printf("Enter 3 delete element from front of the queue\n");
        printf("Enter 4 delete element from rear of the queue\n");
        printf("Enter 5 display element of the queue\n");
        printf("Enter 6 to exit program\n");

        printf("Enter choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            EnQueueFront();
            break;
        case 2:
            EnQueueRear();
            break;
        case 3:
            DeQueueFront();
            break;
        case 4:
            DeQueueRear();
            break;
        case 5:
            Display();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}

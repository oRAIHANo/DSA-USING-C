#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int cqueue_array[SIZE];
int front = -1;
int rear = -1;
int value, choice;

void EnQueue()
{
    if ((rear + 1) % SIZE == front)
    {
        printf("Queue Overflow \n");
        return; // Exit the function to avoid further execution
    }
    else
    {
        if (front == -1)
            /*If queue is initially empty */
            front = 0;
        printf("Inset the element in queue : ");
        scanf("%d", &value);
        rear = (rear + 1) % SIZE; // circular increment
        cqueue_array[rear] = value;
    }
}

void DeQueue()
{
    if (front == -1)
    {
        printf("Queue Underflow \n");
        return;
    }
    else
    {
        printf("Element deleted from the queue : %d\n", cqueue_array[front]);
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE; // circular increment
        }
    }
}

// void Display()
// {
//     if (front == -1)
//         printf("Queue is empty \n");
//     else
//     {
//         for (int i = front; i != (rear + 1) % SIZE; i = (i + 1) % SIZE)
//             printf("Element %d : %d\n", i, cqueue_array[i]);
//     }
// }

void Display()
{
    if (front == -1)
        printf("Queue is empty \n");
    else
    {
        int i = front;
        do
        {
            printf("Element %d : %d\n", i, cqueue_array[i]);
            i = (i + 1) % SIZE;
        } while (i != (rear + 1) % SIZE);
    }
}

void main()
{
    printf("Enter 1 Insert element to queue \n");
    printf("Enter 2 Delete element from queue \n");
    printf("Enter 3 Display all elements of queue \n");
    printf("Enter 4 Quit \n");
    while (1)
    {

        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            EnQueue();
            break;
        case 2:
            DeQueue();
            break;
        case 3:
            Display();
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice \n");
        }
    }
}

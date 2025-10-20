#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int queue_array[SIZE];
int rear = -1;
int front = -1;
int item, choice;

// code for insertion into the queue
void EnQueue()
{
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
    {
        printf("Queue Overflow \n");
    }
    else
    {
        if (front == -1)
            /*If queue is initially empty */
            front = 0;
        printf("Inset the element in queue : ");
        scanf("%d", &item);
        rear = rear + 1;
        queue_array[rear] = item;
    }
} /* End of insert() */

void DeQueue()
{
    if (front == -1)
    {
        printf("Queue Underflow \n");
        return;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", queue_array[front]);
        front = front + 1;
    }
} /* End of delete() */

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
        printf("Enter 1 Insert element to queue \n");
        printf("Enter 2 Delete element from queue \n");
        printf("Enter 3 Display all elements of queue \n");
        printf("Enter 4 Quit \n");

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
        } /* End of switch */
    }     /* End of while */
} /* End of main() */

#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int data;
    struct queue *link;
};

struct queue *front = NULL, *rear = NULL, *ptr;
int item, choice;

void EnQueue()
{
    struct queue *newnode = (struct queue *)malloc(sizeof(struct queue));
    if (newnode == NULL)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        printf("Inset the element in queue : ");
        scanf("%d", &item);
        newnode->data = item;
        newnode->link = NULL;
        if (front == NULL) // (front = NULL )
        {
            front = rear = newnode;
        }
        else
        {
            rear->link = newnode;
            rear = newnode;
        }
    }
}

void DeQueue()
{
    if (front == NULL)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        int value = -1;
        ptr = front;
        front = front->link;
        value = ptr->data;
        free(ptr);
        printf("Deleted %d from the front of the queue\n", value);
    }
}

// code for linked list traversal
void LinkedListTraversal()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        int i = 0;
        ptr = front;
        while (ptr != NULL)
        {
            i++;
            printf("Element %d : %d\n", i, ptr->data);
            ptr = ptr->link;
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
            LinkedListTraversal();
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice \n");
        } /* End of switch */
    }     /* End of while */
} /* End of main() */

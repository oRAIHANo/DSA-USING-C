// Case 1 : Deletion at the beginning
// Case 2 : Deletion at the middle or between
// Case 3 : Deletion at the end
// Case 4 : Deletion of a node with given value

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head, *ptr;
int value, choice, position;

// code for insertion at the beginning
void InsertNodeAtBeginning()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value of the new node : ");
    scanf("%d", &value);
    newnode->data = value;
    newnode->link = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->link = head;
        head = newnode;
    }
}

// code for deletion at the beginning
void DeleteNodeAtBeginning()
{
    if (head == NULL)
    {
        printf("Linked list is empty");
    }
    else
    {
        ptr = head;
        head = head->link;
        free(ptr);
    }
}

// code for deletion at the middle
void DeleteNodeAtMiddle()
{
    if (head == NULL)
    {
        printf("Linked list is empty");
    }
    else
    {
        printf("Enter index of node that you want to delete : ");
        scanf("%d", &position);
        struct node *p = head;
        struct node *q = head->link;
        for (int i = 0; i < position - 1; i++)
        {
            p = p->link;
            q = q->link;
        }
        p->link = q->link;
        free(q);
    }
}

// code for deletion at the end
void DeleteNodeAtEnd()
{
    if (head == NULL)
    {
        printf("Linked list is empty");
    }
    else
    {
        struct node *p = head;
        struct node *q = head->link;

        while (q->link != NULL)
        {
            p = p->link;
            q = q->link;
        }
        p->link = NULL;
        free(q);
    }
}

// code for deletion of a node with given value
void DeleteNodeAtValue()
{
    if (head == NULL)
    {
        printf("Linked list is empty");
    }
    else
    {
        printf("Enter the value of the node : ");
        scanf("%d", &value);
        struct node *p = head;
        struct node *q = head->link;
        while (q->data != value && q->link != NULL)
        {
            p = p->link;
            q = q->link;
        }

        if (q->data == value)
        {
            p->link = q->link;
            free(q);
        }
    }
}

// code for linked list traversal
void LinkedListTraversal()
{
    if (head == NULL)
    {
        printf("Linked List is empty\n");
    }
    else
    {
        int i = 0;
        ptr = head;
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
        printf("\nMenu\n");
        printf("Enter 1 to delete node at the beginning of the linked list\n");
        printf("Enter 2 to delete node at the middle of the linked list\n");
        printf("Enter 3 to delete node at the end of the linked list\n");
        printf("Enter 4 to delete node at the given value\n");
        printf("Enter 5 to Display all elements of the linked list\n");
        printf("Enter 6 to insert node at the beginning of the linked list\n");
        printf("Enter 7 to Exit\n");

        printf("Enter choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            DeleteNodeAtBeginning();
            break;
        case 2:
            DeleteNodeAtMiddle();
            break;
        case 3:
            DeleteNodeAtEnd();
            break;
        case 4:
            DeleteNodeAtValue();
            break;
        case 5:
            LinkedListTraversal();
            break;
        case 6:
            InsertNodeAtBeginning();
            break;
        case 7:
            printf("Exiting program");
            exit(0);
            break;
        default:
            printf("Choice is invalid");
            break;
        }
    }
}

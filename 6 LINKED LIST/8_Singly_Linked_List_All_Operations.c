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
        newnode->link = head; // linking the new node with the already existing node
        head = newnode;       // pointing head to the newly created node
    }
}

// code for insertion at the middle
void InsertNodeAtMiddle()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter index at which you want to enter node : ");
    scanf("%d", &position);
    printf("Enter the value of the new node : ");
    scanf("%d", &value);
    newnode->data = value;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        ptr = head;
        int i = 0;
        while (i != position - 1)
        {
            ptr = ptr->link;
            i++;
        }

        newnode->link = ptr->link;
        ptr->link = newnode;
    }
}

// code for insertion at the end
void InsertNodeAtEnd()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value of the new node : ");
    scanf("%d", &value);
    newnode->data = value;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        ptr = head;
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = newnode;
        newnode->link = NULL;
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
    int i = 0;
    ptr = head;
    while (ptr != NULL)
    {
        i++;
        printf("Element %d : %d\n", i, ptr->data);
        ptr = ptr->link;
    }
}

void main()
{
    printf("\nMenu\n");
    printf("Enter 1 to insert node at the beginning of the linked list\n");
    printf("Enter 2 to insert node at the middle of the linked list\n");
    printf("Enter 3 to insert node at the end of the linked list\n");
    printf("Enter 4 to delete node at the beginning of the linked list\n");
    printf("Enter 5 to delete node at the middle of the linked list\n");
    printf("Enter 6 to delete node at the end of the linked list\n");
    printf("Enter 7 to delete node at the given value\n");
    printf("Enter 8 to Display all elements of the linked list\n");
    printf("Enter 9 to Exit\n");

    while (1)
    {
        printf("Enter choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            InsertNodeAtBeginning();
            break;
        case 2:
            InsertNodeAtMiddle();
            break;
        case 3:
            InsertNodeAtEnd();
            break;
        case 4:
            DeleteNodeAtBeginning();
            break;
        case 5:
            DeleteNodeAtMiddle();
            break;
        case 6:
            DeleteNodeAtEnd();
            break;
        case 7:
            DeleteNodeAtValue();
            break;
        case 8:
            LinkedListTraversal();
            break;
        case 9:
            printf("Exiting program");
            exit(0);
            break;
        default:
            printf("Invalid choice");
            break;
        }
    }
}
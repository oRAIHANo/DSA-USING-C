// Case 1 : Insertion at the beginning
// Case 2 : Insertion at the middle or between
// Case 3 : Insertion at the end
// Case 4 : Insertion after a node

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head = NULL, *ptr;
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
        head = newnode; // pointing head to the newly created node
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
        // for(int i =0; i<position-1; i++)
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
        printf("Enter 1 to insert node at the beginning of the linked list\n");
        printf("Enter 2 to insert node at the middle of the linked list\n");
        printf("Enter 3 to insert node at the end of the linked list\n");
        printf("Enter 4 to Display all elements of the linked list\n");
        printf("Enter 5 to Exit\n");

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
            LinkedListTraversal();
            break;
        case 5:
            printf("Exiting program");
            exit(0);
            break;
        default:
            printf("Choice is invalid");
            break;
        }
    }
}
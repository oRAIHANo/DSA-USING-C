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
// Structure of a circular linked list node
struct node {
    int data;
    struct node *link;  // pointer to the next node
};

struct node *head = NULL, *ptr;
int value;

// Code for insertion at the beginning
void InsertNodeAtBeginning() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value of the new node: ");
    scanf("%d", &value);
    newnode->data = value;

    // Case 1: Empty list
    if (head == NULL) {
        head = newnode;
        newnode->link = head; // points to itself
    } 
    else {
        ptr = head;
        // Traverse to the last node
        while (ptr->link != head) {
            ptr = ptr->link;
        }
        // Adjust links
        ptr->link = newnode;   // last node points to new node
        newnode->link = head;  // new node points to old head
        head = newnode;        // update head to new node
    }
    printf("Node inserted at the beginning successfully.\n");
}


void InsertNodeAtMiddle(){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter index at which you want to enter node : ");
    scanf("%d", &position);
    printf("Enter the value of the new node : ");
    scanf("%d", &value);
    newnode->data = value;

    if (head == NULL)
    {
        head = newnode;
        head->link = head;
    }
    else
    {
        int i = 0;
        ptr = head;
        while (i != position - 1)
        {
            ptr = ptr->link;
            i++;
        }
        // At this point we are at the end of the circular linked list
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
    newnode->link = NULL;
    if (head == NULL)
    {
        head = newnode;
        head->link = head;
    }
    else
    {
        ptr = head;
        while (ptr->link != head)
        {
            ptr = ptr->link;
        }
        // At this point we are at the end of the circular linked list
        ptr->link = newnode;
        newnode->link = head;
    }
}

// code for linked list traversal
// At the end of the while the currentNode will be head but you need to stop at the node before the head.
// There will be no troubles if you use a while loop. All you need to do is to start from the next node after head and go until the node before head.
// void LinkedListTraversal()
// {
//     ptr = head;
//     printf("Element : %d\n", ptr->data);
//     ptr = ptr->link;
//     while (ptr != head)
//     {
//         printf("Element : %d\n", ptr->data);
//         ptr = ptr->link;
//     }
// }

// code for linked list traversal (Using do while loop is a better way)
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
        do
        {
            i++;
            printf("Element %d : %d\n", i, ptr->data);
            ptr = ptr->link;
        } while (ptr != head);
    }
}

void main()
{
    while (1)
    {
        printf("\nMenu\n");
        printf("Enter 1 to insert node at the beginning of the circular linked list\n");
        printf("Enter 2 to insert node at the middle of the circular linked list\n");
        printf("Enter 3 to insert node at the end of the circular linked list\n");
        printf("Enter 4 to Display all elements of the circular linked list\n");
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
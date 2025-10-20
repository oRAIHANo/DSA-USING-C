#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prevlink;
    struct node *nextlink;
};

struct node *head, *ptr;
int value, position, choice;

// Code to delete element one after the other so that we can test
void InsertNode() {
    printf("Enter the value: ");
    scanf("%d", &value);

    // Create a new node
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->nextlink = NULL;
    newnode->prevlink = NULL;

    // If the list is empty
    if (head == NULL) {
        head = newnode;
    } 
    else {
        ptr = head;
        // Move to the last node
        while (ptr->nextlink != NULL) {
            ptr = ptr->nextlink;
        }
        // Link the new node
        ptr->nextlink = newnode;
        newnode->prevlink = ptr;
    }

    printf("Node with value %d deleteed successfully.\n", value);
}

void DeleteNodeAtBeginning() {
    if (head == NULL) {
        printf("Linked list is empty\n");
    } else {
        ptr = head;                  // Store the current head node
        head = head->nextlink;       // Move head to next node
        if (head != NULL) {
            head->prevlink = NULL;   // Set new head’s prevlink to NULL
        }
        free(ptr);                   // Free the old head node
        printf("Node deleted from beginning\n");
    }
}

void DeleteNodeAtMiddle() {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    int position;
    printf("Enter the position to delete: ");
    scanf("%d", &position);

    struct node *ptr = head;

    // If deleting the first node
    if (position == 1) {
        head = head->nextlink;
        if (head != NULL)
            head->prevlink = NULL;
        free(ptr);
        printf("Node deleted at position 1\n");
        return;
    }

    // Traverse to the node at given position
    for (int i = 1; i < position && ptr != NULL; i++) {
        ptr = ptr->nextlink;
    }

    // If position is invalid
    if (ptr == NULL) {
        printf("Invalid position\n");
        return;
    }

    // Adjust the links
    if (ptr->prevlink != NULL)
        ptr->prevlink->nextlink = ptr->nextlink;

    if (ptr->nextlink != NULL)
        ptr->nextlink->prevlink = ptr->prevlink;

    free(ptr);
    printf("Node deleted at position %d\n", position);
}

void DeleteNodeAtEnd() {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    struct node *ptr = head;

    // Case 1: Only one node
    if (head->nextlink == NULL) {
        head = NULL;
        free(ptr);
        printf("Node deleted from end (only node)\n");
        return;
    }

    // Case 2: Traverse to the last node
    while (ptr->nextlink != NULL) {
        ptr = ptr->nextlink;
    }

    // Adjust links
    ptr->prevlink->nextlink = NULL;
    free(ptr);

    printf("Node deleted from end\n");
}

void DeleteNodeByValue() {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    int value;
    printf("Enter the value to delete: ");
    scanf("%d", &value);

    struct node *ptr = head;

    // Traverse until we find the node with the value
    while (ptr != NULL && ptr->data != value) {
        ptr = ptr->nextlink;
    }

    // If not found
    if (ptr == NULL) {
        printf("Value %d not found in the list\n", value);
        return;
    }

    // Case 1: Node is the first node
    if (ptr == head) {
        head = head->nextlink;
        if (head != NULL)
            head->prevlink = NULL;
        free(ptr);
        printf("Node with value %d deleted (was at beginning)\n", value);
        return;
    }

    // Case 2: Node is the last node
    if (ptr->nextlink == NULL) {
        ptr->prevlink->nextlink = NULL;
        free(ptr);
        printf("Node with value %d deleted (was at end)\n", value);
        return;
    }

    // Case 3: Node is in the middle
    ptr->prevlink->nextlink = ptr->nextlink;
    ptr->nextlink->prevlink = ptr->prevlink;
    free(ptr);

    printf("Node with value %d deleted (from middle)\n", value);
}

// code for linked list traversal
void LinkedListTraversal()
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->nextlink;
    }
}

void main()
{
    printf("\nMenu\n");
    printf("Enter 1 to insert node one after the other in a doubly linked list\n");
    printf("Enter 2 to delete node at the beginning of the doubly linked list\n");
    printf("Enter 3 to delete node at the middle of the doubly linked list\n");
    printf("Enter 4 to delete node at the end of the doubly linked list\n");
    printf("Enter 5 to delete node at after the value of the doubly linked list\n");
    printf("Enter 6 to Display all elements of the linked list\n");
    printf("Enter 7 to Exit\n");

    while (1)
    {
        printf("Enter choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            InsertNode();
            break;
        case 2:
            DeleteNodeAtBeginning();
            break;
        case 3:
            DeleteNodeAtMiddle();
            break;
        case 4:
            DeleteNodeAtEnd();
            break;
        case 5:
            DeleteNodeByValue();
            break;
        case 6:
            LinkedListTraversal();
            break;
        case 7:
            printf("Exiting program");
            exit(0);
            break;
        default:
            printf("Invalid choice");
            break;
        }
    }
}
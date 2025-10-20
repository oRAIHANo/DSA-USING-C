#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prevlink;
    struct node *nextlink;
};

struct node *head, *ptr;
int value, position, choice;

// Code to insert element one after the other so that we can test
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

    printf("Node with value %d inserted successfully.\n", value);
}

void InsertNodeAtBeginning() {
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
        newnode->nextlink = head;  // Link new node to the old head
        head->prevlink = newnode;  // Old head points back to new node
        head = newnode;            // Move head to new node
    }

    printf("Node with value %d inserted at the beginning.\n", value);
}

void InsertNodeAtMiddle() {
    printf("Enter index (starting from 1): ");
    scanf("%d", &position);
    printf("Enter the value: ");
    scanf("%d", &value);

    // Create a new node
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->nextlink = NULL;
    newnode->prevlink = NULL;

    // If list is empty
    if (head == NULL) {
        if (position == 1) {
            head = newnode;
            printf("Node inserted as the first element.\n");
        } else {
            printf("List is empty, invalid index.\n");
            free(newnode);
        }
        return;
    }

    // If inserting at the beginning
    if (position == 1) {
        newnode->nextlink = head;
        head->prevlink = newnode;
        head = newnode;
        printf("Node with value %d inserted at position 1.\n", value);
        return;
    }

    // Traverse to the (index - 1)th node
    ptr = head;
    for (int i = 1; i < position - 1 && ptr->nextlink != NULL; i++) {
        ptr = ptr->nextlink;
    }

    // Insert after node p
    newnode->nextlink = ptr->nextlink;
    newnode->prevlink = ptr;
    // if (p->nextlink != NULL)
    //     p->nextlink->prevlink = newnode;
    ptr->nextlink = newnode;

    printf("Node with value %d inserted at position %d.\n", value, position);
}

void InsertNodeAtEnd() {
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
        // Link new node at the end
        ptr->nextlink = newnode;
        newnode->prevlink = ptr;
    }

    printf("Node with value %d inserted at the end.\n", value);
}

void InsertNodeAtValue() {
    int target;
    printf("Enter the value after which you want to insert: ");
    scanf("%d", &target);
    printf("Enter the new value to insert: ");
    scanf("%d", &value);

    // Create a new node
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->nextlink = NULL;
    newnode->prevlink = NULL;

    // If list is empty
    if (head == NULL) {
        printf("List is empty. Cannot insert after value %d.\n", target);
        free(newnode);
        return;
    }

    // Search for the target value
    struct node *ptr = head;
    while (ptr != NULL && ptr->data != target) {
        ptr = ptr->nextlink;
    }

    // If target not found
    if (ptr == NULL) {
        printf("Value %d not found in the list.\n", target);
        free(newnode);
        return;
    }

    // Insert after the target node
    newnode->nextlink = ptr->nextlink;
    newnode->prevlink = ptr;

    if (ptr->nextlink != NULL) {  // If not inserting at the end
        ptr->nextlink->prevlink = newnode;
    }

    ptr->nextlink = newnode;

    printf("Node with value %d inserted after %d.\n", value, target);
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
    printf("Enter 2 to insert node at the beginning of the doubly linked list\n");
    printf("Enter 3 to insert node at the middle of the doubly linked list\n");
    printf("Enter 4 to insert node at the end of the doubly linked list\n");
    printf("Enter 5 to insert node at after the value of the doubly linked list\n");
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
            InsertNodeAtBeginning();
            break;
        case 3:
            InsertNodeAtMiddle();
            break;
        case 4:
            InsertNodeAtEnd();
            break;
        case 5:
            InsertNodeAtValue();
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

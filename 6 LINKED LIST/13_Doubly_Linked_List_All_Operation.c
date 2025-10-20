#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prevlink;
    struct node *nextlink;
};

struct node *head, *ptr;
int value, position, choice;

// ========================== INSERTION FUNCTIONS ==========================

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
    if (ptr->nextlink != NULL)
        ptr->nextlink->prevlink = newnode;
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

// ========================== DELETION FUNCTIONS ==========================

// Delete from beginning
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

// Delete from middle (by position)
void DeleteNodeAtMiddle() {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

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

// Delete from end
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

// Delete by value
void DeleteNodeByValue() {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

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

// ========================== TRAVERSAL FUNCTION ==========================
void LinkedListTraversal() {
    struct node *ptr = head;
    if (ptr == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    while (ptr != NULL) {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->nextlink;
    }
}

// ========================== MAIN FUNCTION ==========================
void main() {
    printf("\nMenu\n");
    printf("Enter 1 to insert node one after the other in a doubly linked list\n");
    printf("Enter 2 to insert node at the beginning of the doubly linked list\n");
    printf("Enter 3 to insert node at the middle of the doubly linked list\n");
    printf("Enter 4 to insert node at the end of the doubly linked list\n");
    printf("Enter 5 to insert node after a value in the doubly linked list\n");
    printf("Enter 6 to delete node at the beginning of the doubly linked list\n");
    printf("Enter 7 to delete node at the middle of the doubly linked list\n");
    printf("Enter 8 to delete node at the end of the doubly linked list\n");
    printf("Enter 9 to delete node by value in the doubly linked list\n");
    printf("Enter 10 to display all elements of the linked list\n");
    printf("Enter 11 to Exit\n");

    while (1) {
        printf("\nEnter choice : ");
        scanf("%d", &choice);

        switch (choice) {
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
            DeleteNodeAtBeginning();
            break;
        case 7:
            DeleteNodeAtMiddle();
            break;
        case 8:
            DeleteNodeAtEnd();
            break;
        case 9:
            DeleteNodeByValue();
            break;
        case 10:
            LinkedListTraversal();
            break;
        case 11:
            printf("Exiting program\n");
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}

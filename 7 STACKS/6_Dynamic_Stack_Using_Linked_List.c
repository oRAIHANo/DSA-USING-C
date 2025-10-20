// In Linked List head means starting of the Linked List
// In Stack using linked List we refer head as top = struct stack *top = NULL
// In stack using linked list we perfrom Push and Pop operations where head is pointing
// If we perfrom Push and Pop at head we can perform insertion and deletion in constant time which is big O(1)
// Insertion and deletion at head means we are performing insertion at the beginning of the Linked List
// Linked List = [50][40][30][20][10]
// Push = [60][50][40][30][20][10] [60] in pushed at the beginning of the Linked List
// Pop = [50][40][30][20][10] [60] in popped from the beginning of the Linked List
// Traversal = [50][40][30][20][10]

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *link;
};

struct stack *top = NULL, *ptr;
int value, choice, position;

// code to push or insert element into the stack
void Push() // Push means inserting node at index 0
{
    struct stack *newnode = (struct stack *)malloc(sizeof(struct stack));
    if (newnode == NULL)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("Enter element that you want to push : ");
        scanf("%d", &value);
        newnode->data = value;
        newnode->link = top;
        top = newnode;
    }
}

// code to pop or delete element from the stack
void Pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        struct stack *n = top;
        top = top->link;
        int value = n->data;
        free(n);
        printf("Popped element : %d", value);
    }
}

void Peek()
{
    printf("Enter index who value you want to know : ");
    scanf("%d", &position);
    ptr = top;
    for (int i = 0; i < position - 1 && ptr != NULL; i++)
    {
        ptr = ptr->link;
    }
    if (ptr != NULL)
    {
        printf("Value at index %d is : %d\n", position, ptr->data);
    }
    else
    {
        printf("Error");
    }
}

// code to print the top most element of the stack
void StackTop()
{
    printf("Stack top elmenet is %d", top->data);
}

// code to print the bottom most element of the stack
void StackBottom()
{
    ptr = top;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    printf("Stack bottom elmenet is %d", ptr->data);
}

// code for linked list traversal
void LinkedListTraversal()
{
    int i = 0;
    ptr = top;
    while (ptr != NULL)
    {
        i++;
        printf("Element %d : %d\n", i, ptr->data);
        ptr = ptr->link;
    }
}

void main()
{
    Push();
    Push();
    Push();
    Push();
    Push();

    while (1)
    {
        printf("\nMenu\n");
        printf("Enter 1 to Push element into the stack\n");
        printf("Enter 2 to Pop element from the stack\n");
        printf("Enter 3 to perform peek operation\n");
        printf("Enter 4 to Display element at top\n");
        printf("Enter 5 to Display element at bottom\n");
        printf("Enter 6 to Display all elements\n");
        printf("Enter 7 to Exit\n");

        printf("Enter choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            Push();
            break;
        case 2:
            Pop();
            break;
        case 3:
            Peek();
            break;
        case 4:
            StackTop();
            break;
        case 5:
            StackBottom();
            break;
        case 6:
            LinkedListTraversal();
            break;
        case 7:
            printf("Exiting program");
            exit(0);
        default:
            printf("Choice is invalid");
            break;
        }
    }
}
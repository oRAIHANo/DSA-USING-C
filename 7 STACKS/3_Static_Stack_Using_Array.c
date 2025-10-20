// Wap to implement a menu driven static stack using arrays
#include <stdio.h>
#include <stdlib.h>

#define size 100

int stack[size];
int top = -1, choice;

int IsEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int IsFull()
{
    if (top == size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// code to push or insert element into the stack
void Push()
{
    if (IsFull())
    {
        printf("Stack Overflow");
    }
    else
    {
        int value;
        printf("Enter element that you want to enter : ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
    }
}

// code to pop or delete element from the stack
void Pop()
{
    if (IsEmpty())
    {
        printf("Stack Underflow\n");
    }
    else
    {
        int value = stack[top];
        top--;
        printf("Popped element %d from the stack\n", value);
    }
}

// code to print the top most element of the stack
void StackTop()
{
    printf("Stack top elmenet is %d", stack[top]);
}

// code to print the bottom most element of the stack
void StackBottom()
{
    printf("Stack bottom elmenet is %d", stack[0]);
}

// code to view element at a given position in stack
void Display()
{
    for (int i = top; i >= 0; i--)
    {
        printf("Stack element at %d position is : %d\n", i, stack[i]);
    }
}

void main()
{
    printf("Stack created successfully\n");

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
        printf("Enter 3 to Display element at top\n");
        printf("Enter 4 to Display element at bottom\n");
        printf("Enter 5 to Display all elements\n");
        printf("Enter 6 to Exit\n");

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
            StackTop();
            break;
        case 4:
            StackBottom();
            break;
        case 5:
            Display();
            break;
        case 6:
            printf("Exiting program");
            exit(0);
        default:
            printf("Choice is invalid");
            break;
        }
    }
}

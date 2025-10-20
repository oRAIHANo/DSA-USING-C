#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

// code to check if stack is empty
int IsEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1; // 1 means stack is empty
    }
    else
    {
        return 0; // 0 means stack is not empty
    }
}

// code to check if stack is full
int IsFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1; // 1 means stack is full
    }
    else
    {
        return 0; // 0 means stack is not full
    }
}

// code to push or insert element into the stack
void Push(struct stack *ptr)
{
    if (IsFull(ptr))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        int value;
        printf("Enter the value that you want to push : ");
        scanf("%d", &value);
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

// code to pop or delete element from the stack
int Pop(struct stack *ptr)
{
    if (IsEmpty(ptr))
    {
        printf("Stack Underflow cannot pop from the stack\n");
        return -1;
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        printf("Popped element: %d\n", value);
        return value;
    }
}

// code to view element at a given position in stack
int Peek()
{
    int i;
    int arrIndex = ptr->top - i + 1;
    if (arrIndex < 0)
    {
        printf("Not a valid position");
    }
    else
    {
        return ptr->arr[arrIndex];
    }
}

void Display(struct stack *ptr)
{
    if (IsEmpty(ptr))
    {
        printf("Stack is empty\n");
        return;
    }
    for (int i = ptr->top; i >= 0; i--)
    {
        printf("Element %d : %d\n", i, ptr->arr[i]);
    }
}

// Return top element
int StackTop(struct stack *ptr)
{
    if (IsEmpty(ptr))
    {
        printf("Stack is empty\n");
        return -1;
    }
    printf("Top element: %d\n", ptr->arr[ptr->top]);
    return ptr->arr[ptr->top];
}

// Return bottom element
int StackBottom(struct stack *ptr)
{
    if (IsEmpty(ptr))
    {
        printf("Stack is empty\n");
        return -1;
    }
    printf("Bottom element: %d\n", ptr->arr[0]);
    return ptr->arr[0];
}

int main()
{
    struct stack *s;
    int choice;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

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
            Push(s);
            break;
        case 2:
            Pop(s);
            break;
        case 3:
            StackTop(s);
            break;
        case 4:
            StackBottom(s);
            break;
        case 5:
            Display(s);
            break;
        case 6:
            printf("Exiting program\n");
            free(s->arr);
            free(s);
            exit(0);
        default:
            printf("Choice is invalid\n");
            break;
        }
    }

    return 0;
}
 
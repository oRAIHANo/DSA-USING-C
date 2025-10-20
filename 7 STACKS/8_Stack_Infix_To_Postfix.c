#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 100

char stack[size];
char infix[size];
char postfix[size];
int top = -1;

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
void Push(char value)
{
    if (IsFull())
    {
        printf("Stack Overflow");
    }
    else
    {
        top++;
        stack[top] = value;
    }
}

// code to pop or delete element from the stack
char Pop()
{
    if (IsEmpty())
    {
        printf("Stack Underflow\n");
    }
    else
    {
        char value = stack[top];
        top--;
        return value;
    }
}

int IsOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    else
        return 0;
}

int Precedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

void InfixToPostfix()
{
    int i = 0; // Infix Scanner
    int j = 0; // Postfix fill
    printf("Enter infix expression : ");
    scanf("%s", &infix);
    int length = strlen(infix);
    infix[length] = '\0';

    while (infix[i] != '\0')
    {
        if (!IsOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (Precedence(infix[i]) > Precedence(stack[top]))
            {
                Push(infix[i]);
                i++;
            }
            else
            {
                postfix[j] = Pop();
                j++;
            }
        }
    }
    while (!IsEmpty())
    {
        postfix[j] = Pop();
        j++;
    }
    postfix[j] = '\0';
    printf("Postfix is %s", postfix);
}

int main()
{
    InfixToPostfix();
    return 0;
}
// Paranthesis Matching Problem
// If there is an opening paranthesis ( then push into the stack
// If there is a closing paranthesis ) then pop ( from the stack
// Example of a balanced expression = ((a+b) * (a-b))
// Example of an unbalanced expression = (a+b) * (a-b)) and (a * (b - a*(c)
// Condition for a balanced expression
// While popping stack should not be underflow or empty -> If it happens then expression is unbalanced
// At the end of expression stack must be empty
// Best case complexity: O(1)
// Worst case complexity: O(n)

#include <stdio.h>
#include <string.h>

char exp_arr[] = "{[(hello)]}";
int size = strlen(exp_arr);
char stack[100]; // safer to give fixed size instead of variable-length array
int top = -1;
char element;

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

void Push(char element)
{
    if (IsFull())
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = element;
    }
}

char Pop()
{
    if (IsEmpty())
    {
        printf("Stack Underflow\n");
        return 0;
    }
    else
    {
        char val = stack[top];
        top--;
        return val;
    }
}

void display()
{
    printf("Looping using strlen():\n");
    for (int i = 0; i < size; i++)
    {
        printf("%c \n", exp_arr[i]);
    }
    printf("\n");
}

void Parenthesis_Matching()
{
    for (int i = 0; i < size; i++)
    {
        if (exp_arr[i] == '(' || exp_arr[i] == '{' || exp_arr[i] == '[')
        {
            Push(exp_arr[i]);
        }

        if (exp_arr[i] == ')' || exp_arr[i] == '}' || exp_arr[i] == ']')
        {
            if (IsEmpty())
            {
                printf("Parenthesis are not balanced\n");
                return;
            }

            char popped = Pop();

            if ((exp_arr[i] == ')' && popped != '(') || (exp_arr[i] == '}' && popped != '{') || (exp_arr[i] == ']' && popped != '['))
            {
                printf("Parenthesis are not balanced\n");
                return;
            }
        }
    }

    if (IsEmpty())
    {
        printf("Parenthesis are balanced\n");
    }
    else
    {
        printf("Parenthesis are not balanced\n");
    }
}

int main()
{
    display();
    Parenthesis_Matching();

    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>

// #define size 100

// char array[size];
// int top = -1, choice;

// // code to push or insert element into the stack
// void Push(char value)
// {
//     if (top == size - 1)
//     {
//         printf("Stack Overflow cannot push %d\n", value);
//     }
//     else
//     {
//         top++;
//         array[top] = value;
//     }
// }

// // code to pop or delete element from the stack
// char Pop()
// {
//     if (top == -1)
//     {
//         printf("Stack Underflow cannot pop from the stack\n");
//         return -1;
//     }
//     else
//     {
//         char value = array[top];
//         top--;
//         return value;
//     }
// }

// // code to solve parenthesis matching problem
// int Parenthesis(char *expr)
// {
//     for (int i = 0; expr[i] != '\0'; i++)
//     {
//         if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[')
//         {
//             Push(expr[i]);
//         }
//         else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']')
//         {
//             if (top == -1)
//             {
//                 return 0;
//             }
//             char popped = Pop();
//             if ((expr[i] == ')' && popped != '(') || (expr[i] == '}' && popped != '{') || (expr[i] == ']' && popped != '['))
//             {
//                 return 0; // Mismatched closing bracket
//             }
//         }
//     }

//     if (top == -1)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// int main()
// {
//     // char *expr = "((a+b) * (a-b))";
//     // char *expr = "(a+b) * (a-b))";
//     char *expr = "{[(a+b) * (a-b)] + (a*b)";

//     if (Parenthesis(expr))
//     {
//         printf("Parenthesis is matching");
//     }
//     else
//     {
//         printf("Parenthesis is not matching");
//     }

//     return 0;
// }


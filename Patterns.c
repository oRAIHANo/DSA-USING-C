#include <stdio.h>
#include <stdlib.h>
int n;

void Pattern1()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}
void Pattern2()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}
void Pattern3()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= i + 1; j++)
        {
            printf("%d", j);
        }
        printf("\n");
    }
}
void Pattern4()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d", i);
        }
        printf("\n");
    }
}
void Pattern5()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n - i + 1; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}
void Pattern6()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            printf("%d", j);
        }
        printf("\n");
    }
}
void Pattern7()
{
    for (int i = 0; i < n; i++)
    {
        // Space
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }

        // Star
        for (int j = 0; j < 2 * i + 1; j++)
        {
            printf("*");
        }
        // Space
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        printf("\n");
    }
}
void Pattern8()
{
    for (int i = 0; i < n; i++)
    {
        // Space
        for (int j = 0; j < i; j++)
        {
            printf(" ");
        }

        // Star
        for (int j = 0; j < 2 * n - (2 * i + 1); j++)
        {
            printf("*");
        }

        // Space
        for (int j = 0; j < i; j++)
        {
            printf(" ");
        }
        printf("\n");
    }
}
void Pattern9()
{
    Pattern7();
    Pattern8();
}
void Pattern10()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
void Pattern11()
{
    int start = 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            start = 1;
        else
            start = 0;
        for (int j = 0; j <= i; j++)
        {
            printf("%d", start);
            start = 1 - start;
        }
        printf("\n");
    }
}

int main()
{
    printf("Enter the value of n : ");
    scanf("%d", &n);
    Pattern11();
}
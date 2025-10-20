#include <stdio.h>
int num;
int size;
void DigitsConverter()
{
    while(num>0)
    {
        int digits = num % 10;
        printf("%d\n", digits);
        num = num / 10;
    }
}
int main()
{

    printf("Enter a number : ");
    scanf("%d", &num);

    printf("Enter the length : ");
    scanf("%d", &size);
    DigitsConverter();
}
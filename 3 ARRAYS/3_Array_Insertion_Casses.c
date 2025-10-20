// Wap to implement a menu driven insertion in 1 d array.
#include <stdio.h>
#include <stdlib.h>

int arr[50], size, element, position, choice;

// code for insert element into an empty array
void ArrayElement()
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter %d element : ", i);
        scanf("%d", &arr[i]);
    }
}

// code for insert element at the beginning
void InsertElementAtBeginning()
{
    printf("Enter element : ");
    scanf("%d", &element);
    for (int i = size - 1; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = element;
    size++;
}

// // code for insert element at the middle
void InsertElementAtMiddle()
{
    printf("Enter element : ");
    scanf("%d", &element);
    printf("Enter index : ");
    scanf("%d", &position);
    for (int i = size - 1; i >= position - 1; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[position - 1] = element;
    size++;
}

// code for insert element at the end
void InsertElementAtEnd()
{
    printf("Enter element : ");
    scanf("%d", &element);
    arr[size] = element;
    size++;
}

// code to display the elements of an array (Traversal)
void ArrayTraversal()
{
    for (int i = 0; i < size; i++)
    {
        printf("Element entered at the %d position : ", i);
        printf("%d\n", arr[i]);
    }
}

int main()
{
    printf("Enter the size of the array : ");
    scanf("%d", &size);
    if (size > 100)
    {
        printf("Size is invalid");
    }

    InsertElement();

    while (1)
    {
        printf("\nMenu\n");
        printf("Enter 1 to Insert Element at Beginning\n");
        printf("Enter 2 to Insert Element at Middle or at given index\n");
        printf("Enter 3 to Insert Element at End\n");
        printf("Enter 4 to Display elements of the array\n");
        printf("Enter 5 to Exit\n");

        printf("\nEnter Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            InsertElementAtBeginning();
            break;
        case 2:
            InsertElementAtMiddle();
            break;
        case 3:
            InsertElementAtEnd();
            break;
        case 4:
            ArrayTraversal();
            break;
        case 5:
            printf("Exiting program");
            exit(0);
        default:
            printf("Choice is invalid");
            break;
        }
    }
    return 0;
}
// Traversal
#include <stdio.h>

int arr[100], size;

// code to insert elements into an array
void ArrayElement()
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter the %d element : ", i);
        scanf("%d", &arr[i]);
    }
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
    printf("\nEnter Elements into the array\n");
    ArrayElement(arr, size);
    printf("\nDisplaying elements of the array\n");
    ArrayTraversal(arr, size);
}
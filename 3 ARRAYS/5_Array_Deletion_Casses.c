// Deletion
#include <stdio.h>

// code for element insertion into an empty array
void ArrayElement(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter the %d element : ", i);
        scanf("%d", &arr[i]);
    }
}

// code for deletion
void DeleteElement(int arr[], int size, int index)
{
    if (index == 0)
    {
        for (int i = index; i < size; i++)
        {
            arr[i] = arr[i + 1];
        }
    }
    else if (index == size - 1)
    {
        size--;
    }
    else
    {
        for (int i = index; i < size; i++)
        {
            arr[i] = arr[i + 1];
        }
    }
}

// code to display the elements of an array (Traversal)
void ArrayTraversal(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
}

int main()
{
    int arr[100];
    int size;  // number of elements present in the array
    int index; // index at which you want to enter element
    printf("Enter the size of the array : ");
    scanf("%d", &size);
    ArrayElement(arr, size);
    printf("Index at which you want to delete element : ");
    scanf("%d", &index);

    if (index > size)
    {
        printf("Index out of range");
    }
    else
    {
        printf("Array before deletion\n");
        ArrayTraversal(arr, size);
        DeleteElement(arr, size, index);
        size--;
        printf("Array after deletion\n");
        ArrayTraversal(arr, size);
    }

    return 0;
}
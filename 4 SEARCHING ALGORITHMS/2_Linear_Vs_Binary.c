// Linear Search
// Binary Search
#include <stdio.h>

int array[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
int size = sizeof(array) / sizeof(array[0]);
int value;

// code to perform Linear Search
void LinearSearch()
{
    printf("Enter element that you want to search in the array : ");
    scanf("%d", &value);
    for (int i = 0; i < size; i++)
    {
        if (array[i] == value)
        {
            printf("Element found at index %d", i);
        }
    }
}

// code to perform Binary Search
void BinarySearch()
{
    printf("Enter element that you want to search in the array : ");
    scanf("%d", &value);
    int low = 0;
    int mid;
    int high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (array[mid] == value)
        {
            printf("Element found at index %d", mid);
        }
        if (array[mid] < value)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
}

int main()
{
    // LinearSearch();
    BinarySearch();
    return 0;
}
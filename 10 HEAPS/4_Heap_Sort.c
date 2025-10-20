#include <stdio.h>

int arr[] = {10,1,5,4,9,2,8,3,7,6};
int size = sizeof(arr) / sizeof(arr[0]);

// Function to swap the position of two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// To heapify a subtree rooted with node i
// which is an index in arr[].
// size is size of heap
void heapify(int arr[], int size, int i)
{
    // Find largest among root,
    // left child and right child

    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int left = 2 * i + 1;

    // right = 2*i + 2
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < size && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest
    // so far
    if (right < size && arr[right] > arr[largest])
        largest = right;

    // Swap and continue heapifying
    // if root is not largest
    // If largest is not root
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapify(arr, size, largest);
    }
}

// Main function to do heap sort
void heapSort()
{
    // Build max heap
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    // Heap sort
    for (int i = size - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);

        // Heapify root element
        // to get highest element at
        // root again
        heapify(arr, i, 0);
    }
}

// A utility function to print array of size size
void printArray()
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver's code
int main()
{
    // Function call
    heapSort();
    printf("Sorted Array is : \n");
    printArray();
}
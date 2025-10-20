#include <stdio.h>

int array[] = {100, 50, 90, 30, 80, 10, 20, 70, 40, 60};
int size = sizeof(array) / sizeof(array[0]);

void Merge(int array[], int low, int mid, int high)
{
    int i, j, k;
    int merged_array[size];
    i = low;
    j = mid + 1;
    k = 0;

    while (i <= mid && j <= high)
    {
        if (array[i] < array[j])
        {
            merged_array[k] = array[i];
            i++;
            k++;
        }
        else
        {
            merged_array[k] = array[j];
            j++;
            k++;
        } 
    }

    while (i <= mid)
    {
        merged_array[k] = array[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        merged_array[k] = array[j];
        j++;
        k++;
    }

    for (i = 0; i < k; i++)
    {
        array[low + i] = merged_array[i];
    }
}

void MergeSort(int array[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        MergeSort(array, low, mid);
        MergeSort(array, mid + 1, high);
        Merge(array, low, mid, high);
    }
}

void ArrayTraversal()
{
    for (int a = 0; a < size; a++)
    {
        printf("%d ", array[a]);
    }
    printf("\n");
}

int main()
{
    printf("Running Merge Sort...\n");
    printf("Before Sorting\n");
    ArrayTraversal();
    MergeSort(array, 0, size - 1);
    printf("After Sorting\n");
    ArrayTraversal();
    return 0;
}


/* 

void Merge(int* array, int low, int mid, int high) {
    int size = high - low + 1;
    int* merged_array = (int*)malloc(size * sizeof(int));
    
    int i = low;
    int j = mid + 1;
    int k = 0;

    // Merge the two halves into merged_array
    while (i <= mid && j <= high) {
        if (array[i] <= array[j]) {
            merged_array[k] = array[i];
            i++;
        } else {
            merged_array[k] = array[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements from the left half, if any
    while (i <= mid) {
        merged_array[k] = array[i];
        i++;
        k++;
    }

    // Copy remaining elements from the right half, if any
    while (j <= high) {
        merged_array[k] = array[j];
        j++;
        k++;
    }

    // Copy merged array back to the original array
    for (k = 0; k < size; k++) {
        array[low + k] = merged_array[k];
    }

    // Free the allocated memory
    free(merged_array);
}

void MergeSort(int* array, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        // Recursively sort first half
        MergeSort(array, low, mid);

        // Recursively sort second half
        MergeSort(array, mid + 1, high);

        // Merge the sorted halves
        Merge(array, low, mid, high);
    }
}

int* sortArray(int* array, int size, int* returnSize) {
    // Call MergeSort to sort the array
    MergeSort(array, 0, size - 1);

    // Set the return size
    *returnSize = size;

    // Return the sorted array
    return array;
}

*/

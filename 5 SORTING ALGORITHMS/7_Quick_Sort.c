<<<<<<< HEAD
// Quick sort is a highly efficient and widely used sorting algorithm that employs the divide-and-conquer strategy. Here’s a brief explanation of how it works:

// Pivot Selection: 
// Quick sort starts by selecting a 'pivot' element from the array. This can be the first, last, or any random element, though the choice can affect performance.

// Partitioning: 
// The array is then rearranged so that all elements less than the pivot are moved to its left, and all elements greater than the pivot are moved to its right. The pivot is now in its correct final position.

// Recursive Sorting: 
// The process is recursively applied to the sub-arrays on the left and right of the pivot until the base case is reached, where the sub-array has one or zero elements and is therefore already sorted.

// Combine: 
// Since the sub-arrays are sorted in place, no combining step is necessary.

// Quick sort is favored for its average-case time complexity of O(nlogn) and generally performs well in practice, though its worst-case time complexity is 
// O(n^2) if poor pivot choices consistently occur. However, with good pivot selection strategies (like choosing the median), the worst case can often be avoided.



#include <stdio.h>

#define SIZE 100
int arr[SIZE];
int size;

// Function to partition the array into two parts
int Partition(int low, int high)
{
    int pivot = arr[low]; // pivot
    int i = low;          // Start from the low index
    int j = high + 1;     // Start from the high index

    while (i < j)
    {
        // Move i to the right as long as elements are less than or equal to pivot
        do
        {
            i++;
        } while (i <= high && arr[i] <= pivot);

        // Move j to the left as long as elements are greater than pivot
        do
        {
            j--;
        } while (arr[j] > pivot);

        // If the pointers have crossed, break out of the loop
        if (i >= j)
            break;

        // Swap arr[i] and arr[j] if they are out of place
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Swap the pivot with arr[j] to place the pivot in the correct position
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j; // Return the partition index
}

// // Function to implement QuickSort
void QuickSort(int low, int high)
{
    if (low < high)
    {
        // pi is partitioning index, arr[pi] is now at the right place
        int pi = Partition(low, high);

        // Recursively sort elements before partition and after partition
        QuickSort(low, pi - 1);
        QuickSort(pi + 1, high);
    }
}

// code for array traversal
void ArrayTraversal()
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    printf("Enter the size of the array : ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        printf("Enter %i element  : ", i);
        scanf("%d", &arr[i]);
    }

    QuickSort(0, size - 1);

    ArrayTraversal();

    return 0;
}
=======
// Quick sort is a highly efficient and widely used sorting algorithm that employs the divide-and-conquer strategy. Here’s a brief explanation of how it works:

// Pivot Selection: 
// Quick sort starts by selecting a 'pivot' element from the array. This can be the first, last, or any random element, though the choice can affect performance.

// Partitioning: 
// The array is then rearranged so that all elements less than the pivot are moved to its left, and all elements greater than the pivot are moved to its right. The pivot is now in its correct final position.

// Recursive Sorting: 
// The process is recursively applied to the sub-arrays on the left and right of the pivot until the base case is reached, where the sub-array has one or zero elements and is therefore already sorted.

// Combine: 
// Since the sub-arrays are sorted in place, no combining step is necessary.

// Quick sort is favored for its average-case time complexity of O(nlogn) and generally performs well in practice, though its worst-case time complexity is 
// O(n^2) if poor pivot choices consistently occur. However, with good pivot selection strategies (like choosing the median), the worst case can often be avoided.



#include <stdio.h>

#define SIZE 100
int arr[SIZE];
int size;

// Function to partition the array into two parts
int Partition(int low, int high)
{
    int pivot = arr[low]; // pivot
    int i = low;          // Start from the low index
    int j = high + 1;     // Start from the high index

    while (i < j)
    {
        // Move i to the right as long as elements are less than or equal to pivot
        do
        {
            i++;
        } while (i <= high && arr[i] <= pivot);

        // Move j to the left as long as elements are greater than pivot
        do
        {
            j--;
        } while (arr[j] > pivot);

        // If the pointers have crossed, break out of the loop
        if (i >= j)
            break;

        // Swap arr[i] and arr[j] if they are out of place
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Swap the pivot with arr[j] to place the pivot in the correct position
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j; // Return the partition index
}

// // Function to implement QuickSort
void QuickSort(int low, int high)
{
    if (low < high)
    {
        // pi is partitioning index, arr[pi] is now at the right place
        int pi = Partition(low, high);

        // Recursively sort elements before partition and after partition
        QuickSort(low, pi - 1);
        QuickSort(pi + 1, high);
    }
}

// code for array traversal
void ArrayTraversal()
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    printf("Enter the size of the array : ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        printf("Enter %i element  : ", i);
        scanf("%d", &arr[i]);
    }

    QuickSort(0, size - 1);

    ArrayTraversal();

    return 0;
}
>>>>>>> 94a60068450327b4cdee702c3ee0df09667e186b

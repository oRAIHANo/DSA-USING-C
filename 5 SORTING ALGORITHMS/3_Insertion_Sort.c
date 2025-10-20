/*

Insertion Sort works on the basic principle of shifting

The array is virtually split into a sorted and an unsorted part.
Values from the unsorted part are picked and placed in the correct position in the sorted part.

Insertion sort is a stable sort.
During the selection sort process, we will only swap the ordering of any two items if the item on the right is less than the item to its left.
Therefore, the ordering of two equivalent items will always be preserved in insertion sort.

Insertion sort is an Adaptive sorting algorithm

Total no. of passes - n-1 - If the size of the array is 5 then total number of passes is 4
Total no. of comparisons - n*(n-1)/2
Time complexity best case - o(n) when the array is sorted
Time complexity worst case - o(n*n)

Dry run
-1   0   1   2   3   4   5   6   7   8   9 Index
    01, 09, 08, 07, 06, 10, 02, 03, 04, 05 Input Array elements
    01, 09,|08, 07, 06, 10, 02, 03, 04, 05 i=1, key=9, j=0 1st pass
    01, 09, 08,|07, 06, 10, 02, 03, 04, 05 i=2, key=8, j=1 2nd pass
    01, 08, 09, 07,|06, 10, 02, 03, 04, 05 i=3, key=7, j=2 3rd pass
    01, 07, 08, 09, 06,|10, 02, 03, 04, 05 i=4, key=6, j=3 4th pass     
    01, 06, 07, 08, 09, 10,|02, 03, 04, 05 i=5, key=10, j=4 5th pass
    01, 06, 07, 08, 09, 10, 02,|03, 04, 05 i=6, key=2, j=5 6th pass
    01, 02, 06, 07, 08, 09, 10, 03,|04, 05 i=7, key=3, j=6 7th pass
    01, 02, 03, 06, 07, 08, 09, 10, 04,|05 i=8, key=4, j=7 8th pass
    01, 02, 03, 04, 05, 06, 07, 08, 09, 10| i=9, key=5, j=8 9th pass   

*/

#include <stdio.h>
int array[] = {1, 9, 8, 7, 6, 10, 2, 3, 4, 5};
int size = sizeof(array) / sizeof(array[0]);

// code for insertion sort
void InsertionSort()
{
    int temp;
    for (int i = 1; i < size; i++)
    {
        int key = array[i];
        // loop for each pass
        int j = i - 1;
        while (j >= 0 && array[j] > key) // array[j] > key for ascending order sorting
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

// code for array traversal
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
    printf("Running Insertion Sort...\n");
    printf("Before Sorting\n");
    ArrayTraversal();
    InsertionSort();
    printf("After Sorting\n");
    ArrayTraversal();
}

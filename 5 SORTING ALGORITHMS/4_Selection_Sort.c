/*

// Select Minimum and swap

Dry run
// Example {8, 0, 7, 1, 3}

// Input Array (There will be total n-1 passes. 5-1 = 4 in this case!)
//  00  01  02  03  04
// |08, 00, 07, 01, 03

// After first pass
//  00  01  02  03  04
//  00,|08, 07, 01, 03

// After second pass
// 00  01  02  03  04
// 00, 01,|07, 08, 03

// After third pass
// 00  01  02  03  04
// 02, 01, 03,|08, 07

// After fourth pass
// 00  01  02  03  04
// 00, 01, 03, 07,|08

// Output Array
// 00  01  02  03  04
// 00, 01, 03, 07, 08

*/

#include <stdio.h>

int array[] = {8, 0, 7, 1, 3};
int size = 5;

void SelectionSort()
{
    int indexOfMin, temp;
    for (int i = 0; i < size - 1; i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        // Swap A[i] and A[indexOfMin]
        temp = array[i];
        array[i] = array[indexOfMin];
        array[indexOfMin] = temp;
    }
}

// code for array traversal
void ArrayTraversal()
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    printf("Running Selection Sort...\n");
    printf("Before Sorting\n");
    ArrayTraversal();
    SelectionSort();
    printf("After Sorting\n");
    ArrayTraversal();
    return 0;
}
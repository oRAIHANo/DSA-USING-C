// Two way merge
#include <stdio.h>
#define SIZE 12

int a1[] = {10, 50, 100, 150, 200, 1000};
int a2[] = {2, 30, 50, 99, 150, 150};
int ma[] = {SIZE};

void MergeSort()
{

    int i = 0, j = 0, k = 0;

    int a1_size = sizeof(a1) / sizeof(a1[0]);
    int a2_size = sizeof(a2) / sizeof(a2[0]);

    while (i < a1_size && j < a2_size)
    {
        if (a1[i] < a2[j])
        {
            ma[k] = a1[i];
            i++;
            k++;
        }
        else
        {
            ma[k] = a2[j];
            j++;
            k++;
        }
    }

    if (i == a1_size)
    {
        while (j < a2_size)
        {
            ma[k] = a2[j];
            j++;
            k++;
        }
    }

    if (j == a2_size)
    {
        while (i < a1_size)
        {
            ma[k] = a1[i];
            i++;
            k++;
        }
    }
}

// code for array traversal
void ArrayTraversal()
{
    for (int a = 0; a < SIZE; a++)
    {
        printf("%d ", ma[a]);
    }
    printf("\n");
}

int main()
{
    printf("Running Merge Sort...\n");
    MergeSort();
    printf("Sorted Array\n");
    ArrayTraversal();
    return 0;
}
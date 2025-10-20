<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int arr[SIZE]; // Array to store the elements
int size;      // Variable to store the size of the array

void CountSort()
{
    int max = arr[0];

    // Find the maximum element in the array
    for (int i = 1; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    printf("Max element : %d\n", max);

    // Create a count array to store the frequency of elements
    int count[max + 1];

    // Initialize count array with 0
    for (int i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    // Store the count of each element in the count array
    for (int i = 0; i < size; i++)
    {
        count[arr[i]] = count[arr[i]] + 1;
    }

    int i=0;
    int j=0;

    while(i<= max){
        if(count[i]>0){
            arr[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else{
            i++;
        }
    } 

    // Print the sorted array
    printf("Sorted array: ");
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

    for (int i = 0; i < size; i++)
    {
        printf("Element %i : %d \n", i, arr[i]);
    }

    // Display the original array
    printf("Original array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    CountSort();
    return 0;
}
=======
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int arr[SIZE]; // Array to store the elements
int size;      // Variable to store the size of the array

void CountSort()
{
    int max = arr[0];

    // Find the maximum element in the array
    for (int i = 1; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    printf("Max element : %d\n", max);

    // Create a count array to store the frequency of elements
    int count[max + 1];

    // Initialize count array with 0
    for (int i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    // Store the count of each element in the count array
    for (int i = 0; i < size; i++)
    {
        count[arr[i]] = count[arr[i]] + 1;
    }

    int i=0;
    int j=0;

    while(i<= max){
        if(count[i]>0){
            arr[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else{
            i++;
        }
    } 

    // Print the sorted array
    printf("Sorted array: ");
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

    for (int i = 0; i < size; i++)
    {
        printf("Element %i : %d \n", i, arr[i]);
    }

    // Display the original array
    printf("Original array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    CountSort();
    return 0;
}
>>>>>>> 94a60068450327b4cdee702c3ee0df09667e186b

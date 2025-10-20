#include <stdio.h>
#define SIZE 100
int arr[SIZE];
int size;
int hash[SIZE];

void CountFrequency()
{

    // Find the maximum element in the array
    int max = arr[0]; // Initialize max with the first element
    for (int i = 1; i < size; i++)
    { // Start from the second element
        if (arr[i] > max)
        {
            max = arr[i]; // Update max if a larger value is found
        }
    }

    printf("\n");
    printf("Max element : %d\n", max);

    // Initialize the hash array with zeros
    for (int i = 0; i <= max; i++)
    {
        hash[i] = 0;
    }

    // Count the frequency of each element
    for (int j = 0; j < size; j++)
    {
        if (arr[j] != 0)
        {
            hash[arr[j]] += 1;
        }
    }

    // Print the frequency count
    printf("Frequency of elements:\n");
    for (int i = 0; i <= max; i++)
    {
        if (hash[i] > 0)
        {
            printf("Element %d: %d times\n", i, hash[i]);
        }
    }
}

int main()
{

    printf("Enter the size of the array : ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    CountFrequency();

    return 0;
}
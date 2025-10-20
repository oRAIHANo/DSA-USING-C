#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

int heap[MAX_HEAP_SIZE];
int heapSize = 0;

// Function to swap two integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted with node i
void maxHeapify(int arr[], int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        // Recursively heapify the affected sub-tree
        maxHeapify(arr, n, largest);
    }
}

// Function to insert a new element into the heap
void insert(int key)
{
    if (heapSize >= MAX_HEAP_SIZE)
    {
        printf("Heap overflow\n");
        return;
    }

    // Insert the new element at the end
    int i = heapSize;
    heap[i] = key;
    heapSize++;

    // Fix the max heap property if it is violated
    while (i > 0 && heap[(i - 1) / 2] < heap[i])
    {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to delete a specific node from the heap
void deleteNode(int index)
{
    if (heapSize <= 0 || index >= heapSize)
    {
        printf("Invalid index or Heap underflow\n");
        return;
    }

    // Replace the node to be deleted with the last element
    heap[index] = heap[heapSize - 1];
    heapSize--;

    // Heapify the affected subtree
    maxHeapify(heap, heapSize, index);
}

// Function to print the elements of the heap
void printHeap()
{
    printf("Heap: ");
    for (int i = 0; i < heapSize; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main()
{
    int choice, node;
    while (1)
    {
        printf("\n----- Menu -----\n");
        printf("1. Insert node\n");
        printf("2. Delete node\n");
        printf("3. Print heap\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the node value to insert: ");
            scanf("%d", &node);
            insert(node);
            printf("Node %d inserted successfully.\n", node);
            break;
        case 2:
            printf("Enter the index of the node to delete: ");
            scanf("%d", &node);
            deleteNode(node);
            printf("Node at index %d deleted successfully.\n", node);
            break;
        case 3:
            printHeap();
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

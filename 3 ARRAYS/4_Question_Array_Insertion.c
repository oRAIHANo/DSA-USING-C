// It inserts a new element (5) into a sorted array {1,2,3,4,6}, maintaining the sorted order.

#include <stdio.h>

int arr[100] = {1, 2, 3, 4, 6};
int size = 5;           // Number of elements currently in the array
int element = 5;        // Element to insert

void display() {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert() {
    int index = size;   // Assume element goes at the end

    // Find the correct index where element should be inserted
    for (int i = 0; i < size; i++) {
        if (arr[i] > element) {
            index = i;
            break;
        }
    }

    // Shift elements to the right to make space
    for (int i = size-1; i > index-1; i--) {
        arr[i+1] = arr[i];
    }

    // Insert the element
    arr[index] = element;
    size++; // Increase size after insertion
}

int main() {
    display();  // Display before insertion
    insert();   // Insert element in sorted order
    display();  // Display after insertion
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int row = 2;
int col = 2;
int array[2][2];

void InsertElement() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Enter the value at position %d, %d: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }
}

void Display(){
    printf("\nThe array is:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

int main() {
    InsertElement();
    Display();
    
    return 0;
}

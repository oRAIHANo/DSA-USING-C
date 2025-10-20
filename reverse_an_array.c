// Online C compiler to run C program online
#include <stdio.h>
#define SIZE 100
int arr[SIZE];
int size;
int i =0;

void ArrayTraversal(){
    for(int i =0;i<size;i++){
        printf("%d", arr[i]);
    }
}

int ReverseArray(int l,int r){
    if (l>=r){
        return 0;
    }
    else{
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        ReverseArray(l+1,r-1);
    }
    return 0;
}

int main() {
    printf("EEnter the size of the array : ");
    scanf("%d", &size);
    for(int i =0;i<size;i++){
        printf("Enter the %d element : ",i);
        scanf("%d", &arr[i]);
    }
    
    ArrayTraversal();
    printf("\n");
    ReverseArray(i,size-1);
    printf("\n");
    ArrayTraversal();

    return 0;
}
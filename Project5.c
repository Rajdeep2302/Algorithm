//Write a C program to perform Bubble Sort on an integer array to sort it in ascending order and compute the time complexity for an input of size N.
#include <stdio.h>
int count = 0;

void BubbleSort(int arr[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i-1; j++){
            count++;
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    BubbleSort(arr, n);
    printf("Sorted array is: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\nTime complexity: O(n^2) = %d\n", count);
    return 0;
}
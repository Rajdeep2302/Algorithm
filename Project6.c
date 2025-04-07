//Write a C Program to perform insertion sort on an Integer array to sort it in ascending order and compute the time complexity for an input of size N.
#include <stdio.h>

int count = 0;

void InsertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key){
            count++;
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    printf("Enter the size of the array: ");
    int n;
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    InsertionSort(arr, n);
    printf("Sorted array is: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\nTime complexity: O(n^2) = %d\n", count);
}
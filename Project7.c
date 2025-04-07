//Write a C program to perform selection sort on an integer array to sort it in ascending order and compute the time complexity for an input of size N.
#include <stdio.h>
int count = 0;
void SelectionSort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        int min = i;
        for(int j = i+1; j < n; j++){
            count++;
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
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
    SelectionSort(arr, n);
    printf("Sorted array is: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\nTime complexity: O(n^2) = %d\n", count);
    return 0;
}
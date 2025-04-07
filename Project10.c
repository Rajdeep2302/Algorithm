//Write a C Program to perform count sort on an integer array to sort it in ascending order and compute the time complexity for an input of size N.
#include <stdio.h>

int complexity = 0;

int find_max(int arr[], int size){
    int max_value = arr[0];
    for(int i = 1; i< size; i++){
        if(max_value < arr[i]){
            max_value = arr[i];
        }
    }
    return max_value;
}

void count_sort(int size, int arr[]){
    int max_value = find_max(arr, size);
    printf("Max value is: %d\n", max_value);

    int count[max_value+1];
    for(int i = 0; i <= max_value; i++){
        count[i] = 0;
        complexity ++;
    }

    for(int i = 0; i < size; i++){
        count[arr[i]] ++;
        complexity ++;
    }

    for(int i = 1; i<= max_value; i++){
        count[i]=count[i-1]+count[i];
        complexity ++;
    }

    int new_array[size];

    for(int i = size-1; i!=-1; i--){
        new_array[count[arr[i]]-1] = arr[i];
        count[arr[i]] = count[arr[i]]-1;
        printf("%d ",arr[i]);
        complexity ++;
    }

    for(int i = 0; i < size; i++){
        arr[i] = new_array[i];
        complexity ++;
    }
}

int main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int array[n];
    printf("Enter the all array elements: ");
    for(int i = 0; i< n ; i++){
        scanf("%d",&array[i]);
    }
    count_sort(n, array);
    printf("\nSort array is: ");
    for(int i = 0 ; i < n; i++){
        printf("%d\t",array[i]);
    }
    printf("Complexity is: %d",complexity);
    return 0;
}

// Recursive Write a C Program to perform Binary search on an array of size N and compute time complexity for size N.

#include <stdio.h>
int count = 0;

void BinarySearch(int arr[], int low, int high, int value)
{
    if (low > high)
    {
        printf("Element not found\n");
        return;
    }
    int mid = (low + high) / 2;
    count++;
    if (arr[mid] == value)
    {
        printf("Element found at index %d\n", mid);
        return;
    }
    else if (arr[mid] > value)
    {
        BinarySearch(arr, low, mid - 1, value);
    }
    else
    {
        BinarySearch(arr, mid + 1, high, value);
    }
}

int main()
{
    int n, value;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the value to search: ");
    scanf("%d", &value);
    BinarySearch(arr, 0, n - 1, value);
    printf("Time complexity: O(log(n)) = %d\n", count);
    return 0;
}
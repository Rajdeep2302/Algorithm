// Write a C program using linear search to search to search an element in an array also compute time complexity for an input of size N.
#include <stdio.h>

int count = 0;

void LinearSearch(int arr[], int n, int value)
{
    for (int i = 0; i < n; i++)
    {
        count++;
        if (arr[i] == value)
        {
            printf("Element found at index %d\n", i);
            break;
        }
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
    LinearSearch(arr, n, value);
    printf("Time complexity: O(n) = %d\n", count);
    return 0;
}
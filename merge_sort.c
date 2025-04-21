// Write a C Program to perform Merge Sort on an integer array to sort it in ascending order and compute the time complexity for an input of size N.
#include <stdio.h>

int count = 0;
void merge_sort(int array[], int low, int mid, int high)
{
    int size1 = mid - low + 1;
    int size2 = high - mid;

    int temp_array1[size1], temp_array2[size2];
    for (int i = 0; i < size1; i++)
    {
        temp_array1[i] = array[low + i];
    }
    for (int j = 0; j < size2; j++)
    {
        temp_array2[j] = array[mid + 1 + j];
    }

    int left = 0, right = 0, k = low;
    while (left < size1 && right < size2)
    {
        count++;
        if (temp_array1[left] <= temp_array2[right])
        {
            array[k] = temp_array1[left];
            left++;
        }
        else
        {
            array[k] = temp_array2[right];
            right++;
        }
        k++;
    }
    while (left < size1)
    {
        count++;
        array[k] = temp_array1[left];
        left++;
        k++;
    }
    while (right < size2)
    {
        count++;
        array[k] = temp_array2[right];
        right++;
        k++;
    }
}

void merge(int array[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        count++;
        merge(array, low, mid);
        merge(array, mid + 1, high);
        merge_sort(array, low, mid, high);
    }
}

int main()
{
    int a;
    printf("Enter the size of the array: ");
    scanf("%d", &a);
    int array[a];

    printf("Enter the values of the array: ");
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &array[i]);
    }

    merge(array, 0, a - 1);

    printf("Sorted array: ");
    for (int j = 0; j < a; j++)
    {
        printf("%d ", array[j]);
    }
    printf("\n");
    printf("Time Complexity is O(n*log(n)): %d", count);
    printf("\n");

    return 0;
}

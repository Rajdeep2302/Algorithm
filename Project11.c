// Write a C Program to perform radix sort on an integer array to sort it in ascending order and compute the time complexity for an input of size N.
#include <stdio.h>

int complexity = 0;
int find_max(int arr[], int size)
{
    int max_value = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (max_value < arr[i])
        {
            max_value = arr[i];
        }
    }
    return max_value;
}

void sortIndex(int array[], int a, int temp[])
{
    int arr[a], x;
    for (int i = 0; i < a; i++)
    {
        arr[i] = 0;
    }
    int min;
    for (int i = 0; i < a; i++)
    {
        complexity++;
        for (x = 0; arr[x] != 0; x++)
            ;
        min = x;
        for (int j = 0; j < a; j++)
        {
            if (arr[j] != 1)
            {
                if (array[min] > array[j] && arr[j] == 0)
                {
                    complexity++;
                    min = j;
                }
            }
        }
        arr[min] = 1;
        temp[i] = min;
    }
}

void radix_sort(int size, int arr[])
{
    int max_value = find_max(arr, size);
    for (int i = 1; max_value / i > 0; i = i * 10)
    {
        complexity++;
        int bit_array[size], temp[size];
        for (int j = 0; j < size; j++)
        {
            complexity++;
            bit_array[j] = (arr[j] / i) % 10;
        }
        sortIndex(bit_array, size, temp);
        int extra_array[size];
        for (int k = 0; k < size; k++)
        {
            extra_array[k] = arr[temp[k]];
        }
        for (int l = 0; l < size; l++)
        {
            arr[l] = extra_array[l];
        }
    }
}

int main()
{
    printf("Enter the size of array: ");
    int n;
    scanf("%d", &n);
    int array[n];
    printf("Enter all array values: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    radix_sort(n, array);
    printf("Sorted array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\nComplexity is: %d", complexity);
    return 0;
}

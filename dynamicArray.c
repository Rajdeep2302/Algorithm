// Write a C program to implement dynamic array. First take maximum length of array from user input. Then start by creating array of size 1, and start taking input. Every time the array is full, double its capacity. Use amortize analysis (aggregate) to calculate time complexity of the program.
#include <stdio.h>
#include <stdlib.h>

int complexity = 0;

int main()
{
    int n;
    printf("Enter the maximum size of array:");
    scanf("%d", &n);
    int *array = (int *)malloc(sizeof(int) * 1);
    int size = 1;
    int i = 0;
    while (i != n)
    {
        printf("Enter The value to insert: ");
        complexity++;
        int value;
        scanf("%d", &value);
        if (i == size)
        {
            size = size * 2;
            array = (int *)realloc(array, sizeof(int) * size);
        }
        array[i] = value;
        i++;
    }
    printf("Your array is: ");
    for (int j = 0; j < n; j++)
    {
        printf("%d ", array[j]);
    }
    printf("\n");
    printf("Time complexity: O(n) = %d\n", complexity);
    printf("Amortized time complexity: O(1) = %d\n", complexity / n);
    free(array);
    return 0;
}
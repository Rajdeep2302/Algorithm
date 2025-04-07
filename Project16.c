// Write C program to implement stack with the use of array. Make a new function Multi Pop which pops k times. Take k as user input. Uses amortize analysis (accounting) to calculate time complexity of the program.

#include <stdio.h>
#include <stdlib.h>

int complexity = 0;
int top = -1;
int *stack = NULL;
int main()
{
    printf("Enter the size of stack: ");
    int n;
    scanf("%d", &n);
    stack = (int *)malloc(sizeof(int) * n);
    int size = n;
    printf("Enter all the value to push: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &stack[i]);
    }

    printf("Enter the pop time (k): ");
    int k;
    scanf("%d", &k);
    if (k > n)
    {
        printf("Invalid pop time.\n");
        return 0;
    }
    for (int i = 0; i < k; i++)
    {
        complexity++;
        top--;
    }
    printf("Your stack after popping %d times is: ", k);
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }

    printf("\nPopped values are: ");
    for (int i = 0; i < k; i++)
    {
        printf("%d ", stack[top + 1 + i]);
    }

    printf("\n");
    printf("Time complexity: O(n) = %d\n", complexity);
    printf("Amortized time complexity: O(1) = %d\n", complexity / k);
    free(stack);
    return 0;
}
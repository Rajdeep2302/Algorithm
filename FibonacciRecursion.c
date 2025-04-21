// Write a C Programming to print Fibonacci series upto n terms using Recursion also compute time complexity in terms of input size.

// use normal approach to solve the problem
#include <stdio.h>
int count = 0;
int fibonacci(int n)
{
    if (n <= 1)
    {
        count++;
        return n;
    }
    count++;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main()
{
    printf("Enter the size of of the series: ");
    int n;
    scanf("%d", &n);
    printf("Your fibonacci series is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", fibonacci(i));
    }
    printf("Time complexity: O(2^n) = %d\n", count);
    return 0;
}


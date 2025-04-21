// use Fibonacci Dynamic Programming to solve the problem
#include <stdio.h>

int memory[100];
int count = 0;

int fibonacci(int n)
{
    if(n<=1){
        count++;
        return n;
    }
    if(memory[n] != -1){
        return memory[n];
    }
    count++;
    memory[n] = fibonacci(n-1)+fibonacci(n-2);
    return memory[n];
}

int main()
{
    for(int i = 0; i < 100; i++){
        memory[i] = -1;
    }
    printf("Enter the size of of the series: ");
    int n;
    scanf("%d", &n);
    printf("Your fibonacci series is: \n");
    int a = fibonacci(n);
    if(n>=2){
        printf("0\n");
        printf("1\n");
    } else if(n == 1){
        printf("0\n");
    }
    for(int i = 2; i < n; i++){
        printf("%d\n", memory[i]);
    }
    printf("Time complexity: O(n) = %d\n", count);
    return 0;
}
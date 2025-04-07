//Write a C Programming to print Fibonacci series upto n terms using iteration also compute time complexity.

#include<stdio.h>
int count = 0;

void fibonacci(int n){
    int a = 0, b = 1, c;
    count++;
    count++;
    printf("%d\n%d\n", a, b);
    for(int i = 2; i < n; i++){
        count++;
        c = a + b;
        printf("%d\n", c);
        a = b;
        b = c;
    }
}

int main(){
    printf("Enter the size of of the series: ");
    int n; 
    scanf("%d", &n);
    printf("Your fibonacci series is: \n");
    fibonacci(n);
    printf("Time complexity: O(n) = %d\n", count);
    return 0;
}   
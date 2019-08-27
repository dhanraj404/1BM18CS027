//Fibonacii using recursive function#include<stdio.h>
#include<stdio.h>
int f(int);
int main()
{
    int n, i = 0, c;
    printf("Enter number of elements to be printed:\n ");
    scanf("%d", &n);
    printf("Fibonacci series terms are:\n");

    for (c = 1; c <= n; c++)
    {
        printf("%d\n", f(i));
        i++;
    }

    return 0;
}
int f(int n)
{
    if(n == 0 || n == 1)
        return n;
    else
        return (f(n-1) + f(n-2));
}

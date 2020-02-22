#include <stdio.h>

/* This function calculates the factorial of a given number
* Parameters:
* int n: The number to calculate the factorial
* Return: the result of the factorial
*/
long long int factorial(int n);

/* This function returns the nth term in the fibonacci sequence
* Parameters:
* int n: The term to get from the fibonacci sequence
* Return: the number in the nth position
*/
int fibonacci(int n);

// Main function
int main(void)
{
    int nFact;
    int nFib;

    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &nFact);

    printf("Enter the term number of the fibonacci sequence: ");
    scanf("%d", &nFib);

    printf("Factiorial of %d: %lld\n", nFact, factorial(nFact));
    printf("Term number %d of fibonacci: %d\n", nFib, fibonacci(nFib));
}

long long int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return factorial(n-1) * n;
}

int fibonacci(int n) 
{
    if (n == 1)
    {
        return 0;
    }

    if (n == 2)
    {
        return 1;
    }

    return fibonacci(n-1) + fibonacci(n-2);
}
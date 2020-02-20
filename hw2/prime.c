#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
    if (n == 1) {
        return false;
    }
    
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    if (isPrime(n)) {
        printf("%d is prime!\n", n);
    } else {
        printf("%d is not prime!\n", n);
    }
}#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
    if (n == 1) {
        return false;
    }
    
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    if (isPrime(n)) {
        printf("%d is prime!\n", n);
    } else {
        printf("%d is not prime!\n", n);
    }
}
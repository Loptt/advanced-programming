#include <stdio.h>

void fibonacci(int n) {
    int prev1 = 1, prev2 = 0;
    int curr, tmp;

    if (n < 1) {
        return;
    }

    printf("0 ");

    if (n == 1) {
        return;
    }

    printf("1 ");

    if (n == 2) {
        return;
    }

    for (int i = 2; i < n; i++) {
        printf("%d ", prev1 + prev2);
        tmp = prev2;
        prev2 = prev1;
        prev1 = prev1+tmp;
    }

    printf("\n");
}

int main() {
    int n;
    printf("Enter number of terms to get: ");
    scanf("%d", &n);
    fibonacci(n);
}
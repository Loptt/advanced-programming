#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int iInteger;
    char cCharacter;
    double dDouble;
    char basura;
    fflush(stdin);

    printf("Enter an integer: ");
    scanf("%d", &iInteger);

    //scanf("%c", &basura);

    printf("Enter a character: ");
    scanf("%c", &cCharacter);
    fflush(stdin);

    printf("Enter a double: ");
    scanf("%lf", &dDouble);
    fflush(stdin);

    printf("Your integer %d storage size is %ld bytes\n", iInteger, sizeof(iInteger));
    printf("%c\n", cCharacter);
}
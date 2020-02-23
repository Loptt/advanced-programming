//
// Author: Carlos Estrada
// ID: A01039919
// Date: 19/02/2020
//
// Exercises with types in C
//

#include <stdio.h>
#include <float.h>

// This function cleans the stdin buffer since fflush is useless
// for stdin and fgets is too problematic, credits to Mathiun for this
// on https://stackoverflow.com/questions/17318886/fflush-is-not-working-in-linux
void cleanStdin(void);

// Main Function
int main(void) {
    int integer;
    char character;
    double ddouble;

    printf("Enter an integer: ");
    scanf("%d", &integer);

    cleanStdin();

    printf("Enter a character: ");
    scanf("%c", &character);

    cleanStdin();

    printf("Enter a double: ");
    scanf("%lf", &ddouble);

    printf("Your integer %d storage size is %ld bytes\n", integer, sizeof(integer));
    printf("Your char %c storage size is %ld byte. And I can read it as %c or as %d.\n",
        character, sizeof(character), character, character);
    printf("Your double %f storage size is %ld bytes, I can read any number from %.5e to %.5e in this data type.\n",
        ddouble, sizeof(ddouble), DBL_MIN, DBL_MAX);
}

void cleanStdin(void) {
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
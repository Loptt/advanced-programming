//
// Author: Carlos Estrada
// ID: A01039919
// Date: 19/02/2020
//
// Exercises with unions in C
//

#include <stdio.h>
#include <float.h>

// This function cleans the stdin buffer since fflush is useless
// for stdin and fgets is too problematic, credits to Mathiun for this
// on https://stackoverflow.com/questions/17318886/fflush-is-not-working-in-linux
void cleanStdin(void);

union Input
{
    int integer;
    char character;
    double ddouble;
};

// Main Function
int main(void) {
    union Input in;

    printf("Enter an integer: ");
    scanf("%d", &in.integer);

    cleanStdin();
    printf("Your integer %d storage size is %ld bytes\n", in.integer, sizeof(in.integer));

    printf("Enter a character: ");
    scanf("%c", &in.character);

    cleanStdin();
    printf("Your char %c storage size is %ld byte. And I can read it as %c or as %d.\n",
        in.character, sizeof(in.character), in.character, in.character);


    printf("Enter a double: ");
    scanf("%lf", &in.ddouble);

    printf("Your double %f storage size is %ld bytes, I can read any number from %.5e to %.5e in this data type.\n",
        in.ddouble, sizeof(in.ddouble), DBL_MIN, DBL_MAX);
}

void cleanStdin(void) {
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
#include <stdio.h>
#include "Single.h"
#include "Multi.h"

int main(void) 
{
    long double pi;

    printf("Single thread calculation:\n");
    pi = calculatePiSingle();
    printf("Pi is: %.15Lg\n", pi);

    printf("\nMulti thread calculation:\n");
    pi = calculatePiMulti();
    printf("Pi is: %.15Lg\n", pi);

    return 0;
}
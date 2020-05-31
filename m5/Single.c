#include <stdio.h>
#include <time.h>
#include <math.h>

#define AMOUNT_OF_RECTANGLES 2000000000

long double calculatePiSingle()
{
    time_t start, stop;
    
    start = clock();

    long long int sizes = AMOUNT_OF_RECTANGLES;

    long double area = 0.0;
    long double width = 1.0 / (long double) sizes;
    long double height;
    long double x;
    long double pi;

    for (int i = 0; i < sizes; i++){
        x = i * width;
        height = sqrt(1.0 - x * x);
        area += width * height;
    }

    pi = 4.0 * area;

    stop = clock();

    long double elapsed = (long double)(stop - start) / CLOCKS_PER_SEC;
    
    printf("Time for calculation: %Lf\n", elapsed);

    return pi;
}
#include <stdio.h>

#define SIZE 2

void readMatrix(const char *message, int matrix[SIZE][SIZE]);

void printMatrix(const char *message, int matrix[SIZE][SIZE]);

int main(void) 
{
    int aMatrix[SIZE][SIZE];
    int bMatrix[SIZE][SIZE];

    readMatrix("Please enter values for matrix A", aMatrix);
    readMatrix("Please enter values for matrix B", bMatrix);

    printMatrix("Matrix A", aMatrix);
    printMatrix("Matrix B", bMatrix);
}

void readMatrix(const char *message, int matrix[SIZE][SIZE]) 
{
    printf("%s\n", message);

    for(int i = 0; i < SIZE; i++) 
    {
        for(int j = 0; j < SIZE; j++)
        {
            scanf("%d", &matrix[i][j]);        
        }
    }
}

void printMatrix(const char *message, int matrix[SIZE][SIZE])
{
    printf("%s\n", message);

    for(int i = 0; i < SIZE; i++) 
    {
        for(int j = 0; j < SIZE; j++)
        {
            printf("%d ", matrix[i][j]);        
        }

        printf("\n");
    }
}
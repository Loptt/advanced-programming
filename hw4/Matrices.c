#include <stdio.h>

#define SIZE 2

void readMatrix(const char *message, int matrix[SIZE][SIZE]);

void printMatrix(const char *message, int matrix[SIZE][SIZE]);

void sumMatrices(int aMatrix[SIZE][SIZE], int bMatrix[SIZE][SIZE], int rMatrix[SIZE][SIZE]);

void subtractMatrices(int aMatrix[SIZE][SIZE], int bMatrix[SIZE][SIZE], int rMatrix[SIZE][SIZE]);

int main(void) 
{
    int aMatrix[SIZE][SIZE];
    int bMatrix[SIZE][SIZE];
    int rMatrix[SIZE][SIZE];

    readMatrix("Please enter values for matrix A", aMatrix);
    readMatrix("Please enter values for matrix B", bMatrix);

    printMatrix("Matrix A", aMatrix);
    printMatrix("Matrix B", bMatrix);

    sumMatrices(aMatrix, bMatrix, rMatrix);
    printMatrix("Sum of A and B", rMatrix);

    subtractMatrices(aMatrix, bMatrix, rMatrix);
    printMatrix("Subtraction of A and B", rMatrix);
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

void sumMatrices(int aMatrix[SIZE][SIZE], int bMatrix[SIZE][SIZE], int rMatrix[SIZE][SIZE]) 
{
    for(int i = 0; i < SIZE; i++) 
    {
        for(int j = 0; j < SIZE; j++)
        {
            rMatrix[i][j] = aMatrix[i][j] + bMatrix[i][j];        
        }
    }
}

void subtractMatrices(int aMatrix[SIZE][SIZE], int bMatrix[SIZE][SIZE], int rMatrix[SIZE][SIZE]) 
{
    for(int i = 0; i < SIZE; i++) 
    {
        for(int j = 0; j < SIZE; j++)
        {
            rMatrix[i][j] = aMatrix[i][j] - bMatrix[i][j];        
        }
    }
}

void multipluMatrices(int aMatrix[SIZE][SIZE], int bMatrix[SIZE][SIZE], int rMatrix[SIZE][SIZE]) 
{
    for(int i = 0; i < SIZE; i++) 
    {
        for(int j = 0; j < SIZE; j++)
        {
            for(int k = 0; k < SIZE; k++)
            {
                  
            }   
        }
    }
}
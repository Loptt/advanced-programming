//
// Author: Carlos Estrada
// ID: A01039919
// Date: 19/02/2020
//
// Exercises with matrices and functions in C
//

#include <stdio.h>

#define SIZE 2

/* This function prompts the user to enter a SIZE by SIZE matrix
* Parameters:
* char *message: The message to print to the user
* int m[][]: The matrix to save the entered values
*/
void readMatrix(const char *message, int matrix[SIZE][SIZE]);

/* This function prints a matrix to the user
* Parameters:
* char *message: The message to print to the user
* int m[][]: The matrix to print to the screen
*/
void printMatrix(const char *message, int matrix[SIZE][SIZE]);

/* This function adds two matrices A and B and stores the result in R
* Parameters:
* int a[][]: The first matrix to add
* int b[][]: The second matrix to add
* int r[][]: The matrix to store the result
*/
void sumMatrices(int aMatrix[SIZE][SIZE], int bMatrix[SIZE][SIZE], int rMatrix[SIZE][SIZE]);

/* This function subtracts two matrices A and B and stores the result in R
* Parameters:
* int a[][]: The first matrix to subtract
* int b[][]: The second matrix to subtract
* int r[][]: The matrix to store the result
*/
void subtractMatrices(int aMatrix[SIZE][SIZE], int bMatrix[SIZE][SIZE], int rMatrix[SIZE][SIZE]);

/* This function multiplies two matrices A and B and stores the result in R
* Parameters:
* int a[][]: The first matrix to multiply
* int b[][]: The second matrix to multiply
* int r[][]: The matrix to store the result
*/
void multiplyMatrices(int aMatrix[SIZE][SIZE], int bMatrix[SIZE][SIZE], int rMatrix[SIZE][SIZE]);


// Main function
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

    multiplyMatrices(aMatrix, bMatrix, rMatrix);
    printMatrix("Multiplication of A and B", rMatrix);
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

void multiplyMatrices(int aMatrix[SIZE][SIZE], int bMatrix[SIZE][SIZE], int rMatrix[SIZE][SIZE]) 
{
    int aux = 0;

    for(int i = 0; i < SIZE; i++) 
    {
        for(int j = 0; j < SIZE; j++)
        {
            for(int k = 0; k < SIZE; k++)
            {
                aux += aMatrix[i][k] * bMatrix[k][j];
            }

            rMatrix[i][j] = aux;
            aux = 0;
        }
    }
}
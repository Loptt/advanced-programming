//
// Author: Carlos Estrada
// ID: A01039919
// Date: 27/03/2020
//
// Hour of Code 2
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/*
Function to parse the input from the user
Parameters: input, the numbers array, the amount of numbers
Return: the amount of new numbers
*/
int processInput(char *buffer, int numbers[100], int amountNumbers);

/*
Function to transform a string number to its corresponding int value
Parameters: name to transform
Return: the int value
*/
int nameToInt(char *name);

/*
Function to transform a string number to its corresponding int value
Parameters: name to transform
Return: the int value
*/
int simpleNameToInt(char *name);

/*
Function copy a substring of a string to a new buffer
Parameters: the original buffer, the buffer to copy to, substring initial pos, substring end pos
Return: nothing
*/
void copyToBuffer(char *buffer, char *copyb, int init, int end);

/*
Function to count the digits in all the numbers array
Parameters: numbers array
Return: the int value
*/
int countDigits(int numbers[100], int amount);


/*
Function to validate the id
Parameters: id to validate
Return: the int value
*/
bool validateId(char *id);


// Main function
int main(void)
{
    char *id;
    char *buffer;
    char *digitBuffer;
    char singleDigitBuffer[5];
    int numbers[100];
    int amountNumbers = 0;
    int digits = 0;
    int inputReturn;
    int randinit;

    buffer = malloc(sizeof(char) *1000);
    digitBuffer = malloc(sizeof(char) *1000);
    id = malloc(sizeof(char) *10);

    srand((unsigned) time(0));

    printf("Escribe tu id actual: ");
    fgets(id, 100, stdin);

    while (!validateId(id)) {
        printf("ID invalido, vuelve a introducirlo: ");
        fgets(id, 100, stdin);
    }

    while (digits < 9)
    {
        memset(buffer, 0, 1000);
        printf("Escribe numeros separados por coma: \n");
        fgets(buffer, 1000, stdin);
        inputReturn = processInput(buffer, numbers, amountNumbers);

        if (inputReturn == -1)
        {
            printf("Error leyendo numeros. Abortando programa\n");
            exit(1);
        }

        amountNumbers += inputReturn;
        digits = countDigits(numbers, amountNumbers);
    }

    memset(digitBuffer, 0, 1000);
    memset(singleDigitBuffer, 0, 5);

    for (int i = 0; i < amountNumbers; i++)
    {
        sprintf(singleDigitBuffer, "%d", numbers[i]);
        strcat(digitBuffer, singleDigitBuffer);
    }

    randinit = rand();

    for (int i = 0; i < 9; i++) {
        id[i+4] = digitBuffer[(randinit+i)%9];
    }

    printf("El nuevo ID es: %s\n", id);

    free(buffer);
    free(id);
    free(digitBuffer);
}

int processInput(char *buffer, int numbers[100], int initNumbers)
{
    int init = 0;
    int number;
    char copyb[1000];

    int amountRead = 0;

    for (int i = 0; i < strlen(buffer); i++)
    {
        if (buffer[i] == ',' || i == strlen(buffer)-1)
        {
            memset(copyb, 0, 1000);
            //printf("Copying %d-%d\n", init, i);
            copyToBuffer(buffer, copyb, init, i);
            init = i+1;

            //printf("Numero: %s\n", copyb);

            number = nameToInt(copyb);

            if (number == -1)
            {
                return -1;
            }
            
            numbers[initNumbers + amountRead] = number;
            amountRead++;
        }
    }

    return amountRead;
}

int nameToInt(char *name)
{
    int ypos = 0;
    char copyb[100];

    int number;
    int retval;

    //printf("Converting string to int\n");

    for (int i = 0; i < strlen(name); i++)
    {
        if (name[i] == 'y')
        {
            ypos = i;
            break;
        }
    }

    if (ypos != 0)
    {
        memset(copyb, 0, 100);
        copyToBuffer(name, copyb, 0, ypos);

        retval = simpleNameToInt(copyb);

        if (retval == -1)
        {
            return -1;
        }

        number = retval;

        memset(copyb, 0, 100);
        copyToBuffer(name, copyb, ypos+1, strlen(name));

        retval = simpleNameToInt(copyb);

        if (retval == -1)
        {
            return -1;
        }

        number += retval;
    }
    else
    {
        retval = simpleNameToInt(name);

        if (retval == -1)
        {
            return -1;
        }

        number = retval;
    }

    return number;
}

int simpleNameToInt(char *name)
{
    if (strcmp(name, "cero") == 0) return 0;
    if (strcmp(name, "uno") == 0) return 1;
    if (strcmp(name, "dos") == 0) return 2;
    if (strcmp(name, "tres") == 0) return 3;
    if (strcmp(name, "cuatro") == 0) return 4;
    if (strcmp(name, "cinco") == 0) return 5;
    if (strcmp(name, "seis") == 0) return 6;
    if (strcmp(name, "siete") == 0) return 7;
    if (strcmp(name, "ocho") == 0) return 8;
    if (strcmp(name, "nueve") == 0) return 9;
    if (strcmp(name, "diez") == 0) return 10;
    if (strcmp(name, "once") == 0) return 11;
    if (strcmp(name, "doce") == 0) return 12;
    if (strcmp(name, "trece") == 0) return 13;
    if (strcmp(name, "catorce") == 0) return 14;
    if (strcmp(name, "quince") == 0) return 15;
    if (strcmp(name, "dieciseis") == 0) return 16;
    if (strcmp(name, "diecisiete") == 0) return 17;
    if (strcmp(name, "dieciocho") == 0) return 18;
    if (strcmp(name, "diecinueve") == 0) return 19;
    if (strcmp(name, "veinte") == 0) return 20;
    if (strcmp(name, "veintiuno") == 0) return 21;
    if (strcmp(name, "veintidos") == 0) return 22;
    if (strcmp(name, "veintitres") == 0) return 23;
    if (strcmp(name, "veinticuatro") == 0) return 24;
    if (strcmp(name, "veinticinco") == 0) return 25;
    if (strcmp(name, "veintiseis") == 0) return 26;
    if (strcmp(name, "veintisiete") == 0) return 27;
    if (strcmp(name, "veintiocho") == 0) return 28;
    if (strcmp(name, "veintinueve") == 0) return 29;
    if (strcmp(name, "treinta") == 0) return 30;
    if (strcmp(name, "cuarenta") == 0) return 40;
    if (strcmp(name, "cincuenta") == 0) return 50;
    if (strcmp(name, "sesenta") == 0) return 60;
    if (strcmp(name, "setenta") == 0) return 70;
    if (strcmp(name, "ochenta") == 0) return 80;
    if (strcmp(name, "noventa") == 0) return 90;
    if (strcmp(name, "cien") == 0) return 100;

    return -1;
}

void copyToBuffer(char *buffer, char *copyb, int init, int end)
{
    int counter = 0;
    for (int i = 0; i < end - init; i++) 
    {
        if (buffer[init + i] != ' ')
        {
            copyb[counter++] = buffer[init + i];
        }
    }

}

int countDigits(int numbers[100], int amount)
{
    int a = 0;
    for (int i = 0; i < amount; i++)
    {
        if (numbers[i] < 10)
        {
            a += 1;
        }
        else if (numbers[i] < 100)
        {
            a += 2;
        }
        else
        {
            a += 3;
        }
    }

    return a;
}

bool validateId(char *active)
{
    if (strlen(active) != 14)
    {
        return false;
    }

    for (int i = 0; i < 13; i++) 
    {

        if (i < 4 && (active[i] < 'A' || (active[i] > 'Z' && active[i] < 'a') || active[i] > 'z')) 
        {
            return false;
        }

        if (i >= 4 && (active[i] < '0' || active[i] > '9')) 
        {
            return false;
        }
    }

    return true;
}
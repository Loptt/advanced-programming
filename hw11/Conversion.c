//
// Author: Carlos Estrada
// ID: A01039919
// Date: 27/03/2020
//
// Practice 11
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/*
Function to convert a char array representing a binary number to its integer equivalent.
The user of the function must make sure the string contains only 0s and 1s.
Parameters: the array to convert
Return: The corresponding integer 
*/
int asciiBinaryToInt(char *s);

/*
Function to convert a hex char to its corresponding int value. The user of the function 
must make sure the char is a valid hex char
Parameters: the array to convert
Return: The corresponding integer 
*/
int hexLetterToInt(char letter);

/*
Function to convert a char array representing a hex number to its integer equivalent.
The user of the function must make sure the string contains valid hex chars
Parameters: the array to convert
Return: The corresponding integer 
*/
int asciiHEXToInt(char *s);

/*
Function to convert a char array representing a hex number to its integer equivalent.
The user of the function must make sure the string contains valid hex chars
Parameters: the array to convert
Return: The corresponding integer 
*/
int asciiOCTtoInt(char *s);

/*
Function to validate if the string is a valid binary number
Parameters: the array to validate
Return: True if it's a valid number
*/
bool validateBinary(char *s);

/*
Function to validate if the string is a valid hex number
Parameters: the array to validate
Return: True if it's a valid number
*/
bool validateHex(char *s);

/*
Function to validate if the string is a valid oct number
Parameters: the array to validate
Return: True if it's a valid number
*/
bool validateOct(char *s);

/*
Function to multiply a number by 2
Parameters: number
Return: the result
*/
int multByTwo(int *i);

/*
Function to divide a number by 2
Parameters: number
Return: the result
*/
int divideByTwo(int *i);

int main(void)
{
    char numstr[100];
    bool run = true;
    int num;

    int opt;

    while (run)
    {
        printf("\nChoose an option:\n");
        printf("1. Save binary number\n");
        printf("2. Save octal number\n");
        printf("3. Save hex number\n");
        printf("4. Multiply saved number by two\n");
        printf("5. Divide saved number by two\n");

        scanf("%d", &opt);

        switch(opt)
        {
            case 1:
                printf("Enter number: ");
                scanf("%s", numstr);

                if (!validateBinary(numstr)) 
                {
                    printf("\nInvalid number format!\n");
                }
                else
                {
                    num = asciiBinaryToInt(numstr);
                    printf("Number %d saved!\n\n", num);
                }

                break;
            case 2:
                printf("Enter number: ");
                scanf("%s", numstr);

                if (!validateOct(numstr)) 
                {
                    printf("\nInvalid number format!\n");
                }
                else
                {
                    num = asciiOCTtoInt(numstr);
                    printf("Number %d saved!\n\n", num);
                }
                break;
            case 3:
                printf("Enter number: ");
                scanf("%s", numstr);

                if (!validateHex(numstr)) 
                {
                    printf("\nInvalid number format!\n");
                }
                else
                {
                    num = asciiHEXToInt(numstr);
                    printf("Number %d saved!\n\n", num);
                }
                break;
            case 4:
                printf("%d * 2 = ", num);
                multByTwo(&num);
                printf("%d\n", num);
                break;
            case 5:
                printf("%d / 2 = ", num);
                divideByTwo(&num);
                printf("%d\n", num);
                break;
            default:
                printf("Invalid option\n\n");
        }
    }
}

int asciiBinaryToInt(char *s)
{
    int result = 0;
    int pow = 1;

    for (int i = strlen(s)-1; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            result += pow;
        }
        pow *= 2;
    }

    return result;
}

int hexLetterToInt(char letter)
{
    if (letter >= 'a')
    {
        return letter - 'a' + 10;
    }
    else
    {
        return letter - 'A' + 10;
    }
    
}

int asciiHEXToInt(char *s)
{
    int result = 0;
    int pow = 1;

    for (int i = strlen(s)-1; i >= 0; i--)
    {
        if (s[i] <= '9')
        {
            result += (s[i] - '0') * pow;
        }
        else 
        {
            result += hexLetterToInt(s[i]) * pow;
        }

        pow *= 16;
    }
    
    return result;
}

int asciiOCTtoInt(char *s)
{
    int result = 0;
    int pow = 1;

    for (int i = strlen(s)-1; i >= 0; i--)
    {
        result += (s[i] - '0') * pow;
        pow *= 8;
    }
    
    return result;
}


bool validateBinary(char *s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] != '0' && s[i] != '1') 
        {
            return false;
        }
    }

    return true;
}

bool validateHex(char *s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (!isxdigit(s[i]))
        {
            return false;
        }
    }

    return true;
}

bool validateOct(char *s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] < '0' || s[i] > '7')
        {
            return false;
        }
    }

    return true;
}

int multByTwo(int *i)
{
    *i = (*i) << 1;
    return *i; 
}

int divideByTwo(int *i)
{
    *i = (*i) >> 1;
    return *i; 
}


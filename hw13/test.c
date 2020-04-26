#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

HINSTANCE hCodigoDll;

typedef int (ASCII_TO_BINARY)(char *s);

ASCII_TO_BINARY* ptrFuncAsciiToBinary = 0;

typedef int (ASCII_TO_HEXA)(char *s);

ASCII_TO_HEXA* ptrFuncAsciiToHexa = 0;

typedef double (ASCII_TO_DOUBLE)(char *s);

ASCII_TO_DOUBLE* ptrFuncAsciiToDouble = 0;


void main() 
{
    char *binario = "11010111";
    char *hexa = "FF";
    char *floto = "123.45";

    if (hCodigoDll = LoadLibrary("Conversion.dll"))
    {
        if (ptrFuncAsciiToBinary = (ASCII_TO_BINARY*) GetProcAddress(hCodigoDll, "asciiBinaryToInt"))
        {
            int result = (*ptrFuncAsciiToBinary)(binario);

            printf("Numero Binario: %d\n", result);
        }
        else 
        {
            printf("ERROR: Routine not found!\n");
        }

        if (ptrFuncAsciiToHexa = (ASCII_TO_HEXA*) GetProcAddress(hCodigoDll, "asciiHEXToInt"))
        {
            int result = (*ptrFuncAsciiToHexa)(hexa);

            printf("Numero Hexa: %d\n", result);
        }
        else 
        {
            printf("ERROR: Routine not found!\n");
        }

        if (ptrFuncAsciiToDouble = (ASCII_TO_DOUBLE*) GetProcAddress(hCodigoDll, "asciiToDouble"))
        {
            double result = (*ptrFuncAsciiToDouble)(floto);

            printf("Numero Double: %f\n", result);
        }
        else 
        {
            printf("ERROR: Routine not found!\n");
        }
    }
    else 
    {
        printf("ERROR: Library not found!\n");
    }

    FreeLibrary(hCodigoDll);
}

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "Conversion.h"

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

double asciiToDouble(char *s)
{
    double result = 0;

    int whole = 0, decimal = 0;
    int pow = 1, decount = 1;
    int remaining = 0;

    double decimalD = 0.0;

    bool point = false;
    bool negative = false;

    for (int i = strlen(s)-1; i >= 0; i--)
    {
        if (s[i] == '.') 
        {
            point = true;
            remaining = i-1;
            break;
        }

        if (isdigit(s[i]))
        {
            decimal += (s[i] - '0') * pow;
        }

        if (s[i] == '-' && i == 0)
        {
            negative = true;
        }

        pow *= 10;
        decount *= 10;
    }
    
    if (!point)
    {
        return decimal;
    }

    pow = 1;

    for (int i = remaining; i >= 0; i--)
    {
        if (isdigit(s[i]))
        {
            whole += (s[i] - '0') * pow;
        }

        if (s[i] == '-' && i == 0)
        {
            negative = true;
        }

        pow *= 10;
    }

    decimalD = ((double) decimal) / ((double) decount);

    result = (double) whole + decimalD;

    if (negative)
    {
        result *= -1;
    }

    return result;
}

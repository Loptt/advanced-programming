#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int asciiBinaryToInt(char *s);

int hexLetterToInt(char letter);

int asciiHEXToInt(char *s);

double asciiToDouble(char *s);

bool validateBinary(char *s);

bool validateHex(char *s);

bool validateDouble(char *s);

int main(void)
{
    printf("%d\n", asciiHEXToInt("B"));
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

bool validateBinary(char *s)
{

}

bool validateHex(char *s)
{
    
}

bool validateDouble(char *s)
{
    
}
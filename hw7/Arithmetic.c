//
// Author: Carlos Estrada
// ID: A01039919
// Date: 19/02/2020
//
// Exercises with pointer arithmetic in C
//

#include <stdio.h>
#include <string.h>

/* This function applies the defined cypher to the input message
* Parameters:
* char *message: The message to cypher
*/
void cypher(char *message);

// Main function
int main(void)
{
    char message[200];
    printf("Enter message to cypher: ");
    fgets(message, 200, stdin);

    cypher(message);

    printf("The cyphered message is: %s\n", message);
}

void cypher(char *message)
{
    for (int i = 0; i < strlen(message); i++)
    {
        switch (*(message + i))
        {
            case 'A':
            case 'a':
                *(message + i) = '4';
                break;
            case 'E':
            case 'e':
                *(message + i) = '3';
                break;
            case 'i':
            case 'I':
                *(message + i) = '1';
                break;
            case 'O':
            case 'o':
                *(message + i) = '0';
                break;
            case 'U':
            case 'u':
                *(message + i) = '2';
                break;
        }
    }
}
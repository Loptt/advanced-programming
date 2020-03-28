//
// Author: Carlos Estrada
// ID: A01039919
// Date: 08/03/2020
//
// Practice 10
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char c;
    struct node *next;
} Node;

const char END = '\n';

/*
Function to read an extremely large string
Parameters: the node to the head of the string
Return: nothing
*/
void extremelyLargeString(Node **head);

/*
Function to print the extremely large string
Parameters: the node to the head of the string
Return: nothing
*/
void printString(Node *string);

/*
Function to free the extremely large string
Parameters: the node to the head of the string
Return: nothing
*/
void freeString(Node *string);

// Main
int main(void)
{
    Node *string;

    printf("Enter extremely large string: ");

    extremelyLargeString(&string);

    printString(string);

    freeString(string);
}

void extremelyLargeString(Node **head)
{
    char c;
    Node *curr;
    
    c = getchar();

    if (c == END) {
        return;
    }

    *head = malloc(sizeof(Node));

    (*head)->c = c;

    curr = *head;

    while (c != END)
    {
        c = getchar();

        if (c != END) {
            curr->next = malloc(sizeof(Node));
            curr->next->c = c;
            curr = curr->next;
        }
    }
}

void printString(Node *string)
{
    printf("\nYour extremely large string is: ");

    Node *curr = string;

    while(curr != 0)
    {
        printf("%c", curr->c);
        curr = curr->next;
    }

    printf("\n");
}

void freeString(Node *string)
{
    if (string == 0)
    {
        return;
    }

    Node *curr = string;
    Node *tmp = string;

    while (curr != 0)
    {
        tmp = curr;
        curr = curr->next;
        free(tmp);
    }
}
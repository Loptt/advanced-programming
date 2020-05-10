// Carlos Estrada A01039919 
// Hour of Code 3
// 28/047/2020

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct coordinate {
    char longC[30];
    double longN;
    char latC[30];
    double latN;
} Coordinate;

int countCoordinates(FILE *f);

void readCoordinates(FILE *f, Coordinate* coordList, int amount);

int compareCoordinates(const void * c1, const void * c2);

void printCoordinates(Coordinate *list, int amount);

void createFiles(Coordinate *list, int amount);

char *getName(const char letter);

void getLetterFromCoord(char coord[]);

int main(int argc, char **argv) 
{
    char *file;
    FILE *input;
    int coordAmount;
    Coordinate* coordList;

    if (argc != 2) {
        printf("Usage %s <coordinate file>\n", argv[0]);
        exit(1);
    }

    file = argv[1];
    input = fopen(file, "r");

    coordAmount = countCoordinates(input);
    coordList = (Coordinate *) malloc(sizeof(Coordinate) * coordAmount);

    readCoordinates(input, coordList, coordAmount);
    //printCoordinates(coordList, coordAmount);

    qsort(coordList, coordAmount, sizeof(Coordinate), compareCoordinates);
    //printCoordinates(coordList, coordAmount);

    createFiles(coordList, coordAmount);

    fclose(input);
    free(coordList);
}

int countCoordinates(FILE *f) 
{
    char buffer[200];
    int count = 0;
    
    while(fscanf(f, "%s", buffer) == 1) {
        count++;
    }

    rewind(f);

    return count/6;
}

void readCoordinates(FILE *f, Coordinate* coordList, int amount) 
{
    char longC[20];
    char latC[20];
    char garbage[20];

    double longN;
    double latN;

    for (int i = 0; i < amount; i++)
    {
        fscanf(f, "%s", garbage);
        fscanf(f, "%s", latC);
        fscanf(f, "%lf", &latN);
        fscanf(f, "%s", garbage);
        fscanf(f, "%s", longC);
        fscanf(f, "%lf", &longN);

        Coordinate coordinate;

        strcpy(coordinate.latC, latC);
        strcpy(coordinate.longC, longC);

        coordinate.latN = latN;
        coordinate.longN = longN;

        coordList[i] = coordinate;
    }    
    
    rewind(f);
}

int compareCoordinates(const void * c1, const void * c2) 
{ 
    Coordinate coord1 = *((Coordinate *) c1);
    Coordinate coord2 = *((Coordinate *) c2);

    // Equal
    if (coord1.latN - coord2.latN < 0.0000001 && coord2.latN - coord1.latN < 0.0000001)
    {
        // Equal
        if (coord1.longN - coord2.longN < 0.0000001 && coord2.longN - coord1.longN < 0.0000001)
        {
            return 0;
        }
        else
        {
            // Negative
            if (coord1.longN - coord2.longN < 0) 
            {
                return -1;
            }
            // Positive
            else {
                return 1;
            }
        }
    }
    else
    {
        if (coord1.latN - coord2.latN < 0)
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
} 

void printCoordinates(Coordinate *list, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        printf("Latitude: %s %lf --- Longitude: %s %lf\n", list[i].latC, list[i].latN, list[i].longC, list[i].longN);
    }   
}

void createFiles(Coordinate *list, int amount)
{
    FILE *file1 = fopen("detail.txt","w");
    FILE *file2 = fopen("numbers.txt","w");


    for (int i = 0; i < amount; i++)
    {
        getLetterFromCoord(list[i].latC);
        getLetterFromCoord(list[i].longC);

        fprintf(file1, "%s %s\n", list[i].latC, list[i].longC);
        fprintf(file2, "%lf %lf\n", list[i].latN, list[i].longN);
    } 

    fclose(file1);
    fclose(file2);
}

char *getName(const char letter)
{
   
    if (letter == 'N') {
        return "North";
    }
    if (letter == 'E') {
        return "East";
    }
    if (letter == 'W') {
        return "West";
    }
    if (letter == 'S') {
        return "South";
    }
}

void getLetterFromCoord(char coord[])
{
    char *quote = strstr(coord, "″");
    strcpy(quote+3, getName(*(quote+3)));
}
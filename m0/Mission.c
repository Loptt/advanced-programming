#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct nodeChar {
    struct nodeChar *next;
    char content[100];
} NodeChar;

typedef struct agent {
    char name[100];
    char lastName[100];    
    int age;
    NodeChar *headActivos;
    NodeChar *headMissions;
} Agent;

typedef struct nodeAgent {
    struct nodeAgent *next;
    Agent agent;
} NodeAgent;

NodeAgent *headAgents;

void addAgent();

void readAgent(Agent *agent);

void showAgents();

void printAgent(Agent agent);

bool validateActive(char *mission);

bool validateMission(char *mission);

int main(void)
{
    int opt; 
    while (true)
    {
        printf("MENU: \n 1. Add agent\n 2. Show all agents \n");
        printf("Enter option: ");
        scanf("%d", &opt);

        switch (opt)
        {
            case 1:
                addAgent();
                break;
            case 2:
                showAgents();
                break;
        }
    }
}

void addAgent()
{
    Agent newAgent;
    readAgent(&newAgent);

    if (headAgents == 0)
    {
        headAgents = (NodeAgent*) malloc(sizeof(NodeAgent));
        headAgents->agent = newAgent;
        headAgents->next = 0;
        return;
    }

    NodeAgent *curr = headAgents;

    while (curr->next != 0)
    {
        curr = curr->next;
    }

    curr->next = (NodeAgent*) malloc(sizeof(NodeAgent));
    curr->next->agent = newAgent;
    curr->next->next = 0;
}

bool validateMission(char *mission)
{
    if (strlen(mission) != 12)
    {
        return false;
    }

    for (int i = 0; i < strlen(mission); i++) 
    {

        if (i < 3 && (mission[i] < 'A' || (mission[i] > 'Z' && mission[i] < 'a') || mission[i] > 'z')) 
        {
            return false;
        }

        if (i >= 3 && (mission[i] < '0' || mission[i] > '9')) 
        {
            return false;
        }
    }

    return true;
}

bool validateActive(char *active)
{
    if (strlen(active) != 13)
    {
        return false;
    }

    for (int i = 0; i < strlen(active); i++) 
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

void readAgent(Agent *agent)
{
    int activeAmount = 0, missionAmount = 0;

    char mission[100];
    char active[100];

    NodeChar *curr = 0;

    printf("Enter new agent first name: ");
    scanf("%s", agent->name);

    printf("Enter new agent last name: ");
    scanf("%s", agent->lastName);

    printf("Enter new agent age: ");
    scanf("%d", &agent->age);

    printf("Enter active amount: ");
    scanf("%d", &activeAmount);

    curr = agent->headActivos;

    for (int i = 0; i < activeAmount; i++)
    {
        printf("Enter active #%d: ", i+1);
        scanf("%s", active);

        while (!validateActive(active))
        {
            printf("Invalid active! Enter it again: ");
            scanf("%s", active);
        }

        curr = (NodeChar*) malloc(sizeof(NodeChar));
        strcpy(curr->content, active);
        curr->content[13] = '\0';
        curr = curr->next;
    }
    
    printf("Enter mission amount: ");
    scanf("%d", &missionAmount);

    curr = agent->headMissions;

    for (int i = 0; i < missionAmount; i++)
    {
        printf("Enter mission #%d: ", i+1);
        scanf("%s", mission);

        while (!validateMission(mission))
        {
            printf("Invalid mission! Enter it again: ");
            scanf("%s", mission);
        }

        curr = (NodeChar*) malloc(sizeof(NodeChar));
        strcpy(curr->content, mission);
        curr = curr->next;
    }

    printf("Agent added succesfully\n\n");
}

void showAgents()
{
    if (headAgents == 0)
    {
        printf("No agents registered!\n\n");
    }

    NodeAgent *curr = headAgents;

    while (curr != 0)
    {
        printAgent(curr->agent);
    }
}

void printAgent(Agent agent)
{
    NodeChar *curr = 0;

    printf("==============================\n");

    printf("Agent %s %s\n", agent.name, agent.lastName);
    printf("Age: %d\n", agent.age);

    printf("------------\n");
    printf("Actives: \n");
    curr = agent.headActivos;

    while (curr != 0)
    {
        printf("Imprimiento 1\n");
        printf("%s, ", curr->content);
        printf("Imprimiento 1\n");
        curr = curr->next;
    }

    printf("\n");
    printf("------------\n");

    printf("Missions: \n");
    curr = agent.headMissions;

    while (curr != 0)
    {
        printf("%s, ", curr->content);
        curr = curr->next;
    }

    printf("\n");
    printf("------------\n");
    printf("==============================\n");


}
//
// Author: Carlos Estrada
// ID: A01039919
// Date: 01/03/2020
//
// Mission 0
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

/*
================================
Structs definitions
================================
*/

// Node for string lists
typedef struct nodeChar {
    struct nodeChar *next;
    char content[100];
} NodeChar;

// Struct defining the agent's characteristics
typedef struct agent {
    char name[100];
    char lastName[100];    
    int age;
    int id;
    NodeChar *headActivos;
    NodeChar *headMissions;
} Agent;

// Node for agent lists
typedef struct nodeAgent {
    struct nodeAgent *next;
    Agent agent;
} NodeAgent;

/*
================================
Global variables
================================
*/

// Agents list
NodeAgent *headAgents = 0;

/*
================================
Function definitions
================================
*/

/*
Function to add a new agent to the list
Parameters: none
Return: none
*/
void addAgent();

/*
Function to read the agent's attributes and validate them
Parameters: the agent to modify
Return: none
*/
void readAgent(Agent *agent);

/*
Function to print all agents
Parameters: none
Return: none
*/
void showAgents();

/*
Function print a specific agent
Parameters: agent to print
Return: none
*/
void printAgent(Agent agent);

/*
Function to determine if a string is a valid active
Parameters: string to validate
Return: if it is valid
*/
bool validateActive(char *mission);

/*
Function to determine if a string is a valid mission
Parameters: string to validate
Return: if it is valid
*/
bool validateMission(char *mission);

/*
Function to add a new node of type char to the list
Parameters: head of the list, content to add
Return: none
*/
void addNodeChar(NodeChar **head, char *content);

/*
Function to delete an agent from the list
Parameters: none
Return: none
*/
void deleteAgent();

/*
Function to delete the lists of an agent
Parameters: agent to delete
Return: none
*/
void deleteAgentInfo(Agent agent);

/*
Function to determine if the id is not already present
Parameters: id to validate
Return: if it is valid
*/
bool isValidId(int id);

// Main function
int main(void)
{
    int opt;
    bool running = true;
    while (running)
    {
        printf("\n=======================\n");
        printf("\nMENU: \n 1. Add agent\n 2. Show all agents \n 3. Delete agent\n 4. Quit\n\n");
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
            case 3:
                deleteAgent();
                break;
            case 4:
                running = false;
                break;
            default:
                printf("\nInvalid option\n");
        }
    }
}

/*
================================
Function Implementations
================================
*/

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
    int activeAmount = 0, missionAmount = 0, id = 0;

    char mission[100];
    char active[100];

    NodeChar *curr = 0;

    agent->headActivos = 0;
    agent->headMissions = 0;

    printf("Enter new agent first name: ");
    scanf("%s", agent->name);

    printf("Enter new agent last name: ");
    scanf("%s", agent->lastName);

    do
    {
        printf("Enter agent ID: ");
        scanf("%d", &id);
    } while (!isValidId(id));

    agent->id = id;

    printf("Enter new agent age: ");
    scanf("%d", &agent->age);

    printf("Enter active amount: ");
    scanf("%d", &activeAmount);

    for (int i = 0; i < activeAmount; i++)
    {
        printf("Enter active #%d: ", i+1);
        scanf("%s", active);

        while (!validateActive(active))
        {
            printf("Invalid active! Enter it again: ");
            scanf("%s", active);
        }

        addNodeChar(&agent->headActivos, active);
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

        addNodeChar(&agent->headMissions, mission);
    }

    printf("Agent added succesfully\n\n");
}

void showAgents()
{
    printf("\n\nAGENTS:\n\n");

    if (headAgents == 0)
    {
        printf("No agents registered!\n\n");
    }

    NodeAgent *curr = headAgents;

    while (curr != 0)
    {
        printAgent(curr->agent);
        curr = curr->next;
    }
}

void printAgent(Agent agent)
{
    NodeChar *curr = 0;

    printf("Agent %s %s\n", agent.name, agent.lastName);
    printf("ID: %d\n", agent.id);
    printf("Age: %d\n", agent.age);

    if (agent.headActivos == 0)
    {
        printf("No Actives! \n");
    }
    else
    {
        printf("------------\n");
        printf("Actives: \n");
        curr = agent.headActivos;

        while (curr != 0)
        {
            printf("%s, ", curr->content);
            curr = curr->next;
        }

        printf("\n");
    }
    
    if (agent.headMissions == 0)
    {
        printf("No Missions! \n");
    }
    else
    {
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
    }
    

    printf("\n");
}

void addNodeChar(NodeChar **head, char* content)
{
    NodeChar *curr = *head;

    if (*head == 0)
    {
        *head = (NodeChar*) malloc(sizeof(NodeChar));
        strcpy((*head)->content, content);
        (*head)->next = 0;
        return; 
    }

    while (curr->next != 0)
    {
        curr = curr->next;
    }

    curr->next =  (NodeChar*) malloc(sizeof(NodeChar));
    strcpy(curr->next->content, content);
    curr->next->next = 0;
}

void deleteAgent()
{
    int id = 0;
    NodeAgent *curr = headAgents;
    NodeAgent *tmp;

    printf("Enter agent ID: ");
    scanf("%d", &id);

    if (curr == 0)
    {
        printf("\nError: Agent not found!\n");
        return;
    }

    if (curr->agent.id == id)
    {
        headAgents = curr->next;
        deleteAgentInfo(curr->agent);
        free(curr);
        printf("\nAgent %d deleted successfully.\n", id);
        return;
    }

    while (curr->next != 0)
    {
        if (curr->next->agent.id == id)
        {
            tmp = curr->next;
            curr->next = curr->next->next;
            deleteAgentInfo(tmp->agent);
            free(tmp);
            printf("\nAgent %d deleted successfully.\n", id);
            return;
        }
        curr = curr->next;
    }

    printf("\nError: Agent not found!\n");
}

void deleteAgentInfo(Agent agent)
{
    NodeChar *curr1 = agent.headActivos;
    NodeChar *curr2 = agent.headActivos;

    while (curr1 != 0)
    {
        curr2 = curr1;
        curr1 = curr1->next;
        free(curr2);
    }

    curr1 = agent.headMissions;
    curr2 = agent.headMissions;

    while (curr1 != 0)
    {
        curr2 = curr1;
        curr1 = curr1->next;
        free(curr2);
    }
}

bool isValidId(int id)
{
    NodeAgent *curr = headAgents;

    if (headAgents == 0)
        return true;

    while (curr != 0)
    {
        if (curr->agent.id == id)
        {
            printf("ID already exists!\n");
            return false;
        }
        curr = curr->next;
    }

    return true;
}
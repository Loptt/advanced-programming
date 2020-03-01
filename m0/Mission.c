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
    int id;
    NodeChar *headActivos;
    NodeChar *headMissions;
} Agent;

typedef struct nodeAgent {
    struct nodeAgent *next;
    Agent agent;
} NodeAgent;

NodeAgent *headAgents = 0;

void addAgent();

void readAgent(Agent *agent);

void showAgents();

void printAgent(Agent agent);

bool validateActive(char *mission);

bool validateMission(char *mission);

void addNodeChar(NodeChar **head, char *content);

void deleteAgent();

void deleteAgentInfo(Agent agent);

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

    agent->headActivos = 0;
    agent->headMissions = 0;

    printf("Enter new agent first name: ");
    scanf("%s", agent->name);

    printf("Enter new agent last name: ");
    scanf("%s", agent->lastName);

    printf("Enter new agent ID (numeric): ");
    scanf("%d", &agent->id);

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
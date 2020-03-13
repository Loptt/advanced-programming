//
// Author: Carlos Estrada
// ID: A01039919
// Date: 08/03/2020
//
// Mission 1
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
bool authenticated = false;
char *realPassword = "a";

/*
================================
Function definitions
================================
*/

/*
Function to show menu
Parameters: none
Return: none
*/
void showMenu();

/*
Function to encrypt string using multiplicative cypher
Parameters: string to encrypt
Return: none
*/
void encrypt(char message[100]);

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
Function to delete an agent
Parameters: none
Return: none
*/
void askDeleteAgent();

/*
Function to delete an agent from the list
Parameters: none
Return: none
*/
void deleteAgent(int id);

/*
Function to delete the lists of an agent
Parameters: agent to delete
Return: none
*/
void deleteAgentInfo(Agent agent);

/*
Function to find a given agent
Parameters: none
Return: none
*/
void findAgent();

/*
Function to find a given agent with last name
Parameters: none
Return: none
*/
void findAgentLastName();

/*
Function to find a given agent with active
Parameters: none
Return: none
*/
void findAgentActive();

/*
Function to manage a found agent
Parameters: found agent
Return: none
*/
void manageAgent(Agent *agent);

/*
Function to edit given agent
Parameters: found agent
Return: none
*/
void editAgent(Agent *agent);

/*
Function to add new active to agent
Parameters: agent to modify
Return: none
*/
void addActive(Agent *agent);

/*
Function to add new mission to agent
Parameters: agent to modify
Return: none
*/
void addMission(Agent *agent);

/*
Function to determine if the id is not already present
Parameters: id to validate
Return: if it is valid
*/
bool isValidId(int id);

/*
Function to validate password
Parameters: password and real password
Return: if it is valid
*/
bool validatePassword(char *p, char *rp);


// Main function
int main(void)
{
    char password[100];

    printf("Enter password: ");
    scanf("%s", password);

    authenticated = validatePassword(password, realPassword);

    showMenu();
}

/*
================================
Function Implementations
================================
*/

void showMenu()
{
    int opt;
    bool running = true;

    char menu[] = "\nMENU: \n 1. Add agent\n 2. Show all agents \n 3. Find Agent \n 4. Delete agent\n 5. Quit\n\n";
    char option[] = "Enter option: ";
    char invalid[] = "\nInvalid option\n";

    encrypt(menu);
    encrypt(option);
    encrypt(invalid);

    while (running)
    {
        printf("\n=======================\n");
        printf("%s", menu);
        printf("%s", option);
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
                findAgent();
                break;
            case 4:
                askDeleteAgent();
                break;
            case 5:
                running = false;
                break;
            default:
                printf("%s", invalid);
        }
    }
}

void encrypt(char message[])
{
    if (authenticated)
        return;
    
    for (int i = 0; i < strlen(message); i++)
    {
        if (message[i] == '\n')
            continue;

        message[i] = ((message[i] * 23) % 90) + '!';
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
    char enterName[] = "Enter new agent first name: ";
    char enterLName[] = "Enter new agent last name: ";
    char enterID[] = "Enter agent ID: ";
    char enterAge[] = "Enter new agent age: ";
    char enterAAmount[] = "Enter active amount: ";
    char enterActive[] ="Enter new active: ";
    char enterMAmount[] = "Enter mission amount: ";
    char enterMission[] = "Enter new mission: ";
    char invalidActive[] = "Invalid active! Enter it again: ";
    char invalidMission[] = "Invalid mission! Enter it again: ";
    char added[] = "Agent added succesfully";


    int activeAmount = 0, missionAmount = 0, id = 0;

    char mission[100];
    char active[100];

    NodeChar *curr = 0;

    agent->headActivos = 0;
    agent->headMissions = 0;

    encrypt(enterName);
    encrypt(enterLName);
    encrypt(enterID);
    encrypt(enterAge);
    encrypt(enterAAmount);
    encrypt(enterActive);
    encrypt(enterMAmount);
    encrypt(enterMission);
    encrypt(invalidActive);
    encrypt(invalidMission);
    encrypt(added);

    printf("%s", enterName);
    scanf("%s", agent->name);

    printf("%s", enterLName);
    scanf("%s", agent->lastName);

    do
    {
        printf("%s", enterID);
        scanf("%d", &id);
    } while (!isValidId(id));

    agent->id = id;

    printf("%s", enterAge);
    scanf("%d", &agent->age);

    printf("%s", enterAAmount);
    scanf("%d", &activeAmount);

    for (int i = 0; i < activeAmount; i++)
    {
        printf("%s", enterActive);
        scanf("%s", active);

        while (!validateActive(active))
        {
            printf("%s", invalidActive);
            scanf("%s", active);
        }

        addNodeChar(&agent->headActivos, active);
    }
    
    printf("%s", enterMAmount);
    scanf("%d", &missionAmount);

    curr = agent->headMissions;

    for (int i = 0; i < missionAmount; i++)
    {
        printf("%s",enterMission);
        scanf("%s", mission);

        while (!validateMission(mission))
        {
            printf("%s", invalidMission);
            scanf("%s", mission);
        }

        addNodeChar(&agent->headMissions, mission);
    }

    printf("%s\n\n", added);
}

void showAgents()
{
    char agents[] = "AGENTS:";
    char noAgents[] = "No agents registered!";

    encrypt(agents);
    encrypt(noAgents);

    printf("\n\n%s\n\n", agents);

    if (headAgents == 0)
    {
        printf("%s\n\n", noAgents);
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
    char name[300];
    char age[10];
    char id[10];
    char active[100];
    char mission[100];

    
    char actives[] = "Actives: ";
    char missions[] = "Missions: ";
    char noActives[] = "No actives!";
    char noMissions[] = "No missions!";

    NodeChar *curr;
    
    sprintf(name, "Agent %s %s", agent.name, agent.lastName);
    sprintf(age, "Age: %d", agent.age);
    sprintf(id, "ID: %d", agent.id);

    encrypt(name);
    encrypt(age);
    encrypt(id);
    encrypt(actives);
    encrypt(missions);
    encrypt(noActives);
    encrypt(noMissions);

    printf("%s\n", name);
    printf("%s\n", id);
    printf("%s\n", age);

    curr = agent.headActivos;

    printf("----------\n");

    if (curr == 0)
    {
        printf("%s\n", noActives);
    }
    else
    {
        printf("%s:\n", actives);
        while (curr != 0)
        {
            sprintf(active, "%s, ", curr->content);
            encrypt(active);
            printf("%s", active);
            curr = curr->next;
        }

        printf("\n");
    }

    curr = agent.headMissions;
    printf("----------\n");

    if (curr == 0)
    {
        printf("%s\n", noMissions);
    }
    else
    {
        printf("%s:\n", missions);
        while (curr != 0)
        {
            sprintf(mission, "%s, ", curr->content);
            encrypt(mission);
            printf("%s", mission);
            curr = curr->next;
        }

        printf("\n");
    }
    printf("----------\n");
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

void askDeleteAgent()
{
    char enter[] = "Enter agent ID: ";
    int id = 0;

    encrypt(enter);

    printf("%s", enter);
    scanf("%d", &id);

    deleteAgent(id);
}

void deleteAgent(int id)
{
    char error[] = "\nError: Agent not found!\n";
    char success[] = "\nAgent deleted successfully.\n";
    NodeAgent *curr = headAgents;
    NodeAgent *tmp;

    encrypt(error);
    encrypt(success);

    if (curr == 0)
    {
        printf("%s", error);
        return;
    }

    if (curr->agent.id == id)
    {
        headAgents = curr->next;
        deleteAgentInfo(curr->agent);
        free(curr);
        printf("%s", success);
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
            printf("%s", success);
            return;
        }
        curr = curr->next;
    }

    printf("%s", error);
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

void findAgent()
{
    char findWhatMessage[] = "\nFind agent using:\n 1. Last name \n 2. Active\n 3. Cancel \n option: ";
    char invalidOption[] = "Invalid option. Try again ";
    int opt;

    encrypt(findWhatMessage);
    encrypt(invalidOption);


    do
    {
        printf("%s", findWhatMessage);
        scanf("%d", &opt);
        
        if (opt < 1 || opt > 3)
        {
            printf("%s", invalidOption);
        }

    } while (opt < 1 || opt > 3);
    

    if (opt == 3)
    {
        return;
    }

    switch (opt)
    {
        case 1:
            findAgentLastName();
            break;
        case 2:
            findAgentActive();
            break;
    }
}

void findAgentLastName()
{
    char askLastName[] = "Enter agent's last name: ";
    char noAgents[] = "No agents found with given last name\n";
    char lastName[100];
    NodeAgent *curr = headAgents;

    encrypt(askLastName);
    encrypt(noAgents);

    printf("%s", askLastName);
    scanf("%s", lastName);

    while (curr != 0)
    {
        if (strcmp(lastName, curr->agent.lastName) == 0)
        {
            manageAgent(&curr->agent);
            return;
        }
        curr = curr->next;
    }

    printf("%s", noAgents);
}

void findAgentActive()
{
    char askLastName[] = "Enter agent's active: ";
    char noAgents[] = "No agents found with given active\n";
    char active[100];
    NodeAgent *curr = headAgents;
    NodeChar *currChar;

    encrypt(askLastName);
    encrypt(noAgents);

    printf("%s", askLastName);
    scanf("%s", active);

    while (curr != 0)
    {
        currChar = curr->agent.headActivos;

        while (currChar != 0) 
        {
            if (strcmp(active, currChar->content) == 0)
            {
                manageAgent(&curr->agent);
                return;
            }
            currChar = currChar->next;
        }
        curr = curr->next;
    }

    printf("%s", noAgents);
}

void manageAgent(Agent *agent)
{
    char agentFound[] = "Agent found:";
    char options[] = "What do you want to do with this agent?\n 1. Edit \n 2. Delete\n 3. Canel \nOption: ";
    char invalidOption[] = "Invalid option. Try again ";
    int opt;

    encrypt(options);
    encrypt(invalidOption);
    encrypt(agentFound);

    printf("\n%s\n", agentFound);
    printAgent(*agent);

    do
    {
        printf("%s", options);
        scanf("%d", &opt);
        
        if (opt < 1 || opt > 3)
        {
            printf("%s", invalidOption);
        }

    } while (opt < 1 || opt > 3);
    

    if (opt == 3)
    {
        return;
    }

    switch (opt)
    {
        case 1:
            editAgent(agent);
            break;
        case 2:
            deleteAgent(agent->id);
            break;
    }
}

void editAgent(Agent *agent)
{
    char options[] = "What do you want to add?\n 1. Actives \n 2. Missions\n 3. Cancel \nOption: ";
    char invalidOption[] = "Invalid option. Try again ";
    char edited[] = "Agent edited successfully";
    int opt;

    encrypt(options);
    encrypt(invalidOption);
    encrypt(edited);

    do
    {
        printf("%s", options);
        scanf("%d", &opt);
        
        if (opt < 1 || opt > 3)
        {
            printf("%s", invalidOption);
        }

    } while (opt < 1 || opt > 3);
    

    if (opt == 3)
    {
        return;
    }

    switch (opt)
    {
        case 1:
            addActive(agent);
            break;
        case 2:
            addMission(agent);
            break;
    }

    printf("%s\n", edited);
}

void addActive(Agent *agent)
{
    char enter[] = "Enter active to add: ";
    char invalid[] = "Invalid active! Enter it again: ";
    char active[20];

    encrypt(enter);
    encrypt(invalid);

    printf("%s\n", enter);

    scanf("%s", active);

    while (!validateActive(active))
    {
        printf("%s", invalid);
        scanf("%s", active);
    }

    addNodeChar(&agent->headActivos, active);
}

void addMission(Agent *agent)
{
    char enter[] = "Enter mission to add: ";
    char invalid[] = "Invalid mission! Enter it again: ";
    char mission[20];

    encrypt(enter);
    encrypt(invalid);

    printf("%s\n", enter);

    scanf("%s", mission);

    while (!validateMission(mission))
    {
        printf("%s", invalid);
        scanf("%s", mission);
    }

    addNodeChar(&agent->headMissions, mission);
}

bool isValidId(int id)
{
    char invalid[] = "ID already exists!";
    NodeAgent *curr = headAgents;

    encrypt(invalid);

    if (headAgents == 0)
        return true;

    while (curr != 0)
    {
        if (curr->agent.id == id)
        {
            printf("%s\n", invalid);
            return false;
        }
        curr = curr->next;
    }

    return true;
}

bool validatePassword(char *p, char *rp)
{
    return strcmp(p, rp) == 0;
}
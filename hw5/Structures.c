//
// Author: Carlos Estrada
// ID: A01039919
// Date: 19/02/2020
//
// Exercises with structs in C
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// This structs defines the field of an agent
typedef struct agent 
{
    char name[100]; 
    char lastName[100];
    char gender[50];
    char mission[12];
    int age;
} Agent;

void readAgentInfo(Agent *agent);

void printAgentInfo(Agent agent);

// Main function
int main(void)
{
    Agent agent;
    readAgentInfo(&agent);
    printAgentInfo(agent);
}

/* This function reads the necessary fields for an agent
* Parameters:
* Agent *agent: The agent to store the results
*/
void readAgentInfo(Agent *agent)
{
    char mission[12];
    bool correctMission = true;

    printf("Enter agent's first name: ");
    scanf("%s", agent->name);

    printf("Enter agent's last name: ");
    scanf("%s", agent->lastName);

    printf("Enter agent's age: ");
    scanf("%d", &agent->age);

    printf("Enter agent's gender (one word): ");
    scanf("%s", agent->gender);

    do {
        printf("Enter agent's mission ID (3 letters followed by 9 numbers): ");
        scanf("%s", mission);
        
        correctMission = true;

        if (strlen(mission) < 12)
        {
            correctMission = false;
        }

        for (int i = 0; i < strlen(mission); i++) 
        {

            if (i < 3 && (mission[i] < 'A' || (mission[i] > 'Z' && mission[i] < 'a') || mission[i] > 'z')) 
            {
                correctMission = false;
            }

            if (i >= 3 && (mission[i] < '0' || mission[i] > '9')) 
            {
                correctMission = false;
            }
        }

        if (!correctMission) {
            printf("%s", "Invalid mission ID\n");
        }
    }
    while (!correctMission);

    strcpy(agent->mission, mission);
}

/* This function prints the agent's info in a formated manner
* Parameters:
* Agent agent: The agent to print
*/
void printAgentInfo(Agent agent)
{
    printf("Agent %s %s, of %d years of age, identifies themselves as %s and is currently deployed executing mission %s\n",
        agent.name, agent.lastName, agent.age, agent.gender, agent.mission);
}
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>

// State to perform the xorshift
struct state
{
    uint32_t a;
};

/*
Function that performs the xorshift algorithm on a state
Parameters:
The state to update it
Return: The next value for the state
*/
uint32_t xorshift(struct state *s)
{
	uint32_t r = s->a;

	r ^= r << 13;
	r ^= r >> 17;
	r ^= r << 5;

	return s->a = r;
}

/*
Function that performs the xorshift algorithm 100 times to generate the random
number
Parameters:
Nothing
Return:
Nothing
*/
int random()
{
    struct state s;

    s.a = time(0);

    for (int i = 0; i < 100; i++)
    {
        xorshift(&s);
    }

    return xorshift(&s);
}

// Main function to test the program
int main(void)
{
    printf("10 random numbers\n");
    for (int i = 0; i < 10; i++)
    {
        printf("Random %d: %u\n", i+1, random());
        sleep(1);
    }
}
#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool vote(string name);
void print_winner(void);

typedef struct
{
    string name;
    int votes;
}
candidate;

// Global variables

int MAX = 9;
int candidate_count;
candidate candidates[9];

int main(int argc, string argv[])
{
    candidate_count = argc - 1;

    // User input
    int number_of_voters = get_int("Number of voters: ");

    // Assigning candidates to their candidate position and voting
    for (int i = 0; i < number_of_voters; i++)
    {
        candidates[i].name = argv[i + 1];
        string name = get_string("Vote: ");
        vote(name);
    }

    // Printing out the winner/s
    print_winner();
    return 0;
}

// vote function
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }

    return false;
}

// print_winner function:
// Compares the largest number of votes with the
//candidates' votes, if they have that number of votes they are printed
void print_winner(void)
{
    int max_vote = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_vote)
        {
            max_vote = candidates[i].votes;
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_vote)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}

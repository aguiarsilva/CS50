#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // Iterate over each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // Check if candidate's name matches given name - use string compare function
        if (strcmp(name, candidates[i].name) == 0)
        {
            // if yes, increment candidate's votes and return true
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Find the maximum number of votes
    // Need variable to store top voted candidate
    int top_votes = 0;
    int i = 0;
    int j = 0;

    // iterate through list of candidates
    while (candidate_count > i)
    {
        // check for the candidate with most votes and set it to the variable top votes
        if (candidates[i].votes > top_votes)
            top_votes = candidates[i].votes;
        i++;
    }
    // Print the candidate (or candidates) with maximum votes
    // after checking how many votes the winner received, check if the candidate amount of votes
    // matches the top_votes variable
    while (candidate_count > j)
    {
        if (candidates[j].votes == top_votes)
            // print the name of the candidates that reached the top_votes amount
            printf("%s\n", candidates[j].name);
        j++;
    }
    return;
}

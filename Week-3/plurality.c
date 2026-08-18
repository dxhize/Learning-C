#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct
{
    string name;
    int votes;
} candidate_type;

int main(int argc, string argv[])
{
    candidate_type candidate[argc-1];
// checks the range conditions for the starting of the function
    if (argc <= 1 || argc > 10)
    {
        return 1;
    }
    // fills in the given values into a pre-initialized array with votes of each to be 0
    for (int i = 1, j = 0; i<argc; i++, j++)
    {
        candidate[j].name = argv[i];
        candidate[j].votes = 0;
    }

    // first we recieve all this data. 
    // we need to calculate how many times, a given entitity in argv, is again choosen during the voting operation
    // rather then using just strings to make comparisons, we know its not easy to do, so we will use strcmp() for that. 
    // first we will store the given argv entities into our normal candidates array, and then set their all vote counts to 0;
    // on a successful true bool from the strcmp, we can increment te number of vote for that matched entitiy
    // strcmp(s1,s2);

    for (int i = 0; i<argc-1;i++)
    {   
        string selected_candid = get_string("Vote: ");
        int found = 0;
        for (int i = 0; i<argc-1; i++)
        {
            if (strcmp(selected_candid, candidate[i].name) == 0)
            {
                candidate[i].votes++;
                found = 1;
                break;
            }// if the voter inputs a possible input, vote increases
        }
        if (found == 0)
        {
            printf("Invalid\n");
            continue;
        }
    }
    // till here we have the names, and the votes assigned to them during this vote operation. now we gotta find out
    // who has the maximum votes. we can do that by using something like selection sort here.
    int max_vote_index = 0;
    for (int i = 1; i<argc-1; i++)
    {
        if (candidate[i].votes > candidate[max_vote_index].votes)
        {
            max_vote_index = i;
        }
        if (candidate[i].votes == candidate[max_vote_index].votes)
        {
            printf("Tie!\n");
            return 1;
        }
        else 
        {
            continue;
        }
    }
    // till here, max_vote_index should be updated to the index entity with most votes
    // now the final move
    printf("%s\n", candidate[max_vote_index].name);
}
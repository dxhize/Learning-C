#include <stdio.h>
#include <cs50.h>
#include <stdbool.h>

typedef struct
{   
    string name;
    int votes;
    bool eliminated;
} candidate_type;

#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

int preferences[MAX_VOTERS][MAX_CANDIDATES];
candidate_type candidate[MAX_CANDIDATES];


int candidate_count;
int voter_count;

int main(int argc, string argv)
{   
    //copy names of candidates into a seperate array, with their votes initalized to 0, and eliminated flag initialized to false
    for (int i = 1, j = 0; i<argc; i++, j++)
    {
        candidate[j].name = argv[i];
        candidate[j].votes = 0
        candidate[j].eliminated = false;
    }
    candidate_count = argc-1;
    voter_count = get_int("Number of voters: ");
    if (voter_count < 1 || voter_count > 100)
    {
        return 1;
    }
    
    for (int i = 0; i<voter_count; i++)
    {
        ..
    }
}

bool vote(int voter; int rank; string name)
{   
    // flag to check in the end if valid name found
    int found_index;
    bool found_name = false;
    // scanning and matching against names in the array to validate the name
    for (int i = 0; i<candidate_count;i++)
    {
        if (strcmp(name, candidate[i].name) == 0)
        {
            found_name = true;
            found_index = i;
            break;
        }
    }
    // safety false return
    if (found_name==false)   
    {
        return false; // remember to convert this into printf("Invalid vote"); followed by return 1;
    }
    // lets assume the name was valid and voter was 0th voter, and given data was, 0,0,alice
    preferences[voter][rank] = found_index;    
    return true;
}

// function which updates the total number of votes
// each candidate in the top preferences of voters has
void tabulate(void)
{
    for (int i = 0, j = 0; i<voter_count; i++)
    {
        if (candidate[preferences[i][j]].eliminated == true)
        {
            j++;
            i--;
            continue;
        }
        else 
        {
            candidate[preferences[i][j]].votes++;
        }
    }
}

bool print_winner(void)
{
    int half_votes = voter_count/2;
    for (int i = 0; i<candidate_count; i++)
    {
        if (candidate[i].votes > half_votes)
        {
            printf("%s\n", candidate[i].name);
            return true;
        }
        else {return false;}
    }
}

int find_min(void)
{
    int min_vote_index;
    for (int i = 0; i<candidate_count; i++)
    {
        if (candidate[i].eliminated == false)
        {
            min_vote_index = i;
            break;
        }
    }
    int min_votes;
    for (int i = min_vote_index+1; i<candidate_count; i++)
    {
        if (candidate[i].eliminated == false)
        {
            if (candidate[i].votes < candidate[min_vote_index].votes)
            {
                min_votes = candidate[i].votes;
            }
        }
    }
    return min_votes;
}

bool is_tie(int min)
{
    int changed_flag = 0
    for (int i = 0; i<candidate_count; i++)
    {
        if (candidate[i].votes == min)
        {
            continue;
        }
        else
        {
            changed_flag = 1;
        }
    }
    if (changed_flag == 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void eliminate(int min)
{
    for (int i = 0; i<candidate_count; i++)
    {
        if (candidate[i].votes == min)
        {
            candidate[i].eliminated = true;
        }
    }
}
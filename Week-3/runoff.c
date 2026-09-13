#include <stdio.h>
#include <cs50.h>
#include <stdbool.h>
#include <string.h>

// prototypes here of helper functions
bool vote(int voter; int rank; string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

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
candidate_count = argc-1;

int main(int argc, string argv)
{   
    //copy names of candidates into a seperate array, with their votes initalized to 0, and eliminated flag initialized to false
    for (int i = 1, j = 0; i<argc; i++, j++)
    {
        candidate[j].name = argv[i];
        candidate[j].votes = 0
        candidate[j].eliminated = false;
    }
    voter_count = get_int("Number of voters: ");
    // returns 1 to stop program if voter count not in range
    if (voter_count < 1 || voter_count > 100)
    {
        return 1;
    }
    
    // performs the voting operation, calls vote() on each new addition thus adding them to preference memory array
    for (int i = 0; i<voter_count; i++)
    {
        string current_candidate;
        for (int j = 0; j<candidate_count; j++)
        {
            printf("Rank %i: ", j+1);
            current_candidate = get_string("");
            if (vote(i,j,current_candidate) == true)
            {
                continue;
            }
            else
            {
                return 1;
            }
            printf("\n");
        }           
    }
    
    // calling tabulate() here will count us the total first preference votes a candidate has
    // in case of elimination, it still works
    // but we gotta have this running in a loop, rather than 1 single call.
    while (true) // i know its dangerous
    {
        tabulate();
        if (print_winner() == false)
        {
            eliminate(find_min());
        }
        else if (is_tie(find_min()) == true)
        {
            printf("Tie!");
            return 1;
        }
        else
        {
            return 1;
        }
    }    
}


// this function takes these parameters, alters the preferences 2d array
// in a way so that every voter based on their given rank and name of the candidate gets the candidate saved in their
// ballot (2d array). performs a scan operation using a bool flag and returns true if the array is altered
// false if name doesnt match
bool vote(int voter, int rank, string name)
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
    // instead of saving the name of the candidate in the 2d array we rather put the index of the candidate as per their name
    // which can later be used to extract the name itself
    preferences[voter][rank] = found_index;    
    return true;
}

// function which updates the total number of votes
// each candidate in the top preferences of voters has
// adds 1 vote to the candidate's votes in the top preferences, if the candidate is not eliminated
void tabulate(void)
{
    for (int i = 0, j = 0; i<voter_count; i++)
    {
        // these pointers i and j move like a file system, through the preference array, i keeps a candidate
        // while j keeps the record of that candidate's index postion in the overall candidate array
        if (candidate[preferences[i][j]].eliminated == true)
        {
            j++;
            i--;
            continue;
        }
        else 
        {
            // right after the first not-eliminated candidate is found, their vote is added by 1, and pointer j resets
            // to avoid garbage condidtion in next voter's ballot
            candidate[preferences[i][j]].votes++;
            j = 0;
        }
    }
}

// this function can scan the candidate array, and if a winner is found, prints its name and returns true;
// thus ending the program
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
// this function finds and returns the minimum number of votes a candidate has.
int find_min(void)
{
    // find the first candidate in the candidate array to start from on basis of elimination
    // from the first candidate who is found not eliminated,we start further sorting 
    // this saves some cpu cycles later during sorting (not exactly lol)
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
    // prolly follows the selection sort mechanism
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

// checks if all candidates dont share the minimum votes possible, on this condition being true, returns false
// else returns true
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

// takes the minimum votes value, and eliminates candidates if they have that number of votes
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
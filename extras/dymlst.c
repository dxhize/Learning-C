#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>

unsigned long hash(unsigned char *str);
int dynamic_bucket_handler(char ***bucket_arr, int *capacity);

typedef struct node
{
    int number;
    struct node *next;
} node;


int main(void)
{
    int buffer = 5;
    char **bucket_arr = (char**)malloc(buffer*sizeof(char *));
    if (bucket_arr == NULL)
    {
        return 1;
    }
    if (dynamic_bucket_handler(&bucket_arr, &buffer) != 0)
    {
        return 1;
    }   
    return 0;  
}

int dynamic_bucket_handler(char ***bucket_arr, int *capacity)
{
    int turn = 0;
    int buff_mltiplier = 2;
    while (true)
    {
        char *word = get_string("Word: ");
        if (word == NULL)
        {
            break;
        }

        if (turn == *capacity)
        {
            int new_capacity = *capacity * buff_mltiplier;
            char **temp = realloc(*bucket_arr, new_capacity * sizeof(char *));
            if (temp == NULL)
            {
                printf("Error occured while reallocation!\n");
                return 1;
            }
            *capacity = new_capacity;
            *bucket_arr = temp;
            buff_mltiplier++;
        }

        (*bucket_arr)[turn] = (char *)malloc((strlen(word)+1) * sizeof(char));
        if ((*bucket_arr)[turn] == NULL)
        {
            printf("Memory allocation failed!\n");
            return 1;
        }
        strcpy((*bucket_arr)[turn], word);
        turn++;
        
    }
    return 0;
}

unsigned long hash(unsigned char *str) 
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) 
    {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }

    return hash;
}
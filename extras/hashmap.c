#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <time.h>

unsigned long hash(unsigned char *str);
typedef struct node
{
    char *data;
    struct node *next;
} node;

int print_hshmap(node **bucket_arr, int capacity);
int lookup(node **bucket_arr, char *query);

int main(void)
{
    clock_t start_time, end_time;
    double time_taken;

    int capacity = 60;
    int bucket_arr_size = 10;
    node **bucket_arr = (node **)malloc(capacity*sizeof(node *)); // here i first allocate a double pointer to keep a track of a nodal array

    for (int i = 0; i<bucket_arr_size; i++)
    {
        bucket_arr[i] = NULL;
    }// here i set all the pointers of nodes to NULL

    printf("Press CTRL+D to stop input stream!\n");

    node *tmp;
    for (int i = 0; i<capacity; i++)
    {
        char *name = get_string("Name: ");
        if (name == NULL || name[0] == '\0')
        {
            printf("\n");
            printf("Encountered EOF. Ending input stream.\n");
            printf("Printing the hash-database: \n");
            break;
        }

        int hash_index = hash(name)%10;

        if (bucket_arr[hash_index] == NULL)
        {
        bucket_arr[hash_index] = malloc(sizeof(node));
        bucket_arr[hash_index]->data = name;
        bucket_arr[hash_index]->next = NULL;
        }
        else
        {
            tmp = bucket_arr[hash_index];
            while (tmp->next != NULL)
            {
                node *next = tmp->next;
                tmp = next;
            }
            tmp->next = malloc(sizeof(node));
            node *n = tmp->next;
            n->data = name;
            n->next = NULL;
        }
    }// till here the data is allocated to nodes one by one while also taking care of the 
    // collision cases, and the bucket_arr gets initialised and filled up by data
    clearerr(stdin);
    print_hshmap(bucket_arr,bucket_arr_size);
    printf("enter 'f'-lookup, 'n'-none\n");
    while (true)
    {
        char ans = get_char("Action: ");
        if (ans == 'f')
        {
            char *query = get_string("Name to look for: ");
            start_time = clock();
            lookup(bucket_arr, query);// i have implemented this lookup function which reverses the flow and finds the data using the hash value
            //provided by the djb2 function
            end_time = clock();
            time_taken = ((double)(end_time-start_time))/CLOCKS_PER_SEC;
            printf("Lookup time: %f seconds.\n");
        }
        if (ans == 'n')
        {
            break;
        }
    }
}

int lookup(node **bucket_arr, char *query)
{
    int hash_index = hash(query)%10;
    node *tmp = bucket_arr[hash_index];
    int node_index = 0;

    if (tmp == NULL)
    {
        printf("=====================\n(Entity Not Found!)\n=====================\n");
        return 0;
    }
    while (tmp->next != NULL)
    {   
        if (strcmp(tmp->data, query) == 0)
        {
            printf("====(Entity Found!)====\nEntity: %s\nLocation:\nArray-Index: %i\nNode-Index: %i\n=======================\n",tmp->data, hash_index, node_index);
            return 0;
        }
        tmp = tmp->next;
        node_index++;
    }

    if (tmp->next == NULL && strcmp(tmp->data, query) != 0)
    {
        printf("=====================\n(Entity Not Found!)\n=====================\n");
        return 0;
    }

    else if (tmp->next == NULL && strcmp(tmp->data, query) == 0)
    {
        printf("====(Entity Found!)====\nEntity: %s\nLocation:\nArray-Index: %i\nNode-Index: %i\n=======================\n",tmp->data, hash_index, node_index);
        return 0;
    }
}

int print_hshmap(node **bucket_arr, int capacity)// i have also implemented this function which also prints how the data structure looks visually
{
    printf("\n");
    for (int i = 0; i<capacity; i++)
    {
        if (bucket_arr[i] == NULL)
        {
            printf("[%i] = [NULL]\n", i);
            continue;
        }
        else 
        {
            node *tmp = bucket_arr[i];
            printf("[%i] = [%s]", i, tmp->data);
            while (tmp->next != NULL)
            {
                printf("-->");
                node *s = tmp->next;
                tmp = s;
                printf("[%s]",tmp->data);
            }
            printf("\n");
        }
    }
}

unsigned long hash(unsigned char *str) // returns a hash index of the given string
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) 
    {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    // this is the djb2 function which provides the hash values 
    return hash;
}

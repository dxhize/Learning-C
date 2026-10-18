#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>


typedef struct node
{
    int number;
    struct node *adrs;
} node;

void print_llst(node *list);
int add(node *list, int value);
int insert(node **list, int position, int value);
int pop(node **list, int position);
int turn;

int main(void)
{
    node *list = NULL;
    turn = get_int("Lenght of Linked List: ");

    for (int i = 0; i<turn; i++)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }

        (*n).number = get_int("Number: ");
        (*n).adrs = NULL;

        (*n).adrs = list;
        list = n;
    }
    print_llst(list);
    printf("i-insert,a-append_at_end,p-pop,n-none\n");
    while (true)
    {
        char ans = get_char("Action: ");
        if (ans == 'a')
        {
            add(list,get_int("Value: "));
            print_llst(list);
        }
        if (ans == 'i')
        {
            insert(&list,get_int("Position(0-th order): "),get_int("Value: "));
            print_llst(list);
        }
        if (ans == 'p')
        {
            pop(&list,get_int("Position(0th order): "));
            print_llst(list);
        }


        if (ans == 'n')
        {
            break;
            return 1;
        }
    }

}

void print_llst(node *list)
{
    if (list == NULL) 
    {
        printf("Empty List\n");
        return NULL;
    }

    node *ptr = list;
    printf("  *list--------------->");
    
    // Loop until we are standing on the VERY LAST node
    while (ptr->adrs != NULL)
        {
            printf("[%i]---------->", ptr->number);
            ptr = ptr->adrs;
        } 
    // Print the very last node's value and a newline
    printf("[%i]\n", ptr->number);

    // --- Bottom row stays exactly the same ---
    printf("(%p)", list);
    printf("           ");

    for (ptr = list->adrs; ptr != NULL; ptr = ptr->adrs)
        {
            printf("(%p)", ptr);
            printf(" ");
        } printf("   ");printf("(NULL)\n");
}


int add(node *list, int value)
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    (*n).number = value;
    (*n).adrs = NULL;

    if (list == NULL)
    {
        list = n;
        return 0;
    }

    node *ptr = list;
    

    while (ptr->adrs != NULL)
    {
        node *adrs = ptr->adrs;
        ptr = adrs;
    }
        (*ptr).adrs = n;
    turn++;
}

int insert(node **list, int position, int value)
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    (*n).adrs = NULL;
    (*n).number = value;

    node *ptr = *list;

    if (position == 0)
    {
        (*n).adrs = *list;
        *list = n;
        return 0;
    }
    else if (position >0 && position < turn-1)
    {   
        int i = 0;
        while (i<position-1)
        {
            ptr = ptr->adrs;
            i++;
        } n->adrs = ptr->adrs;
          ptr->adrs = n;    
    }
    else if (position == turn-1)
    {
        printf("Use add()");
        return 1;
    }
}

int pop(node **list, int position)
{
    if (list == NULL || *list == NULL)
    {
        printf("Error! list is empty!");
        return -1;
    }

    node *temp = *list;

    if (position == 0)
    {
        int pop_data = temp->number;
        *list = temp->adrs;
        free(temp);
        return pop_data;
    }

    node *n = NULL;
    for (int i = 0; i<position; i++)
    {
        n = temp;
        temp = temp->adrs;
    }
    if (temp == NULL)
    {
        return -1;
    }

    n->adrs = temp->adrs;

    int pop_data = temp->number;
    free(temp);
    return pop_data;
}
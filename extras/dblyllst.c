#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

struct node
{
    struct node *prev;
    int number;
    struct node *next;
}node;

void print_dllst(struct node *list);

int main(void)
{
    struct node *head = NULL;
    int turn = get_int("Lenght of Linked List: ");

    for (int i = 0; i<turn; i++)
    {
        struct node *tmp = malloc(sizeof(struct node));
        if (tmp == NULL)
        {
            return 1;
        }
        tmp->prev = NULL;
        tmp->number = get_int("Number: ");
        tmp->next = NULL;

        if (head == NULL)
        {
            head = tmp;
        }
        else
        {
        tmp->prev = head;
        head->next = tmp;
        head = tmp;
        }
    }
    struct node *first_node = head;
    while (first_node->prev != NULL)
    {
        first_node = first_node->prev;
    }
    print_dllst(first_node);
}

void print_dllst(struct node *list)
{
    if (list == NULL) 
    {
        printf("Empty List\n");
        return; // Fixed: void functions use 'return;', not 'return NULL;'
    }

    // --- ROW 1: Top Visual Chains [PREV | DATA | NEXT] ---
    struct node *ptr = list;
    printf("*Head Pointer -> ");
    
    while (ptr != NULL)
    {
        // We look at the pointer variables inside the node. 
        // If they are NULL, we print "nil". Otherwise, we print the short hex address (%p).
        printf("[");
        if (ptr->prev == NULL) printf("NULL"); else printf("%p", (void*)ptr->prev);
        printf(" | %i | ", ptr->number);
        if (ptr->next == NULL) printf("NULL"); else printf("%p", (void*)ptr->next);
        printf("]");

        // If there is another node ahead, print a two-way binding arrow
        if (ptr->next != NULL)
        {
            printf(" <=> ");
        }
        ptr = ptr->next;
    }
    printf("\n");

    // --- ROW 2: Physical Memory Mapping Alignment ---
    // This row prints the actual baseline memory addresses of the nodes themselves
    ptr = list;
    printf("                "); // Line up perfectly under the "Head Pointer -> " string
    
    while (ptr != NULL)
    {
        // Print this node's actual home address in memory
        printf(" (At: %p) ", (void*)ptr);
        
        // Add padding space to match the width of the arrow connectors above
        if (ptr->next != NULL)
        {
            printf("       "); 
        }
        ptr = ptr->next;
    }
    printf("\n");
}
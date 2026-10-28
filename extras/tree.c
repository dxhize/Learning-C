#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>


typedef struct node
{
    struct node *parent;
    struct node *left;
    struct node *right;
    int number; 
}node;

node* node_init(int value)
{
    node *n = malloc(sizeof(node));
    n->left = NULL;
    n->right = NULL;
    n->number = value;
    return n;
}

void tree_handler(node *parent_node, int value)
{
    if (value<parent_node->number)
    {
        if (parent_node->left == NULL)
        {
            parent_node->left = node_init(value);
        }
        else
        {
            tree_handler(parent_node->left, value);
        }
    }
    else if (value>parent_node->number)
    {
        if (parent_node->right == NULL)
        {
            parent_node->right = node_init(value);
        }
        else
        {
            tree_handler(parent_node->right, value);
        }
    }
    else if (value == parent_node->number)
    {
        printf("Value already present!\n");
    }
}

void print_tree_visual(node *parent_node, int space, char branch_type)
{
    if (parent_node == NULL)
    {
        return;
    }

    space += 8;

    print_tree_visual(parent_node->right, space, 'R');

    printf("\n");
    for (int i = 8; i < space-4; i++)
    {
        printf(" ");
    } 
    
    if (branch_type == 'R')
    {
        printf("┌── ");
        
    } 
    else if (branch_type == 'L')
    {
        printf("└── ");
    }
    
    printf("%d\n", parent_node->number);

    print_tree_visual(parent_node->left, space, 'L');
}

int main(void)
{
    node *root_node = (node *)node_init(get_int("Value: "));
    root_node->parent = NULL;

    while (true)
    {
        int value = get_int("Value: ");
        if (feof(stdin) != 0)
        {
            break;
        }
        tree_handler(root_node, value);
    } clearerr(stdin);
    printf("\n--- Visual Tree Layout (Tilt Head Left) ---\n");

    print_tree_visual(root_node, 0, 'O');
    
    printf("\n-------------------------------------------\n");  
}
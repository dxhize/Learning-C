#include <stdio.h>
#include <cs50.h>

int main(void)
{   
    int height;
    while (true)
    // getting the positive input
    {
        height = get_int("Height: ");

        if (height<1)
        {
            continue;
        }
        else
        {
            break;
        }
    }
    
    int j = height -1;
    for (int i = 0; i < height; i++)
    {
        // create a loop which prints 1 less space each time
        for (int p = 0; p<j; p++) 
        {
            printf(" ");
        }
        j--;
        // create a loop which starts with 1 # and continues increasing it at every new line
        for (int k = 0; k<=i;k++)
        {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}
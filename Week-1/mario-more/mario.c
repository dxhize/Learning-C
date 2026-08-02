#include <stdio.h>
#include <cs50.h>

 void hash(int s)
        {   for (int k = 0; k<=s;k++)
            {
                printf("#");
            }
        }

int main(void)
{
    int height;
    while (true)
    // getting the positive input between 1 and 8 inclusive
    {
        height = get_int("Height: ");

        if (height<1||height>8)
        {
            continue;
        }
        else
        {
            break;
        }
    }
    int j = height -1;
    for (int i = 0;i<height;i++)
    {
        for (int p = 0; p<j; p++)
        {
            printf(" ");
        }
        j--;
        hash(i);
        printf("  ");
        hash(i);
        printf("\n");
    }

}
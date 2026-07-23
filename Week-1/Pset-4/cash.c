#include <stdio.h>
#include <cs50.h>

int main(void)
{   
    int change;
    while (true)
    {
        change = get_int("Change owed: ");
        if (change<0)
        {
            continue;
        }
        else
        {
            break;
        }
    }
    
    // following the top to bottom rule till it drops below 5
    // div with 25
    int coins = 0;
    while (change>=25)
    {
        change = change - 25;
        coins++;
    }
    while (change>=10)
    {
        change = change-10;
        coins++;
    }
    while (change>=5)
    {
        change = change - 5;
        coins++;
    }
    if (change<5)
    {
        coins = coins + change;
    }
    printf("%i\n",coins);
}
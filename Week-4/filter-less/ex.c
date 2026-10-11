#include <stdio.h>
#include <cs50.h>
#include <stdint.h>

int main(void)
{
    int rows = 3;
    int cols = 4;

    int (*matrix)[cols] = malloc(rows*cols*sizeof(int));
    if (matrix == NULL)
    {
        return 1;
    }

}

#include <stdio.h>
#include <string.h>

int i;
int j;
int counter = 0;

int handler(int x, int len, int arr[len]);

int main(void)
{
    i = 0;
    int arr[] = {1,1,4,2,3};
    int len = 5;
    j = len - 1;

    printf("%d\n", handler(5, 5, arr));
}

int handler(int x, int len, int arr[len])
{
    if (i > j || x < 0)
    {
        return -1;
    }

    int p = arr[i];
    int q = arr[j];

    if (p > q && p <= x)
    {
        x -= p;
        i++; 
    }
    else if (q >= p && q <= x)
    {
        x -= q;
        j--; 
    }   
    else if (p > x && q > x)
    {
        return -1;
    }

    counter++;
    
    if (x == 0)
    {
        return counter;
    }  

    if (x > 0)
    {
        return handler(x, len, arr);
    }
    
    return -1;
}

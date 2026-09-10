#include <stdio.h>
    
//alphabetic global array for revolution after 9
char chararr[] = {'A','B','C','D','E','F'};

int main(void)
{
    int n;
    printf("n: ");
    scanf("%i", &n);
    if (n>255){printf("Hexadecimal doesnt support number greater than 255\n");return 0;}

    char first;
    char last;
    int flip = 0;
    if (n<=9) {printf("0x0%i", n); return 1;}

    while (n>=16)
    {        
        flip++;
        n = n-16;
    }
    // we use the final value of n and connect it with the alphabets if n>9
    if (n>9)
    {
        last = chararr[n-10];
    }
    if (flip>9)
    {
        first = chararr[flip-10];
    }
    // hex num, num hex, hex hex, num num
    if (flip>9 && n<=9) 
    {
        printf("Hex code is: 0x%c%i\n", first, n);
    }
    if (flip <=9 && n>9)
    {
        printf("Hex code is: 0x%i%c\n", flip, last);
    }
    if (flip>9 && n>9)
    {
        printf("Hex code is: 0x%c%c\n", first, last);
    }
    if (flip<=9 && n<=9)
    {
        printf("Hex code is: 0x%i%i\n", flip, n);
    }
}

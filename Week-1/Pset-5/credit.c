#include <stdio.h>
#include <cs50.h>
#include <stdbool.h>

int main(void)
{   

    long card_number;
    while (true)
    {
        if (card_number = get_long("Number: "))
        {
            if (card_number>0)
            {    
            break;
            }
        }
    }
   
    string card_name;
    bool found_name = false;
    int s = 0; // odd strip
    int p = 0; // even strip
    int t = 0;
  
    while (true)
    {   
        
       if (card_number == 0)
       {
           break;
        }
        
        if (card_number == 4)
       {
           if (t == 6)
           {
               card_name = "VISA";
               found_name = !found_name;
           }
       }
       
        // here performed the odd strip
        s = s + card_number%10;
        
        // MASTERCARD check
        if (card_number == 51 ||card_number == 52 || card_number ==53 || card_number ==54 || card_number ==55)
        {
            card_name = "MASTERCARD";
            found_name = !found_name;
        }

        // here comes the even strip
        card_number /= 10;
        p = p + ((card_number%10)*2)%10 + ((card_number%10)*2)/10;

         // VISA check
       if (card_number == 4)
       {
           if (t == 7)
           {
               card_name = "VISA";
               found_name = !found_name;
           }
       }
        // AMEX check
        if (card_number == 34 || card_number ==37)
        {
            card_name = "AMEX";
            found_name = !found_name;
        }
        if (card_number == 0)
        {
           break;
        }
       
        card_number /= 10;


        t++;
    }

    if (found_name == false)
        {
            printf("INVALID\n");
        }
    else if ((s+p)%10 == 0 && found_name == true )
    {
        printf("%s\n", card_name);
    }
     
}
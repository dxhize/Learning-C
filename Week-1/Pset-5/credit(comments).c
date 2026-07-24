#include <stdio.h>
#include <cs50.h>
#include <stdbool.h>

int main(void)
{   
    // remember that a modulo by 10 gives the last digit 
    // get correct user input
    long card_number;
    while (true)
    {
        if (card_number = get_long("Number: "))
        {
            break;
        }
    }
    //strip away every last pos number by dividing by 10 in long integer format
    string card_name;
    bool found_name = false;
    int s = 0; // odd strip
    int p = 0; // even strip
    int t = 0;
  
    while (true)
    {   
        // AMEX check
        if (card_number == 34 || card_number ==37)
        {
            card_name = "AMEX";
            found_name = !found_name;
        }
        // MASTERCARD check
        if (card_number == 51 ||card_number == 52 || card_number ==53 || card_number ==54 || card_number ==55)
        {
            card_name = "MASTERCARD";
            found_name = !found_name;
        }
        // VISA check
       if (card_number == 4)
       {
           if (t == 13 || t == 16)
           {
               card_name = "VISA";
               found_name = !found_name;
           }
       }
        
        // here performed the odd strip
        s = s + card_number%10;
        // here comes the even strip
        if (card_number == 0)
        {
            break;
        }
        

        card_number /= 10;
       
       // p = p + card_number%10;
        // this till here willl look like 0+2+6+5+4+9 and so on
        // we gotta rather combine them and multiply, we mutiply at same time, 
        //perform if else to detect digits
        // and only add those digits
        p = p + ((card_number%10)*2)%10 + ((card_number%10)*2)/10;
        
        t++;
    }
    //after every strip-off add the number at last pos to a variable with initial value 0
    //again strip and keep repeating, till end
    // before stripping those initial odd pos numbers, add their value to a second variable
    // initialised with 0
    if (found_name == false)
        {
            card_name = "INVALID";
        }
    else if ((s+p)%10 == 0 && found_name == true )
    {
        printf("%s\n", card_name);
    }
    // apply modulo on the sum of these 2 variables and match with 0    
}
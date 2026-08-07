#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int char_handler(char letter, int key);

int main(int argc, string argv[])
{   

    // confirm cli input in digits
    while (true)
    {
        if (argc == 2)
        {   
            if (atoi(argv[1]) == 0)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
            else {break;}
        }
        else 
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // save the key number
    int key = atoi(argv[1]);

    // ***theory***
    // first we take input from user in form of command line, the input is the key
    // according to caesar, the alphabets are inclusively replaced by the index + key value
    // its like, out of 26 letters, the letters become the same after each 26 revolutions
    // so if its the letter "A", after 25 revolves, it becomes "Z" and at the 26th one it again becomes "A"
    // thats what the formula is about. if the sum of key and index of the character exceeds 26
    // they get divided by 26 meaning a whole circle gets completed, and gets to the letter it is meant to be
    // ***

    // gets the input (plaintext) from the user after number(argv[1]) has being recognized 
    string input;
    while (true)
    {    
        if ((input = get_string("PlainText: ")))
        {
            break;
        }
        else {continue;} 
    }
    // there doesnt seems to be an easy way to not use some identification about casing, and get the right letter with the right case
    // even tho it can be done, but i aint going that long right now
    // we can use "islower()" function for this, and create one single function maybe that just performs the task and not apply DRY
    printf("ciphertext: ");
    for (int i = 0,j = strlen(input); i<j;i++)
        {
           if (isdigit(input[i]))
           {
            printf("%i", input[i]);
            i++;
            continue;
           }
           else if (isblank(input[i]))
           {
            printf("%c",input[i]);
            i++;
            continue;
           }
            else if (ispunct(input[i]))
            {
                printf("%c",input[i]);
                i++;
                continue;
            }
            else
            {
            printf("%c", char_handler(input[i], key));                
            }
        }
    printf("\n");
    // another useful function is atoi from "stdlib.h" which ill use to convert argv[1] into an int
    // Capital chars start from 65 and go till 90 inclusive.
    // small chars 97 to 122
    // these are total of 52 characters
    // if a character 'H' is to be considered, its position would be 7 if count with 'A' as 0
    // the position of 'H' is 72 in ascii table, a key basically less or equal to 18 wont be a problem
    // but as soon it turns 19, the letter has to be 'A' but direct addition to ascii index will cause trouble
    // dynamically trying to subtract by using conditions wont be good
    // the best idea would be, subtract the lower range of the specific casing from the letter index of ascii
    // u get the zero order index, perform the remainder function on it to get the final zero count index    
    // add back the lower range to it to get the specific required character ascii index and finally set a print loop.

}

int char_handler(char letter, int key)
{   
    int lower_bound;
    int ascii_index = (int) letter;
    
    if (isupper(letter)) {lower_bound = 65;} else {lower_bound = 97;}

    int final_index;
    final_index = (((ascii_index - lower_bound) + key) % 26) + lower_bound;
    return final_index;
}
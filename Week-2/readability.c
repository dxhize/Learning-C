#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

void text_handler(string text,int arr[]);
int main(void)
{
    string input = get_string("Text: ");
    int values[3]; 

    text_handler(input, values);
    float L = (values[0]*100.0f)/values[1];// using correct float data type to avoid truncation
    float S = (values[2]*100.0f)/values[1];
    int G;

    float index = (0.0588f * L) - (0.296f * S) - (15.8f);//the main formula
    if (index - (int) index < 0.5000)
        {
            G = (int) index;
        }
    else
        {
            G = (int) index + 1;
        }
    if (index < 1.0)
        {
            printf("Before Grade 1\n");
        }
    if (index > 16.0)
        {
            printf("Grade 16+\n");
        }
    if (G >1 && G < 17)
        {
            printf("Grade %i\n", G);
        }
}

void text_handler(string text,int arr[]) // this is the handler/helper function which contains the parsing algorithm
{
    int g = 0;
    int x = 0;/// these are all the counter vars
    int y = 0;

    for (int i = 0, z = strlen(text); i<z; i++)
    {
        if (isalpha(text[i])) // checks for the letters in every character
        {
            g++;
            for (i=(i+1); isalpha(text[i]) ; i++) // if matched then it keeps on cheking until the word ends
            {
                g++;
            }
        }

        if (isspace(text[i])) 
        {
            if (g == 0)
            {
                continue;
            }
            else 
            {   

                x++;
            }
        }
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') // after a space or an exclamatory, a word is detected followed by
        {
            if (g >= 1)
            {
                y++;// detection of the end of string
            }
        }
    }

    arr[0] = g;// finally passed to the main to compute
    arr[1] = x+1;
    arr[2] = y;
}

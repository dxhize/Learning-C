#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

void text_handler(string text,int arr[]);
int main(void)
{
    // so we need to use coleman liau's formula to have a working algorithm based on it
    string input = get_string("Text: ");
    // we need the algorithm to be able to understand what a word is, what a sentence is
    int values[3]; // recieves letter, word, statement count respectively
    // we need average number of letters per 100 words
    // which is (no of letters * 100) / total words
    // similarly
    // we need average number of sentences per 100 words (no. of sentences is what we need this time)
    text_handler(input, values);
    float L = (values[0]*100.0f)/values[1];
    float S = (values[2]*100.0f)/values[1];
    int G;
    // once do that, we can easily extract the number of values it gets maybe we can do it all in one helper function
    // and use insert the values into the coleman formula and get the output
    // here comes the final value
    float index = (0.0588f * L) - (0.296f * S) - (15.8f);
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
    // with that said we have some edge cases, like inserting spaces alot of times before the first word
    // or multiple spaces inside the text which we need to ignore sometimes
    // and proceed with puctuation marks which notify the ending of a statement
}

void text_handler(string text,int arr[])
{
    // maintain counter variables for statement tracking, and word tracking respectively
    // can use isspace() and isalpha() from ctype.h
    int g = 0;// letter counter
    int x = 0;// word counter
    int y = 0;// statement counter

    // example- / "crow" can be a "cow", but "cow" can't be a "crow"!
    for (int i = 0, z = strlen(text); i<z; i++)
    {
        if (isalpha(text[i])) // check if its a letter
        {
            g++;
            for (i=(i+1); isalpha(text[i]) ; i++) // check if the next character is a letter
            {
                g++;
            }
        }// all good till here

        if (isspace(text[i])) // malfunctioning
        {
            if (g == 0)
            {
                continue;
            }
            else 
            {   

                x++;// only increment if the space came after a letter or multiple were found and then the space was present
            }
        }
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') //perfectly running rn
        {
            if (g >= 1)
            {
                y++;// statement increment only at '.'
            }
        }
    }

    arr[0] = g;
    arr[1] = x+1;
    arr[2] = y;
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main(void)
{
    // so we need to use coleman liau's formula to have a working algorithm based on it
    // we need the algorithm to be able to understand what a word is, what a sentence is
    // once do that, we can easily extract the number of values it gets maybe we can do it all in one helper function
    // and use insert the values into the coleman formula and get the output

    // with that said we have some edge cases, like inserting spaces alot of times before the first word
    // or multiple spaces inside the text which we need to ignore sometimes
    // and proceed with puctuation marks which notify the ending of a statement
}
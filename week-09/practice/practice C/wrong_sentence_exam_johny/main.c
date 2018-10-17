#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    There are some mistakes in the sentence below: some words start with capital letter, despite the fact
    that only the initial word should start with a capital letter.
    Print out the wrong words.
    Your program works as expected if you see this text on the console:
    Not
    Many
    Note that, strtok() is not neccessary to use and not always the best solution.
    */

    char text[]= "He said he was Not there yesterday; however, Many people saw him there.";
    char *token;

    /* get the first token */
    token = strtok(text, " ");

    /* walk through other tokens */
    int counter = 0;
    while( token != NULL ) {

        if(counter != 0 && token[0] >= 'A' && token[0] <= 'Z')
        {
          printf( " %s\n", token );
        }

        token = strtok(NULL, " ");
        ++counter;
    }

    return 0;
}

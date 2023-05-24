/**
 * File: my_strtok
 * Authors: Abenezer Kifle & Fabrice RANDRIATSIMIVONY
 *
 */

#include <stdio.h>

/**
 * my_strtok - returns a pointer to a newly allocated space in memory
 *            containing a copy of the tokens from a given string input.
 *
 * @inputString: an input long string to be split into words.
 *
 *
 */

unsigned int is_delim(char c, char *delim)
{
    while (*delim != '\0')
    {
        if (c == *delim)
            return (1);
        delim++;
    }
    return (0);
}

char *my_strtok(char *inputString, char *delim)
{
    static char *backup_string; // start of the next search
    if (!inputString)
    {
        inputString = backup_string;
    }
    if (!inputString)
    {
        // user is bad user
        return NULL;
    }
    // handle beginning of the string containing delims
    while (1)
    {
        if (is_delim(*inputString, delim))
        {
            inputString++;
            continue;
        }
        if (*inputString == '\0')
        {
            // end of the string
            return NULL;
        }
        break;
    }
    char *ret = inputString;
    while (1)
    {
        if (*inputString == '\0')
        {
            /*end of the input string and
            next exec will return NULL*/
            backup_string = inputString;
            return (ret);
        }
        if (is_delim(*inputString, delim))
        {
            *inputString = '\0';
            backup_string = inputString + 1;
            return (ret);
        }
        inputString++;
    }
}

// int main()
// {
//     // an input string to be split into words
//     char inputString[] = "Any Sentence Could be Split into Words";
//     // delimiter
//     char *delim = "; ";
//     // calling own version of strtok function
//     char *token = my_strtok(inputString, delim);
//     while (token)
//     {
//         printf("%s\n", token);
//         token = my_strtok(NULL, delim);
//     }
//     return 0;
// }
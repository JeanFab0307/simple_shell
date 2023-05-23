#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *inputString;
    size_t length = 1024;

    while (1)
    {
        printf("$ ");
        inputString = (char *)malloc(length);
        getline(&inputString, &length, stdin);
        // user input is taken!

        // parsing continues....
        char *token = strtok(inputString, " ");
        char *parsed[5]; // an array of strings to store a command input.
        // I gave the array size 5 if there is a case we could get morethan 
        // 5 strings it could be edited!

        int index = 0; 
        while (token != NULL)
        {
            if (index == 0)
            {
                char bin[] = "/bin/";
                strcat(bin, token); // concatinating a command with bin.
                parsed[index] = bin;
            }
            else
            {
                parsed[index] = token;
            }
            token = strtok(NULL, " ");
            index++;
        }

        char *commandArray[index];
        for (int i = 0; i < index; i++)
        { // copying a command array to a new string array.
            commandArray[i] = parsed[i];
            printf(" % s\n", commandArray[i]);
        }

        // Todo next step....
    }

    return (0);
}

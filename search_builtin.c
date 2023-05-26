#include <stdlib.h>
#include "main.h"
#define EXIT_SHELL "exit -shell"

/**
 * search_builtin - search if the command entered is a buitin command
 * @argv: an array of string where the builtin command can be found
 *
 * Return: Nothing
 */
void search_builtin(char **argv)
{
        int i = 0;
        builtin_t command[] = {
            {"exit", exit_shell},
            {NULL, NULL}};

        while (command[i])
        {
                if (!strcmp(argv[0], command[i].name))
                {
                        command[i].action(argv);
                        free_2D(argv[0]);
                        break;
                }
                i++;
        }
}
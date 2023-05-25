#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "main.h"

void handle(int sig);
/**
 * main - entry point in the simple shell
 * @ac: the number of argument passed in the prompt
 * @av: an array of string containing the arguments given in the prompt
 * @env: an array of string of the environement of the program
 *
 * Return: 0 on success
 * Or 1 on Failure
 */
int main(int ac __attribute__((unused)),
	 char **av, char **env)
{
	char **argv;
	char *input, *buffer;
	int i = 1;

	while (1)
	{
		input = getinput();
		argv = strparse(input, " ");
		if (!argv)
		{
			free_arr(input);
			continue;
		}
		buffer = search_path(argv[0], env);
		if (!buffer)
		{
			fprintf(stderr, "%s: %d: %s: not found\n",
				av[0], i, argv[0]);
		}
		else
		{
			execute(buffer, argv, env);
		}
		if (buffer != argv[0])
			free_arr(buffer);
		free_arr(input);
		free_2D(argv);
		i++;
		signal(SIGTSTP, &handle);
	}
	exit(EXIT_SUCCESS);
}

/**
 * handle - handle an action on a signal stop
 * @sig: the signal
 *
 * Return: nothing
 */
void handle(int sig)
{
        if (sig == SIGTSTP)
        {
                exit(EXIT_SUCCESS);
        }
}

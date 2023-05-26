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
 *
 * Return: 0 on success
 * Or 1 on Failure
 */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char **argv;
	char *input, *buffer;
	int i = 1, res = 0;

	while (1)
	{
		input = getinput();
		argv = strparse(input, " ");
		if (!argv)
		{
			free_arr(input);
			continue;
		}
		free_arr(input);
		res = search_builtin(argv);
		if (res == 1)
		{
			_fprintf(STDERR_FILENO, "ssdsd",
			av[0], ": ", i, ": exit: Illegal value", argv[0]);
		}
		else if (res == -1)
		{
			continue;
		}
		else
		{
			buffer = search_path(argv[0]);
			if (!buffer)
			{
				_fprintf(STDERR_FILENO, "ssisss",
				av[0], ": " i, ": " argv[0], "not found");
			}
			else
			{
				execute(buffer, argv);
			}
			if (buffer != argv[0])
				free_arr(buffer);
			free_2D(argv);
		}
		i++;
		signal(SIGTSTP, &handle);
	}
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

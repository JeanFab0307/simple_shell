#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * exit_shell - exit the shell
 * @argv: the argument with exit
 *
 * Return: -1 if argv is not a positive number
 */
int exit_shell(char **argv)
{
	int status;

	if (argv[1])
		status = _atoi(argv[1]);

	if (status < 0)
	{
		return (-1);
	}
	free_2D(argv);
	exit(EXIT_SUCCESS + status);
}

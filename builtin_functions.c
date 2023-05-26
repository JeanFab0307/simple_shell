#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * exit_shell - exit the shell
 * @argv: the argument with exit
 *
 * Return: -1 if argv is not a positive number
 */
int exit_shell(char **argv)
{
	int stat = 0;

	if (argv[1])
		stat = _atoi(argv[1]);

	if (stat < 0)
	{
		return (-1);
	}
	free_2D(argv);
	exit(EXIT_SUCCESS + stat);
}

/**
 * print_env - print the current environement
 * @argv: the argument with env
 *
 * Return: 1 on success
 * Or 0 on failure
 */
int print_env(char **argv)
{
	int i = 0;

	while (environ[i])
	{
		if (i != 0)
			print_string("\n", STDOUT_FILENO);
		print_string(environ[i], STDOUT_FILENO);
		i++;
	}
	print_string("\n", STDOUT_FILENO);
	free_2D(argv);
	return (1);
}

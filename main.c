#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

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
	 char **av __attribute__((unused)), char **env)
{
	char **argv;
	char *input, *buffer;
	int i = 0;

	while (1)
	{
		input = getinput();
		if (input[0] == '\n')
		{
			free_arr(input);
			continue;
		}
		argv = strparse(input, " ");
		buffer = search_path(argv[0], env);
		if (!buffer)
		{
			perror("Error: ");
		}
		else
		{
			execute(buffer, argv, env);
		}
		free_arr(buffer);
		free_arr(input);
		free_2D(argv);
		i++;
	}
	exit(EXIT_SUCCESS);
}

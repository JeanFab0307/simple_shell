#include <stdlib.h>
#include "main.h"

/**
 * search_builtin - search if the command entered is a buitin command
 * @argv: an array of string where the builtin command can be found
 *
 * Return: Nothing
 */
int search_builtin(char **argv)
{
	int i = 0, res = 0;
	builtin_t command[] = {
		{"exit", exit_shell},
		{NULL, NULL}
	};

	while (command[i].name)
	{
		if (!_strcmp(argv[0], command[i].name))
		{
			res = command[i].action(argv);
			if (res == -1)
				return (-1);
			break;
		}
		i++;
	}
	return (res);
}

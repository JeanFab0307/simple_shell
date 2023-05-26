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
		{"exit", exit_shell}, {"env", print_env},
		{NULL, NULL}
	};

	while (command[i].name)
	{
		if (!_strcmp(argv[0], command[i].name))
		{
			return (command[i].action(argv));
		}
		i++;
	}
	return (res);
}

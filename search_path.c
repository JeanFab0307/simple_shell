#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include "main.h"
#include <string.h>
#include <stdio.h>


/**
 * search_path - identify if the string given is an exiting executable or not
 * @command: a string containing the executable name
 *
 * Return: The path of the given executable
 * Or NULL if it does not exist or on  error
 */
char *search_path(char *command)
{
	char *pathname;
	struct stat st;

	if (!stat(command, &st))
	{
		return (command);
	}

	pathname = search_in_dir(command);
	return (pathname);
}

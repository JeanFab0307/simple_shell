#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "main.h"
#include <string.h>

char **parse_path(char ** environ);
/**
 * search_in_dir - search for an executable in the PATH directories
 * @command: the executable to search for
 * @env: the environement of the program
 *
 * Return: the complete pathname of the executable
 * Or NULL is not found
 */
char *search_in_dir(char *command, char **env)
{
	DIR *path;
	struct dirent *file;
	char *buffer;
	int i = 0, j;
	char **pathdir = NULL;

	pathdir = parse_path(env);
	while (pathdir[i])
	{
		path = opendir(pathdir[i]);
		if (path == NULL)
		{
			perror("Error: ");
			exit(EXIT_FAILURE);
		}

		file = readdir(path);
		while (file != NULL)
		{
			j = 0;
			while (file->d_name[j] == command[j])
			{
				if ((!file->d_name[j]) || (!command[j]))
				{
					closedir(path);
					buffer = _strdup(pathdir[i]);
					free_2D(pathdir);
					buffer = str_concat(buffer, "/");
					buffer = str_concat(buffer, command);
					return (buffer);
				}
				j++;
			}
			file = readdir(path);
		}
		if (closedir(path) == -1)
		{
			perror("Error: ");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	free_2D(pathdir);
	return (NULL);
}

/**
 * parse_path - break the path into its directories
 * @env: the environement of the program
 *
 * Return: An array of string of the directories in the PATH
 */
char **parse_path(char **environ)
{
	char *PATH, *buffer = NULL;
	char **buff2 = NULL;
	int i = 0, j;

	PATH = "PATH=";
	while (environ[i])
	{
		j = 0;
		while (environ[i][j] == PATH[j])
		{
			if (PATH[j + 1] == '\0')
			{
				buffer = _strdup(environ[i]);
				break;
			}
			j++;
		}
		i++;
	}
	buff2 = strparse(buffer, "=");
	free_arr(buffer);
	buffer = _strdup(buff2[1]);
	free_2D(buff2);
	buff2 = strparse(buffer, ":");
	free_arr(buffer);
	return (buff2);
}

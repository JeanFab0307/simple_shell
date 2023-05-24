#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * strparse -  transform a 1D array into a 2D array
 * @str: the array containing one or several words
 * @delim: a string containing the delimitors in str
 * Description: a list of delimiters is specified in delim.
 * The characters will be the chosen delimiters to obtain
 * an array of string form str.
 * "Hello World!" will become "Hello" and "World!" if space is delim
 *
 * Return: A 2D array containing each word of str
 * Or NULL if failed
 */
char **strparse(char *str, char *delim)
{
	unsigned int i;
	char **argv = NULL;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = ' ';
		i++;
	}
	argv = strtow(str, delim[0]);

	if (!argv)
		return (NULL);

	return (argv);
}

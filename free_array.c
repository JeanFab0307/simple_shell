#include <stdlib.h>
#include "main.h"
#include <stdio.h>
/**
 * free_arr - free a 1 Dimensional array
 * @str: the array to free
 *
 * Return: Nothing
 */
void free_arr(char *str)
{
	free(str);
	str = NULL;
}
/**
 * free_2D - free a 2 dimensional array
 * @str: the 2D array
 *
 * Return: Nothing
 */
void free_2D(char **str)
{
	int i = 0;

	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
		str = NULL;
	}
}

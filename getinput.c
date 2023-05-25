#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * getinput - get the input from the prompt
 *
 * Return: Nothing
 */
char *getinput(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t size = 0;
	char *buff = "($) ";
	int len_buff;

	len_buff = _strlen(buff);
	write(STDOUT_FILENO, buff, len_buff);
	size = getline(&input, &len, stdin);
	if (size == -1)
	{
		free_arr(input);
		exit(EXIT_FAILURE);
	}
	return (input);
}

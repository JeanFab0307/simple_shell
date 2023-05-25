#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "main.h"

void handle(int sig);
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
	char *buff = "($) ", *pipe;
	int len_buff;

	pipe = malloc(1);
	if (!write(STDIN_FILENO, pipe, 1))
	{
		len_buff = _strlen(buff);
		write(STDOUT_FILENO, buff, len_buff);
		free_arr(pipe);
	}
	size = getline(&input, &len, stdin);
	if (size == -1)
	{
		free_arr(input);
		exit(EXIT_SUCCESS);
	}
	return (input);
}


#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include "main.h"

/**
 * execute - create a new process to run an executable
 * @command: the pathname of the command
 * @argv: an array of string for the parameters of execve
 *
 * Return: Nothing
 */
void execute(char *command, char **argv)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("Error: ");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(command, argv, environ);
	}
	else
	{
		wait(&status);
	}
}

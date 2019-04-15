#include "holberton.h"
/**
 * execute_execve - execute commands
 * @comand: command to executed
 * Return: 0 on success
 */
int execute_execve(char **comand)
{
	pid_t new_fork;

	new_fork = fork();
	if (new_fork < 0)
		perror("Error: ");
	else if (new_fork == 0)
		execve(comand[0], comand, environ);
	else
		wait(NULL);
	return (0);
}

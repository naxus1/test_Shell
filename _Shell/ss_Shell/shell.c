#include "holberton.h"
/**
 * main - entri point the shell
 * @void: no paramters accepted
 * Return: integer
 */
int main(void)
{
	char *buff_word, **w_get, *aux_word = NULL;
	size_t bufsize;
	int i, r_current = 0;

	while (i != -1)
	{
		buff_word = NULL;
		bufsize = 0;
		signal(SIGINT, SIG_IGN);
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "$_ ", 3);
		i = getline(&buff_word, &bufsize, stdin);
		if (_strcmp(buff_word, "exit") == 0)
			break;
		if (i != 1 && i != -1)
		{
			w_get = token(buff_word);
			aux_word = w_get[0];
			w_get[0] = search_path(w_get[0]);
			if (_strcmp(w_get[0], "NO") == 0)
				continue;
			if (_strcmp(w_get[0], aux_word) == 0)
				r_current =  access(aux_word, F_OK);
			if (_strcmp(w_get[0], aux_word) == 0 && r_current != 0)
			{
				perror(" --Error:");
				free(buff_word);
				continue;
			}
			execute_execve(w_get);
		}
	}
	free(buff_word);
	return (0);
}

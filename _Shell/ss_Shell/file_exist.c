#include "holberton.h"

int file_exist(char **tok_args)
{
	if (access(tok_args[0], F_OK != 0))
		return (1);
	return (0);
}

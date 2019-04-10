#include "holberton.h"

int hand_errors(char **av)
{
	unsigned int i;
	struct stat st;

	i = 0;
	while (av[i])
	{
		printf("%s:", av[i]);
		if (stat(av[i], &st) == 0)
			printf(" FOUND\n");
		else
			printf(" NOT FOUND\n");
		i++;
	}

	return (0);
}

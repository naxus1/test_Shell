#include "holberton_shell.h"

void _strtok(char * word)
{
	char *token;

	printf("%s", word);

	token = strtok(word, "-");
	printf("Primer token%s \n", token);
}

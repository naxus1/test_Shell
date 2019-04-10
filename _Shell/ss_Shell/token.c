#include "holberton.h"

char **token(char *buff_word)
{
	char delimit[]=" \t\r\n\v\f";
	char *word;
	char **token;
	int iterator = 1;

	token = malloc(50 * sizeof(char));
	word = strtok(buff_word, delimit);
	token[0] = word;

	while(word != NULL)
	{
		word = strtok(NULL, delimit);
		token[iterator] = word;
		iterator++;
	}
	return(token);
}

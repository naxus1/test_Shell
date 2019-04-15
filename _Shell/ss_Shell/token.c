#include "holberton.h"
/**
 * token - function to delimit the path
 * @buff_word: word to cut
 * Return: word to token
 */
char **token(char *buff_word)
{
	char delimit[] = " \t\r\n\v\f";
	char *word;
	char **token;
	int iterator = 1;

	if (buff_word == NULL)
		return (NULL);

	token = malloc(50 * sizeof(char));

	if (buff_word == NULL)
		return (NULL);
	word = strtok(buff_word, delimit);
	token[0] = word;

	while (word != NULL)
	{
		word = strtok(NULL, delimit);
		token[iterator] = word;
		iterator++;
	}
	token[iterator] = NULL;
	return (token);
}

#include "holberton.h"
/**
 * _strcmp - comparate two strings
 *@s1: Pointer one to comparate
 *@s2: Pointer two to comparate
 * Return: Always 0 (Success)
 */
int _strcmp(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}


char *_strncpy(char *path, char *comand)
{
	int i, j;
	char *new_string;
	int lenght_path = _strlenght(path);
	int lenght_comand = _strlenght(comand);
	int suma = lenght_path + lenght_comand + 1;

	new_string = malloc(sizeof(char) * suma);

	for (i = 0; i < lenght_path  && path[i] != '\0'; i++)
	{
		new_string[i] = path[i];
	}

	new_string[i] = '/';
	i++;

	for (j = 0; i < suma && comand[j] != '\0'; i++, j++)
	{
		new_string[i] = comand[j];
	}
	return (new_string);
}

int _strlenght(char * palabra)
{
	int i;
	for(i = 0; palabra[i] != '\0'; i++)
	{}
	return (i);
}

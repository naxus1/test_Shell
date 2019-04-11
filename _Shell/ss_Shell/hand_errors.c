#include "holberton.h"

int error_getline(char *word)
{
	if( _strcmp(word, " ") == 0 || _strcmp(word, "\r") == 0 ||
	    _strcmp(word, "\v") == 0 ||
	    _strcmp(word, "\n") == 0 || _strcmp (word, "\f") == 0)
	{
		free(word);
		return (0);
	}
	else
		return (1);
}

#include "holberton.h"
/**
 * _free - free the array_pointer
 * @w_get: array of pointers to free
 * Return: free array of pointers
 */
void _free(char **w_get)
{
	int iterator;

	for (iterator = 0; w_get[iterator] != NULL; iterator++)
	{
		free(w_get[iterator]);
	}
	free(w_get);
}

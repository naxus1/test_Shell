#include "holberton.h"
extern char **environ;

char *search_path(char *comand)
{
	char **get_array = NULL, *word, *result_execute = NULL;
	int i;

	if (comand == NULL)
	  {
	    result_execute = "NO";
	    return (result_execute);
	  }
	else
	  {
	    get_array = create_array();
	    for (i = 0; get_array[i] != NULL; i++)
	      {
		word = _strncpy(get_array[i], comand);
		get_array[i] = word;
	      }
	    
	    result_execute = _execute(get_array);

	    if(_strcmp(result_execute, "NO") == 0)
	      {
		result_execute = comand;
	      }
	    return (result_execute);

	  }
}


char * _execute(char **path_comand)
{
	int i;

	for (i = 0; path_comand[i] != NULL; i++)
	{
		if (access(path_comand[i], F_OK) == 0)
		{
			return (path_comand[i]);
			break;
		}
	}

	return ("NO");

}





char **create_array()
{
	int i = 0, lenght_palabra = 0, cont = 0, j, y, iterator = 1;
	char *aux, **str_tok, *palabra = "PATH", *word;
	char *s2 = NULL;

	lenght_palabra = _strlenght(palabra);
	str_tok = malloc(1024 * sizeof(char));


	while(environ[i] != NULL)
	{

		aux = environ[i];

		for (y = 0, j = 0; y < lenght_palabra; y++, j++)
		{
			if(aux[j] == palabra[j])
		       		cont++;
		}

       		if(cont == lenght_palabra)
		{
			s2 = strdup(environ[i]);
			word =  strtok(s2, "=");
			word = strtok(NULL, "=");
			word = strtok(word, ":");
			str_tok[0] = word;

			while(word != NULL)
			{
				word = strtok(NULL, ":");
				str_tok[iterator] = word;
				iterator++;
			}
			break;
		}
		i++;
	}

	return (str_tok);
}

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cont_word(char * palabra);
extern char **environ;

typedef struct nodo
{
	char *word;
	struct nodo *next;
} new_nodo;


new_nodo *add_node(new_nodo **head, char *str)
{
	new_nodo *node;

	node = malloc(sizeof(new_nodo));

	node->word = str;
	node->next = *head;
	*head = node;

	return(node);
}


int main()
{
	int i = 0, box = 1, lenght_palabra = 0, cont = 0, j, y;
	char *word, *aux, *str_tok;
	char *palabra = "PATH";
	new_nodo *head, *pr_nodo;

	head = NULL;

	lenght_palabra = cont_word(palabra);

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
			str_tok = strtok(environ[i], "=");
			while(str_tok != NULL)
			{
				str_tok = strtok(NULL, ":");
				if(str_tok != NULL)
				{
					printf(" %s\n", str_tok);
					pr_nodo = add_node(&head, str_tok);
				}
			}
			break;
		}
		i++;
	}
}

int cont_word(char * palabra)
{
	int i;

	for(i = 0; palabra[i] != '\0'; i++)
	{}

	return (i);
}

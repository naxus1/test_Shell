#include "holberton.h"

int main(int argc, char * argv[])
{
	char *buff_word;
	size_t bufsize;
	char  **word_get, **aux_o;
	int i;

	while(1)
	{
		buff_word = NULL;
		bufsize = 0;
		if (isatty(0) != 0 )
		  printf("$_ ");
		i = getline(&buff_word, &bufsize, stdin);
		
		if (_strcmp(buff_word, "exit") == 0)
			break;
		
		if (i != 1 && i != -1)
		  {
		       word_get = token(buff_word);
		       word_get[0] = search_path(word_get[0]);
		      
		       if (_strcmp(word_get[0], "NO") == 0)
			 continue;
		     		     		 
		    if (fork() == 0)
		      {
			if (word_get[0] == NULL)
			  exit(EXIT_SUCCESS);
			  
			if (execve(word_get[0], word_get, NULL) == -1)
				perror("Error: ");
			break;
		      }
		    else
		      	wait(NULL);
		  }
	}
	free(buff_word);
 }

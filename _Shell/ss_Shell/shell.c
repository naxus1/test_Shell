#include "holberton.h"

int main(__attribute__((unused))int argc, char * argv[])
{
	char *buff_word = NULL;
	size_t bufsize = 0;
	char *tira [] = {"", NULL}, **word_get;

	while(1)
	{
		printf("$ ");
		getline(&buff_word, &bufsize, stdin);
		word_get = token(buff_word);
        	if(fork() == 0)
			execve(word_get[0], word_get, NULL);
		else
			wait(NULL);
	}

	free(buff_word);
	free(token);
}

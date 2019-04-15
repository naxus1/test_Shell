#ifndef _SHELL_H_
#define _SHELL_H_

extern char **environ;

#include <string.h>
#include <stdarg.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int execute_execve(char **comand);
char *_strdup(char *str_last);
int cont_word(char * palabra);
char **token(char *buff_word);
int _strcmp(const char *s1, const char *s2);
char **create_array();
char *search_path(char *comand);
int cont_word(char * palabra);
int error_getline(char *word);
int file_exist(char **tok_args);
int _strlenght(char * palabra);
char *_strncpy(char *path, char *comand);
char * _execute(char **path_comand);
void _free(char **w_get);

#endif

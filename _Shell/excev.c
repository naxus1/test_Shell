#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int child1, i;
	char* tira [] = { "ls", "-l", "/tmp", 0 };

		for(i = 0; i < 5; i++ )
		{
		 	if(fork() == 0)
			{
				child1 =  execv( "/bin/ls", tira );
				printf("--> ingreso");
				break;
			}
			else
			{

				printf("Hola");
				wait();
			}
		}

		printf("Terminnooooo ::::: [%u]\n", getpid());

}

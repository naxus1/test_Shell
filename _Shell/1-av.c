#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 1;

	for(i = 0; argv[i] != NULL; i++)
	{
		printf("%s\n", argv[i]);
	}
}

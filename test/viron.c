#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

extern char **environ;

int main(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
		printf("environ:[%s]\n", environ[i]);

	return (0);
}

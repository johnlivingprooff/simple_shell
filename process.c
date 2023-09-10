#include "main.h"

/**
 * _process - runs the child processes
 * @path: the string with the path '/bin/'
 * @args: the tokens
 */
void _process(char *path, char **args)
{
	if (fork() == 0)
	{
		execve(path, args, NULL);
		perror("execve error");
		exit(EXIT_FAILURE);
	} else
		wait(NULL);
}

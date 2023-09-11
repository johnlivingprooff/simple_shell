#include "main.h"

/**
 * _process - runs the child processes
 * @path: the string with the path '/bin/'
 * @args: the tokens
 * @envp: the environment variables
 */
void _process(char *path, char **args, char **envp)
{
	if (fork() == 0)
	{
		if (execve(path, args, envp) == -1)
		{
			perror("");
			exit(EXIT_FAILURE);
		}
	} else
		wait(NULL);
}

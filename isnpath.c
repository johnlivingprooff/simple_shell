#include "sshell.h"

/**
 * npath - handles PATH, when cmd isn't a path
 * like '/bin/'
 * @envp: the env pointer
 * @args: array of commands
 */
void npath(char **envp, char **args)
{
	char *token, *path = getenv("PATH");

	if (path == NULL)
	{
		perror("getenv");
		exit(EXIT_FAILURE);
	}

	token = strtok(path, ":");
	while (token != NULL)
	{
		snprintf(envp[0], BUFFER, "%s/%s", token, args[0]);
		execve(envp[0], args, envp);
		token = strtok(NULL, ":");
	}
	perror("");
	exit(EXIT_FAILURE);
}

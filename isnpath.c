#include "sshell.h"

/**
 * npath - handles PATH, when cmd isn't a path like '/bin/'
 * @envp: the env pointer
 * @args: array of commands
 */
void npath(char **envp, char **args)
{
	char *token, *path = getenv("PATH");
	char buffer[BUFFER];

	if (path == NULL)
	{
		perror("getenv");
		exit(EXIT_FAILURE);
	}

	token = strtok(path, ":");
	while (token != NULL)
	{
		snprintf(buffer, sizeof(buffer), "%s/%s", token, args[0]);
		execve(buffer, args, envp);
		token = strtok(NULL, ":");
	}
	perror("execve");
	exit(EXIT_FAILURE);
}
